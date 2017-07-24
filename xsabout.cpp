#include "xsabout.h"
#include "ui_xsabout.h"

xsAbout::xsAbout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::xsAbout)
{
    ui->setupUi(this);
}

xsAbout::~xsAbout()
{
    delete ui;
}
