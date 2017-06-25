#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QItemSelectionModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    api = new xsPasswd();
    uiJoin = new DialogJoin(api);
    while(uiJoin->exec() != QDialog::Accepted);

    ui->setupUi(this);
    ui->comboTable->addItems(api->tableList());
}

MainWindow::~MainWindow()
{
    delete ui;
}

QList<QStandardItem*> MainWindow::getRow(int index)
{
    QList<QStandardItem*> out;
    QStringList in = api->dataGet(index);
    for(int i = 0; i < in.count(); i++)
        out.insert(i,new QStandardItem(in.at(i)));
    return out;
}

void MainWindow::on_comboTable_currentIndexChanged(int index)
{
    api->tableUse(ui->comboTable->currentText());
    QStringList fields = api->database->getFields(true);
    table = new QStandardItemModel(0,fields.count(),this);

    for(int i = 0; i < fields.count(); i++)
        table->setHorizontalHeaderItem(i, new QStandardItem(fields.at(i)));

    ui->tableView->setModel(table);
    for(int i = 1; i <= api->database->getRecordCount() + 1; i++)
        table->appendRow(getRow(i));
}

void MainWindow::on_buttonAdd_clicked()
{
    table->insertRow(table->rowCount());
}

void MainWindow::on_buttonRemove_clicked()
{
    table->removeRow(ui->tableView->currentIndex().row());
}
