#include "unaryoperatornode.h"

UnaryOperatorNode::UnaryOperatorNode(QSharedPointer<Node> expr) : expr_(expr) {}

bool UnaryOperatorNode::IsException() const{
    return false;
}

QString UnaryOperatorNode::GetMessage() const{
    return "OK";
}

void UnaryOperatorNode::AddReference(int row, int column) const{
    expr_->AddReference(row, column);
}

void UnaryOperatorNode::RemoveReference(int row, int column) const{
    expr_->RemoveReference(row, column);
}
