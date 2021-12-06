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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *login;
    QWidget *tab_6;
    QPushButton *login_2;
    QLineEdit *username;
    QLineEdit *password;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *tab;
    QLineEdit *id_emp;
    QLineEdit *nom;
    QLineEdit *salaire;
    QDateEdit *dateEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *tab_2;
    QLineEdit *id_empSupp;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QWidget *tab_3;
    QTableView *tablemp;
    QComboBox *trier;
    QPushButton *pb_pdf;
    QWidget *tab_4;
    QPushButton *recherche_button;
    QComboBox *recherche_type;
    QLineEdit *text_recherche;
    QTableView *tablemp_1;
    QWidget *tab_5;
    QPushButton *sendmail;
    QLineEdit *name;
    QLabel *label_6;
    QLineEdit *passwrd;
    QLabel *label_7;
    QLineEdit *object;
    QLabel *label_8;
    QLineEdit *recep;
    QLabel *label_9;
    QPlainTextEdit *msg;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        login = new QTabWidget(centralwidget);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(40, 30, 701, 591));
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        login_2 = new QPushButton(tab_6);
        login_2->setObjectName(QStringLiteral("login_2"));
        login_2->setGeometry(QRect(260, 210, 93, 28));
        username = new QLineEdit(tab_6);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(110, 120, 113, 22));
        password = new QLineEdit(tab_6);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(110, 170, 113, 22));
        label_10 = new QLabel(tab_6);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 120, 61, 16));
        label_11 = new QLabel(tab_6);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 170, 56, 16));
        login->addTab(tab_6, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        id_emp = new QLineEdit(tab);
        id_emp->setObjectName(QStringLiteral("id_emp"));
        id_emp->setGeometry(QRect(150, 50, 113, 22));
        nom = new QLineEdit(tab);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(150, 100, 113, 22));
        salaire = new QLineEdit(tab);
        salaire->setObjectName(QStringLiteral("salaire"));
        salaire->setGeometry(QRect(150, 160, 113, 22));
        dateEdit = new QDateEdit(tab);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(150, 210, 110, 22));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 50, 56, 16));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 100, 56, 16));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 160, 56, 16));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 210, 56, 16));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 300, 93, 28));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 260, 93, 28));
        login->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        id_empSupp = new QLineEdit(tab_2);
        id_empSupp->setObjectName(QStringLiteral("id_empSupp"));
        id_empSupp->setGeometry(QRect(150, 80, 113, 22));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 130, 93, 28));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 80, 56, 16));
        login->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tablemp = new QTableView(tab_3);
        tablemp->setObjectName(QStringLiteral("tablemp"));
        tablemp->setGeometry(QRect(80, 40, 421, 301));
        trier = new QComboBox(tab_3);
        trier->setObjectName(QStringLiteral("trier"));
        trier->setGeometry(QRect(220, 360, 131, 31));
        pb_pdf = new QPushButton(tab_3);
        pb_pdf->setObjectName(QStringLiteral("pb_pdf"));
        pb_pdf->setGeometry(QRect(430, 360, 93, 28));
        login->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        recherche_button = new QPushButton(tab_4);
        recherche_button->setObjectName(QStringLiteral("recherche_button"));
        recherche_button->setGeometry(QRect(360, 40, 93, 28));
        recherche_type = new QComboBox(tab_4);
        recherche_type->setObjectName(QStringLiteral("recherche_type"));
        recherche_type->setGeometry(QRect(50, 40, 101, 31));
        text_recherche = new QLineEdit(tab_4);
        text_recherche->setObjectName(QStringLiteral("text_recherche"));
        text_recherche->setGeometry(QRect(200, 40, 113, 22));
        tablemp_1 = new QTableView(tab_4);
        tablemp_1->setObjectName(QStringLiteral("tablemp_1"));
        tablemp_1->setGeometry(QRect(70, 120, 401, 211));
        login->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        sendmail = new QPushButton(tab_5);
        sendmail->setObjectName(QStringLiteral("sendmail"));
        sendmail->setGeometry(QRect(460, 320, 93, 28));
        name = new QLineEdit(tab_5);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(150, 30, 113, 22));
        label_6 = new QLabel(tab_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 30, 61, 21));
        passwrd = new QLineEdit(tab_5);
        passwrd->setObjectName(QStringLiteral("passwrd"));
        passwrd->setGeometry(QRect(150, 80, 113, 22));
        label_7 = new QLabel(tab_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 80, 61, 21));
        object = new QLineEdit(tab_5);
        object->setObjectName(QStringLiteral("object"));
        object->setGeometry(QRect(150, 130, 113, 22));
        label_8 = new QLabel(tab_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(50, 130, 61, 21));
        recep = new QLineEdit(tab_5);
        recep->setObjectName(QStringLiteral("recep"));
        recep->setGeometry(QRect(170, 200, 113, 22));
        label_9 = new QLabel(tab_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 200, 91, 16));
        msg = new QPlainTextEdit(tab_5);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(70, 236, 361, 101));
        login->addTab(tab_5, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        login->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        login_2->setText(QApplication::translate("MainWindow", "login", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "username", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "password", Q_NULLPTR));
        login->setTabText(login->indexOf(tab_6), QApplication::translate("MainWindow", "login", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "id_emp", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "salaire", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "date_entre", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        login->setTabText(login->indexOf(tab), QApplication::translate("MainWindow", "Ajouter/Modifier", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "id_emp", Q_NULLPTR));
        login->setTabText(login->indexOf(tab_2), QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        trier->clear();
        trier->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "id_emp", Q_NULLPTR)
         << QApplication::translate("MainWindow", "salaire", Q_NULLPTR)
         << QApplication::translate("MainWindow", "date_entre", Q_NULLPTR)
        );
        pb_pdf->setText(QApplication::translate("MainWindow", " pdf", Q_NULLPTR));
        login->setTabText(login->indexOf(tab_3), QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        recherche_button->setText(QApplication::translate("MainWindow", "recherche", Q_NULLPTR));
        recherche_type->clear();
        recherche_type->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "id_emp", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "date_entre", Q_NULLPTR)
        );
        login->setTabText(login->indexOf(tab_4), QApplication::translate("MainWindow", "rechercher", Q_NULLPTR));
        sendmail->setText(QApplication::translate("MainWindow", "sendmail", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "password", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "object", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "email adresse", Q_NULLPTR));
        login->setTabText(login->indexOf(tab_5), QApplication::translate("MainWindow", "mailing", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
