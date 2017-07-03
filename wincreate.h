#ifndef WINCREATE_H
#define WINCREATE_H

#include <QDialog>
#include <libStronghold/stronghold.h>
#include <QStandardItemModel>

namespace Ui {
class winCreate;
}

class winCreate : public QDialog
{
    Q_OBJECT

public:
    explicit winCreate(Stronghold* _api, QWidget *parent = 0);
    ~winCreate();

    QString name;
private slots:
    void on_pushAdd_clicked();

    void on_pushRemove_clicked();

    void on_buttonBox_accepted();

private:
    Ui::winCreate *ui;
    Stronghold* api;
    QStandardItemModel* list;
};

#endif // WINCREATE_H
