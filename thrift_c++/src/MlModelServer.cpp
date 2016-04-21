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
#include "mlmodel.h"

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

	MLOlineServiceHandler()
	{
		cout<<"construct handler"<<"\n";
		ml_model = new LibSvm_Model("/home/spongebob/MLmodel_online_project/thrift_c++/data/dianping_qqweixin_comm_feature_scale.model", "test_libsvm");
	}

	~MLOlineServiceHandler()
	{
		if(ml_model != NULL)
		{
			cout<<" free ml_model in handler"<<"\n";
			delete ml_model;
		}
	}
	
	void getLabel(std::vector<int32_t> & _return, const int32_t clientid, const std::string& modelName)
	{
		int nr_class = ml_model->get_nr_class();
		int * label_poi = ml_model->get_labels();
		for(int i=0; i<nr_class; i++)
			_return.push_back(label_poi[i]);
		cout << clientid <<" call getLabel" << endl;
	}

	void modelPredict(returnType& _return, const int32_t clientid, const std::string& modelName, const std::string& strFeature)
	{
		cout << clientid <<" call modelPredict" << endl;
		int nr_class = ml_model->get_nr_class();
		double *prob_estimates = (double *) malloc(nr_class*sizeof(double));
		//string.c_str returns const char* c_str() const and append \0 in the end;
		char * line = new char [strFeature.length()+1];
		strcpy (line, strFeature.c_str());		
		_return.predicted = ml_model->predict(line,prob_estimates);
		//_return.predicted = 0;
		delete[] line;
		for(int i=0; i<nr_class; i++)
		{
			if(ml_model->get_predict_probability()==0)
				_return.prob.push_back(0);
			else
				_return.prob.push_back(prob_estimates[i]);
		}
		free(prob_estimates);
	}

private:
	ML_Model *ml_model;	

};

/*
  MLOlineServiceIfFactory is code generated.
  MLOlineServiceCloneFactory is useful for getting access to the server side of the
  transport.  It is also useful for making per-connection state.  Without this
  CloneFactory, all connections will end up sharing the same handler instance.
*/
class MLOlineServiceCloneFactory : virtual public MLOlineServiceIfFactory {
public:
	virtual ~MLOlineServiceCloneFactory() {}
	virtual MLOlineServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo)
	{
		boost::shared_ptr<TSocket> sock = boost::dynamic_pointer_cast<TSocket>(connInfo.transport);
		cout << "Incoming connection\n";
		cout << "\tSocketInfo: "  << sock->getSocketInfo() << "\n";
		cout << "\tPeerHost: "    << sock->getPeerHost() << "\n";
		cout << "\tPeerAddress: " << sock->getPeerAddress() << "\n";
		cout << "\tPeerPort: "    << sock->getPeerPort() << "\n";
		return new MLOlineServiceHandler;
	}
	virtual void releaseHandler( MLOlineServiceIf* handler)
	{
		delete handler;
	}
};

int main() {
	TThreadedServer server(
		boost::make_shared<MLOlineServiceProcessorFactory>(boost::make_shared<MLOlineServiceCloneFactory>()),
		boost::make_shared<TServerSocket>(8000), //port
		boost::make_shared<TBufferedTransportFactory>(),
		boost::make_shared<TBinaryProtocolFactory>());

	cout << "Starting the server..." << endl;
	server.serve();
	cout << "Done." << endl;
	return 0;
}





