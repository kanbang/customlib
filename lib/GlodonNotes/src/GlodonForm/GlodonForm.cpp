#include "GlodonForm.h"
#include "ui_GlodonForm.h"
#include <QTranslator>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QTabBar>

GlodonForm::GlodonForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GlodonForm)
{
    ui->setupUi(this);

    QTranslator m_translatorQt;
    m_translatorQt.load("D:/program/language/tran_CN.qm");
    qApp->installTranslator(&m_translatorQt);
    setWindowFlags(windowFlags() & ~Qt::WindowMinMaxButtonsHint);
    setWindowFlags(windowFlags()|Qt::WindowMaximizeButtonHint);
}

GlodonForm::~GlodonForm()
{
    delete ui;
}
#include <QLabel>
void GlodonForm::initUI()
{
//    ui->actionMyNew->setData(tr("xingkongdao"));
//    ui->radioButton->setChecked(!ui->radioButton_2->isChecked());
//    ui->radioButton_2->setChecked(!ui->radioButton->isChecked());
//    ui->radioButton->setText(tr("GPS_Rbtn"));
//    ui->radioButton->resize(ui->radioButton->width() + 100,ui->radioButton->height());

//    QLineEdit* line = new QLineEdit();
//    line->setGeometry(100,100,100,100);
//    QHBoxLayout *pHblLayoutCurBQ = new QHBoxLayout(this);
//    pHblLayoutCurBQ->setContentsMargins(9, 0, 9, 0);
//    pHblLayoutCurBQ->addWidget(line, 300, Qt::AlignCenter);

//    this->setLayout(pHblLayoutCurBQ);

//    line->setText("xkd");
//    line->setVisible(false);

    QLineEdit* lineEdit = new QLineEdit(this);
    QLabel* label = new QLabel("Test :");
    QHBoxLayout* pHBLayout = new QHBoxLayout(this);
    pHBLayout->addWidget(label);
    pHBLayout->addWidget(lineEdit);

//    pHBLayout->setContentsMargins(9, 0, 9 , 0);

    setLayout(pHBLayout);
    pHBLayout->setGeometry(QRect(100,100,100,100));

    lineEdit->setText("xkd");
}


