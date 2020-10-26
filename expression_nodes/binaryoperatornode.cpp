#include "binaryoperatornode.h"

BinaryOperatorNode::BinaryOperatorNode(QSharedPointer<Node> left_expr,
                                       QSharedPointer<Node> right_expr) :
                                        left_expr_(left_expr),
                                        right_expr_(right_expr) {}

void BinaryOperatorNode::AddReference(size_t row, size_t column) const{
    left_expr_->AddReference(row, column);
    right_expr_->AddReference(row, column);
}

void BinaryOperatorNode::RemoveReference(size_t row, size_t column) const{
    left_expr_->RemoveReference(row, column);
    right_expr_->RemoveReference(row, column);
}
