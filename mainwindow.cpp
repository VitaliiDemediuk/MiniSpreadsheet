#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAdd_row_triggered()
{
    int row_count = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(row_count + 1);
}

void MainWindow::on_actionRemove_row_triggered()
{
    int row_count = ui->tableWidget->rowCount();
    if(row_count>0){
        ui->tableWidget->setRowCount(row_count - 1);
    }
}

void MainWindow::on_actionAdd_column_triggered()
{
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
}

void MainWindow::on_actionRemove_column_triggered()
{
    int column_count = ui->tableWidget->columnCount();
    if(column_count>0){
        ui->tableWidget->setColumnCount(column_count - 1);
    }
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    QString column_header_title = ui->tableWidget->horizontalHeaderItem(column)->text();
    ui->lineEditCellAddress->setText(column_header_title + QString::number(row+1));
}
