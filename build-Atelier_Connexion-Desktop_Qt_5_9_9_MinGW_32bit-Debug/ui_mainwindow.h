/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *stackedWidgetPage1;
    QLabel *label_19;
    QPushButton *pa_pushButton_101;
    QPushButton *pa_pushButton_102;
    QLabel *Clocklabel;
    QWidget *stackedWidgetPage2;
    QLabel *label_2;
    QLineEdit *le_type1;
    QLineEdit *le_nom;
    QLabel *label;
    QPushButton *pb_ajouter;
    QLineEdit *le_id;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *le_cin;
    QTableView *tab_plainte_2;
    QLineEdit *le_id_supp;
    QPushButton *pb_supprimer;
    QLabel *label_3;
    QLabel *label_12;
    QPushButton *pb_modifier;
    QPushButton *pushButton;
    QLineEdit *le_recherche;
    QPushButton *recherche;
    QComboBox *rechercher;
    QComboBox *trie;
    QLabel *label_16;
    QPushButton *pushButton_pd1_pa;
    QPushButton *pushButton_excel1_pa;
    QLabel *label_20;
    QDateEdit *pb_dateEdit;
    QCalendarWidget *pb_calendarWidget;
    QProgressBar *progressBar100;
    QPushButton *pa_pushButton_4;
    QPushButton *pa_pushButton_103;
    QLabel *label_17;
    QWidget *stackedWidgetPage3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *le_idm;
    QLineEdit *le_status;
    QLineEdit *le_type;
    QLineEdit *le_prix;
    QPushButton *pb_ajouter2;
    QTableView *tab_amende_2;
    QLineEdit *le_idm_supp;
    QPushButton *pb_supprimer_1;
    QLabel *label_10;
    QLabel *label_14;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *recherche1;
    QLineEdit *le_recherche1;
    QComboBox *trie_2;
    QComboBox *rechercher_2;
    QLabel *label_15;
    QLabel *label_18;
    QPushButton *pushButton_excel1_pa_2;
    QPushButton *pushButton_pd1_pa_2;
    QPushButton *pa_pushButton_5;
    QPushButton *pa_pushButton_104;
    QProgressBar *progressBar101;
    QWidget *stackedWidgetPage4;
    QCustomPlot *customPlot;
    QTabWidget *pa_tabWidget_2;
    QWidget *tab_11;
    QPushButton *pa_pushButton_106;
    QLabel *label_21;
    QLabel *label_23;
    QWidget *stackedWidgetPage5;
    QCustomPlot *customPlot_2;
    QPushButton *pa_pushButton_105;
    QLabel *label_22;
    QLabel *label_24;
    QWidget *menu;
    QFrame *menu_frame;
    QLabel *menu_label_11;
    QPushButton *menu_pushButton_48;
    QPushButton *menu_pushButton_49;
    QPushButton *menu_pushButton_50;
    QPushButton *menu_pushButton_51;
    QPushButton *menu_pushButton_52;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 720);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(270, 0, 1011, 671));
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName(QStringLiteral("stackedWidgetPage1"));
        label_19 = new QLabel(stackedWidgetPage1);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(0, 0, 1341, 701));
        label_19->setStyleSheet(QStringLiteral("background:rgb(44, 83, 125)"));
        pa_pushButton_101 = new QPushButton(stackedWidgetPage1);
        pa_pushButton_101->setObjectName(QStringLiteral("pa_pushButton_101"));
        pa_pushButton_101->setGeometry(QRect(250, 190, 591, 101));
        QFont font;
        font.setPointSize(27);
        font.setUnderline(false);
        font.setStrikeOut(false);
        pa_pushButton_101->setFont(font);
        pa_pushButton_101->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid blue;\n"
"border-radius: 10px;\n"
"background-color: rgb(0, 211, 211);\n"
"border:2px solid #000;\n"
"}\n"
"QPushButton {\n"
"     color: #fff !important;\n"
"text-transform: uppercase;\n"
"text-decoration: none;\n"
"background: #00BFFF;\n"
"padding: 20px;\n"
"border-radius: 5px;\n"
"display: inline-block;\n"
"border: none;\n"
"transition: all 0.4s ease 0s;\n"
" }\n"
" QPushButton:hover {\n"
"     background: #000000;\n"
"letter-spacing: 1px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
" }\n"
""));
        pa_pushButton_102 = new QPushButton(stackedWidgetPage1);
        pa_pushButton_102->setObjectName(QStringLiteral("pa_pushButton_102"));
        pa_pushButton_102->setGeometry(QRect(250, 360, 591, 101));
        pa_pushButton_102->setFont(font);
        pa_pushButton_102->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid blue;\n"
