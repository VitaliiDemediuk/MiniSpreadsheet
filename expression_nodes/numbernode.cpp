#include "numbernode.h"

NumberNode::NumberNode(const QString& number) :
                       number_(number.toStdString()) {}

cpp_int NumberNode::Calculate() const {
    return number_;
}
