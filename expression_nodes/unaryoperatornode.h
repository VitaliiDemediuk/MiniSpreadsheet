#ifndef UNARYOPERATORNODE_H
#define UNARYOPERATORNODE_H

#include "node.h"
#include <QSharedPointer>

class UnaryOperatorNode : public Node{
public:
    explicit UnaryOperatorNode(QSharedPointer<Node> expr);
    virtual cpp_int Calculate() const = 0;
protected:
    QSharedPointer<Node> expr_;
};

#endif // UNARYOPERATORNODE_H
