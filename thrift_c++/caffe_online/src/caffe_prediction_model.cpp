#include "caffe_prediction_model.h"

using namespace caffe;
using namespace std;


Caffe_Model::Caffe_Model(const string& model_file_name, const string& weight_file_name) {
	Caffe::set_mode(Caffe::CPU);
	caffe_net = new Net(model_file_name, caffe::TEST);
	caffe_net.CopyTrainedLayersFrom(weight_file_name);
	
}
