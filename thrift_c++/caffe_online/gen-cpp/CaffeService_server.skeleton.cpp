// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "CaffeService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::caffeserver;

class CaffeServiceHandler : virtual public CaffeServiceIf {
 public:
  CaffeServiceHandler() {
    // Your initialization goes here
  }

  void modelPredict(returnType& _return, const int32_t clientid, const std::string& picName) {
    // Your implementation goes here
    printf("modelPredict\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<CaffeServiceHandler> handler(new CaffeServiceHandler());
  shared_ptr<TProcessor> processor(new CaffeServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

