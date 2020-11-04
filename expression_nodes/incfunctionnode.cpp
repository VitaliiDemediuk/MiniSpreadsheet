#include "incfunctionnode.h"

IncFunctionNode::IncFunctionNode(QSharedPointer<Node> arg) : arg_(arg) {}

CalculationResult IncFunctionNode::Calculate() const{
    return ++arg_->Calculate();
}

void IncFunctionNode::AddReference(int row, int column) const{
    arg_->AddReference(row, column);
}

void IncFunctionNode::RemoveReference(int row, int column) const{
    arg_->RemoveReference(row, column);
}
