/********************************************************************************
** Form generated from reading UI file 'formload.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMLOAD_H
#define UI_FORMLOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormLoad
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Load;

    void setupUi(QWidget *FormLoad)
    {
        if (FormLoad->objectName().isEmpty())
            FormLoad->setObjectName(QString::fromUtf8("FormLoad"));
        FormLoad->resize(443, 129);
        gridLayout = new QGridLayout(FormLoad);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(FormLoad);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(FormLoad);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(341, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 2);

        pushButton_Load = new QPushButton(FormLoad);
        pushButton_Load->setObjectName(QString::fromUtf8("pushButton_Load"));

        gridLayout->addWidget(pushButton_Load, 1, 2, 1, 1);


        retranslateUi(FormLoad);

        QMetaObject::connectSlotsByName(FormLoad);
    } // setupUi

    void retranslateUi(QWidget *FormLoad)
    {
        FormLoad->setWindowTitle(QApplication::translate("FormLoad", "Form", nullptr));
        label->setText(QApplication::translate("FormLoad", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\275\320\260 \320\260\320\275\320\263\320\273\320\270\320\271\321\201\320\272\320\276\320\274 \320\261\320\265\320\267 \320\277\321\200\320\276\320\261\320\265\320\273\320\276\320\262", nullptr));
        pushButton_Load->setText(QApplication::translate("FormLoad", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormLoad: public Ui_FormLoad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMLOAD_H
