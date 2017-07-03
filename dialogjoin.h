#ifndef DIALOGJOIN_H
#define DIALOGJOIN_H

#include <QDialog>
#include <xslib/xslib.h>
#include <libStronghold/stronghold.h>

namespace Ui {
class DialogJoin;
}

class DialogJoin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogJoin(Stronghold *_lib, QWidget *parent = 0);
    ~DialogJoin();
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogJoin *ui;
    Stronghold* lib;
};

#endif // DIALOGJOIN_H
