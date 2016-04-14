#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "svm.h"
#include "eval.h"
#include "mlmodel.h"


static char *line = NULL;
static int max_line_len;

void exit_with_help()
{
	printf(
	"Usage: svm-predict [options] test_file model_file output_file\n"
	"options:\n"
	"-b probability_estimates: whether to predict probability estimates, 0 or 1 (default 0); for one-class SVM only 0 is supported\n"
	"-q : quiet mode (no outputs)\n"
	);
	exit(1);
}

static char* readline(FILE *input)
{
	int len;

	if(fgets(line,max_line_len,input) == NULL)
		return NULL;

	while(strrchr(line,'\n') == NULL)
	{
		max_line_len *= 2;
		line = (char *) realloc(line,max_line_len);
		len = (int) strlen(line);
		if(fgets(line+len,max_line_len-len,input) == NULL)
			break;
	}
	return line;
}

int main(int argc, char **argv)
{
	FILE *input, *output;
	int i,j;
	int predict_probability=0;
	for(i=1;i<argc;i++)
	{
		if(argv[i][0] != '-') break;
		++i;
		switch(argv[i-1][1])
		{
			case 'b':
				predict_probability = atoi(argv[i]);
				break;
			case 'q':
				//info = &print_null;
				i--;
				break;
			default:
				fprintf(stderr,"Unknown option: -%c\n", argv[i-1][1]);
				
		}
	}
	
	if(i>=argc-2)
		exit_with_help();

	//testing for 1000 times for watching whether memory leak
	for(int k=1; k<=1000; k++)
	{
	printf("testing for %d times.\n" ,k);	
	
	input = fopen(argv[i],"r");
	if(input == NULL)
	{
	fprintf(stderr,"can't open input file %s\n",argv[i]);
		exit(1);
	}

	output = fopen(argv[i+2],"w");
	if(output == NULL)
	{
		fprintf(stderr,"can't open output file %s\n",argv[i+2]);
		exit(1);
	}
	
	max_line_len = 1024;
        line = (char *)malloc(max_line_len*sizeof(char));
	
	//LibSvm_Model *libsvm_model = new LibSvm_Model("/home/spongebob/MLmodel_online_project/thrift_c++/data/dianping_qqweixin_comm_feature_scale.model");
	LibSvm_Model *libsvm_model = new LibSvm_Model(argv[i+1], "test_libsvm");

	double *prob_estimates = NULL;
	int nr_class = libsvm_model->get_nr_class();
	double predict_label;

	predict_probability = libsvm_model->get_predict_probability();
	if(predict_probability) 
	{
		prob_estimates = (double *) malloc(nr_class*sizeof(double));
	}

	//write header
	int * labels = libsvm_model->get_labels();
	fprintf(output,"labels");
	for(j=0;j<nr_class;j++)  
		fprintf(output," %d",labels[j]);
	fprintf(output,"\n");
	
	while(readline(input) != NULL){
		predict_label = libsvm_model->predict(line,prob_estimates);
		fprintf(output,"%g",predict_label);
		if(predict_probability)
		{
			for(j=0;j<nr_class;j++)
				fprintf(output," %g",prob_estimates[j]);
		}
		fprintf(output,"\n"); 

	}

	delete libsvm_model;
	free(line);
	if(prob_estimates != NULL)
		free(prob_estimates);
	fclose(input);
	fclose(output);

	}//end for(int k=1: k<=1000; k++) 

	return 0;
}

