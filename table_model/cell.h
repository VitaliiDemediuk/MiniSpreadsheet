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
    Cell(bool is_corect_cell = true);
    QString GetText() const;
    QString GetVisibleText();
    CalculationResult GetValue();
    void ChangeText(const QString& text);
    void Recalculate(int row = -1, int column = -1);
    void AddReferringCell(int row, int column);
    void RemoveReferringCell(int row, int column);    
    bool IsCorectCell();
    bool IsEmptyCell();
    bool WasInThisCell();
    void GoInThisCell();
    void GoOutThisCell();    void AddReference(int row, int column);
    void RemoveReference(int row, int column);
private:
    bool is_corect_cell_ = true;
    int was_in_this_cell_ = 0;
    QString text_;
    QSharedPointer<Node> tree_;
    std::set<CellCoordinates> referring_cells_;
};

#endif // CELL_H
