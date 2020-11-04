#ifndef UNARYPLUSNODE_H
#define UNARYPLUSNODE_H

#include "unaryoperatornode.h"

class UnaryPlusNode : public UnaryOperatorNode{
public:
    explicit UnaryPlusNode(QSharedPointer<Node> expr);
    CalculationResult Calculate() const override;
};

#endif // UNARYPLUSNODE_H
