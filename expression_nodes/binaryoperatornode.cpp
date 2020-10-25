#include "binaryoperatornode.h"

BinaryOperatorNode::BinaryOperatorNode(QSharedPointer<Node> left_expr,
                                       QSharedPointer<Node> right_expr) :
                                        left_expr_(left_expr),
                                        right_expr_(right_expr) {}
