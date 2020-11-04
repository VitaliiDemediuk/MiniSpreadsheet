#ifndef EXCEPTIONNODE_H
#define EXCEPTIONNODE_H

#include "node.h"
#include "QString"

class ExceptionNode : public Node{
public:
    explicit ExceptionNode(QString message);
    CalculationResult Calculate() const override;
    bool IsException() const override;
    QString GetMessage() const override;
    void RemoveReference(int row, int column) const override;
    void AddReference(int row, int column) const override;
private:
    QString message_;
};

#endif // EXCEPTIONNODE_H
