#include "decfunctionnode.h"

DecFunctionNode::DecFunctionNode(QSharedPointer<Node> arg) : arg_(arg) {}

CalculationResult DecFunctionNode::Calculate() const{
    return --arg_->Calculate();
}

void DecFunctionNode::AddReference(int row, int column) const{
    arg_->AddReference(row, column);
}

void DecFunctionNode::RemoveReference(int row, int column) const{
    arg_->RemoveReference(row, column);
}
