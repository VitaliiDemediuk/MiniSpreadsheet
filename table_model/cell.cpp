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

QString Cell::GetVisibleText(){
    QString result;
    if(!text_.isEmpty()){
        this->GoInThisCell();
        CalculationResult calc_res = tree_->Calculate();
        this->GoOutThisCell();
        if(calc_res.IsCorrectCalculation()){
            this->GoInThisCell();
            result = QString(tree_->Calculate().GetNumber().str().c_str());
            this->GoOutThisCell();
        }else{
            result = "#####";
        }
    }
    return result;
}

CalculationResult Cell::GetValue(){
    this->GoInThisCell();
    auto result = (text_.isEmpty() ? CalculationResult(0) : tree_->Calculate());
    this->GoOutThisCell();
    return result;
}

void Cell::ChangeText(const QString& text){
    text_ = text;
    if(!text_.isEmpty()){
        tree_ = Parser::GetTree(text_);
    }else{
        tree_ = QSharedPointer<Node>(new NumberNode(0));
    }
    Recalculate();
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

void Cell::Recalculate(int row, int column){
    TableSingleton& table = TableSingleton::getInstance();
    if(row >= 0 and column >= 0){
        emit table.cell_recalculated(row, column);
    }
    for(auto& el : referring_cells_){
        auto& cell = table.GetCell(el.GetRow(), el.GetColumn());
        cell.Recalculate(el.GetRow(), el.GetColumn());
    }
}


void Cell::AddReference(int row, int column){
    tree_->AddReference(row, column);
}

void Cell::RemoveReference(int row, int column){
    tree_->RemoveReference(row, column);
}

bool Cell::WasInThisCell(){
    return !(was_in_this_cell_ == 0);
}

void Cell::GoInThisCell(){
    ++was_in_this_cell_;
}

void Cell::GoOutThisCell(){
    --was_in_this_cell_;
}
