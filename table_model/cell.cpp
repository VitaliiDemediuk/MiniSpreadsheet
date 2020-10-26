#include "cell.h"

#include <tuple>
#include "numbernode.h"
#include "parser.h"

//CellCoordinates
Cell::CellCoordinates::CellCoordinates(int row, int column) :
                                       row_(row), column_(column) {}

size_t Cell::CellCoordinates::GetRow() const{
    return row_;
}

size_t Cell::CellCoordinates::GetColumn() const{
    return column_;
}

bool Cell::CellCoordinates::operator<(const CellCoordinates& right_cell){
    return std::tie(this->row_, this->column_) <
           std::tie(right_cell.row_, right_cell.column_);
}

//Cell

Cell::Cell() : tree_(QSharedPointer<Node>(new NumberNode("0"))){}

QString Cell::GetText() const{
    return text_;
}

QString Cell::GetVisibleText() const{
    return (text_.isEmpty() ? text_ : QString(tree_->Calculate().str().c_str()));
}

cpp_int Cell::GetValue() const{
    return (text_.isEmpty() ? 0 : tree_->Calculate());
}

void Cell::ChangeText(const QString& text){
    text_ = text;
    tree_ = Parser::GetTree(text);
}

void Cell::AddReferringCell(int row, int column){
    referring_cells_.insert(CellCoordinates(row, column));
}

void Cell::RemoveReferringCell(int row, int column){
    referring_cells_.erase(CellCoordinates(row, column));
}

bool operator<(const Cell::CellCoordinates& left_cell, const Cell::CellCoordinates& right_cell){
    return std::tie(left_cell.row_, left_cell.column_) <
           std::tie(right_cell.row_, right_cell.column_);
}

