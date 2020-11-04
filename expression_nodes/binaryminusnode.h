#ifndef BINARYMINUSNODE_H
#define BINARYMINUSNODE_H

#include "node.h"
#include "binaryoperatornode.h"
#include <QSharedDataPointer>

class BinaryMinusNode : public BinaryOperatorNode{
public:
    explicit BinaryMinusNode(QSharedPointer<Node> left_expr,
                            QSharedPointer<Node> right_expr);
    CalculationResult Calculate() const override;
};

#endif // BINARYMINUSNODE_H
