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
    explicit DialogJoin(SUM *_sum, QWidget *parent = 0);
    ~DialogJoin();
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogJoin *ui;
    SUM* sum;
    User* user;
};

#endif // DIALOGJOIN_H
