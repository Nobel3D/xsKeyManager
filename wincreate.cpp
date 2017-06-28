#include "wincreate.h"
#include "ui_wincreate.h"
#include <QListView>
#include <QMessageBox>

winCreate::winCreate(xsPasswd *_api, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::winCreate)
{
    api = _api;
    ui->setupUi(this);
    list = new QStandardItemModel();
    ui->listView->setModel(list);
}

winCreate::~winCreate()
{
    delete ui;
}


void winCreate::on_pushAdd_clicked()
{
    list->appendRow(new QStandardItem("field_name"));
}

void winCreate::on_pushRemove_clicked()
{
    list->removeRow(ui->listView->currentIndex().row());
}

void winCreate::on_buttonBox_accepted()
{
    name = ui->lineTable->text();
    int iRow = list->rowCount();
    if(name.isEmpty() || iRow < 1)
    {
        QMessageBox::warning(0,"Creation failed!", "Field or Table name didn't find!\nTable won't be create.");
        reject();
        return;
    }
    QStringList fields;
    for(int i = 0; i < iRow; i++)
        fields.append(list->index(i, 0).data().toString());

    api->tableCreate(name, fields);
}
