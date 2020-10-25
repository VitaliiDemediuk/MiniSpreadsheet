#ifndef BINARYMULTIPLYNODE_H
#define BINARYMULTIPLYNODE_H

#include "node.h"
#include "binaryoperatornode.h"
#include <QSharedDataPointer>

class BinaryMultiplyNode : public BinaryOperatorNode{
public:
    explicit BinaryMultiplyNode(QSharedPointer<Node> left_expr,
                                QSharedPointer<Node> right_expr);
    cpp_int Calculate() const override;
};

#endif // BINARYMULTIPLYNODE_H
