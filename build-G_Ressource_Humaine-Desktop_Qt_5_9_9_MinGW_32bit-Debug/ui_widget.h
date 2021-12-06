/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *nickname;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *message;
    QPushButton *send;
    QPushButton *bind;

    void setupUi(QDialog *widget)
    {
        if (widget->objectName().isEmpty())
            widget->setObjectName(QStringLiteral("widget"));
        widget->resize(680, 437);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        nickname = new QLineEdit(widget);
        nickname->setObjectName(QStringLiteral("nickname"));

        horizontalLayout_2->addWidget(nickname);


        verticalLayout->addLayout(horizontalLayout_2);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        message = new QLineEdit(widget);
        message->setObjectName(QStringLiteral("message"));

        horizontalLayout->addWidget(message);

        send = new QPushButton(widget);
        send->setObjectName(QStringLiteral("send"));
        send->setStyleSheet(QLatin1String("background-color: red;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 6em;\n"
"    padding: 4;"));

        horizontalLayout->addWidget(send);

        bind = new QPushButton(widget);
        bind->setObjectName(QStringLiteral("bind"));
        bind->setStyleSheet(QLatin1String("background-color: red;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 6em;\n"
"    padding: 4;"));

        horizontalLayout->addWidget(bind);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(widget);

        QMetaObject::connectSlotsByName(widget);
    } // setupUi

    void retranslateUi(QDialog *widget)
    {
        widget->setWindowTitle(QApplication::translate("widget", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("widget", "Your_Name  :", Q_NULLPTR));
        label_2->setText(QApplication::translate("widget", "Message :", Q_NULLPTR));
        send->setText(QApplication::translate("widget", "Envoyer ", Q_NULLPTR));
        bind->setText(QApplication::translate("widget", "Connecter ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class widget: public Ui_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
