#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <libStronghold/stronghold.h>
#include <dialogjoin.h>
#include <wincreate.h>
#include <wingenerate.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_comboTable_currentIndexChanged(int index);
    void on_buttonAdd_clicked();
    void on_buttonRemove_clicked();
    void on_buttonSave_clicked();
    void on_buttonCreate_clicked();
    void on_menuAboutQT();
    void on_menuAboutXSoftware();
    void on_menuGenerate();
    void on_menuImportTable();
    void on_menuImportDatabase();
    void on_menuExportTable();
    void on_menuExportDatabase();
    void on_menuAdmin();
    void on_menuDatabase();

private:
    Ui::MainWindow *ui;
    DialogJoin* uiJoin;
    winCreate* create;
    winGenerate* generate;
    SUM* sum;
    PEM* pem;
};

#endif // MAINWINDOW_H
