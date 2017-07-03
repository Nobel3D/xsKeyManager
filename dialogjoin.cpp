#include "dialogjoin.h"
#include "ui_dialogjoin.h"
#include <QMessageBox>
#include <QComboBox>

DialogJoin::DialogJoin(Stronghold* _lib, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogJoin)
{
    if(_lib != nullptr) //TODO: Error message
        lib = _lib;
    ui->setupUi(this);
    ui->comboBox->addItems(lib->login->getUsers());
}

DialogJoin::~DialogJoin()
{
    delete ui;
}


void DialogJoin::on_buttonBox_accepted()
{
    if(!lib->userJoin(ui->comboBox->currentText(), ui->linePassword->text()))
    {
        //TODO: Add login limit function
        //ui->label_2->setText("(" + QString::number(lib->password->getHit()) + "/" + QString::number(lib->password->getMaxHit()) +  ")");
        reject();
    }
}

void DialogJoin::on_buttonBox_rejected()
{
    exit(0);
}
