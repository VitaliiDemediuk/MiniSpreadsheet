#include <functionnode.h>

#include <QString>

bool FunctionNode::IsException() const{
    return false;
}

QString FunctionNode::GetMessage() const{
    return "OK";
}
