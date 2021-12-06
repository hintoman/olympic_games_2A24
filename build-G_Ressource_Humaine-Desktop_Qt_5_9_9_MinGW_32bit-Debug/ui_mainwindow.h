/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_user;
    QLineEdit *lineEdit_pass;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 721, 321));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QStringLiteral("background-color: rgb(0, 229, 255);"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 100, 81, 16));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 150, 81, 16));
        label_3->setFont(font1);
        lineEdit_user = new QLineEdit(groupBox);
        lineEdit_user->setObjectName(QStringLiteral("lineEdit_user"));
        lineEdit_user->setGeometry(QRect(270, 100, 121, 20));
        lineEdit_user->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        lineEdit_pass = new QLineEdit(groupBox);
        lineEdit_pass->setObjectName(QStringLiteral("lineEdit_pass"));
        lineEdit_pass->setGeometry(QRect(270, 150, 121, 20));
        lineEdit_pass->setStyleSheet(QLatin1String("selection-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        lineEdit_pass->setEchoMode(QLineEdit::Password);
        lineEdit_pass->setReadOnly(false);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(610, 280, 75, 23));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 260, 75, 23));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 20, 431, 41));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        label_4->setFont(font2);
        label_4->setStyleSheet(QLatin1String("color: rgb(0, 170, 0);\n"
"color: rgb(255, 0, 0);"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(280, 240, 71, 71));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/ICON_EHEALTH.png")));
        label_6->setScaledContents(true);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(286, 40, 81, 41));
        label->setPixmap(QPixmap(QString::fromUtf8(":/hospital-logo-clinic-health-care-physician-business-thumbnail.jpg")));
        label->setScaledContents(true);
        label_2->raise();
        label_3->raise();
        lineEdit_user->raise();
        pushButton->raise();
        pushButton_2->raise();
        lineEdit_pass->raise();
        label_4->raise();
        label_6->raise();
        label->raise();
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Authentification ", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "UserName :", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Password : ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Confirmer ", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "QUITTER ", Q_NULLPTR));
        label_4->setText(QString());
        label_6->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
