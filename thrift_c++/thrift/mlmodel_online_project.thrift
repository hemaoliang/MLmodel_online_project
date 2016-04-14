/*
 * thrift version 0.9.3
 */
namespace cpp modelpro
namespace java modelpro
namespace php modelpro

struct returnType {
  1: double predicted,
  2: list<double> prob
}

exception InvalidInput {
  1: i32 whatOp,
  2: string errorMessage
}

service MLOlineService {
  list<i32> getLabel(1:string modelName),
  returnType modelPredict(1:string strFeature)
}
