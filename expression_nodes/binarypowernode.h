#ifndef BINARYPOWERNODE_H
#define BINARYPOWERNODE_H

#include "node.h"
#include "binaryoperatornode.h"
#include <QSharedDataPointer>

class BinaryPowerNode : public BinaryOperatorNode{
public:
    explicit BinaryPowerNode(QSharedPointer<Node> left_expr,
                             QSharedPointer<Node> right_expr);
    CalculationResult Calculate() const override;
public:
    CalculationResult bin_pow(const CalculationResult& base, const CalculationResult& index) const;
    CalculationResult sqrt(const CalculationResult& base) const;
};

#endif // BINARYPOWERNODE_H
