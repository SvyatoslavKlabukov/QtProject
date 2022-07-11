#ifndef FORMFORNAME_H
#define FORMFORNAME_H

#include <QWidget>

namespace Ui {
class FormForName;
}

class FormForName : public QWidget
{
    Q_OBJECT

public:
    explicit FormForName(QWidget *parent = nullptr);
    ~FormForName();

private:
    Ui::FormForName *ui;

signals:
    void signalFormForName(QString);
private slots:
    void on_pushButton_OK_clicked();
};

#endif // FORMFORNAME_H
