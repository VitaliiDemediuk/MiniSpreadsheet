#ifndef CELLLINKNODE_H
#define CELLLINKNODE_H

#include "node.h"
#include <QString>

class CellReferenceNode : public Node{
public:
    explicit CellReferenceNode(const QString& cell_link);
    cpp_int Calculate() const override;
    void AddReference(size_t row, size_t column) const override;
    void RemoveReference(size_t row, size_t column) const override;
private:
    size_t row_;
    size_t column_;
    size_t bin_pow(const size_t& base, const size_t& index) const;
};

#endif // CELLLINKNODE_H
