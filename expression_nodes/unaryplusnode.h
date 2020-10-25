#ifndef UNARYPLUSNODE_H
#define UNARYPLUSNODE_H

#include "unaryoperatornode.h"

class UnaryPlusNode : public UnaryOperatorNode{
public:
    explicit UnaryPlusNode(QSharedPointer<Node> expr);
    cpp_int Calculate() const override;
};

#endif // UNARYPLUSNODE_H
