#ifndef INCFUNCTIONNODE_H
#define INCFUNCTIONNODE_H

#include <functionnode.h>
#include <QSharedPointer>

class IncFunctionNode : public FunctionNode{
public:
    explicit IncFunctionNode(QSharedPointer<Node> arg);
    CalculationResult Calculate() const override;
    void AddReference(int row, int column) const override;
    void RemoveReference(int row, int column) const override;
private:
    QSharedPointer<Node> arg_;
};

#endif // INCFUNCTIONNODE_H
