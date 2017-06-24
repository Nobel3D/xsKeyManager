#ifndef DIALOGJOIN_H
#define DIALOGJOIN_H

#include <QDialog>
#include <xslib/xslib.h>
#include <libxspasswd/xspasswd.h>

namespace Ui {
class DialogJoin;
}

class DialogJoin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogJoin(xsPasswd *_lib, QWidget *parent = 0);
    ~DialogJoin();
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogJoin *ui;
    xsPasswd* lib;
    bool bLogin;
    void login(QString pw);
    void newdb(QString pw);
};

#endif // DIALOGJOIN_H
