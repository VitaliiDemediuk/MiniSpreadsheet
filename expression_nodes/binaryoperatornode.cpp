#include "binaryoperatornode.h"

BinaryOperatorNode::BinaryOperatorNode(QSharedPointer<Node> left_expr,
                                       QSharedPointer<Node> right_expr) :
                                        left_expr_(left_expr),
                                        right_expr_(right_expr) {}

bool BinaryOperatorNode::IsException() const{
    return false;
}

QString BinaryOperatorNode::GetMessage() const{
    return "OK";
}

void BinaryOperatorNode::AddReference(int row, int column) const{
    left_expr_->AddReference(row, column);
    right_expr_->AddReference(row, column);
}

void BinaryOperatorNode::RemoveReference(int row, int column) const{
    left_expr_->RemoveReference(row, column);
    right_expr_->RemoveReference(row, column);
}
