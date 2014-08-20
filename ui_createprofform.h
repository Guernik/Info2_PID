/********************************************************************************
** Form generated from reading UI file 'createprofform.ui'
**
** Created: Wed 15. Feb 18:14:13 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPROFFORM_H
#define UI_CREATEPROFFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createProfForm
{
public:
    QGroupBox *groupBox;
    QComboBox *combo_puertos;
    QPushButton *btn_refresh;
    QPushButton *btn_connect;
    QLabel *lbl_estado;

    void setupUi(QWidget *createProfForm)
    {
        if (createProfForm->objectName().isEmpty())
            createProfForm->setObjectName(QString::fromUtf8("createProfForm"));
        createProfForm->resize(228, 136);
        groupBox = new QGroupBox(createProfForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 211, 121));
        combo_puertos = new QComboBox(groupBox);
        combo_puertos->setObjectName(QString::fromUtf8("combo_puertos"));
        combo_puertos->setGeometry(QRect(20, 30, 151, 22));
        btn_refresh = new QPushButton(groupBox);
        btn_refresh->setObjectName(QString::fromUtf8("btn_refresh"));
        btn_refresh->setGeometry(QRect(20, 60, 75, 23));
        btn_connect = new QPushButton(groupBox);
        btn_connect->setObjectName(QString::fromUtf8("btn_connect"));
        btn_connect->setGeometry(QRect(100, 60, 71, 23));
        lbl_estado = new QLabel(groupBox);
        lbl_estado->setObjectName(QString::fromUtf8("lbl_estado"));
        lbl_estado->setGeometry(QRect(20, 90, 151, 16));

        retranslateUi(createProfForm);

        QMetaObject::connectSlotsByName(createProfForm);
    } // setupUi

    void retranslateUi(QWidget *createProfForm)
    {
        createProfForm->setWindowTitle(QApplication::translate("createProfForm", "Conexion", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("createProfForm", "Conexion", 0, QApplication::UnicodeUTF8));
        btn_refresh->setText(QApplication::translate("createProfForm", "Refrescar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        btn_connect->setStatusTip(QApplication::translate("createProfForm", "Conectar con 9600,8,1,n", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        btn_connect->setText(QApplication::translate("createProfForm", "Conectar", 0, QApplication::UnicodeUTF8));
        lbl_estado->setText(QApplication::translate("createProfForm", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class createProfForm: public Ui_createProfForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPROFFORM_H
