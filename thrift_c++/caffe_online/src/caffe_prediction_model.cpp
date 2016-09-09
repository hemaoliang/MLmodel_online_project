#include "caffe_prediction_model.h"
#include <unistd.h>

using namespace caffe;
using namespace std;


Caffe_Model::Caffe_Model(const string model_file_name, 
	const std::string weight_file_name, int height, int width):resize_height(height),
	resize_width(width) 
{
	Caffe::set_mode(Caffe::CPU);
	caffe_test_net = new caffe::Net<float>(model_file_name, caffe::TEST);
	caffe_test_net->CopyTrainedLayersFrom(weight_file_name);
	vector<shared_ptr<caffe::Layer<float> > > layers = caffe_test_net->layers();
	for (int i = 0; i < layers.size(); ++i) 
	{
		printf("layer: %s \n", layers[i]->type());
	}

}

double Caffe_Model::predict(char* pic_name, double *prob_estimates)
{
	//get datum 
	Datum datum;
	if (!ReadImageToDatum(pic_name, 1, resize_height, resize_width, true, &datum)) 
	{
		LOG(ERROR) << "Error during file reading";
	}
	Blob<float>* blob = new Blob<float>(1, datum.channels(), datum.height(), datum.width());
	
	return 0.0;
}

std::string Caffe_Model::name()
{
	return caffe_test_net->name();
}

int Caffe_Model::get_height()
{
	return resize_height;
}

int Caffe_Model::get_width()
{
	return resize_width;
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
	
	//for(int i=0; i<=20; i++) {
	
	Caffe_Model* caffe_model = new Caffe_Model(argv[1], argv[2], 227, 227);
	printf("caffe net: %s \n", caffe_model->name().c_str() ); 
	delete caffe_model;
	sleep(1);
	//}

}
