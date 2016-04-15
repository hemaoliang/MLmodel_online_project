/*
 * thrift version 0.9.3
 */
namespace cpp mlmodelserver
namespace java mlmodelserver
namespace php mlmodelserver

struct returnType {
  1: double predicted,
  2: list<double> prob
}

exception InvalidInput {
  1: i32 whatOp,
  2: string errorMessage
}

service MLOlineService {
  list<i32> getLabel(1:i32 clientid, 2:string modelName),
  returnType modelPredict(1:i32 clientid, 2:string modelName, 3:string strFeature)
}
