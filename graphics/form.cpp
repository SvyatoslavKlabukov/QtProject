#include "form.h"
#include "ui_form.h"
#include <QTableWidget>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(2);
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setVerticalHeaderLabels(QStringList() << "X" << "Y");
}

Form::~Form()
{
    delete ui;
}
