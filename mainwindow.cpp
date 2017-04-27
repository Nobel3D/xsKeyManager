#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonJoin_clicked()
{
    if(ui->lineName->text().isEmpty() || ui->linePasswd->text().isEmpty())
        return;

}
int join(QString tmpuser)
{
    QString key;
    user = tmpuser;
    for(int i = 0; i < MAXHIT; i++)
    {
        xsConsole() << "Enter your password ->";
        xsConsole() >> key;
        if(passwd(key) == OK)
        {
            joined = 1;
            if(!database.connect(HOME_PATH + user + DBFILE))
                xsConsole() << "Cannot access into your database file (" << HOME_PATH + user + DBFILE << ")\n";
            return OK;
        }
    }
    user = "tmp";
    return FAIL;
}
