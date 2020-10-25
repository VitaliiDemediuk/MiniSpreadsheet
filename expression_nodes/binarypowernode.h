#ifndef BINARYPOWERNODE_H
#define BINARYPOWERNODE_H

#include "node.h"
#include "binaryoperatornode.h"
#include <QSharedDataPointer>

class BinaryPowerNode : public BinaryOperatorNode{
public:
    explicit BinaryPowerNode(QSharedPointer<Node> left_expr,
                             QSharedPointer<Node> right_expr);
    cpp_int Calculate() const override;
public:
    cpp_int bin_pow(const cpp_int& base, const cpp_int& index) const;
    cpp_int sqrt(const cpp_int& base) const;
};

#endif // BINARYPOWERNODE_H
