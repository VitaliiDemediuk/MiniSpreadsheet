#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H

#include "node.h"

class FunctionNode : public Node{
public:
    virtual cpp_int Calculate() const = 0;
};

#endif // FUNCTIONNODE_H
