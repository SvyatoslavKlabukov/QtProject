#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include "form.h"
#include <QMessageBox>
#include <QList>
#include <QString>
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    formForName = new FormForName;
    formLoad = new FormLoad;
    //соединение сигнала signalFormForName со слотом slotFormForName (при добавлении вкладки)
    connect(formForName, &FormForName::signalFormForName, this, &MainWindow::slotFormForName);
    //соединение окон при загрузке
    connect(formLoad, &FormLoad::signalFormLoad, this, &MainWindow::slotFormLoad);

    //подключение к БД
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDB.db");
    if (db.open())
    {
        qDebug("open db");
    } else
    {
        qDebug("no open db");
    }

    //таблицы для внесения точек
    ui->tableWidget->setRowCount(2);
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setVerticalHeaderLabels(QStringList() << "X" << "Y");
    ui->tableWidget_2->setRowCount(2);
    ui->tableWidget_2->setColumnCount(10);
    ui->tableWidget_2->setVerticalHeaderLabels(QStringList() << "X" << "Y");

    //границы осей
    ui->widget->xAxis->setRange(-10, 10);
    ui->widget->yAxis->setRange(-10, 10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//кнопка Добавить
void MainWindow::on_pushButton_9_clicked()
{
    formForName->show();
}

//кнопка Удаление
void MainWindow::on_pushButton_12_clicked()
{
    //int a = ui->tabWidget->currentIndex();
    QString a = ui->tabWidget->tabText(ui->tabWidget->currentIndex());
    //QString ss;
    //QMessageBox::information(this, "Info", ss.setNum(a));
    QMessageBox::information(this, "Info", a);
    if (map_graphics.contains(a))
    {
        ui->widget->removeGraph(map_graphics[a]);
        ui->widget->replot();
        ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
        QMap <QString, int>:: iterator it;
        it = map_graphics.find(a);
        map_graphics.erase(it);
        number_graphic--;
        if (number_graphic < 0)
        {
            number_graphic = 0;
            ui->widget->clearGraphs();
        }
    } else
    {
        ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
    }
    //ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
    //ui->widget->replot();
    //index_remove +=1;
    //уменьшаем число графиков, должна быть строгая очередность
    //number_graphic--;
}

//кнопка построить(считываем координаты из таблицы)
void MainWindow::on_pushButton_clicked()
{
    QVector<double> x , y;
    bool flag = false;
    for (int i = 0; i < ui->tabWidget->currentWidget()->findChild<QTableWidget *>()->columnCount(); i++)
    {
        QTableWidgetItem *elem_x = ui->tabWidget->currentWidget()->findChild<QTableWidget *>()->item(0, i);
        QTableWidgetItem *elem_y = ui->tabWidget->currentWidget()->findChild<QTableWidget *>()->item(1, i);
        //проверка указателя на ноль, обезопасит нас от попытки обращения к несуществующему объекту
        if ((elem_x != 0) && (elem_y != 0))//проверка наличия элемента в столбце (координаты(x,y))
        {
            //преобразуем string -> double
            QString str_x = elem_x->text();
            double number_x = str_x.toDouble();
            x.push_back(number_x);
            QString str_y = elem_y->text();
            double number_y = str_y.toDouble();
            y.push_back(number_y);
            //QMessageBox::information(this, "Info", "нет элемента");
        } else
        {
            flag = true;
        }
        //удаляет элементы в таблице
        //delete elem_x;
        //delete elem_y;
    }
    if (flag)
    {
       QMessageBox::information(this, "Info", "Не все координаты заданы, либо заданы некорректно");
       flag = false;
    }

    QString tab = ui->tabWidget->tabText(ui->tabWidget->currentIndex());//определяем название текущей вкладки
    QString sss;
    //QMessageBox::information(this, "Info", sss.setNum(ui->tabWidget->currentIndex()));
    QMessageBox::information(this, "Info", tab);
    buildGraph(x, y, number_graphic);//строим график
    //map_graphics.insert(tab, number_graphic);
    map_graphics[tab]= number_graphic;
    number_graphic++;//увеличиваем число графиков, должна быть строгая очередность
}

void MainWindow::buildGraph(QVector<double> x, QVector<double> y, int number)
{
    ui->widget->addGraph();//добавляем один график в widget
    ui->widget->graph(number)->setData(x,y);//отрисовываем график по массивам x y
    //определим выбранный цвет для графика
    if (ui->radioButton_red->isChecked())
    {
        ui->widget->graph(number)->setPen(QPen(Qt::red));
    }
    if (ui->radioButton_green->isChecked())
    {
        ui->widget->graph(number)->setPen(QPen(Qt::green));
    }
    if (ui->radioButton_blue->isChecked())
    {
        ui->widget->graph(number)->setPen(QPen(Qt::blue));
    }

    ui->widget->graph(number)->setLineStyle(QCPGraph::lsLine);//настраиваем линии соединения точек
    ui->widget->graph(number)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));//вид точек
    ui->widget->replot();//перерисовываем график
}

