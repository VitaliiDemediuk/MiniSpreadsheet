#ifndef UNARYMINUSNODE_H
#define UNARYMINUSNODE_H

#include "unaryoperatornode.h"

class UnaryMinusNode : public UnaryOperatorNode{
public:
    explicit UnaryMinusNode(QSharedPointer<Node> expr);
    cpp_int Calculate() const override;
};

#endif // UNARYMINUSNODE_H
