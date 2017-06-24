#include "dialogjoin.h"
#include "ui_dialogjoin.h"
#include <QMessageBox>


DialogJoin::DialogJoin(xsPasswd* _lib, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogJoin)
{
    if(_lib != nullptr) //TODO: Error message
        lib = _lib;
    ui->setupUi(this);
    if(lib->loadPassword(PWFILE))
        bLogin = true;
    else
    {
        bLogin = false;
        ui->label->setText("Insert your new master password");
        ui->label_2->hide();
    }
}

DialogJoin::~DialogJoin()
{
    delete ui;
}


void DialogJoin::on_buttonBox_accepted()
{
    if(bLogin)
        login(ui->linePassword->text());
    else
        newdb(ui->linePassword->text());
}

void DialogJoin::login(QString pw)
{
    xsPassword hot(pw,true);
    if(!lib->userJoin(hot))
    {
        ui->label_2->setText("(" + QString::number(lib->password->getHit()) + "/" + QString::number(lib->password->getMaxHit()) +  ")");
        reject();
    }
}

void DialogJoin::newdb(QString pw)
{
    xsPassword hot(pw);

    if(lib->userCreate(hot, PWFILE))
        QMessageBox::information(0,"Create", "Creation successful on your home directory!");

    reject();
}

void DialogJoin::on_buttonBox_rejected()
{
    exit(0);
}
