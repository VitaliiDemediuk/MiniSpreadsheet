#ifndef BINARYOPERATORNODE_H
#define BINARYOPERATORNODE_H

#include "node.h"
#include <QSharedPointer>

class BinaryOperatorNode : public Node{
public:
    explicit BinaryOperatorNode(QSharedPointer<Node> left_expr,
                       QSharedPointer<Node> right_expr);
    virtual CalculationResult Calculate() const override = 0;
    bool IsException() const override;
    QString GetMessage() const override;
    void AddReference(int row, int column) const override;
    void RemoveReference(int row, int column) const override;
protected:
    QSharedPointer<Node> left_expr_;
    QSharedPointer<Node> right_expr_;

};

#endif // BINARYOPERATORNODE_H
