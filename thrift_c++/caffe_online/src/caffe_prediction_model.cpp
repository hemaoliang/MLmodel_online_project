#include "caffe_prediction_model.h"

using namespace caffe;
using namespace std;


Caffe_Model::Caffe_Model(const string model_file_name, const std::string weight_file_name) {
	Caffe::set_mode(Caffe::CPU);
	caffe_test_net = new caffe::Net<float>(model_file_name, caffe::TEST);
	caffe_test_net->CopyTrainedLayersFrom(weight_file_name);

}

double Caffe_Model::predict(char* pic_name, double *prob_estimates)
{
	return 0.0;
}

std::string Caffe_Model::name()
{
	return caffe_test_net->name();
}

Caffe_Model::~Caffe_Model()
{
	delete caffe_test_net;
}

int main( int argc, char** argv )
{
	if(argc != 3)
	{
		printf("useage: %s <model_file> <weight_file>\n ", argv[0]);
		return -1;
	}

	Caffe_Model caffe_model(argv[1], argv[2]);
	printf("caffe net: %s \n", caffe_model.name().c_str() ); 

}
