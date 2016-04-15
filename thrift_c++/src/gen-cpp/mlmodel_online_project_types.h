/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef mlmodel_online_project_TYPES_H
#define mlmodel_online_project_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace mlmodelserver {

class returnType;

class InvalidInput;

typedef struct _returnType__isset {
  _returnType__isset() : predicted(false), prob(false) {}
  bool predicted :1;
  bool prob :1;
} _returnType__isset;

class returnType {
 public:

  returnType(const returnType&);
  returnType& operator=(const returnType&);
  returnType() : predicted(0) {
  }

  virtual ~returnType() throw();
  double predicted;
  std::vector<double>  prob;

  _returnType__isset __isset;

  void __set_predicted(const double val);

  void __set_prob(const std::vector<double> & val);

  bool operator == (const returnType & rhs) const
  {
    if (!(predicted == rhs.predicted))
      return false;
    if (!(prob == rhs.prob))
      return false;
    return true;
  }
  bool operator != (const returnType &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const returnType & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(returnType &a, returnType &b);

inline std::ostream& operator<<(std::ostream& out, const returnType& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _InvalidInput__isset {
  _InvalidInput__isset() : whatOp(false), errorMessage(false) {}
  bool whatOp :1;
  bool errorMessage :1;
} _InvalidInput__isset;

class InvalidInput : public ::apache::thrift::TException {
 public:

  InvalidInput(const InvalidInput&);
  InvalidInput& operator=(const InvalidInput&);
  InvalidInput() : whatOp(0), errorMessage() {
  }

  virtual ~InvalidInput() throw();
  int32_t whatOp;
  std::string errorMessage;

  _InvalidInput__isset __isset;

  void __set_whatOp(const int32_t val);

  void __set_errorMessage(const std::string& val);

  bool operator == (const InvalidInput & rhs) const
  {
    if (!(whatOp == rhs.whatOp))
      return false;
    if (!(errorMessage == rhs.errorMessage))
      return false;
    return true;
  }
  bool operator != (const InvalidInput &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const InvalidInput & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
  mutable std::string thriftTExceptionMessageHolder_;
  const char* what() const throw();
};

void swap(InvalidInput &a, InvalidInput &b);

inline std::ostream& operator<<(std::ostream& out, const InvalidInput& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
