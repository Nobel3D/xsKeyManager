#include "uilogin.h"
#include "ui_uilogin.h"
#include <QMessageBox>
#include <QComboBox>
#include <QPushButton>

uiLogin::uiLogin(bool firstRun, QDialog *parent) :
    QDialog(parent)
{
    if(firstRun) setupFirstUi();
    else setupUi();

    connect(buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()), this, SLOT(accept()));
    connect(buttonBox->button(QDialogButtonBox::Cancel), SIGNAL(clicked()), this, SLOT(reject()));
}

uiLogin::~uiLogin()
{
    //delete ui;
}

void uiLogin::setupUi()
{
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("this"));
    resize(400, 300);
    gridLayout = new QGridLayout(this);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));

    label_3 = new QLabel(this);
    label_3->setObjectName(QStringLiteral("label_3"));

    gridLayout->addWidget(label_3, 0, 0, 1, 1);

    comboBox = new QComboBox(this);
    comboBox->setObjectName(QStringLiteral("comboBox"));

    gridLayout->addWidget(comboBox, 0, 1, 1, 1);

    label_2 = new QLabel(this);
    label_2->setObjectName(QStringLiteral("label_2"));

    gridLayout->addWidget(label_2, 1, 0, 1, 1);

    lineEdit = new QLineEdit(this);
    lineEdit->setObjectName(QStringLiteral("lineEdit"));

    gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

    /*label = new QLabel(this);
    label->setObjectName(QStringLiteral("label"));

    gridLayout->addWidget(label, 2, 0, 1, 1);

    lineEdit_2 = new QLineEdit(this);
    lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

    gridLayout->addWidget(lineEdit_2, 2, 1, 1, 1);
    */
    buttonBox = new QDialogButtonBox(this);
    buttonBox->setObjectName(QStringLiteral("buttonBox"));
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    buttonBox->setCenterButtons(true);

    gridLayout->addWidget(buttonBox, 3, 0, 1, 2);
    label_3->setText("Insert your\nusername");
    label_2->setText("Insert your\npassword");
    //label->setText("Repeat your\npassword");
}

void uiLogin::setupFirstUi()
{
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("this"));
    resize(400, 300);
    gridLayout = new QGridLayout(this);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    label_3 = new QLabel(this);
    label_3->setObjectName(QStringLiteral("label_3"));

    gridLayout->addWidget(label_3, 0, 0, 1, 1);

    lineEdit_3 = new QLineEdit(this);
    lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

    gridLayout->addWidget(lineEdit_3, 0, 1, 1, 1);

    label_2 = new QLabel(this);
    label_2->setObjectName(QStringLiteral("label_2"));

    gridLayout->addWidget(label_2, 1, 0, 1, 1);

    lineEdit = new QLineEdit(this);
    lineEdit->setObjectName(QStringLiteral("lineEdit"));

    gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

    label = new QLabel(this);
    label->setObjectName(QStringLiteral("label"));

    gridLayout->addWidget(label, 2, 0, 1, 1);

    lineEdit_2 = new QLineEdit(this);
    lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

    gridLayout->addWidget(lineEdit_2, 2, 1, 1, 1);

    buttonBox = new QDialogButtonBox(this);
    buttonBox->setObjectName(QStringLiteral("buttonBox"));
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    buttonBox->setCenterButtons(true);

    gridLayout->addWidget(buttonBox, 3, 0, 1, 2);
    label_3->setText("Insert your\nusername");
    label_2->setText("Insert your\npassword");
    label->setText("Repeat your\npassword");
}
