#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <libxspasswd/xspasswd.h>
#include <dialogjoin.h>

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

private:
    Ui::MainWindow *ui;
    DialogJoin* uiJoin;
    xsPasswd* api;
    QStandardItemModel* table;
    QList<QStandardItem*> getRow(int index);
};

#endif // MAINWINDOW_H
