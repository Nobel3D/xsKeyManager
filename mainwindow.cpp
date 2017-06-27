#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uitable.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    api = new xsPasswd();
    uiJoin = new DialogJoin(api);
    while(uiJoin->exec() != QDialog::Accepted);
    ui->setupUi(this);
    ui->tableView->init(api);
    ui->comboTable->addItems(api->tableList());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboTable_currentIndexChanged(int index)
{
    api->tableUse(ui->comboTable->currentText());
    ui->tableView->loadTable();
}

void MainWindow::on_buttonAdd_clicked()
{
    ui->tableView->addRecord();
}

void MainWindow::on_buttonRemove_clicked()
{
    ui->tableView->removeRecord();
}

void MainWindow::on_buttonSave_clicked()
{
}

