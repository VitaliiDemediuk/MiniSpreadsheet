#ifndef NODE_H
#define NODE_H

#include "calculationresult.h"
class QString;

class Node{
public:
    virtual CalculationResult Calculate() const = 0;
    virtual bool IsException() const = 0;
    virtual QString GetMessage() const = 0;
    virtual void AddReference(int row, int column) const = 0;
    virtual void RemoveReference(int row, int column) const = 0;
};

#endif // NODE_H
