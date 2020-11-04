#include "tablesingleton.h"

#include <QDebug>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDataStream>
#include <QFile>

TableSingleton::TableSingleton(){}

TableSingleton& TableSingleton::getInstance(){
    static TableSingleton instance;
    return instance;
}

void TableSingleton::AddRow(){
    table_.append(QVector<Cell>(column_count_));
    ++row_count_;
}

void TableSingleton::AddColumn(){
    for(int i = 0; i < row_count_; ++i){
        table_[i].append(Cell());
    }
    ++column_count_;
}

void TableSingleton::RemoveRow(){
    if(row_count_ > 0){
        table_.pop_back();
        --row_count_;
    }
}

void TableSingleton::RemoveColumn(){
    if(column_count_ > 0){
        for(int i = 0; i < row_count_; ++i){
            table_[i].pop_back();
        }
        --column_count_;
    }
}

int TableSingleton::GetRowCount(){
    return row_count_;
}

int TableSingleton::GetColumnCount(){
    return column_count_;
}

Cell& TableSingleton::GetCell(int row, int column){
    static Cell incorect_cell(false);
    if(row < row_count_ and column < column_count_){
        return table_[row][column];
    }else{
        return incorect_cell;
    }
}

void TableSingleton::SaveTable(const QString& file_path){
    QString file_put_contents;
    QXmlStreamWriter qxml_stream_wr(&file_put_contents);
    qxml_stream_wr.writeStartDocument("1.0", true);
    qxml_stream_wr.writeStartElement("table");
    qxml_stream_wr.writeStartElement("propertise");
    qxml_stream_wr.writeStartElement("row_count");
    qxml_stream_wr.writeCharacters(std::to_string(row_count_).c_str());
    qxml_stream_wr.writeEndElement();
    qxml_stream_wr.writeStartElement("column_count");
    qxml_stream_wr.writeCharacters(std::to_string(column_count_).c_str());
    qxml_stream_wr.writeEndElement();
    qxml_stream_wr.writeEndElement();
    qxml_stream_wr.writeStartElement("cells");
    for(int row = 0; row < row_count_; ++row){
        for(int column = 0; column < column_count_; ++column){
            QString text = this->GetCell(row, column).GetText();
            if(text != ""){
                qxml_stream_wr.writeStartElement("cell");
                qxml_stream_wr.writeStartElement("row");
                qxml_stream_wr.writeCharacters(std::to_string(row).c_str());
                qxml_stream_wr.writeEndElement();
                qxml_stream_wr.writeStartElement("column");
                qxml_stream_wr.writeCharacters(std::to_string(column).c_str());
                qxml_stream_wr.writeEndElement();
                qxml_stream_wr.writeStartElement("text");
                qxml_stream_wr.writeCharacters(text);
                qxml_stream_wr.writeEndElement();
                qxml_stream_wr.writeEndElement();
            }
        }
    }
    qxml_stream_wr.writeEndElement();
    qxml_stream_wr.writeEndDocument();
    QFile File(file_path);
    File.open(QFile::WriteOnly);
    QTextStream qds(&File);
    qDebug() << file_put_contents;
    qds << file_put_contents;
}

void TableSingleton::NewTable(int row_count, int column_count){
    this->ClearTable();
    table_.resize(row_count);
    for(auto& row : table_){
        row.resize(column_count);
    }
    row_count_ = row_count;
    column_count_ = column_count;
}

void TableSingleton::ClearTable(){
    table_.clear();
    row_count_ = 0;
    column_count_ = 0;
}

bool TableSingleton::IsLastRowEmpty(){
    bool result = true;
    for(auto& el : table_.back()){
        if(!el.IsEmptyCell()){
            result = false;
             break;
        }
    }
    return result;
}

bool TableSingleton::IsLastColumnEmpty(){
    bool result = true;
    for(auto& el : table_){
        if(!el.back().IsEmptyCell()){
            result = false;
            break;
        }
    }
    return result;
}
