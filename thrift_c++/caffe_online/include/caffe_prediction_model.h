#include <cuda_runtime.h>

#include <cstring>
#include <cstdlib>
#include <vector>

#include <string>
#include <iostream>
#include <stdio.h>
#include "caffe/caffe.hpp"
#include "caffe/util/io.hpp"
#include "caffe/blob.hpp"

class Caffe_Model {
public:
	
	Caffe_Model(const std::string model_file_name, const std::string weight_file_name, int height, int width);
	~Caffe_Model();
		
	double predict(char* pic_name, double *prob_estimates);

	std::string name();	

private:
	caffe::Net<float>* caffe_test_net;
	int resize_height;
	int resize_width;

};
