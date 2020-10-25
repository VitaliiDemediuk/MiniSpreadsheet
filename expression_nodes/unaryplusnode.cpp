#include "unaryplusnode.h"

UnaryPlusNode::UnaryPlusNode(QSharedPointer<Node> expr) :
                             UnaryOperatorNode(expr){}

cpp_int UnaryPlusNode::Calculate() const {
    return expr_->Calculate();
}
