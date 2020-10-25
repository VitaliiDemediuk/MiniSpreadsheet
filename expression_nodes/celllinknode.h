#ifndef CELLLINKNODE_H
#define CELLLINKNODE_H

#include "node.h"
#include <QString>

class CellLinkNode : public Node{
public:
    explicit CellLinkNode(const QString& cell_link);
    cpp_int Calculate() const override;
private:
    cpp_int row_;
    cpp_int column_;
    cpp_int bin_pow(const cpp_int& base, const cpp_int& index) const;
};

#endif // CELLLINKNODE_H
