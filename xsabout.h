#ifndef XSABOUT_H
#define XSABOUT_H

#include <QWidget>

namespace Ui {
class xsAbout;
}

class xsAbout : public QWidget
{
    Q_OBJECT

public:
    explicit xsAbout(QWidget *parent = 0);
    ~xsAbout();

private:
    Ui::xsAbout *ui;
};

#endif // XSABOUT_H
