#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "ml_model.h"

LibSvm_Model::LibSvm_Model(const char *model_file_name)
{
	model = svm_load_model(model_file_name);
	if(model==0) {
		fprintf(stderr,"can't open model file %s\n", model_file_name);
		exit(1);
	}
}
