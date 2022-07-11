#ifndef FORMLOAD_H
#define FORMLOAD_H

#include <QWidget>

namespace Ui {
class FormLoad;
}

class FormLoad : public QWidget
{
    Q_OBJECT

public:
    explicit FormLoad(QWidget *parent = nullptr);
    ~FormLoad();

private slots:
    void on_pushButton_Load_clicked();

private:
    Ui::FormLoad *ui;

signals:
    void signalFormLoad(QString);
};

#endif // FORMLOAD_H
