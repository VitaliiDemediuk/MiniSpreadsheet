#include "tablesingleton.h"

TableSingleton::TableSingleton() : row_count_(0), column_count_(0) {}

TableSingleton& TableSingleton::getInstance(){
    static TableSingleton  instance;
    return instance;
}

void TableSingleton::AddRow(){
    table_.append(QVector<Cell>(column_count_));
    ++row_count_;
}

void TableSingleton::AddColumn(){
    for(size_t i = 0; i < row_count_; ++i){
        table_[i].append(Cell());
    }
    ++column_count_;
}

void TableSingleton::RemoveRow(){
    if(column_count_ > 0){
        for(size_t i = 0; i < row_count_; ++i){
            table_[i].pop_back();
        }
        --column_count_;
    }else{
        throw std::length_error("Column count == 0");
    }
}

void TableSingleton::RemoveColumn(){
    if(row_count_ > 0){
        table_.pop_back();
        --row_count_;
    }else{
        throw std::length_error("Row count == 0");
    }
}

size_t TableSingleton::GetRowCount(){
    return row_count_;
}

size_t TableSingleton::GetColumnCount(){
    return column_count_;
}

Cell& TableSingleton::GetCell(size_t row, size_t column){
    if(row < row_count_ and column < column_count_){
        return table_[row][column];
    }else{
        throw std::out_of_range("Out of range of table!");
    }
}
