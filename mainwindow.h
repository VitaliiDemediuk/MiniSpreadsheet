#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void closeEvent(QCloseEvent *event) override;
    MainWindow(QWidget *parent = nullptr);
    void PrepareTable();
    ~MainWindow();

private slots:
    void on_actionAdd_row_triggered();

    void on_actionRemove_row_triggered();

    void on_actionAdd_column_triggered();

    void on_actionRemove_column_triggered();

    void on_tableWidget_cellChanged(int row, int column);

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_tableWidget_itemSelectionChanged();

    void on_lineEditFormula_returnPressed();

    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_actionSave_as_triggered();

    void on_actionOpen_file_triggered();

    void on_actionNew_file_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void refresh_cell(int row, int column);

private:
    Ui::MainWindow *ui;
    void RefreshFormulaLine();
    void RecalculateAfterCellDoubleClick(int row, int column);
    void NewTable(int row, int column);
    int DoYouWantToSave();
    bool DoYouWantToDelete(QString what);
    bool have_permission_change_table_model_ = true;
    bool is_last_signal_was_cell_double_click_ = false;
    bool is_table_modified_ = false;
    bool can_open_error_window_ = true;
    QString table_file_path_;
protected:
     void keyPressEvent(QKeyEvent *event) override;
};
#endif // MAINWINDOW_H
