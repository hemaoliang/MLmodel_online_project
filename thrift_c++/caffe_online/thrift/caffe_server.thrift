/*
 * thrift version 0.9.3
 */
namespace cpp  caffeserver
namespace java caffeserver
namespace php  caffeserver

struct returnType {
  1: string predicted,
  2: double prob
}

exception InvalidInput {
  1: i32 whatOp,
  2: string errorMessage
}

service CaffeService {
  returnType modelPredict(1:i32 clientid, 2:string picName)
}