//кнопка Сохранить
void MainWindow::on_pushButton_10_clicked()
{
    //считываем данные из таблицы приложения
    QVector<QString> x , y;
    for (int i = 0; i < ui->tabWidget->currentWidget()->findChild<QTableWidget *>()->columnCount(); i++)
    {
        QTableWidgetItem *elem_x = ui->tabWidget->currentWidget()->findChild<QTableWidget *>()->item(0, i);
        QTableWidgetItem *elem_y = ui->tabWidget->currentWidget()->findChild<QTableWidget *>()->item(1, i);
        //проверка указателя на ноль, обезопасит нас от попытки обращения к несуществующему объекту
        if ((elem_x != 0) && (elem_y != 0))//проверка наличия элемента в столбце (координаты(x,y))
        {
            QString str_x = elem_x->text();
            x.push_back(str_x);
            QString str_y = elem_y->text();
            y.push_back(str_y);

        }
    }
    QString name = ui->tabWidget->tabText(ui->tabWidget->currentIndex());//определяем название текущей вкладки
    //ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), name) ;//определяем название текущей вкладки
    //QTabWidget *tabWidge = new QTabWidget(this);
    //создаем таблицу, используя sql-запрос
    QSqlQuery *query_new = new QSqlQuery(db);
    qDebug()<<name;
    QString qss = QString("CREATE TABLE %0 (id int primary key, X_coor varchar(30), Y_coor varchar(30))").arg(name) ;
    //QString qs = tr("CREATE TABLE ");
    //QString qs2 = tr(name);
    //QString qs3 = tr(" (id int primary key, X_coor varchar(30), Y_coor varchar(30))");
    qDebug()<<qss;
    //QString qs2= qs+" (id int primary key, X_coor varchar(30), Y_coor varchar(30))";
    //query_new->prepare("CREATE TABLE coordinates (id int primary key, X_coor varchar(30), Y_coor varchar(30))");
    //query_new->prepare(qs);
    //создаем таблицу в БД
    //query_new->exec();
    if (!query_new->exec(qss))
    {
        qDebug("no create table");
    }
    //заполняем таблицу
    bool flag = false;
    for (int i=0; i<x.size(); ++i)
    {
        query_new->prepare(
                    "INSERT INTO " +name+ " (id, X_coor, Y_coor)"
                    "VALUES (:id, :X_coor, :Y_coor)");
        query_new->bindValue(":id", i);
        query_new->bindValue(":X_coor", x[i]);
        query_new->bindValue(":Y_coor", y[i]);
        //query_new->exec();
        if (!query_new->exec())
        {
            qDebug("no insert into table");
        } else
        {
            flag = true;
        }
    }
    if (flag)
    {
       QMessageBox::information(this, "Info", "Сохранение в БД выполнено");
    } else
    {
       QMessageBox::information(this, "Info", "Сохранение в БД не выполнено!!!");
    }
}
//Добавление вкладки с таблицей Form
void MainWindow::slotFormForName(QString str)
{
    ui->tabWidget->addTab(new Form(), QString(str));
    //ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
    //ui->tabWidget->setCurrentIndex(ui->tabWidget->count());

    formForName->close() ;
}

void MainWindow::myAddTab(QString s)
{
    ui->tabWidget->addTab(new Form(), QString(s));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
}

void MainWindow::slotFormLoad(QString str2)
{
    QVector<QString> x , y;
    QSqlQuery *query_new2 = new QSqlQuery(db);
    query_new2->prepare("SELECT X_coor FROM "+str2);
    if (!query_new2->exec())
    {
        qDebug("no select X_coor table");
    } else
    {
        int j = 0;
        while (query_new2->next())
        {
            x.push_back(query_new2->value(0).toString() );
            qDebug("push_back X_coor ");
            qDebug()<<x[j];
            j++;
        }
    }
    //QSqlRecord rec = query_new2->record() ;

    query_new2->prepare("SELECT Y_coor FROM "+str2);
    if (!query_new2->exec())
    {
        qDebug("no select Y_coor table");
    } else
    {
        while (query_new2->next())
        {
            y.push_back(query_new2->value(0).toString() );
        }
    }
    formLoad->close() ;
    //myAddTab(str2);
    Form *f = new Form;
    for(int i=0; i<x.size(); ++i)
    {
        QLineEdit *li = new QLineEdit;
        li->setText(x[i]) ;
        f->findChild<QTableWidget *>()->setCellWidget(0, i, li);
        //f->findChild<QTableWidget *>()->item(0, i)->setText(x[i]);
        QLineEdit *li2 = new QLineEdit;
        li2->setText(y[i]) ;
        f->findChild<QTableWidget *>()->setCellWidget(1, i, li2);
        //f->findChild<QTableWidget *>()->item(1, i)->setText(y[i]);
    }
    ui->tabWidget->addTab(f, QString(str2));
    //ui->tabWidget->addTab(new Form(), QString(str2));
    //ui->tabWidget->setCurrentIndex(ui->tabWidget->count());
    //ui->tabWidget->setCurrentWidget(new Form()) ;
    //ui->tabWidget->currentWidget()->findChild<QTableWidget *>()->item(0, 0)->setText(x[0]);
    //ui->tabWidget->currentWidget()->findChild<QTableWidget *>()->item(1, 0)->setText(y[0]);
    //Заполнение таблицы
    /*for (int i = 0; i<x.size(); ++i)
    {
        //QLineEdit *li = new QLineEdit;
        //li->setText(x[i]) ;
        //ui->tabWidget->currentWidget()->findChild<QTableWidget *>()->setCellWidget(0, i, li) ;
        ui->tabWidget->currentWidget()->findChild<QTableWidget *>()->item(0, i)->setText(x[i]);
        ui->tabWidget->currentWidget()->findChild<QTableWidget *>()->item(1, i)->setText(y[i]);
        qDebug("setText");
    }
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), str2) ;*/
    //ui->tabWidget->currentWidget()-> ;
}

//кнопка Загрузить
void MainWindow::on_pushButton_11_clicked()
{
    formLoad->show();
}

