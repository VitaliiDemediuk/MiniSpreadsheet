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
    int GetRowCount();
    int GetColumnCount();
    Cell& GetCell(int row, int column);
    void SaveTable(const QString& file_path);
    void NewTable(int row_count = 0, int column_count = 0);
    void ClearTable();
    TableSingleton(const TableSingleton&) = delete;
    void operator=(TableSingleton const& ) = delete;
private:
    TableSingleton();

    QVector<QVector<Cell>> table_;
    int row_count_ = 0;
    int column_count_ = 0;
};

#endif // TABLESINGLETON_H
