#include "decfunctionnode.h"

DecFunctionNode::DecFunctionNode(QSharedPointer<Node> arg) : arg_(arg) {}

cpp_int DecFunctionNode::Calculate() const{
    return --arg_->Calculate();
}
