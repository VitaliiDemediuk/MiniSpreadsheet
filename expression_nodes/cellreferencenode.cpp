#include "cellreferencenode.h"

#include <cmath>
#include "tablesingleton.h"
#include <QDebug>

CellReferenceNode::CellReferenceNode(const QString& cell_link): row_(0), column_(0){
    int pos = cell_link.size()-1;
    for(int i = 0; pos >= 0 and cell_link[pos].isDigit(); ++i, --pos){
        row_ += cell_link[pos].digitValue()*bin_pow(10, i);
    }
    int A_unicode = QChar('A').unicode();
    for(int i = 0; pos >= 0; ++i, --pos){
        column_ += (cell_link[pos].unicode()-A_unicode)*bin_pow(26, i);
    }
    --row_;

    qDebug() << row_ << ' ' << column_ << "\n";
}

bool CellReferenceNode::IsException() const{
    return false;
}

QString CellReferenceNode::GetMessage() const{
    return "OK";
}

CalculationResult CellReferenceNode::Calculate() const{
    TableSingleton& table = TableSingleton::getInstance();
    auto& cell = table.GetCell(row_, column_);
    if(!cell.WasInThisCell()){
        if(cell.IsCorectCell()){

            CalculationResult calc_res = cell.GetValue();
            if(calc_res.GetMessage() == "Loop!" or calc_res.IsCorrectCalculation()){
                return calc_res;
            }else{
                return CalculationResult(0, false, "");
            }
        }else{
            return CalculationResult(0, false, "Out of range of table!");
        }
    }else{
        return CalculationResult(0, false, "Loop!");
    }
}

void CellReferenceNode::AddReference(int row, int column) const{
    TableSingleton& table = TableSingleton::getInstance();
    table.GetCell(row_, column_).AddReferringCell(row, column);
}

void CellReferenceNode::RemoveReference(int row, int column) const{
    TableSingleton& table = TableSingleton::getInstance();
    table.GetCell(row_, column_).RemoveReferringCell(row, column);
}

int CellReferenceNode::bin_pow(int base, int index) const{
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
