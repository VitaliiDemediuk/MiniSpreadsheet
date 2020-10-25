#include "incfunctionnode.h"

IncFunctionNode::IncFunctionNode(QSharedPointer<Node> arg) : arg_(arg) {}

cpp_int IncFunctionNode::Calculate() const{
    return ++arg_->Calculate();
}
