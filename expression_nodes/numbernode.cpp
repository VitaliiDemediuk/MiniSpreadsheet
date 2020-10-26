#include "numbernode.h"

NumberNode::NumberNode(const QString& number) :
                       number_(number.toStdString()) {}

cpp_int NumberNode::Calculate() const {
    return number_;
}

void NumberNode::RemoveReference(size_t row, size_t column) const{
    return;
}

void NumberNode::AddReference(size_t row, size_t column) const{
    return;
}
