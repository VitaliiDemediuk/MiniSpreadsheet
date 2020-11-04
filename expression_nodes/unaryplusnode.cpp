#include "unaryplusnode.h"

UnaryPlusNode::UnaryPlusNode(QSharedPointer<Node> expr) :
                             UnaryOperatorNode(expr){}

CalculationResult UnaryPlusNode::Calculate() const {
    return expr_->Calculate();
}
