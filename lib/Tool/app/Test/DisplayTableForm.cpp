#include "DisplayTableForm.h"
#include "ui_DisplayTableForm.h"
#include <QDebug>

DisplayTableForm::DisplayTableForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayTableForm)
{
    resize(1060,600);
    ui->setupUi(this);
    m_model = new TableModel("Contacts",this);
    ui->tableView->setModel(m_model);
    ui->comboBox->addItems(m_model->tableNames());
//    ui->tableView->setCurrentIndex();
    connect(ui->comboBox, SIGNAL(activated(const QString&)), this, SLOT(setTableName(const QString&)));
    ui->comboBox->setCurrentIndex(0);
}

DisplayTableForm::~DisplayTableForm()
{
    delete ui;
}

void DisplayTableForm::setTableName(const QString &name)
{
    qDebug()<<Q_FUNC_INFO;
    m_model->setTableName(name);    
}
