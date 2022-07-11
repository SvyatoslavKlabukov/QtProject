/********************************************************************************
** Form generated from reading UI file 'formforname.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFORNAME_H
#define UI_FORMFORNAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormForName
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_OK;

    void setupUi(QWidget *FormForName)
    {
        if (FormForName->objectName().isEmpty())
            FormForName->setObjectName(QString::fromUtf8("FormForName"));
        FormForName->resize(520, 159);
        gridLayout = new QGridLayout(FormForName);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(FormForName);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(FormForName);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 2);

        pushButton_OK = new QPushButton(FormForName);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
        pushButton_OK->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(pushButton_OK, 1, 2, 1, 1);


        retranslateUi(FormForName);

        QMetaObject::connectSlotsByName(FormForName);
    } // setupUi

    void retranslateUi(QWidget *FormForName)
    {
        FormForName->setWindowTitle(QApplication::translate("FormForName", "Form", nullptr));
        label->setText(QApplication::translate("FormForName", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 \320\275\320\260 \320\260\320\275\320\263\320\273\320\270\320\271\321\201\320\272\320\276\320\274 \320\261\320\265\320\267 \320\277\321\200\320\276\320\261\320\265\320\273\320\276\320\262", nullptr));
        pushButton_OK->setText(QApplication::translate("FormForName", "\320\223\320\276\321\202\320\276\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormForName: public Ui_FormForName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFORNAME_H
