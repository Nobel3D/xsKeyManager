#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uitable.h"
#include <QDebug>
#include <QMessageBox>
#include <QAction>
#include <QFileDialog>
#include <QFileInfoList>

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
    connect(ui->actionGenerator, SIGNAL(triggered()), this, SLOT(on_menuGenerate()));
    connect(ui->actionExport_Database, SIGNAL(triggered()), this, SLOT(on_menuExportDatabase()));
    connect(ui->actionExport_Table, SIGNAL(triggered()), this, SLOT(on_menuExportTable()));
    connect(ui->actionImport_Database, SIGNAL(triggered()), this, SLOT(on_menuImportDatabase()));
    connect(ui->actionImport_Table, SIGNAL(triggered()), this, SLOT(on_menuImportTable()));
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

void MainWindow::on_menuAboutXSoftware()
{
    QMessageBox::aboutQt(0, "About...");
}


void MainWindow::on_menuGenerate()
{
    generate = new winGenerate;
    generate->show();
}

void MainWindow::on_menuImportTable()
{
    QString file;
    file = QFileDialog::getOpenFileName(nullptr, "Select file...", QDir::homePath(), "*.csv");
    if(!file.isEmpty())
        api->importTable(QFileInfo(file).completeBaseName(), file);
    ui->comboTable->addItem(QFileInfo(file).completeBaseName());
}

void MainWindow::on_menuImportDatabase()
{
    QFileInfoList files;
    QStringList buffer;
    buffer = QFileDialog::getOpenFileNames(nullptr, "Select files...", QDir::homePath(), "*.csv");
    for(int i = 0; i < buffer.count(); i++)
        files.append(QFileInfo(buffer.at(i)));
    if(!files.isEmpty())
        api->importDatabase(files);
}

void MainWindow::on_menuExportTable()
{
    QString file;
    file = QFileDialog::getSaveFileName(nullptr, "Select file...", QDir::homePath(), "*.csv");
    if(!file.isEmpty())
        api->exportTable(file);
}

void MainWindow::on_menuExportDatabase()
{
    QString file = QFileDialog::getExistingDirectory(nullptr, "Select directory...", QDir::homePath());
    QDir dir(file);
    if(!file.isEmpty())
        api->exportDatabase(dir);
}
