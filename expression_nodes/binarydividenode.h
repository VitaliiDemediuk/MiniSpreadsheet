#ifndef BINARYDIVIDENODE_H
#define BINARYDIVIDENODE_H

#include "node.h"
#include "binaryoperatornode.h"
#include <QSharedDataPointer>

class BinaryDivideNode : public BinaryOperatorNode{
public:
    explicit BinaryDivideNode(QSharedPointer<Node> left_expr,
                              QSharedPointer<Node> right_expr);
    cpp_int Calculate() const override;
};

#endif // BINARYDIVIDENODE_H
