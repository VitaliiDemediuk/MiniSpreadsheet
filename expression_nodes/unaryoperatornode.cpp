#include "unaryoperatornode.h"

UnaryOperatorNode::UnaryOperatorNode(QSharedPointer<Node> expr) : expr_(expr) {}
