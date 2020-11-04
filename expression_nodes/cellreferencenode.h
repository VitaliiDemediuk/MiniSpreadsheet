#ifndef CELLREFERENCENODE_H
#define CELLREFERENCENODE_H

#include "node.h"
#include <QString>

class CellReferenceNode : public Node{
public:
    explicit CellReferenceNode(const QString& cell_link);
    CalculationResult Calculate() const override;
    bool IsException() const override;
    QString GetMessage() const override;
    void AddReference(int row, int column) const override;
    void RemoveReference(int row, int column) const override;
private:
    int row_;
    int column_;
    int bin_pow(int base, int index) const;
};

#endif // CELLREFERENCENODE_H
