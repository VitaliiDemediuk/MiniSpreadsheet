#ifndef DECFUNCTIONNODE_H
#define DECFUNCTIONNODE_H

#include <functionnode.h>
#include <QSharedPointer>

class DecFunctionNode : public FunctionNode{
public:
    explicit DecFunctionNode(QSharedPointer<Node> arg);
    cpp_int Calculate() const override;
private:
    QSharedPointer<Node> arg_;
};

#endif // DECFUNCTIONNODE_H
