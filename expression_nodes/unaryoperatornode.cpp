#include "unaryoperatornode.h"

UnaryOperatorNode::UnaryOperatorNode(QSharedPointer<Node> expr) : expr_(expr) {}

void UnaryOperatorNode::AddReference(size_t row, size_t column) const{
    expr_->AddReference(row, column);
}

void UnaryOperatorNode::RemoveReference(size_t row, size_t column) const{
    expr_->RemoveReference(row, column);
}
