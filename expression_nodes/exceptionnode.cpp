#include "exceptionnode.h"

#include <QString>
#include <utility>

ExceptionNode::ExceptionNode(QString message) : message_(message){}

CalculationResult ExceptionNode::Calculate() const {
    return CalculationResult(0, false, message_);
}

bool ExceptionNode::IsException() const{
    return true;
}

QString ExceptionNode::GetMessage() const{
    return message_;
}

void ExceptionNode::RemoveReference(int row, int column) const{
    return;
}

void ExceptionNode::AddReference(int row, int column) const{
    return;
}
