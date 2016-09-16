#include <iostream>                                                                                                                             
                                                                                                                                                
#include <thrift/protocol/TBinaryProtocol.h>                                                                                                    
#include <thrift/transport/TSocket.h>                                                                                                           
#include <thrift/transport/TTransportUtils.h>                                                                                                   
                                                                                                                                                
#include "CaffeService.h"                                                                                                          
                                                                                                                                                
using namespace std;                                                                                                                            
using namespace apache::thrift;                                                                                                                 
using namespace apache::thrift::protocol;                                                                                                       
using namespace apache::thrift::transport;                                                                                                      
                                                                                                                                                
using namespace caffeserver;

int main(int argc, char **argv) 
{

	//for(int i=0; i<1000;i++) {
	int i=0;
	while(true) {
	boost::shared_ptr<TTransport> socket(new TSocket("localhost", 8000));
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
	CaffeServiceClient client(protocol);

	transport->open();
	returnType return_val;
	client.modelPredict(return_val, 10011, "/home/spongebob/MLmodel_online_project/thrift_c++/caffe_online/data/320.jpg");
	cout << "get result: " << return_val.predicted << "  " << return_val.prob << endl;
	transport->close();

	cout << "current i :" << i << endl;
	i++;
	}
} 
