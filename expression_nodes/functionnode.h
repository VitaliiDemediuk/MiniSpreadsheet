#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H

#include "node.h"

class FunctionNode : public Node{
public:
    virtual CalculationResult Calculate() const = 0;
    bool IsException() const override;
    QString GetMessage() const override;
};

#endif // FUNCTIONNODE_H
