#ifndef UITABLE_H
#define UITABLE_H

#include <QTableView>
#include <QItemSelectionModel>
#include <QStandardItemModel>

#include <libStronghold/stronghold.h>

class uiTable : public QTableView
{
    Q_OBJECT

public:
    explicit uiTable(QWidget *parent = nullptr);
    void init(Stronghold *_api);
    void addRecord();
    void removeRecord();
    void loadTable();
    void adminTable();
protected slots:
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int>()) override;
private:
    QStandardItemModel* table = nullptr;
    Stronghold* api;
    QList<QStandardItem*> getRow(int index);
    int getID(int row);
};

#endif // UITABLE_H
