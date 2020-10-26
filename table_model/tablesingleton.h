#ifndef TABLESINGLETON_H
#define TABLESINGLETON_H

#include "cell.h"
#include <QVector>

class TableSingleton{
public:
    static TableSingleton& getInstance();
    void AddRow();
    void AddColumn();
    void RemoveRow();
    void RemoveColumn();
    size_t GetRowCount();
    size_t GetColumnCount();
    Cell& GetCell(size_t row, size_t column);
//    void SaveTable();
//    void OpenTable();
private:
    TableSingleton();
//    TableSingleton( const TableSingleton&);
//    TableSingleton& operator=( TableSingleton& );

    QVector<QVector<Cell>> table_;
    size_t row_count_;
    size_t column_count_;
};

#endif // TABLESINGLETON_H
