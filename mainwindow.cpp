#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>
#include "tablesingleton.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>
#include <QFileDialog>
#include <QXmlStreamReader>
#include <QMessageBox>

//ADD LIKE STATIC METHOD TO TABLE MODEL CLASS IN THE FUTURE!!!!!!!
QString NextHeaderItem(const QString& item){
    QString next_item_text = item;
    bool need_to_add_char = true;
    for(int i = next_item_text.length()-1; i >= 0; --i){
        if(next_item_text[i] != 'Z'){
            next_item_text[i] = QChar(next_item_text[i].unicode() + 1);
            need_to_add_char = false;
            break;
        }else{
            next_item_text[i] = QChar('A');
        }
    }
    if(need_to_add_char){
        next_item_text.push_back(QChar('A'));
    }
    return next_item_text;
}
//ADD LIKE STATIC METHOD TO TABLE MODEL CLASS IN THE FUTURE!!!!!!!

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->releaseKeyboard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::PrepareTable(){
    const int column_row_count = 10;
    for(int i = 0; i < column_row_count; ++i){
        on_actionAdd_row_triggered();
        on_actionAdd_column_triggered();
    }
    is_table_modified_ = false;
}


void MainWindow::on_actionAdd_row_triggered()
{
    TableSingleton& table = TableSingleton::getInstance();
    table.AddRow();
    int row_count = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(row_count + 1);
    is_table_modified_ = true;
}

void MainWindow::on_actionRemove_row_triggered()
{
    TableSingleton& table = TableSingleton::getInstance();
    table.RemoveRow();

    int row_count = ui->tableWidget->rowCount();
    if(row_count>0){
        ui->tableWidget->setRowCount(row_count - 1);
    }
    is_table_modified_ = true;
}

void MainWindow::on_actionAdd_column_triggered()
{
    TableSingleton& table = TableSingleton::getInstance();
    table.AddColumn();

    int column_count = ui->tableWidget->columnCount();
    ui->tableWidget->setColumnCount(column_count + 1);

    QTableWidgetItem *item;
    if(column_count == 0){
        item = new QTableWidgetItem(QString("A"));
    }
    else{
        QTableWidgetItem *prev_item = ui->tableWidget->horizontalHeaderItem(column_count-1);
        item = new QTableWidgetItem(NextHeaderItem(prev_item->text()));
    }

    ui->tableWidget->setHorizontalHeaderItem(column_count, item);
    is_table_modified_ = true;
}

void MainWindow::on_actionRemove_column_triggered()
{
    TableSingleton& table = TableSingleton::getInstance();
    table.RemoveColumn();

    int column_count = ui->tableWidget->columnCount();
    if(column_count>0){
        ui->tableWidget->setColumnCount(column_count - 1);
    }
    is_table_modified_ = true;
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    QString column_header_title = ui->tableWidget->horizontalHeaderItem(column)->text();
    ui->lineEditCellReference->setText(column_header_title + QString::number(row+1));
}

void MainWindow::on_tableWidget_cellActivated(int row, int column)
{
    ui->statusbar->showMessage("Cell " + QString(std::to_string(row).c_str()) + " " + QString(std::to_string(column).c_str()) + " activated");
}

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    if(have_permission_change_table_model_){
        have_permission_change_table_model_ = false;
        TableSingleton& table = TableSingleton::getInstance();
        auto ui_cell = ui->tableWidget->item(row, column);
        auto& model_cell = table.GetCell(row, column);
        model_cell.ChangeText(ui_cell->text());
        ui_cell->setText(model_cell.GetVisibleText());
        ui->statusbar->showMessage("Cell " + QString(std::to_string(row).c_str()) + " " + QString(std::to_string(column).c_str()) + " changed " + ui_cell->text());
        RefreshFormulaLine();
        have_permission_change_table_model_ = true;
        is_table_modified_ = true;
    }

}

void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    have_permission_change_table_model_ = false;
    TableSingleton& table = TableSingleton::getInstance();
    auto& model_cell = table.GetCell(row, column);
    QString text = model_cell.GetText();
    ui->tableWidget->setItem(row, column, new QTableWidgetItem(text));
    have_permission_change_table_model_ = true;
    ui->statusbar->showMessage("Cell " + QString(std::to_string(row).c_str()) + " " + QString(std::to_string(column).c_str()) + " double clicked");
    is_last_signal_was_cell_double_click_ = true;
}

void MainWindow::on_tableWidget_cellEntered(int row, int column)
{
    ui->statusbar->showMessage("Cell " + QString(std::to_string(row).c_str()) + " " + QString(std::to_string(column).c_str()) + " entered");
}

void MainWindow::on_tableWidget_cellPressed(int row, int column)
{
    ui->statusbar->showMessage("Cell " + QString(std::to_string(row).c_str()) + " " + QString(std::to_string(column).c_str()) + " pressed");
}

