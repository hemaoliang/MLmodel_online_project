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

#include "CaffeService.h"
#include "caffe_classifier.hpp"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::concurrency;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

using namespace caffeserver;

class CaffeServiceHandler : public CaffeServiceIf
{
public:
	CaffeServiceHandler(const string& model_file,
                       	    const string& trained_file,
                            const string& mean_file,
                           const string& label_file)
	{

		classifier = new Classifier(model_file, trained_file, mean_file, label_file);
	}

	~CaffeServiceHandler()
	{
		if(classifier != NULL)
		{
			cout<<" free classifier in handler"<<"\n";
			delete classifier;
		}
        }

	void modelPredict(returnType& _return, const int32_t clientid, const std::string& picName)
	{
		std::vector<Prediction> predictions = classifier->Classify_file(picName);
		Prediction p = predictions[0];
		_return.predicted = p.first;
		_return.prob = p.second;
	}

private:
	Classifier * classifier;

};

/*
  CaffeServiceIfFactory is code generated.
  CaffeServiceIfFactory is useful for getting access to the server side of the
  transport.  It is also useful for making per-connection state.  Without this
  CloneFactory, all connections will end up sharing the same handler instance.
*/
class CaffeServiceCloneFactory : virtual public CaffeServiceIfFactory {
public:
	virtual ~CaffeServiceCloneFactory() {}
	virtual CaffeServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo)
	{
		string model_file = "data/cifar10_full_train_test.prototxt";
		string trained_file = "data/cifar_iter_400.caffemodel";
		string mean_file = "data/mean.binaryproto";
		string label_file = "data/label_name.txt";
		boost::shared_ptr<TSocket> sock = boost::dynamic_pointer_cast<TSocket>(connInfo.transport);
		cout << "Incoming connection\n";
		cout << "\tSocketInfo: "  << sock->getSocketInfo() << "\n";
		cout << "\tPeerHost: "    << sock->getPeerHost() << "\n";
		cout << "\tPeerAddress: " << sock->getPeerAddress() << "\n";
 		cout << "\tPeerPort: "    << sock->getPeerPort() << "\n";
 		return new CaffeServiceHandler(model_file, trained_file, mean_file, label_file) ;
	}
	virtual void releaseHandler(CaffeServiceIf* handler)
	{
		delete handler;
	}
};

int main() {

	string model_file = "data/cifar10_full_train_test.prototxt";
	string trained_file = "data/cifar_iter_400.caffemodel";
	string mean_file = "data/mean.binaryproto";
	string label_file = "data/label_name.txt";

	//int port = 8000;
	//boost::shared_ptr<CaffeServiceHandler> handler(new CaffeServiceHandler());
	//boost::shared_ptr<TProcessor> processor(new CaffeServiceProcessor(handler));
	//boost::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
	//boost::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
	//boost::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
	//TThreadedServer server(processor, serverTransport, transportFactory, protocolFactory);

	TThreadedServer server(
		boost::make_shared<CaffeServiceProcessorFactory>(boost::make_shared<CaffeServiceCloneFactory>()),
		boost::make_shared<TServerSocket>(8000), //port
		boost::make_shared<TBufferedTransportFactory>(),
		boost::make_shared<TBinaryProtocolFactory>());

	cout << "Starting the server..." << endl;
	server.serve();
	cout << "Done." << endl;
	return 0;
}

