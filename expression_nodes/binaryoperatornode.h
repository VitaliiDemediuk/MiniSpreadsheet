#ifndef BINARYOPERATORNODE_H
#define BINARYOPERATORNODE_H

#include "node.h"
#include <QSharedPointer>

class BinaryOperatorNode : public Node{
public:
    explicit BinaryOperatorNode(QSharedPointer<Node> left_expr,
                       QSharedPointer<Node> right_expr);
    virtual cpp_int Calculate() const override = 0;
    void AddReference(size_t row, size_t column) const override;
    void RemoveReference(size_t row, size_t column) const override;
protected:
    QSharedPointer<Node> left_expr_;
    QSharedPointer<Node> right_expr_;

};

#endif // BINARYOPERATORNODE_H
