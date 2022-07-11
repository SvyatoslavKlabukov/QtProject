#include "formload.h"
#include "ui_formload.h"

FormLoad::FormLoad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormLoad)
{
    ui->setupUi(this);
}

FormLoad::~FormLoad()
{
    delete ui;
}

void FormLoad::on_pushButton_Load_clicked()
{
    emit signalFormLoad(ui->lineEdit->text());//считываем введенное название набора из БД
}

