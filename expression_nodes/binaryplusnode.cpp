#include "binaryplusnode.h"

BinaryPlusNode::BinaryPlusNode(QSharedPointer<Node> left_expr,
                               QSharedPointer<Node> right_expr):
                               BinaryOperatorNode(left_expr, right_expr) {}

CalculationResult BinaryPlusNode::Calculate() const{
    return left_expr_->Calculate() + right_expr_->Calculate();
}
