/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "caffe_server_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace caffeserver {


returnType::~returnType() throw() {
}


void returnType::__set_predicted(const std::string& val) {
  this->predicted = val;
}

void returnType::__set_prob(const double val) {
  this->prob = val;
}

uint32_t returnType::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->predicted);
          this->__isset.predicted = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->prob);
          this->__isset.prob = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t returnType::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("returnType");

  xfer += oprot->writeFieldBegin("predicted", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->predicted);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("prob", ::apache::thrift::protocol::T_DOUBLE, 2);
  xfer += oprot->writeDouble(this->prob);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(returnType &a, returnType &b) {
  using ::std::swap;
  swap(a.predicted, b.predicted);
  swap(a.prob, b.prob);
  swap(a.__isset, b.__isset);
}

returnType::returnType(const returnType& other0) {
  predicted = other0.predicted;
  prob = other0.prob;
  __isset = other0.__isset;
}
returnType& returnType::operator=(const returnType& other1) {
  predicted = other1.predicted;
  prob = other1.prob;
  __isset = other1.__isset;
  return *this;
}
void returnType::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "returnType(";
  out << "predicted=" << to_string(predicted);
  out << ", " << "prob=" << to_string(prob);
  out << ")";
}


InvalidInput::~InvalidInput() throw() {
}


void InvalidInput::__set_whatOp(const int32_t val) {
  this->whatOp = val;
}

void InvalidInput::__set_errorMessage(const std::string& val) {
  this->errorMessage = val;
}

uint32_t InvalidInput::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->whatOp);
          this->__isset.whatOp = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->errorMessage);
          this->__isset.errorMessage = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t InvalidInput::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("InvalidInput");

  xfer += oprot->writeFieldBegin("whatOp", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->whatOp);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("errorMessage", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->errorMessage);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(InvalidInput &a, InvalidInput &b) {
  using ::std::swap;
  swap(a.whatOp, b.whatOp);
  swap(a.errorMessage, b.errorMessage);
  swap(a.__isset, b.__isset);
}

InvalidInput::InvalidInput(const InvalidInput& other2) : TException() {
  whatOp = other2.whatOp;
  errorMessage = other2.errorMessage;
  __isset = other2.__isset;
}
InvalidInput& InvalidInput::operator=(const InvalidInput& other3) {
  whatOp = other3.whatOp;
  errorMessage = other3.errorMessage;
  __isset = other3.__isset;
  return *this;
}
void InvalidInput::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "InvalidInput(";
  out << "whatOp=" << to_string(whatOp);
  out << ", " << "errorMessage=" << to_string(errorMessage);
  out << ")";
}

const char* InvalidInput::what() const throw() {
  try {
    std::stringstream ss;
    ss << "TException - service has thrown: " << *this;
    this->thriftTExceptionMessageHolder_ = ss.str();
    return this->thriftTExceptionMessageHolder_.c_str();
  } catch (const std::exception&) {
    return "TException - service has thrown: InvalidInput";
  }
}

} // namespace