void MainWindow::RefreshFormulaLine(){
    int row = ui->tableWidget->currentRow();
    int column = ui->tableWidget->currentColumn();
    if(row >= 0 and column >= 0){
        TableSingleton& table = TableSingleton::getInstance();
        QString text = table.GetCell(row, column).GetText();
        ui->lineEditFormula->setText(text);
    }
}

void MainWindow::on_tableWidget_itemSelectionChanged()
{
    RefreshFormulaLine();
}

void MainWindow::on_lineEditFormula_returnPressed()
{
    static bool no_rec = false;
    if(!no_rec){
        no_rec = true;
        int row = ui->tableWidget->currentRow();
        int column = ui->tableWidget->currentColumn();       
        const QString& text = ui->lineEditFormula->text();
        ui->tableWidget->setItem(row, column, new QTableWidgetItem(text));
        ui->tableWidget->setFocus();
        no_rec = false;
    }
}

void MainWindow::RecalculateAfterCellDoubleClick(int row, int column){
    if((row >= 0 and column >= 0) and is_last_signal_was_cell_double_click_){
        is_last_signal_was_cell_double_click_ = false;
        on_tableWidget_cellChanged(row, column);
    }
}

void MainWindow::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    RecalculateAfterCellDoubleClick(previousRow, previousColumn);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Return){
        qDebug() << "!!!\n";
        int row = ui->tableWidget->currentRow();
        int column = ui->tableWidget->currentColumn();
        RecalculateAfterCellDoubleClick(row, column);
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    QString file_path = QFileDialog::getSaveFileName();
    TableSingleton& table = TableSingleton::getInstance();
    table.SaveTable(file_path);
    table_file_path_ = file_path;
    is_table_modified_ = false;
}

void MainWindow::on_actionSave_triggered()
{
    if(!table_file_path_.isEmpty()){
        if(is_table_modified_){
            TableSingleton& table = TableSingleton::getInstance();
            table.SaveTable(table_file_path_);
            is_table_modified_ = false;
        }
    }else{
        this->on_actionSave_as_triggered();
    }
}

void MainWindow::on_actionOpen_file_triggered()
{
    QString file_path = QFileDialog::getOpenFileName();
    QFile File(file_path);
    File.open(QFile::ReadOnly);
    QXmlStreamReader qxsr(File.readAll());\
    size_t row_count = 0;
    size_t column_count = 0;
    qxsr.readNextStartElement();
    if(qxsr.isStartElement()){
        qxsr.readNextStartElement();
        if(qxsr.isStartElement()){
            qxsr.readNextStartElement();
            row_count = qxsr.readElementText().toInt();
        }else{

        }
        qxsr.readNextStartElement();
        if(qxsr.isStartElement()){
            column_count = qxsr.readElementText().toInt();
        }else{

        }
        qDebug() << row_count << ' ' << column_count << '\n';
    }else{

    }
    NewTable(row_count, column_count);
    qxsr.readNextStartElement();
    qxsr.readNextStartElement();
    if(qxsr.isStartElement()){
        qxsr.readNextStartElement();
        while(qxsr.isStartElement()){
            qxsr.readNextStartElement();
            int row = qxsr.readElementText().toInt();
            qxsr.readNextStartElement();
            int column = qxsr.readElementText().toInt();
            qxsr.readNextStartElement();
            QString text = qxsr.readElementText();
            ui->tableWidget->setItem(row, column, new QTableWidgetItem(text));
            qDebug() << row << ' ' << column << ' ' << text << '\n';
            qxsr.readNextStartElement();
            qxsr.readNextStartElement();
        }
    }else{

    }
    is_table_modified_ = false;
}

void MainWindow::on_actionNew_file_triggered()
{
    ui->menubar->setFocus();
    int answer = QMessageBox::Discard;
    if(is_table_modified_){
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        answer = msgBox.exec();
        if(answer == QMessageBox::Save){
            this->on_actionSave_triggered();
            answer = QMessageBox::Discard;
        }
    }
    if(answer == QMessageBox::Discard){
        NewTable(10, 10);
    }
}

void MainWindow::NewTable(int row_count, int column_count){
    //ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(row_count);
    ui->tableWidget->setColumnCount(column_count);
    TableSingleton& table = TableSingleton::getInstance();
    table.NewTable(row_count, column_count);
    is_table_modified_ = false;
}

void MainWindow::closeEvent(QCloseEvent *event){
    ui->menubar->setFocus();
    if(is_table_modified_){
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int answer = msgBox.exec();
        if(answer == QMessageBox::Save){
            this->on_actionSave_triggered();
            event->accept();
        }else if(answer == QMessageBox::Discard){
            event->accept();
        }else{
            event->ignore();
        }
    }
}

void MainWindow::on_actionExit_triggered()
{
        this->close();
}
