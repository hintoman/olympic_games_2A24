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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTabWidget *tabWidget_2;
    QWidget *tab_ajouter_emp;
    QLabel *label_id_c;
    QLabel *label_cin_c;
    QLabel *label_nom_c;
    QLabel *label_prenom_c;
    QLineEdit *lineEdit_code;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_date;
    QLineEdit *lineEdit_type;
    QPushButton *pushButton_ajouter_E;
    QPushButton *pushButton_quitter;
    QPushButton *pushButton_modifier_E;
    QPushButton *pushButton_rafraichir_E;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_ville;
    QLineEdit *lineEdit_prix;
    QWidget *tab_afficher_emp;
    QTableView *tableView;
    QPushButton *pushButton_supprimer_E;
    QPushButton *pushButton_rafraichir;
    QPushButton *pushButton_2_quitter;
    QPushButton *pushButton_tri_codee;
    QPushButton *pushButton_tri_nom;
    QPushButton *pushButton_tri_prix;
    QLineEdit *lineEdit_chercher_type;
    QLineEdit *lineEdit_chercher_ville;
    QPushButton *pushButton_chercher_type;
    QPushButton *pushButton_chercher_ville;
    QPushButton *pushButton_pdf;
    QWidget *tab_2;
    QCustomPlot *customPlot;
    QPushButton *pushButton_statistique;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(50, 40, 651, 361));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 651, 341));
        tab_ajouter_emp = new QWidget();
        tab_ajouter_emp->setObjectName(QStringLiteral("tab_ajouter_emp"));
        label_id_c = new QLabel(tab_ajouter_emp);
        label_id_c->setObjectName(QStringLiteral("label_id_c"));
        label_id_c->setGeometry(QRect(50, 30, 47, 13));
        label_cin_c = new QLabel(tab_ajouter_emp);
        label_cin_c->setObjectName(QStringLiteral("label_cin_c"));
        label_cin_c->setGeometry(QRect(50, 70, 47, 13));
        label_nom_c = new QLabel(tab_ajouter_emp);
        label_nom_c->setObjectName(QStringLiteral("label_nom_c"));
        label_nom_c->setGeometry(QRect(50, 110, 47, 13));
        label_prenom_c = new QLabel(tab_ajouter_emp);
        label_prenom_c->setObjectName(QStringLiteral("label_prenom_c"));
        label_prenom_c->setGeometry(QRect(50, 150, 71, 16));
        lineEdit_code = new QLineEdit(tab_ajouter_emp);
        lineEdit_code->setObjectName(QStringLiteral("lineEdit_code"));
        lineEdit_code->setGeometry(QRect(140, 30, 113, 20));
        lineEdit_nom = new QLineEdit(tab_ajouter_emp);
        lineEdit_nom->setObjectName(QStringLiteral("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(140, 70, 113, 20));
        lineEdit_date = new QLineEdit(tab_ajouter_emp);
        lineEdit_date->setObjectName(QStringLiteral("lineEdit_date"));
        lineEdit_date->setGeometry(QRect(140, 110, 113, 20));
        lineEdit_type = new QLineEdit(tab_ajouter_emp);
        lineEdit_type->setObjectName(QStringLiteral("lineEdit_type"));
        lineEdit_type->setGeometry(QRect(140, 150, 113, 20));
        pushButton_ajouter_E = new QPushButton(tab_ajouter_emp);
        pushButton_ajouter_E->setObjectName(QStringLiteral("pushButton_ajouter_E"));
        pushButton_ajouter_E->setGeometry(QRect(370, 280, 75, 23));
        pushButton_quitter = new QPushButton(tab_ajouter_emp);
        pushButton_quitter->setObjectName(QStringLiteral("pushButton_quitter"));
        pushButton_quitter->setGeometry(QRect(550, 280, 75, 23));
        pushButton_modifier_E = new QPushButton(tab_ajouter_emp);
        pushButton_modifier_E->setObjectName(QStringLiteral("pushButton_modifier_E"));
        pushButton_modifier_E->setGeometry(QRect(460, 280, 75, 23));
        pushButton_rafraichir_E = new QPushButton(tab_ajouter_emp);
        pushButton_rafraichir_E->setObjectName(QStringLiteral("pushButton_rafraichir_E"));
        pushButton_rafraichir_E->setGeometry(QRect(560, 10, 75, 23));
        label = new QLabel(tab_ajouter_emp);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 190, 47, 13));
        label_2 = new QLabel(tab_ajouter_emp);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 230, 47, 13));
        lineEdit_ville = new QLineEdit(tab_ajouter_emp);
        lineEdit_ville->setObjectName(QStringLiteral("lineEdit_ville"));
        lineEdit_ville->setGeometry(QRect(140, 190, 113, 20));
        lineEdit_prix = new QLineEdit(tab_ajouter_emp);
        lineEdit_prix->setObjectName(QStringLiteral("lineEdit_prix"));
        lineEdit_prix->setGeometry(QRect(140, 230, 113, 20));
        tabWidget_2->addTab(tab_ajouter_emp, QString());
        tab_afficher_emp = new QWidget();
        tab_afficher_emp->setObjectName(QStringLiteral("tab_afficher_emp"));
        tableView = new QTableView(tab_afficher_emp);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 40, 531, 231));
        pushButton_supprimer_E = new QPushButton(tab_afficher_emp);
        pushButton_supprimer_E->setObjectName(QStringLiteral("pushButton_supprimer_E"));
        pushButton_supprimer_E->setGeometry(QRect(560, 40, 75, 23));
        pushButton_rafraichir = new QPushButton(tab_afficher_emp);
        pushButton_rafraichir->setObjectName(QStringLiteral("pushButton_rafraichir"));
        pushButton_rafraichir->setGeometry(QRect(560, 10, 75, 23));
        pushButton_2_quitter = new QPushButton(tab_afficher_emp);
        pushButton_2_quitter->setObjectName(QStringLiteral("pushButton_2_quitter"));
        pushButton_2_quitter->setGeometry(QRect(560, 280, 75, 23));
        pushButton_tri_codee = new QPushButton(tab_afficher_emp);
        pushButton_tri_codee->setObjectName(QStringLiteral("pushButton_tri_codee"));
        pushButton_tri_codee->setGeometry(QRect(10, 10, 75, 23));
        pushButton_tri_nom = new QPushButton(tab_afficher_emp);
        pushButton_tri_nom->setObjectName(QStringLiteral("pushButton_tri_nom"));
        pushButton_tri_nom->setGeometry(QRect(100, 10, 75, 23));
        pushButton_tri_prix = new QPushButton(tab_afficher_emp);
        pushButton_tri_prix->setObjectName(QStringLiteral("pushButton_tri_prix"));
        pushButton_tri_prix->setGeometry(QRect(190, 10, 75, 23));
        lineEdit_chercher_type = new QLineEdit(tab_afficher_emp);
        lineEdit_chercher_type->setObjectName(QStringLiteral("lineEdit_chercher_type"));
        lineEdit_chercher_type->setGeometry(QRect(10, 280, 113, 20));
        lineEdit_chercher_ville = new QLineEdit(tab_afficher_emp);
        lineEdit_chercher_ville->setObjectName(QStringLiteral("lineEdit_chercher_ville"));
        lineEdit_chercher_ville->setGeometry(QRect(260, 280, 113, 20));
        pushButton_chercher_type = new QPushButton(tab_afficher_emp);
        pushButton_chercher_type->setObjectName(QStringLiteral("pushButton_chercher_type"));
        pushButton_chercher_type->setGeometry(QRect(140, 280, 91, 23));
        pushButton_chercher_ville = new QPushButton(tab_afficher_emp);
        pushButton_chercher_ville->setObjectName(QStringLiteral("pushButton_chercher_ville"));
        pushButton_chercher_ville->setGeometry(QRect(390, 280, 75, 23));
        pushButton_pdf = new QPushButton(tab_afficher_emp);
        pushButton_pdf->setObjectName(QStringLiteral("pushButton_pdf"));
        pushButton_pdf->setGeometry(QRect(560, 70, 75, 23));
        tabWidget_2->addTab(tab_afficher_emp, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        customPlot = new QCustomPlot(tab_2);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(10, 40, 621, 261));
        customPlot->setContextMenuPolicy(Qt::NoContextMenu);
        pushButton_statistique = new QPushButton(tab_2);
        pushButton_statistique->setObjectName(QStringLiteral("pushButton_statistique"));
        pushButton_statistique->setGeometry(QRect(250, 10, 121, 23));
        tabWidget_2->addTab(tab_2, QString());
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_id_c->setText(QApplication::translate("MainWindow", "CODE", Q_NULLPTR));
        label_cin_c->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_nom_c->setText(QApplication::translate("MainWindow", "Date", Q_NULLPTR));
        label_prenom_c->setText(QApplication::translate("MainWindow", "Type", Q_NULLPTR));
        pushButton_ajouter_E->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pushButton_quitter->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        pushButton_modifier_E->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        pushButton_rafraichir_E->setText(QApplication::translate("MainWindow", "Rafraichir", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Ville", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Prix", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_ajouter_emp), QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pushButton_supprimer_E->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        pushButton_rafraichir->setText(QApplication::translate("MainWindow", "Rafraichir", Q_NULLPTR));
        pushButton_2_quitter->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        pushButton_tri_codee->setText(QApplication::translate("MainWindow", "Tri code", Q_NULLPTR));
        pushButton_tri_nom->setText(QApplication::translate("MainWindow", "Tri nom", Q_NULLPTR));
        pushButton_tri_prix->setText(QApplication::translate("MainWindow", "Tri prix", Q_NULLPTR));
        pushButton_chercher_type->setText(QApplication::translate("MainWindow", "Chercher type", Q_NULLPTR));
        pushButton_chercher_ville->setText(QApplication::translate("MainWindow", "Chercher ville", Q_NULLPTR));
        pushButton_pdf->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_afficher_emp), QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        pushButton_statistique->setText(QApplication::translate("MainWindow", "Afficher Statistique", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Evenement", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
