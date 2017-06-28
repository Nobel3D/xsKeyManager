#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uitable.h"
#include <QDebug>
#include <QMessageBox>
#include <QAction>

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
    connect(ui->actionAbout_QT, SIGNAL(triggered()), this, SLOT(on_menuAboutQT()));
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


void MainWindow::on_buttonCreate_clicked()
{
    create = new winCreate(api);
    if(create->exec() == QDialog::Accepted)
        ui->comboTable->addItem(create->name);

}

void MainWindow::on_menuAboutQT()
{
    QMessageBox::aboutQt(0, "About...");
}
