#include "dialogjoin.h"
#include "ui_dialogjoin.h"
#include <QMessageBox>
#include <QComboBox>

DialogJoin::DialogJoin(SUM* _sum, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogJoin)
{
    sum = _sum;
    ui->setupUi(this);
    ui->comboBox->addItems(sum->getUsers());
}

DialogJoin::~DialogJoin()
{
    delete ui;
}


void DialogJoin::on_buttonBox_accepted()
{
    if(!sum->login(ui->comboBox->currentText(), ui->linePassword->text()))
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
