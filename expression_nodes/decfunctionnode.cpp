#include "decfunctionnode.h"

DecFunctionNode::DecFunctionNode(QSharedPointer<Node> arg) : arg_(arg) {}

cpp_int DecFunctionNode::Calculate() const{
    return --arg_->Calculate();
}

void DecFunctionNode::AddReference(size_t row, size_t column) const{
    arg_->AddReference(row, column);
}

void DecFunctionNode::RemoveReference(size_t row, size_t column) const{
    arg_->RemoveReference(row, column);
}
