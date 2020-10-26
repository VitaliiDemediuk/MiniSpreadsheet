#ifndef UNARYOPERATORNODE_H
#define UNARYOPERATORNODE_H

#include "node.h"
#include <QSharedPointer>

class UnaryOperatorNode : public Node{
public:
    explicit UnaryOperatorNode(QSharedPointer<Node> expr);
    virtual cpp_int Calculate() const override = 0;
    void AddReference(size_t row, size_t column) const override;
    void RemoveReference(size_t row, size_t column) const override;
protected:
    QSharedPointer<Node> expr_;
};

#endif // UNARYOPERATORNODE_H
