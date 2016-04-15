#include <thrift/concurrency/ThreadManager.h>                                                                                                                 
#include <thrift/concurrency/PlatformThreadFactory.h>                                                                                                         
#include <thrift/protocol/TBinaryProtocol.h>                                                                                                                  
#include <thrift/server/TSimpleServer.h>                                                                                                                      
#include <thrift/server/TThreadPoolServer.h>                                                                                                                  
#include <thrift/server/TThreadedServer.h>                                                                                                                    
#include <thrift/transport/TServerSocket.h>                                                                                                                   
#include <thrift/transport/TSocket.h>                                                                                                                         
#include <thrift/transport/TTransportUtils.h>                                                                                                                 
#include <thrift/TToString.h>                                                                                                                                 
                                                                                                                                                              
#include <boost/make_shared.hpp>                                                                                                                              
                                                                                                                                                              
#include <iostream>                                                                                                                                           
#include <stdexcept> 
#include <sstream>                                                                                                                                            

#include "../gen-cpp/MLOlineService.h"
#include "ml_models.h"

using namespace std;                                                                                                                                          
using namespace apache::thrift;                                                                                                                               
using namespace apache::thrift::concurrency;                                                                                                                  
using namespace apache::thrift::protocol;                                                                                                                     
using namespace apache::thrift::transport;                                                                                                                    
using namespace apache::thrift::server; 

using namespace mlmodelserver;

class MLOlineServiceHandler : public MLOlineServiceIf
{
public:

	MLOlineServiceHandler() {}

	~MLOlineServiceHandler() 
	{
		if(ml_model != NULL)
			delete ml_model;
	}
	
	void getLabel(std::vector<int32_t> & _return, const int32_t clientid, const std::string& modelName)
	{
		nr_class = ml_model->get_nr_class();
		int * label_poi = ml_model->get_labels();
		for(int i=0; i<nr_class; i++)
			_return.push_back(*label_poi++);
		cout << clientid <<" call getLabel" << endl;
	}

	void modelPredict(returnType& _return, const int32_t clientid, const std::string& modelName, const std::string& strFeature)
	{
		nr_class = ml_model->get_nr_class(); 
		prob_estimates = (double *) malloc(nr_class*sizeof(double));
		//string.c_str returns const char* c_str() const and append \0 in the end;
		char * line = new char [strFeature.length()+1];
		strcpy (line, strFeature.c_str());		
		_return.predicted = ml_model->predict(line.c_str(),prob_estimates);
		delete line;
		for(int i=0; i<nr_class; i++)
		{
			if(ml_model->get_predict_probability()) 
				_return.push_back(0); 
			else
				_return.push_back(*prob_estimates++);
		}
		free(prob_estimates);
	}

private:
	ML_Model *ml_model;	

}





