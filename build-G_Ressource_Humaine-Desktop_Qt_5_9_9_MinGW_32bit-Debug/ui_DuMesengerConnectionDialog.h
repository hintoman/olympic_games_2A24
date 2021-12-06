/********************************************************************************
** Form generated from reading UI file 'DuMesengerConnectionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUMESENGERCONNECTIONDIALOG_H
#define UI_DUMESENGERCONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DuMesengerConnectionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *hostname;
    QFormLayout *formLayout;
    QLabel *label_2;
    QSpinBox *port;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok;
    QPushButton *cancel;

    void setupUi(QDialog *DuMesengerConnectionDialog)
    {
        if (DuMesengerConnectionDialog->objectName().isEmpty())
            DuMesengerConnectionDialog->setObjectName(QStringLiteral("DuMesengerConnectionDialog"));
        DuMesengerConnectionDialog->resize(450, 124);
        verticalLayout = new QVBoxLayout(DuMesengerConnectionDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DuMesengerConnectionDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        hostname = new QLineEdit(DuMesengerConnectionDialog);
        hostname->setObjectName(QStringLiteral("hostname"));

        horizontalLayout->addWidget(hostname);


        verticalLayout->addLayout(horizontalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(DuMesengerConnectionDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        port = new QSpinBox(DuMesengerConnectionDialog);
        port->setObjectName(QStringLiteral("port"));
        port->setMaximum(9999999);

        formLayout->setWidget(0, QFormLayout::FieldRole, port);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ok = new QPushButton(DuMesengerConnectionDialog);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setStyleSheet(QLatin1String("background-color: red;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 6em;\n"
"    padding: 4;"));

        horizontalLayout_2->addWidget(ok);

        cancel = new QPushButton(DuMesengerConnectionDialog);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setStyleSheet(QLatin1String("background-color: red;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 6em;\n"
"    padding: 4;"));

        horizontalLayout_2->addWidget(cancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(DuMesengerConnectionDialog);

        QMetaObject::connectSlotsByName(DuMesengerConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *DuMesengerConnectionDialog)
    {
        DuMesengerConnectionDialog->setWindowTitle(QApplication::translate("DuMesengerConnectionDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DuMesengerConnectionDialog", "HostName :", Q_NULLPTR));
        label_2->setText(QApplication::translate("DuMesengerConnectionDialog", "Port", Q_NULLPTR));
        ok->setText(QApplication::translate("DuMesengerConnectionDialog", "Accepter ", Q_NULLPTR));
        cancel->setText(QApplication::translate("DuMesengerConnectionDialog", "Annuler", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DuMesengerConnectionDialog: public Ui_DuMesengerConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUMESENGERCONNECTIONDIALOG_H
