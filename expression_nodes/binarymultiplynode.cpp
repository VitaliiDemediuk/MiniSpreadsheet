#include "binarymultiplynode.h"

BinaryMultiplyNode::BinaryMultiplyNode(QSharedPointer<Node> left_expr,
                                       QSharedPointer<Node> right_expr):
                                       BinaryOperatorNode(left_expr, right_expr) {}

CalculationResult BinaryMultiplyNode::Calculate() const {
    return left_expr_->Calculate() * right_expr_->Calculate();
}
