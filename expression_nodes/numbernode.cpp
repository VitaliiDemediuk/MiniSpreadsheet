#include "numbernode.h"

using boost::multiprecision::cpp_int;

NumberNode::NumberNode(const QString& number) :
                       number_(number.toStdString()) {}

CalculationResult NumberNode::Calculate() const {
    return CalculationResult(number_);
}

bool NumberNode::IsException() const{
    return false;
}

QString NumberNode::GetMessage() const{
    return "OK";
}

void NumberNode::RemoveReference(int row, int column) const{
    return;
}

void NumberNode::AddReference(int row, int column) const{
    return;
}
