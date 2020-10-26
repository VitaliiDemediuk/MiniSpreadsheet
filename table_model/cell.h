#ifndef CELL_H
#define CELL_H

#include <QSharedPointer>
#include <set>
#include "node.h"

class Cell{
public:
    class CellCoordinates{
    public:
        explicit CellCoordinates(int row, int column);
        size_t GetRow() const;
        size_t GetColumn() const;
        bool operator<(const CellCoordinates& right_cell);
        friend bool operator<(const Cell::CellCoordinates& left_cell, const Cell::CellCoordinates& right_cell);
    private:
        size_t row_;
        size_t column_;
    };

public:
    Cell();
    QString GetText() const;
    QString GetVisibleText() const;
    cpp_int GetValue() const;
    void ChangeText(const QString& text);
    void Recalculate();
    void AddReferringCell(int row, int column);
    void RemoveReferringCell(int row, int column);    

private:
    QString text_;
    QSharedPointer<Node> tree_;
    std::set<CellCoordinates> referring_cells_;
};

#endif // CELL_H
