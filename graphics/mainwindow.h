#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QMap>
#include <QSqlDatabase> //подключение к БД
#include <QDebug> //для отладки программы
#include <QSqlQuery>
#include "formforname.h"
#include "formload.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

public slots:
    void slotFormForName(QString str);
    void slotFormLoad(QString str2);

private:
    Ui::MainWindow *ui;
    int index_remove = 1;
    int number_graphic = 0;//для нумерации графиков
    int number_tab = 1;//для нумерации вкладок
    QMap <QString, int> map_graphics;//для связи вкладок QTabWidget с номером графиков
    FormForName *formForName;//для связи окон через слоты и сигналы
    FormLoad *formLoad;

    QSqlDatabase db;
    QSqlQuery *query;

    void buildGraph(QVector<double> x, QVector<double> y, int number);//построение графика
    void myAddTab(QString s);
};
#endif // MAINWINDOW_H