"border-radius: 10px;\n"
"background-color: rgb(0, 211, 211);\n"
"border:2px solid #000;\n"
"}\n"
"QPushButton {\n"
"     color: #fff !important;\n"
"text-transform: uppercase;\n"
"text-decoration: none;\n"
"background: #00BFFF;\n"
"padding: 20px;\n"
"border-radius: 5px;\n"
"display: inline-block;\n"
"border: none;\n"
"transition: all 0.4s ease 0s;\n"
" }\n"
" QPushButton:hover {\n"
"     background: #000000;\n"
"letter-spacing: 1px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
" }\n"
""));
        Clocklabel = new QLabel(stackedWidgetPage1);
        Clocklabel->setObjectName(QStringLiteral("Clocklabel"));
        Clocklabel->setGeometry(QRect(10, 20, 181, 41));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(61, 65, 61, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(91, 97, 91, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(76, 81, 76, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(30, 32, 30, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(40, 43, 40, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush8(QColor(255, 255, 255, 128));
        brush8.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        QBrush brush9(QColor(255, 255, 255, 128));
        brush9.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        QBrush brush10(QColor(255, 255, 255, 128));
        brush10.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        Clocklabel->setPalette(palette);
        QFont font1;
        font1.setFamily(QStringLiteral("Sitka"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        Clocklabel->setFont(font1);
        Clocklabel->setContextMenuPolicy(Qt::NoContextMenu);
        Clocklabel->setLayoutDirection(Qt::LeftToRight);
        Clocklabel->setStyleSheet(QStringLiteral(""));
        Clocklabel->setFrameShape(QFrame::NoFrame);
        Clocklabel->setFrameShadow(QFrame::Sunken);
        Clocklabel->setLineWidth(4);
        Clocklabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        stackedWidget->addWidget(stackedWidgetPage1);
        stackedWidgetPage2 = new QWidget();
        stackedWidgetPage2->setObjectName(QStringLiteral("stackedWidgetPage2"));
        label_2 = new QLabel(stackedWidgetPage2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 123, 61, 21));
        le_type1 = new QLineEdit(stackedWidgetPage2);
        le_type1->setObjectName(QStringLiteral("le_type1"));
        le_type1->setGeometry(QRect(110, 123, 113, 20));
        le_type1->setStyleSheet(QStringLiteral("background:rgb(153, 196, 242)"));
        le_nom = new QLineEdit(stackedWidgetPage2);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(110, 83, 113, 20));
        le_nom->setStyleSheet(QStringLiteral("background:rgb(153, 196, 242)"));
        label = new QLabel(stackedWidgetPage2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 83, 81, 21));
        pb_ajouter = new QPushButton(stackedWidgetPage2);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(280, 73, 75, 23));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        pb_ajouter->setFont(font2);
        pb_ajouter->setStyleSheet(QLatin1String("QPushButton{\n"
"border: 0px ;\n"
"border-radius: 10px;\n"
"background:rgb(211, 211, 0)\n"
"}\n"
"QPushButton:hover {\n"
"     background: #434343;\n"
"letter-spacing: 1px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
"color:white;\n"
" }\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: #282828;\n"
"\n"
"}"));
        le_id = new QLineEdit(stackedWidgetPage2);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(110, 53, 113, 20));
        le_id->setStyleSheet(QStringLiteral("background:rgb(153, 196, 242)"));
        label_4 = new QLabel(stackedWidgetPage2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 53, 47, 21));
        label_5 = new QLabel(stackedWidgetPage2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 153, 47, 31));
        le_cin = new QLineEdit(stackedWidgetPage2);
        le_cin->setObjectName(QStringLiteral("le_cin"));
        le_cin->setGeometry(QRect(110, 163, 113, 20));
        le_cin->setStyleSheet(QStringLiteral("background:rgb(153, 196, 242)"));
        tab_plainte_2 = new QTableView(stackedWidgetPage2);
        tab_plainte_2->setObjectName(QStringLiteral("tab_plainte_2"));
        tab_plainte_2->setGeometry(QRect(380, 250, 581, 321));
        tab_plainte_2->setStyleSheet(QStringLiteral("background:rgb(153, 196, 242)"));
        le_id_supp = new QLineEdit(stackedWidgetPage2);
        le_id_supp->setObjectName(QStringLiteral("le_id_supp"));
        le_id_supp->setGeometry(QRect(240, 250, 113, 20));
        le_id_supp->setStyleSheet(QStringLiteral("background:rgb(153, 196, 242)"));
        pb_supprimer = new QPushButton(stackedWidgetPage2);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(120, 250, 81, 20));
        pb_supprimer->setStyleSheet(QLatin1String("QPushButton{\n"
"border: 0px ;\n"
"border-radius: 10px;\n"
"background:rgb(211, 211, 211)\n"
"}\n"
"QPushButton:hover {\n"
"     background: #434343;\n"
"letter-spacing: 1px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
"color:white;\n"
" }\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: #282828;\n"
"\n"
"}"));
        label_3 = new QLabel(stackedWidgetPage2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 250, 71, 31));
        label_12 = new QLabel(stackedWidgetPage2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(520, 30, 221, 51));
        QFont font3;
        font3.setPointSize(15);
        label_12->setFont(font3);
        label_12->setStyleSheet(QStringLiteral("color:rgb(0, 170, 255)"));
        pb_modifier = new QPushButton(stackedWidgetPage2);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(280, 153, 80, 22));
        pb_modifier->setFont(font2);
        pb_modifier->setStyleSheet(QLatin1String("QPushButton{\n"
"border: 0px ;\n"
"border-radius: 10px;\n"
"background:rgb(211, 211, 211)\n"
"}\n"
"QPushButton:hover {\n"
"     background: #434343;\n"
"letter-spacing: 1px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
"color:white;\n"
" }\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: #282828;\n"
"\n"
"}"));
        pushButton = new QPushButton(stackedWidgetPage2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 113, 80, 21));
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border: 0px ;\n"
"border-radius: 10px;\n"
"background:rgb(211, 211, 211)\n"
"}\n"
"QPushButton:hover {\n"
"     background: #434343;\n"
"letter-spacing: 1px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
"color:white;\n"
" }\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: #282828;\n"
"\n"
"}"));
        le_recherche = new QLineEdit(stackedWidgetPage2);
        le_recherche->setObjectName(QStringLiteral("le_recherche"));
        le_recherche->setGeometry(QRect(510, 183, 161, 21));
        le_recherche->setStyleSheet(QStringLiteral("background:rgb(153, 196, 242)"));
        recherche = new QPushButton(stackedWidgetPage2);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(690, 183, 80, 22));
        recherche->setStyleSheet(QLatin1String("QPushButton{\n"
"border: 0px ;\n"
"border-radius: 10px;\n"
"background:rgb(211, 211, 211)\n"
"}\n"
"QPushButton:hover {\n"
"     background: #434343;\n"
"letter-spacing: 1px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
"color:white;\n"
" }\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: #282828;\n"
"\n"
"}"));
        rechercher = new QComboBox(stackedWidgetPage2);
        rechercher->setObjectName(QStringLiteral("rechercher"));
        rechercher->setGeometry(QRect(410, 183, 73, 22));
        trie = new QComboBox(stackedWidgetPage2);
        trie->setObjectName(QStringLiteral("trie"));
        trie->setGeometry(QRect(820, 160, 73, 22));
        label_16 = new QLabel(stackedWidgetPage2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(900, 160, 71, 21));
        pushButton_pd1_pa = new QPushButton(stackedWidgetPage2);
        pushButton_pd1_pa->setObjectName(QStringLiteral("pushButton_pd1_pa"));
        pushButton_pd1_pa->setGeometry(QRect(80, 290, 41, 41));
        pushButton_pd1_pa->setStyleSheet(QStringLiteral("border-image:url(:/img/img/Metro-Sd-Blue.ico)"));
        pushButton_excel1_pa = new QPushButton(stackedWidgetPage2);
        pushButton_excel1_pa->setObjectName(QStringLiteral("pushButton_excel1_pa"));
        pushButton_excel1_pa->setGeometry(QRect(160, 290, 41, 41));
        pushButton_excel1_pa->setStyleSheet(QStringLiteral("border-image:url(:/img/img/butttexcel.png)"));
        label_20 = new QLabel(stackedWidgetPage2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(70, 193, 47, 31));
        pb_dateEdit = new QDateEdit(stackedWidgetPage2);
        pb_dateEdit->setObjectName(QStringLiteral("pb_dateEdit"));
        pb_dateEdit->setGeometry(QRect(110, 193, 151, 20));
        pb_dateEdit->setStyleSheet(QStringLiteral("background:rgb(153, 196, 242)"));
        pb_dateEdit->setDateTime(QDateTime(QDate(2021, 1, 1), QTime(0, 0, 0)));
        pb_dateEdit->setCalendarPopup(false);
        pb_dateEdit->setDate(QDate(2021, 1, 1));
        pb_calendarWidget = new QCalendarWidget(stackedWidgetPage2);
        pb_calendarWidget->setObjectName(QStringLiteral("pb_calendarWidget"));
        pb_calendarWidget->setGeometry(QRect(30, 350, 331, 211));
        pb_calendarWidget->setStyleSheet(QLatin1String("QPushButton{\n"
"border: 0px ;\n"
"border-radius: 10px;\n"
"background:rgb(211, 211, 211)\n"
"}\n"
"QPushButton:hover {\n"
"     background: #434343;\n"
"letter-spacing: 1px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
"color:white;\n"
" }\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: #282828;\n"
"\n"
"}"));
        progressBar100 = new QProgressBar(stackedWidgetPage2);
        progressBar100->setObjectName(QStringLiteral("progressBar100"));
        progressBar100->setGeometry(QRect(240, 300, 118, 23));
        progressBar100->setValue(0);
        pa_pushButton_4 = new QPushButton(stackedWidgetPage2);
        pa_pushButton_4->setObjectName(QStringLiteral("pa_pushButton_4"));
        pa_pushButton_4->setGeometry(QRect(820, 70, 101, 41));
        pa_pushButton_4->setStyleSheet(QStringLiteral("border-image:url(:/img/img/satistique.png)"));
        pa_pushButton_103 = new QPushButton(stackedWidgetPage2);
        pa_pushButton_103->setObjectName(QStringLiteral("pa_pushButton_103"));
        pa_pushButton_103->setGeometry(QRect(870, 610, 61, 41));
        pa_pushButton_103->setStyleSheet(QStringLiteral("border-image:url(:/img/img/butretour.png)"));
        label_17 = new QLabel(stackedWidgetPage2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(-1, 0, 1021, 731));
        label_17->setStyleSheet(QStringLiteral("background:rgb(44, 83, 125)"));
        stackedWidget->addWidget(stackedWidgetPage2);
        label_17->raise();
        label_2->raise();
        le_type1->raise();
        le_nom->raise();
        label->raise();
        pb_ajouter->raise();
        le_id->raise();
        label_4->raise();
        label_5->raise();
        le_cin->raise();
        tab_plainte_2->raise();
        le_id_supp->raise();
        pb_supprimer->raise();
        label_3->raise();
        label_12->raise();
        pb_modifier->raise();
        pushButton->raise();
        le_recherche->raise();
        recherche->raise();
        rechercher->raise();
        trie->raise();
        label_16->raise();
        pushButton_pd1_pa->raise();
        pushButton_excel1_pa->raise();
        label_20->raise();
        pb_dateEdit->raise();
        pb_calendarWidget->raise();
        progressBar100->raise();
        pa_pushButton_4->raise();
        pa_pushButton_103->raise();
        stackedWidgetPage3 = new QWidget();
        stackedWidgetPage3->setObjectName(QStringLiteral("stackedWidgetPage3"));
        label_6 = new QLabel(stackedWidgetPage3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 40, 51, 21));
        label_7 = new QLabel(stackedWidgetPage3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 80, 51, 21));
        label_8 = new QLabel(stackedWidgetPage3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(50, 120, 61, 31));
        label_9 = new QLabel(stackedWidgetPage3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 160, 61, 21));
        le_idm = new QLineEdit(stackedWidgetPage3);
        le_idm->setObjectName(QStringLiteral("le_idm"));
        le_idm->setGeometry(QRect(110, 40, 113, 21));
        le_idm->setStyleSheet(QStringLiteral("background:rgb(153, 196, 242)"));
        le_status = new QLineEdit(stackedWidgetPage3);
        le_status->setObjectName(QStringLiteral("le_status"));
        le_status->setGeometry(QRect(110, 80, 113, 21));
        le_status->setStyleSheet(QStringLiteral("background:rgb(153, 196, 242)"));
        le_type = new QLineEdit(stackedWidgetPage3);
        le_type->setObjectName(QStringLiteral("le_type"));
        le_type->setGeometry(QRect(110, 120, 113, 21));
        le_type->setStyleSheet(QStringLiteral("background:rgb(153, 196, 242)"));
        le_prix = new QLineEdit(stackedWidgetPage3);
        le_prix->setObjectName(QStringLiteral("le_prix"));
        le_prix->setGeometry(QRect(110, 160, 113, 21));
        le_prix->setStyleSheet(QStringLiteral("background:rgb(153, 196, 242)"));
        pb_ajouter2 = new QPushButton(stackedWidgetPage3);
        pb_ajouter2->setObjectName(QStringLiteral("pb_ajouter2"));
        pb_ajouter2->setGeometry(QRect(310, 50, 81, 22));
        pb_ajouter2->setStyleSheet(QLatin1String("QPushButton{\n"
"border: 0px ;\n"
"border-radius: 10px;\n"
"background:rgb(211, 211, 211)\n"
"}\n"
"QPushButton:hover {\n"
"     background: #434343;\n"
"letter-spacing: 1px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
"color:white;\n"
" }\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: #282828;\n"
"\n"
"}"));
        tab_amende_2 = new QTableView(stackedWidgetPage3);
        tab_amende_2->setObjectName(QStringLiteral("tab_amende_2"));
        tab_amende_2->setGeometry(QRect(420, 280, 541, 291));
        tab_amende_2->setStyleSheet(QStringLiteral("background:rgb(153, 196, 242)"));
        le_idm_supp = new QLineEdit(stackedWidgetPage3);
        le_idm_supp->setObjectName(QStringLiteral("le_idm_supp"));
        le_idm_supp->setGeometry(QRect(300, 190, 113, 21));
        le_idm_supp->setStyleSheet(QStringLiteral("background:rgb(153, 196, 242)"));
        pb_supprimer_1 = new QPushButton(stackedWidgetPage3);
        pb_supprimer_1->setObjectName(QStringLiteral("pb_supprimer_1"));
        pb_supprimer_1->setGeometry(QRect(310, 160, 80, 22));
        pb_supprimer_1->setStyleSheet(QLatin1String("QPushButton{\n"
"border: 0px ;\n"
"border-radius: 10px;\n"
"background:rgb(211, 211, 211)\n"
"}\n"
"QPushButton:hover {\n"
"     background: #434343;\n"
"letter-spacing: 1px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
"color:white;\n"
" }\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: #282828;\n"
"\n"
"}"));
        label_10 = new QLabel(stackedWidgetPage3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(280, 190, 47, 21));
        label_14 = new QLabel(stackedWidgetPage3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(500, 20, 201, 31));
        label_14->setStyleSheet(QStringLiteral("color:rgb(0, 170, 255)"));
        pushButton_2 = new QPushButton(stackedWidgetPage3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 120, 80, 22));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{\n"
"border: 0px ;\n"
"border-radius: 10px;\n"
"background:rgb(211, 211, 211)\n"
"}\n"
"QPushButton:hover {\n"
"     background: #434343;\n"
"letter-spacing: 1px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
"color:white;\n"
" }\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: #282828;\n"
"\n"
"}"));
        pushButton_3 = new QPushButton(stackedWidgetPage3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 90, 80, 22));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton{\n"
"border: 0px ;\n"
"border-radius: 10px;\n"
"background:rgb(211, 211, 211)\n"
"}\n"
"QPushButton:hover {\n"
"     background: #434343;\n"
"letter-spacing: 1px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
"color:white;\n"
" }\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: #282828;\n"
"\n"
"}"));
        recherche1 = new QPushButton(stackedWidgetPage3);
        recherche1->setObjectName(QStringLiteral("recherche1"));
        recherche1->setGeometry(QRect(720, 210, 111, 31));
        recherche1->setStyleSheet(QLatin1String("QPushButton{\n"
"border: 0px ;\n"
"border-radius: 10px;\n"
"background:rgb(211, 211, 211)\n"
"}\n"
"QPushButton:hover {\n"
"     background: #434343;\n"
"letter-spacing: 1px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
"color:white;\n"
" }\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: #282828;\n"
"\n"
"}"));
        le_recherche1 = new QLineEdit(stackedWidgetPage3);
        le_recherche1->setObjectName(QStringLiteral("le_recherche1"));
        le_recherche1->setGeometry(QRect(560, 209, 151, 31));
        le_recherche1->setStyleSheet(QStringLiteral("background:rgb(153, 196, 242)"));
        trie_2 = new QComboBox(stackedWidgetPage3);
        trie_2->setObjectName(QStringLiteral("trie_2"));
        trie_2->setGeometry(QRect(792, 151, 81, 31));
        rechercher_2 = new QComboBox(stackedWidgetPage3);
        rechercher_2->setObjectName(QStringLiteral("rechercher_2"));
        rechercher_2->setGeometry(QRect(480, 209, 81, 31));
        label_15 = new QLabel(stackedWidgetPage3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(880, 150, 61, 31));
        label_18 = new QLabel(stackedWidgetPage3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(-360, -20, 1461, 731));
        label_18->setStyleSheet(QStringLiteral("background:rgb(44, 83, 125)"));
        pushButton_excel1_pa_2 = new QPushButton(stackedWidgetPage3);
        pushButton_excel1_pa_2->setObjectName(QStringLiteral("pushButton_excel1_pa_2"));
        pushButton_excel1_pa_2->setGeometry(QRect(140, 270, 61, 31));
        pushButton_excel1_pa_2->setStyleSheet(QStringLiteral("border-image:url(:/img/img/butttexcel.png)"));
        pushButton_pd1_pa_2 = new QPushButton(stackedWidgetPage3);
        pushButton_pd1_pa_2->setObjectName(QStringLiteral("pushButton_pd1_pa_2"));
        pushButton_pd1_pa_2->setGeometry(QRect(50, 270, 51, 31));
        pushButton_pd1_pa_2->setStyleSheet(QStringLiteral("border-image:url(:/img/img/Metro-Sd-Blue.ico)"));
        pa_pushButton_5 = new QPushButton(stackedWidgetPage3);
        pa_pushButton_5->setObjectName(QStringLiteral("pa_pushButton_5"));
        pa_pushButton_5->setGeometry(QRect(800, 40, 91, 51));
        pa_pushButton_5->setStyleSheet(QStringLiteral("border-image:url(:/img/img/satistique.png)"));
        pa_pushButton_104 = new QPushButton(stackedWidgetPage3);
        pa_pushButton_104->setObjectName(QStringLiteral("pa_pushButton_104"));
        pa_pushButton_104->setGeometry(QRect(860, 590, 71, 41));
        pa_pushButton_104->setStyleSheet(QStringLiteral("border-image:url(:/img/img/butretour.png)"));
        progressBar101 = new QProgressBar(stackedWidgetPage3);
        progressBar101->setObjectName(QStringLiteral("progressBar101"));
        progressBar101->setGeometry(QRect(300, 230, 118, 23));
        progressBar101->setValue(0);
        stackedWidget->addWidget(stackedWidgetPage3);
        label_18->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        le_idm->raise();
        le_status->raise();
        le_type->raise();
        le_prix->raise();
        pb_ajouter2->raise();
        tab_amende_2->raise();
        le_idm_supp->raise();
        pb_supprimer_1->raise();
        label_10->raise();
        label_14->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        recherche1->raise();
        le_recherche1->raise();
        trie_2->raise();
        rechercher_2->raise();
        label_15->raise();
        pushButton_excel1_pa_2->raise();
        pushButton_pd1_pa_2->raise();
        pa_pushButton_5->raise();
        pa_pushButton_104->raise();
        progressBar101->raise();
        stackedWidgetPage4 = new QWidget();
        stackedWidgetPage4->setObjectName(QStringLiteral("stackedWidgetPage4"));
        customPlot = new QCustomPlot(stackedWidgetPage4);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(190, 120, 681, 421));
        pa_tabWidget_2 = new QTabWidget(stackedWidgetPage4);
        pa_tabWidget_2->setObjectName(QStringLiteral("pa_tabWidget_2"));
        pa_tabWidget_2->setGeometry(QRect(190, 100, 411, 21));
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        pa_tabWidget_2->addTab(tab_11, QString());
        pa_pushButton_106 = new QPushButton(stackedWidgetPage4);
        pa_pushButton_106->setObjectName(QStringLiteral("pa_pushButton_106"));
        pa_pushButton_106->setGeometry(QRect(820, 570, 75, 23));
        label_21 = new QLabel(stackedWidgetPage4);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(0, 0, 1021, 731));
        label_21->setStyleSheet(QStringLiteral("background:rgb(44, 83, 125)"));
        label_23 = new QLabel(stackedWidgetPage4);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(410, 40, 201, 31));
        label_23->setStyleSheet(QStringLiteral("color:rgb(0, 170, 255)"));
        stackedWidget->addWidget(stackedWidgetPage4);
        label_21->raise();
        customPlot->raise();
        pa_tabWidget_2->raise();
        pa_pushButton_106->raise();
        label_23->raise();
        stackedWidgetPage5 = new QWidget();
        stackedWidgetPage5->setObjectName(QStringLiteral("stackedWidgetPage5"));
        customPlot_2 = new QCustomPlot(stackedWidgetPage5);
        customPlot_2->setObjectName(QStringLiteral("customPlot_2"));
        customPlot_2->setGeometry(QRect(190, 120, 711, 441));
        pa_pushButton_105 = new QPushButton(stackedWidgetPage5);
        pa_pushButton_105->setObjectName(QStringLiteral("pa_pushButton_105"));
        pa_pushButton_105->setGeometry(QRect(750, 600, 75, 23));
        label_22 = new QLabel(stackedWidgetPage5);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(0, 0, 1021, 731));
        label_22->setStyleSheet(QStringLiteral("background:rgb(44, 83, 125)"));
        label_24 = new QLabel(stackedWidgetPage5);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(430, 50, 201, 31));
        label_24->setStyleSheet(QStringLiteral("color:rgb(0, 170, 255)"));
        stackedWidget->addWidget(stackedWidgetPage5);
        label_22->raise();
        customPlot_2->raise();
        pa_pushButton_105->raise();
        label_24->raise();
        menu = new QWidget(centralWidget);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setEnabled(true);
        menu->setGeometry(QRect(10, -10, 261, 741));
        menu->setStyleSheet(QStringLiteral(""));
        menu_frame = new QFrame(menu);
        menu_frame->setObjectName(QStringLiteral("menu_frame"));
        menu_frame->setGeometry(QRect(-10, 0, 271, 681));
        menu_frame->setStyleSheet(QLatin1String("background: #00BFFF;\n"
""));
        menu_frame->setFrameShape(QFrame::StyledPanel);
        menu_frame->setFrameShadow(QFrame::Raised);
        menu_label_11 = new QLabel(menu_frame);
        menu_label_11->setObjectName(QStringLiteral("menu_label_11"));
        menu_label_11->setGeometry(QRect(20, 30, 221, 141));
        menu_label_11->setStyleSheet(QStringLiteral("border-image:url(:/img/img/logosmartpolice.png)"));
        menu_pushButton_48 = new QPushButton(menu_frame);
        menu_pushButton_48->setObjectName(QStringLiteral("menu_pushButton_48"));
        menu_pushButton_48->setGeometry(QRect(10, 230, 261, 61));
        QFont font4;
        font4.setPointSize(15);
        font4.setBold(true);
        font4.setUnderline(false);
        font4.setWeight(75);
        font4.setStrikeOut(false);
        menu_pushButton_48->setFont(font4);
        menu_pushButton_48->setStyleSheet(QLatin1String("QPushButton {\n"
"color: #fff !important;\n"
"text-decoration: none;\n"
"background: #00BFFF;\n"
"padding: 10px;\n"
"border-radius: 5px;\n"
"display: inline-block;\n"
"border: none;\n"
"transition: all 0.4s ease 0s;\n"
" }\n"
" QPushButton:hover {\n"
"     background: rgb(0,0 , 51);\n"
"color:white;\n"
"letter-spacing: 2px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
" }border: 10px; border-raduis:100px; border-color:white;background:rgb(252, 252, 252);"));
        menu_pushButton_49 = new QPushButton(menu_frame);
        menu_pushButton_49->setObjectName(QStringLiteral("menu_pushButton_49"));
        menu_pushButton_49->setGeometry(QRect(10, 320, 261, 51));
        QFont font5;
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setUnderline(false);
        font5.setWeight(75);
        font5.setStrikeOut(false);
        menu_pushButton_49->setFont(font5);
        menu_pushButton_49->setStyleSheet(QLatin1String("QPushButton {\n"
"color: #fff !important;\n"
"text-decoration: none;\n"
"background: #00BFFF;\n"
"padding: 10px;\n"
"border-radius: 5px;\n"
"display: inline-block;\n"
"border: none;\n"
"transition: all 0.4s ease 0s;\n"
" }\n"
" QPushButton:hover {\n"
"     background: rgb(0,0 , 51);\n"
"color:white;\n"
"letter-spacing: 2px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
" }border: 10px; border-raduis:100px; border-color:white;background:rgb(252, 252, 252);"));
        menu_pushButton_50 = new QPushButton(menu_frame);
        menu_pushButton_50->setObjectName(QStringLiteral("menu_pushButton_50"));
        menu_pushButton_50->setGeometry(QRect(10, 400, 261, 51));
        menu_pushButton_50->setFont(font5);
        menu_pushButton_50->setStyleSheet(QLatin1String("QPushButton {\n"
"color: #fff !important;\n"
"text-decoration: none;\n"
"background: #00BFFF;\n"
"padding: 10px;\n"
"border-radius: 5px;\n"
"display: inline-block;\n"
"border: none;\n"
"transition: all 0.4s ease 0s;\n"
" }\n"
" QPushButton:hover {\n"
"     background: rgb(0,0 , 51);\n"
"color:white;\n"
"letter-spacing: 3px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
" }border: 10px; border-raduis:100px; border-color:white;background:rgb(252, 252, 252);"));
        menu_pushButton_51 = new QPushButton(menu_frame);
        menu_pushButton_51->setObjectName(QStringLiteral("menu_pushButton_51"));
        menu_pushButton_51->setGeometry(QRect(10, 480, 261, 51));
        menu_pushButton_51->setFont(font5);
        menu_pushButton_51->setStyleSheet(QLatin1String("QPushButton {\n"
"color: #fff !important;\n"
"text-decoration: none;\n"
"background: #00BFFF;\n"
"padding: 10px;\n"
"border-radius: 5px;\n"
"display: inline-block;\n"
"border: none;\n"
"transition: all 0.4s ease 0s;\n"
" }\n"
" QPushButton:hover {\n"
"     background: rgb(0,0 , 51);\n"
"color:white;\n"
"letter-spacing: 3px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
" }border: 10px; border-raduis:100px; border-color:white;background:rgb(252, 252, 252);"));
        menu_pushButton_52 = new QPushButton(menu_frame);
        menu_pushButton_52->setObjectName(QStringLiteral("menu_pushButton_52"));
        menu_pushButton_52->setGeometry(QRect(10, 560, 261, 51));
        menu_pushButton_52->setFont(font5);
        menu_pushButton_52->setStyleSheet(QLatin1String("QPushButton {\n"
"color: #fff !important;\n"
"text-decoration: none;\n"
"background: #00BFFF;\n"
"padding: 10px;\n"
"border-radius: 5px;\n"
"display: inline-block;\n"
"border: none;\n"
"transition: all 0.4s ease 0s;\n"
" }\n"
" QPushButton:hover {\n"
"     background: rgb(0,0 , 51);\n"
"color:white;\n"
"letter-spacing: 3px;\n"
"-webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"-moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);\n"
"box-shadow: 5px 40px -10px rgba(0,0,0,0.57);\n"
"transition: all 0.4s ease 0s;\n"
" }border: 10px; border-raduis:100px; border-color:white;background:rgb(252, 252, 252);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        pa_tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        label_19->setText(QString());
        pa_pushButton_101->setText(QApplication::translate("MainWindow", "Plainte", Q_NULLPTR));
        pa_pushButton_102->setText(QApplication::translate("MainWindow", "Amende", Q_NULLPTR));
        Clocklabel->setText(QApplication::translate("MainWindow", "TexT", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">type</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Nom accuse</span></p></body></html>", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        le_id->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">id</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">cin</span></p></body></html>", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">id</span></p></body></html>", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt;\">Afficher Plainte</span></p></body></html>", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("MainWindow", "recuperer", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        recherche->setText(QApplication::translate("MainWindow", "recherche", Q_NULLPTR));
        rechercher->clear();
        rechercher->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "id", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "type", Q_NULLPTR)
         << QApplication::translate("MainWindow", "cin", Q_NULLPTR)
        );
        trie->clear();
        trie->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "id", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "type", Q_NULLPTR)
         << QApplication::translate("MainWindow", "cin", Q_NULLPTR)
        );
        label_16->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">sort by</span></p></body></html>", Q_NULLPTR));
        pushButton_pd1_pa->setText(QString());
        pushButton_excel1_pa->setText(QString());
        label_20->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Date</span></p></body></html>", Q_NULLPTR));
        pa_pushButton_4->setText(QString());
        pa_pushButton_103->setText(QString());
        label_17->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">id</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">status</span></p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">type</span></p></body></html>", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">prix</span></p></body></html>", Q_NULLPTR));
        pb_ajouter2->setText(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        pb_supprimer_1->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">id</span></p></body></html>", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Afficher amende</span></p></body></html>", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "recuperer", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        recherche1->setText(QApplication::translate("MainWindow", "Recherche", Q_NULLPTR));
        trie_2->clear();
        trie_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "id_am", Q_NULLPTR)
         << QApplication::translate("MainWindow", "status", Q_NULLPTR)
         << QApplication::translate("MainWindow", "type", Q_NULLPTR)
         << QApplication::translate("MainWindow", "prix_am", Q_NULLPTR)
        );
        rechercher_2->clear();
        rechercher_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "idm", Q_NULLPTR)
         << QApplication::translate("MainWindow", "status", Q_NULLPTR)
         << QApplication::translate("MainWindow", "type", Q_NULLPTR)
         << QApplication::translate("MainWindow", "prix_am", Q_NULLPTR)
        );
        label_15->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">sort by</span></p></body></html>", Q_NULLPTR));
        label_18->setText(QString());
        pushButton_excel1_pa_2->setText(QString());
        pushButton_pd1_pa_2->setText(QString());
        pa_pushButton_5->setText(QString());
        pa_pushButton_104->setText(QString());
        pa_tabWidget_2->setTabText(pa_tabWidget_2->indexOf(tab_11), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        pa_pushButton_106->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        label_21->setText(QString());
        label_23->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Statistiques:</span></p><p><br/></p></body></html>", Q_NULLPTR));
        pa_pushButton_105->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        label_22->setText(QString());
        label_24->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Statistiques:</span></p><p><br/></p></body></html>", Q_NULLPTR));
        menu_label_11->setText(QApplication::translate("MainWindow", "hj", Q_NULLPTR));
        menu_pushButton_48->setText(QApplication::translate("MainWindow", "Plainte et Amende", Q_NULLPTR));
        menu_pushButton_49->setText(QApplication::translate("MainWindow", "Materiel et Fournisseur", Q_NULLPTR));
        menu_pushButton_50->setText(QApplication::translate("MainWindow", "Plainte et Amende", Q_NULLPTR));
        menu_pushButton_51->setText(QApplication::translate("MainWindow", "Plainte et Amende", Q_NULLPTR));
        menu_pushButton_52->setText(QApplication::translate("MainWindow", "Plainte et Amende", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
