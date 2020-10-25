#include "unaryminusnode.h"

UnaryMinusNode::UnaryMinusNode(QSharedPointer<Node> expr) :
                             UnaryOperatorNode(expr){}

cpp_int UnaryMinusNode::Calculate() const {
    return expr_->Calculate();
}
