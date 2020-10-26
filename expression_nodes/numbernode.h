#ifndef NUMBERNODE_H
#define NUMBERNODE_H

#include "node.h"
#include <QString>

class NumberNode : public Node{
public:
    explicit NumberNode(const QString&);
    cpp_int Calculate() const override;
    void RemoveReference(size_t row, size_t column) const override;
    void AddReference(size_t row, size_t column) const override;
private:
    cpp_int number_;
};

#endif // NUMBERNODE_H
