#include "formforname.h"
#include "ui_formforname.h"

FormForName::FormForName(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormForName)
{
    ui->setupUi(this);
}

FormForName::~FormForName()
{
    delete ui;
}

void FormForName::on_pushButton_OK_clicked()
{
    emit signalFormForName(ui->lineEdit->text());//считываем введенное название вкладки(str)
}

