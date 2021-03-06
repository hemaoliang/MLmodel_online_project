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
	ML_Model(){ }
	// if not virtual: will prevent the subclass release the memory
	virtual ~ML_Model(){ }
	//double predict(const libsvm::svm_node *x, double *prob_estimates);
	virtual double predict(char *line, double *prob_estimates) = 0;
	virtual int * get_labels() = 0;
	virtual int get_nr_class() = 0;
	virtual int get_predict_probability() = 0; 

	const char *model_type;
	const char *model_name;
};

class LibSvm_Model: public ML_Model
{
public:
	LibSvm_Model(const char *model_file_name, const char *model_name_unique);
	~LibSvm_Model();
	//double predict(const libsvm::svm_node *x, double *prob_estimates);
	double predict(char *line, double *prob_estimates);
	int get_nr_class();
	int get_predict_probability();
	int * get_labels();

private:
	struct libsvm::svm_model* model;

	int *labels;
	int predict_probability;
	int svm_type;
	int nr_class;
};
