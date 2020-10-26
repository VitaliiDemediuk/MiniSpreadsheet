#ifndef INCFUNCTIONNODE_H
#define INCFUNCTIONNODE_H

#include <functionnode.h>
#include <QSharedPointer>

class IncFunctionNode : public FunctionNode{
public:
    explicit IncFunctionNode(QSharedPointer<Node> arg);
    cpp_int Calculate() const override;
    void AddReference(size_t row, size_t column) const override;
    void RemoveReference(size_t row, size_t column) const override;
private:
    QSharedPointer<Node> arg_;
};

#endif // INCFUNCTIONNODE_H
