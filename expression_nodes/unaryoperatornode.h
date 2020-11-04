#ifndef UNARYOPERATORNODE_H
#define UNARYOPERATORNODE_H

#include "node.h"
#include <QSharedPointer>

class UnaryOperatorNode : public Node{
public:
    explicit UnaryOperatorNode(QSharedPointer<Node> expr);
    virtual CalculationResult Calculate() const override = 0;
    bool IsException() const override;
    QString GetMessage() const override;
    void AddReference(int row, int column) const override;
    void RemoveReference(int row, int column) const override;
protected:
    QSharedPointer<Node> expr_;
};

#endif // UNARYOPERATORNODE_H
