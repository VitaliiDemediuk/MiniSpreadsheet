#ifndef DECFUNCTIONNODE_H
#define DECFUNCTIONNODE_H

#include <functionnode.h>
#include <QSharedPointer>

class DecFunctionNode : public FunctionNode{
public:
    explicit DecFunctionNode(QSharedPointer<Node> arg);
    CalculationResult Calculate() const override;
    void AddReference(int row, int column) const override;
    void RemoveReference(int row, int column) const override;
private:
    QSharedPointer<Node> arg_;
};

#endif // DECFUNCTIONNODE_H
