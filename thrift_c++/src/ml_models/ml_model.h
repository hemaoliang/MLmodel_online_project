#include <math.h>                                                                                                                                             
#include <stdio.h>                                                                                                                                            
#include <stdlib.h>                                                                                                                                           
#include <ctype.h>                                                                                                                                            
#include <float.h>                                                                                                                                            
#include <string.h>                                                                                                                                           
#include <stdarg.h>                                                                                                                                           
#include <limits.h>                                                                                                                                           
#include <locale.h>
#include "svm.h"
#include "eval.h"

class ML_Model
{
public:
	ML_Model(const char *model_file_name);
	~ML_Model();
	//double predict(const libsvm::svm_node *x, double *prob_estimates);
	double predict(const char *line, double *prob_estimates);
	const char * model_type;
};

class LibSvm_Model: public ML_Model
{
public:
	LibSvm_Model(const char *model_file_name);
	~LibSvm_Model();
	//double predict(const libsvm::svm_node *x, double *prob_estimates);
	double predict(const char *line, double *prob_estimates);
	const char * model_type = "libsvm";
private:
	struct libsvm::svm_model *model;

	int *labels;
	int predict_probability = 0;
	int svm_type = 0;
	int nr_class = 2;
};
