#include <math.h>                                                                                                                                             
#include <stdio.h>                                                                                                                                            
#include <stdlib.h>                                                                                                                                           
#include <ctype.h>                                                                                                                                            
#include <float.h>                                                                                                                                            
#include <string.h>                                                                                                                                           
#include <stdarg.h>                                                                                                                                           
#include <limits.h>                                                                                                                                           
#include <locale.h>

class ML_Model
{
public:
	ML_Model(const char *model_file_name);
	~ML_Model();
	double predict(const svm_node *x);
	const char * model_name;
};
