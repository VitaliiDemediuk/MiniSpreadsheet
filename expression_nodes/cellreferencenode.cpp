#include "cellreferencenode.h"

#include <cmath>
#include "tablesingleton.h"

CellReferenceNode::CellReferenceNode(const QString& cell_link): row_(0), column_(0){
    int pos = cell_link.size()-1;
    for(int i = 0; pos >= 0 and cell_link[pos].isDigit(); ++i, --pos){
        row_ += cell_link[pos].digitValue()*bin_pow(10, i);
    }
    int A_unicode = QChar('A').unicode();
    for(int i = 0; pos >= 0; ++i, --pos){
        column_ += (cell_link[pos].unicode()-A_unicode)*bin_pow(26, i);
    }
}

cpp_int CellReferenceNode::Calculate() const{
    TableSingleton table = TableSingleton::getInstance();
    return table.GetCell(row_, column_).GetValue();
}

void CellReferenceNode::AddReference(size_t row, size_t column) const{
    TableSingleton table = TableSingleton::getInstance();
    table.GetCell(row_, column_).AddReferringCell(row, column);
}

void CellReferenceNode::RemoveReference(size_t row, size_t column) const{
    TableSingleton table = TableSingleton::getInstance();
    table.GetCell(row_, column_).RemoveReferringCell(row, column);
}

size_t CellReferenceNode::bin_pow(const size_t& base, const size_t& index) const{
    if(index == 0){
        return 1;
    } else if(index == 1){
        return base;
    }else if(index % 2 == 0){
        return bin_pow(base, index/2);
    }else{
        return base*bin_pow(base, index-1);
    }
}
