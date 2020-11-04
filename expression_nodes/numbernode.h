#ifndef NUMBERNODE_H
#define NUMBERNODE_H

#include "node.h"
#include <QString>

#include <boost/multiprecision/cpp_int.hpp>

class NumberNode : public Node{
public:
    explicit NumberNode(const QString&);
    CalculationResult Calculate() const override;
    bool IsException() const override;
    QString GetMessage() const override;
    void RemoveReference(int row, int column) const override;
    void AddReference(int row, int column) const override;
private:
    boost::multiprecision::cpp_int number_;
};

#endif // NUMBERNODE_H
