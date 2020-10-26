#include "incfunctionnode.h"

IncFunctionNode::IncFunctionNode(QSharedPointer<Node> arg) : arg_(arg) {}

cpp_int IncFunctionNode::Calculate() const{
    return ++arg_->Calculate();
}

void IncFunctionNode::AddReference(size_t row, size_t column) const{
    arg_->AddReference(row, column);
}

void IncFunctionNode::RemoveReference(size_t row, size_t column) const{
    arg_->RemoveReference(row, column);
}
