#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "mlmodel.h"

LibSvm_Model::LibSvm_Model(const char *model_file_name, const char *model_name_unique)
{
	model = libsvm::svm_load_model(model_file_name);
	if(model==0) {
		fprintf(stderr,"can't open model file %s\n", model_file_name);
		exit(1);
	}

	model_type = "libsvm";
	model_name = model_name_unique; 
	predict_probability = libsvm::svm_check_probability_model(model);
	svm_type = libsvm::svm_get_svm_type(model);
	nr_class = libsvm::svm_get_nr_class(model);
	
	labels = (int *) malloc(nr_class*sizeof(int));
	libsvm::svm_get_labels(model,labels);
}

LibSvm_Model::~LibSvm_Model()
{
	free(labels);
	libsvm::svm_free_and_destroy_model(&model);
}

int LibSvm_Model::get_nr_class()
{
	return nr_class;
}

int LibSvm_Model::get_predict_probability()
{
	return predict_probability;
}

int * LibSvm_Model::get_labels()
{
	return labels;
}

//LibSvm_Model::predict(const svm_node *x, double *prob_estimates)
double LibSvm_Model::predict(char *line, double *prob_estimates)
{
	struct libsvm::svm_node *x;
	int max_nr_attr = 64;
	x = (struct libsvm::svm_node *) malloc(max_nr_attr*sizeof(struct libsvm::svm_node));

	//int svm_type=libsvm::svm_get_svm_type(model);
	//int nr_class=libsvm::svm_get_nr_class(model);
	//double *prob_estimates=NULL;	

	//if (svm_type==NU_SVR || svm_type==EPSILON_SVR)
	//	printf("Prob. model for test data: target value = predicted value + z,\nz: Laplace distribution e^(-|z|/sigma)/(2sigma),sigma=%g\n",
	//		libsvm::svm_get_svr_probability(model));
	//else
	//{
	//	int *labels=(int *) malloc(nr_class*sizeof(int));
	//	libsvm::svm_get_labels(model,labels);
	//	//prob_estimates = (double *) malloc(nr_class*sizeof(double));
	//	free(labels);
	//}

	int i = 0;
	double target_label, predict_label;	
	char *idx, *val, *label, *endptr;
	int inst_max_index = -1; // strtol gives 0 if wrong format, and precomputed kernel has <index> start from 0	

	char *line_back = (char *)malloc(1000*sizeof(char)); ;
	strcpy(line_back,line); 
	//printf("libsvm predict %s\n", line);
	
	// strtok is not a thread safe function
	//label = strtok(line," \t\n");
	char *last;	
	label = strtok_r(line," \t\n",&last);
	if(label == NULL) // empty line
		fprintf(stderr,"label Wrong input format [%s].\n", line_back); 

	target_label = strtod(label,&endptr);
	if(endptr == label || *endptr != '\0')
		fprintf(stderr,"target_label Wrong input format [%s].\n", line_back);
	
	while(1)
	{
		if(i>=max_nr_attr-1)
		{
			max_nr_attr *= 2;
			x = (struct libsvm::svm_node *) realloc(x,max_nr_attr*sizeof(struct libsvm::svm_node));
		}
		idx = strtok_r(NULL,":",&last);
		val = strtok_r(NULL," \t",&last);
		
		if(val == NULL)
			break;
		errno = 0;
		x[i].index = (int) strtol(idx,&endptr,10);
		if(endptr == idx || errno != 0 || *endptr != '\0' || x[i].index <= inst_max_index)
			fprintf(stderr,"index Wrong input format [%s] index %s.\n", line_back, idx);
		else
			inst_max_index = x[i].index;
		
		errno = 0;
		x[i].value = strtod(val,&endptr);
		if(endptr == val || errno != 0 || (*endptr != '\0' && !isspace(*endptr)))
			fprintf(stderr,"value Wrong input format [%s] val %s.\n", line_back, val);
		
		++i;
	}
	x[i].index = -1;
	
	if(predict_probability)
		predict_label = svm_predict_probability(model,x,prob_estimates);
	else
		predict_label = svm_predict(model,x);	
	
	free(x);
	free(line_back);
	return predict_label;
}
