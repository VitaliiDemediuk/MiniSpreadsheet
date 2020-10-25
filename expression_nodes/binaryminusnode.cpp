#include "binaryminusnode.h"

BinaryMinusNode::BinaryMinusNode(QSharedPointer<Node> left_expr,
                               QSharedPointer<Node> right_expr):
                               BinaryOperatorNode(left_expr, right_expr) {}

cpp_int BinaryMinusNode::Calculate() const{
    return left_expr_->Calculate() - right_expr_->Calculate();
}
