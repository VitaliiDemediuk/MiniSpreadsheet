#include "unaryminusnode.h"

UnaryMinusNode::UnaryMinusNode(QSharedPointer<Node> expr) :
                             UnaryOperatorNode(expr){}

CalculationResult UnaryMinusNode::Calculate() const {
    return -expr_->Calculate();
}
