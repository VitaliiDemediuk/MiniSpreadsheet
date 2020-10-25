#include "celllinknode.h"

#include <cmath>

CellLinkNode::CellLinkNode(const QString& cell_link): row_(0), column_(0){
    int pos = cell_link.size()-1;
    for(int i = 0; pos >= 0 and cell_link[pos].isDigit(); ++i, --pos){
        row_ += cell_link[pos].digitValue()*bin_pow(10, i);
    }
    int A_unicode = QChar('A').unicode();
    for(int i = 0; pos >= 0; ++i, --pos){
        column_ += (cell_link[pos].unicode()-A_unicode)*bin_pow(26, i);
    }
}

cpp_int CellLinkNode::Calculate() const{
    return 0;
}

cpp_int CellLinkNode::bin_pow(const cpp_int& base, const cpp_int& index) const{
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
