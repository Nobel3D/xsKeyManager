#include "uitable.h"
#include <QDebug>

uiTable::uiTable(QWidget *parent)
    : QTableView(parent)
{
}

void uiTable::init(xsPasswd *_api)
{
    api = _api;
    loadTable();
}

void uiTable::loadTable()
{
    if(table != nullptr)
        delete table;
    QStringList fields = api->database->getFields();
    table = new QStandardItemModel(0,fields.count(),this);

    for(int i = 0; i < fields.count(); i++)
        table->setHorizontalHeaderItem(i, new QStandardItem(fields.at(i)));

    setModel(table);
    for(int i = 1; i <= api->database->getRecordCount() + 1; i++)
        table->appendRow(getRow(i));
}

QList<QStandardItem*> uiTable::getRow(int index)
{
    QList<QStandardItem*> out;
    QStringList in = api->dataGet(index);
    for(int i = 0; i < in.count(); i++)
        out.insert(i,new QStandardItem(in.at(i)));
    return out;
}

int uiTable::getID(int row)
{
    return table->index(row, 0).data().toInt();
}

void uiTable::addRecord()
{
    QStringList values;
    for(int i = 0; i < api->database->getFieldCount(); i++)
        values.append("");

    api->dataAdd(values);
    table->appendRow(getRow(api->database->getRecordCount() + 1));
}

void uiTable::removeRecord()
{
    int buf = currentIndex().row();
    api->dataDelete(getID(buf));
    table->removeRow(buf);
}

void uiTable::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
{

    api->dataUpdate(api->tableField().at(topLeft.column()), topLeft.data().toString(), getID(topLeft.row()));
}
