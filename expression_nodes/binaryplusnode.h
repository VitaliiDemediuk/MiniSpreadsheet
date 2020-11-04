#ifndef BINARYPLUSNODE_H
#define BINARYPLUSNODE_H

#include "node.h"
#include "binaryoperatornode.h"
#include <QSharedDataPointer>

class BinaryPlusNode : public BinaryOperatorNode{
public:
    explicit BinaryPlusNode(QSharedPointer<Node> left_expr,
                            QSharedPointer<Node> right_expr);
    CalculationResult Calculate() const override;
};

#endif // BINARYPLUSNODE_H
