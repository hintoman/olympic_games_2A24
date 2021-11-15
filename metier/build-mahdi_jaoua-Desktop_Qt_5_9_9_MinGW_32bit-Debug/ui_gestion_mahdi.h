/********************************************************************************
** Form generated from reading UI file 'gestion_mahdi.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_MAHDI_H
#define UI_GESTION_MAHDI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gestion_mahdi
{
public:
    QAction *actionajout_terrain;
    QAction *actionsuppression_terrain;
    QAction *actionajout_reclamation;
    QAction *actionsuppression_reclamation;
    QAction *actionmodifier_terrain;
    QAction *actionmodifier_reclamation;
    QAction *actioncheck_map;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableau_terrain;
    QLineEdit *rech_terrain;
    QComboBox *sel_col_terrain;
    QLineEdit *lieu;
    QLabel *label_7;
    QLabel *label_11;
    QLineEdit *id_terrain;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_13;
    QComboBox *etat;
    QLineEdit *nom;
    QSpinBox *capacite;
    QPushButton *ajou_t;
    QPushButton *modification_t;
    QPushButton *suppression_t;
    QWidget *tab_3;
    QTableView *tableau_reclamation;
    QLineEdit *rech_reclamation;
    QComboBox *sel_col_reclamation;
    QLabel *label_10;
    QLineEdit *id_reclamation;
    QLabel *label_8;
    QTextEdit *description;
    QLineEdit *mail;
    QLabel *label_14;
    QComboBox *etat_reclamation;
    QLabel *label_15;
    QPushButton *ajout_r;
    QPushButton *modification_r;
    QPushButton *suppression_r;
    QWidget *tab_2;
    QPushButton *sendBtn;
    QLineEdit *subject;
    QPushButton *browseBtn;
    QLineEdit *file;
    QTextEdit *msg;
    QLineEdit *rcpt;
    QLineEdit *mail_pass;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gestion_mahdi)
    {
        if (gestion_mahdi->objectName().isEmpty())
            gestion_mahdi->setObjectName(QStringLiteral("gestion_mahdi"));
        gestion_mahdi->resize(909, 583);
        actionajout_terrain = new QAction(gestion_mahdi);
        actionajout_terrain->setObjectName(QStringLiteral("actionajout_terrain"));
        actionsuppression_terrain = new QAction(gestion_mahdi);
        actionsuppression_terrain->setObjectName(QStringLiteral("actionsuppression_terrain"));
        actionajout_reclamation = new QAction(gestion_mahdi);
        actionajout_reclamation->setObjectName(QStringLiteral("actionajout_reclamation"));
        actionsuppression_reclamation = new QAction(gestion_mahdi);
        actionsuppression_reclamation->setObjectName(QStringLiteral("actionsuppression_reclamation"));
        actionmodifier_terrain = new QAction(gestion_mahdi);
        actionmodifier_terrain->setObjectName(QStringLiteral("actionmodifier_terrain"));
        actionmodifier_reclamation = new QAction(gestion_mahdi);
        actionmodifier_reclamation->setObjectName(QStringLiteral("actionmodifier_reclamation"));
        actioncheck_map = new QAction(gestion_mahdi);
        actioncheck_map->setObjectName(QStringLiteral("actioncheck_map"));
        centralwidget = new QWidget(gestion_mahdi);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(50, 20, 731, 451));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tableau_terrain = new QTableView(tab);
        tableau_terrain->setObjectName(QStringLiteral("tableau_terrain"));
        tableau_terrain->setGeometry(QRect(220, 71, 451, 291));
        tableau_terrain->setSortingEnabled(true);
        tableau_terrain->horizontalHeader()->setCascadingSectionResizes(true);
        tableau_terrain->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableau_terrain->horizontalHeader()->setStretchLastSection(false);
        rech_terrain = new QLineEdit(tab);
        rech_terrain->setObjectName(QStringLiteral("rech_terrain"));
        rech_terrain->setGeometry(QRect(360, 30, 181, 24));
        rech_terrain->setClearButtonEnabled(true);
        sel_col_terrain = new QComboBox(tab);
        sel_col_terrain->setObjectName(QStringLiteral("sel_col_terrain"));
        sel_col_terrain->setGeometry(QRect(561, 30, 111, 22));
        lieu = new QLineEdit(tab);
        lieu->setObjectName(QStringLiteral("lieu"));
        lieu->setGeometry(QRect(30, 310, 141, 20));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 230, 101, 16));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 120, 47, 14));
        id_terrain = new QLineEdit(tab);
        id_terrain->setObjectName(QStringLiteral("id_terrain"));
        id_terrain->setGeometry(QRect(30, 90, 141, 20));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 170, 61, 16));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 70, 47, 14));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(40, 290, 47, 14));
        etat = new QComboBox(tab);
        etat->setObjectName(QStringLiteral("etat"));
        etat->setGeometry(QRect(30, 190, 141, 22));
        nom = new QLineEdit(tab);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(30, 140, 141, 20));
        capacite = new QSpinBox(tab);
        capacite->setObjectName(QStringLiteral("capacite"));
        capacite->setGeometry(QRect(30, 253, 141, 22));
        ajou_t = new QPushButton(tab);
        ajou_t->setObjectName(QStringLiteral("ajou_t"));
        ajou_t->setGeometry(QRect(50, 390, 121, 28));
        modification_t = new QPushButton(tab);
        modification_t->setObjectName(QStringLiteral("modification_t"));
        modification_t->setGeometry(QRect(230, 390, 93, 28));
        suppression_t = new QPushButton(tab);
        suppression_t->setObjectName(QStringLiteral("suppression_t"));
        suppression_t->setGeometry(QRect(370, 390, 93, 28));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tableau_reclamation = new QTableView(tab_3);
        tableau_reclamation->setObjectName(QStringLiteral("tableau_reclamation"));
        tableau_reclamation->setGeometry(QRect(210, 70, 481, 331));
        tableau_reclamation->setSortingEnabled(true);
        tableau_reclamation->horizontalHeader()->setCascadingSectionResizes(true);
        tableau_reclamation->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableau_reclamation->horizontalHeader()->setStretchLastSection(false);
        rech_reclamation = new QLineEdit(tab_3);
        rech_reclamation->setObjectName(QStringLiteral("rech_reclamation"));
        rech_reclamation->setGeometry(QRect(320, 30, 221, 24));
        rech_reclamation->setClearButtonEnabled(true);
        sel_col_reclamation = new QComboBox(tab_3);
        sel_col_reclamation->setObjectName(QStringLiteral("sel_col_reclamation"));
        sel_col_reclamation->setGeometry(QRect(561, 30, 131, 22));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 100, 81, 16));
        id_reclamation = new QLineEdit(tab_3);
        id_reclamation->setObjectName(QStringLiteral("id_reclamation"));
        id_reclamation->setGeometry(QRect(30, 70, 161, 20));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 50, 47, 14));
        description = new QTextEdit(tab_3);
        description->setObjectName(QStringLiteral("description"));
        description->setGeometry(QRect(30, 130, 161, 141));
        mail = new QLineEdit(tab_3);
        mail->setObjectName(QStringLiteral("mail"));
        mail->setGeometry(QRect(30, 300, 161, 20));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(30, 280, 47, 14));
        etat_reclamation = new QComboBox(tab_3);
        etat_reclamation->setObjectName(QStringLiteral("etat_reclamation"));
        etat_reclamation->setGeometry(QRect(40, 350, 141, 22));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(40, 330, 61, 16));
        ajout_r = new QPushButton(tab_3);
        ajout_r->setObjectName(QStringLiteral("ajout_r"));
        ajout_r->setGeometry(QRect(50, 410, 93, 28));
        modification_r = new QPushButton(tab_3);
        modification_r->setObjectName(QStringLiteral("modification_r"));
        modification_r->setGeometry(QRect(210, 410, 93, 28));
        suppression_r = new QPushButton(tab_3);
        suppression_r->setObjectName(QStringLiteral("suppression_r"));
        suppression_r->setGeometry(QRect(370, 410, 93, 28));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        sendBtn = new QPushButton(tab_2);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(10, 410, 651, 23));
        subject = new QLineEdit(tab_2);
        subject->setObjectName(QStringLiteral("subject"));
        subject->setGeometry(QRect(10, 44, 651, 16));
        browseBtn = new QPushButton(tab_2);
        browseBtn->setObjectName(QStringLiteral("browseBtn"));
        browseBtn->setGeometry(QRect(587, 79, 75, 24));
        file = new QLineEdit(tab_2);
        file->setObjectName(QStringLiteral("file"));
        file->setGeometry(QRect(10, 80, 571, 23));
        msg = new QTextEdit(tab_2);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(10, 116, 651, 291));
        rcpt = new QLineEdit(tab_2);
        rcpt->setObjectName(QStringLiteral("rcpt"));
        rcpt->setGeometry(QRect(10, 10, 491, 21));
        mail_pass = new QLineEdit(tab_2);
        mail_pass->setObjectName(QStringLiteral("mail_pass"));
        mail_pass->setGeometry(QRect(522, 10, 141, 20));
        mail_pass->setEchoMode(QLineEdit::Password);
        tabWidget->addTab(tab_2, QString());
        gestion_mahdi->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gestion_mahdi);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 909, 26));
        gestion_mahdi->setMenuBar(menubar);
        statusbar = new QStatusBar(gestion_mahdi);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        gestion_mahdi->setStatusBar(statusbar);

        retranslateUi(gestion_mahdi);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(gestion_mahdi);
    } // setupUi

    void retranslateUi(QMainWindow *gestion_mahdi)
    {
        gestion_mahdi->setWindowTitle(QApplication::translate("gestion_mahdi", "MainWindow", Q_NULLPTR));
        actionajout_terrain->setText(QApplication::translate("gestion_mahdi", "ajout_terrain", Q_NULLPTR));
        actionsuppression_terrain->setText(QApplication::translate("gestion_mahdi", "suppression_terrain", Q_NULLPTR));
        actionajout_reclamation->setText(QApplication::translate("gestion_mahdi", "ajout_reclamation", Q_NULLPTR));
        actionsuppression_reclamation->setText(QApplication::translate("gestion_mahdi", "suppression_reclamation", Q_NULLPTR));
        actionmodifier_terrain->setText(QApplication::translate("gestion_mahdi", "modifier_terrain", Q_NULLPTR));
        actionmodifier_reclamation->setText(QApplication::translate("gestion_mahdi", "modifier_reclamation", Q_NULLPTR));
        actioncheck_map->setText(QApplication::translate("gestion_mahdi", "check_map", Q_NULLPTR));
        rech_terrain->setPlaceholderText(QApplication::translate("gestion_mahdi", "Recherche", Q_NULLPTR));
        sel_col_terrain->clear();
        sel_col_terrain->insertItems(0, QStringList()
         << QApplication::translate("gestion_mahdi", "All", Q_NULLPTR)
         << QApplication::translate("gestion_mahdi", "ID", Q_NULLPTR)
         << QApplication::translate("gestion_mahdi", "Nom", Q_NULLPTR)
         << QApplication::translate("gestion_mahdi", "Lieu", Q_NULLPTR)
         << QApplication::translate("gestion_mahdi", "Etat", Q_NULLPTR)
         << QApplication::translate("gestion_mahdi", "Capacite", Q_NULLPTR)
        );
        lieu->setText(QString());
        label_7->setText(QApplication::translate("gestion_mahdi", "Capacite", Q_NULLPTR));
        label_11->setText(QApplication::translate("gestion_mahdi", "Nom", Q_NULLPTR));
        label_9->setText(QApplication::translate("gestion_mahdi", "Etat", Q_NULLPTR));
        label_12->setText(QApplication::translate("gestion_mahdi", "ID", Q_NULLPTR));
        label_13->setText(QApplication::translate("gestion_mahdi", "Lieu", Q_NULLPTR));
        etat->clear();
        etat->insertItems(0, QStringList()
         << QApplication::translate("gestion_mahdi", "            --", Q_NULLPTR)
         << QApplication::translate("gestion_mahdi", "type 1", Q_NULLPTR)
         << QApplication::translate("gestion_mahdi", "type 2", Q_NULLPTR)
         << QApplication::translate("gestion_mahdi", "type 3", Q_NULLPTR)
         << QApplication::translate("gestion_mahdi", "type 4", Q_NULLPTR)
        );
        ajou_t->setText(QApplication::translate("gestion_mahdi", "ajout", Q_NULLPTR));
        modification_t->setText(QApplication::translate("gestion_mahdi", "modification", Q_NULLPTR));
        suppression_t->setText(QApplication::translate("gestion_mahdi", "supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("gestion_mahdi", "terrain", Q_NULLPTR));
        rech_reclamation->setPlaceholderText(QApplication::translate("gestion_mahdi", "Recherche", Q_NULLPTR));
        sel_col_reclamation->clear();
        sel_col_reclamation->insertItems(0, QStringList()
         << QApplication::translate("gestion_mahdi", "All", Q_NULLPTR)
         << QApplication::translate("gestion_mahdi", "ID", Q_NULLPTR)
         << QApplication::translate("gestion_mahdi", "Description", Q_NULLPTR)
         << QApplication::translate("gestion_mahdi", "Mail", Q_NULLPTR)
         << QApplication::translate("gestion_mahdi", "Etat", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("gestion_mahdi", "Description", Q_NULLPTR));
        label_8->setText(QApplication::translate("gestion_mahdi", "ID", Q_NULLPTR));
        label_14->setText(QApplication::translate("gestion_mahdi", "Mail", Q_NULLPTR));
        etat_reclamation->clear();
        etat_reclamation->insertItems(0, QStringList()
         << QApplication::translate("gestion_mahdi", "Non traitee", Q_NULLPTR)
         << QApplication::translate("gestion_mahdi", "Traitee", Q_NULLPTR)
        );
        label_15->setText(QApplication::translate("gestion_mahdi", "Etat", Q_NULLPTR));
        ajout_r->setText(QApplication::translate("gestion_mahdi", "ajout", Q_NULLPTR));
        modification_r->setText(QApplication::translate("gestion_mahdi", "modification", Q_NULLPTR));
        suppression_r->setText(QApplication::translate("gestion_mahdi", "suppression", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("gestion_mahdi", "reclamation", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("gestion_mahdi", "Send", Q_NULLPTR));
        subject->setPlaceholderText(QApplication::translate("gestion_mahdi", "subject", Q_NULLPTR));
        browseBtn->setText(QApplication::translate("gestion_mahdi", "Browse ...", Q_NULLPTR));
        file->setPlaceholderText(QApplication::translate("gestion_mahdi", "attachement here", Q_NULLPTR));
        msg->setPlaceholderText(QApplication::translate("gestion_mahdi", "type your message here ...", Q_NULLPTR));
        rcpt->setPlaceholderText(QApplication::translate("gestion_mahdi", "recipient", Q_NULLPTR));
        mail_pass->setPlaceholderText(QApplication::translate("gestion_mahdi", "your mail password", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("gestion_mahdi", "mail", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gestion_mahdi: public Ui_gestion_mahdi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_MAHDI_H
