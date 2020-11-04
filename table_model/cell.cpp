#include "cell.h"

#include <tuple>
#include "numbernode.h"
#include "parser.h"
#include <QDebug>
#include "tablesingleton.h"

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

Cell::Cell(bool is_corect_cell) : is_corect_cell_(is_corect_cell),
                tree_(QSharedPointer<Node>(new NumberNode(is_corect_cell ? "0" : "99999999"))){}

QString Cell::GetText() const{
    return text_;
}

QString Cell::GetVisibleText() const{
    QString result;
    if(!text_.isEmpty()){
        CalculationResult calc_res = tree_->Calculate();
        if(calc_res.IsCorrectCalculation()){
            result = QString(tree_->Calculate().GetNumber().str().c_str());
        }else{
            result = "#####";
        }
    }
    return result;
}

CalculationResult Cell::GetValue() const{
    return (text_.isEmpty() ? CalculationResult(0) : tree_->Calculate());
}

void Cell::ChangeText(const QString& text){
    text_ = text;
    if(!text_.isEmpty()){
        tree_ = Parser::GetTree(text_);
    }else{
        tree_ = QSharedPointer<Node>(new NumberNode(0));
    }
    qDebug() << text_ << '\n';
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

bool Cell::IsCorectCell(){
    return is_corect_cell_;
}

bool Cell::IsEmptyCell(){
    return text_.isEmpty();
}

void Cell::Recalculate(){
    TableSingleton& table = TableSingleton::getInstance();
    for(auto& el : referring_cells_){
        table.GetCell(el.GetRow(), el.GetColumn()).Recalculate();
    }
}
