#ifndef BINARYOPERATORNODE_H
#define BINARYOPERATORNODE_H

#include "node.h"
#include <QSharedPointer>

class BinaryOperatorNode : public Node{
public:
    explicit BinaryOperatorNode(QSharedPointer<Node> left_expr,
                       QSharedPointer<Node> right_expr);
    virtual cpp_int Calculate() const = 0;
protected:
    QSharedPointer<Node> left_expr_;
    QSharedPointer<Node> right_expr_;

};

#endif // BINARYOPERATORNODE_H
