/********************************************************************************
** Form generated from reading UI file 'gestion_amira.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_AMIRA_H
#define UI_GESTION_AMIRA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gestion_amira
{
public:
    QAction *actionadd_sponsor;
    QAction *actiondelete_sponsor;
    QAction *actionstats;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableau_sponsors;
    QLineEdit *rech;
    QComboBox *sel_col;
    QPushButton *export_excel;
    QPushButton *pushButton;
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
    QToolBar *toolBar;

    void setupUi(QMainWindow *gestion_amira)
    {
        if (gestion_amira->objectName().isEmpty())
            gestion_amira->setObjectName(QStringLiteral("gestion_amira"));
        gestion_amira->resize(800, 600);
        actionadd_sponsor = new QAction(gestion_amira);
        actionadd_sponsor->setObjectName(QStringLiteral("actionadd_sponsor"));
        actiondelete_sponsor = new QAction(gestion_amira);
        actiondelete_sponsor->setObjectName(QStringLiteral("actiondelete_sponsor"));
        actionstats = new QAction(gestion_amira);
        actionstats->setObjectName(QStringLiteral("actionstats"));
        centralwidget = new QWidget(gestion_amira);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 10, 711, 461));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tableau_sponsors = new QTableView(tab);
        tableau_sponsors->setObjectName(QStringLiteral("tableau_sponsors"));
        tableau_sponsors->setGeometry(QRect(20, 71, 651, 331));
        tableau_sponsors->setSortingEnabled(true);
        tableau_sponsors->horizontalHeader()->setCascadingSectionResizes(true);
        tableau_sponsors->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableau_sponsors->horizontalHeader()->setStretchLastSection(false);
        rech = new QLineEdit(tab);
        rech->setObjectName(QStringLiteral("rech"));
        rech->setGeometry(QRect(470, 30, 111, 24));
        rech->setClearButtonEnabled(true);
        sel_col = new QComboBox(tab);
        sel_col->setObjectName(QStringLiteral("sel_col"));
        sel_col->setGeometry(QRect(591, 30, 81, 22));
        export_excel = new QPushButton(tab);
        export_excel->setObjectName(QStringLiteral("export_excel"));
        export_excel->setGeometry(QRect(20, 410, 651, 28));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 30, 93, 28));
        tabWidget->addTab(tab, QString());
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
        gestion_amira->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gestion_amira);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        gestion_amira->setMenuBar(menubar);
        statusbar = new QStatusBar(gestion_amira);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        gestion_amira->setStatusBar(statusbar);
        toolBar = new QToolBar(gestion_amira);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        gestion_amira->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionadd_sponsor);
        toolBar->addAction(actiondelete_sponsor);
        toolBar->addSeparator();
        toolBar->addAction(actionstats);

        retranslateUi(gestion_amira);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(gestion_amira);
    } // setupUi

    void retranslateUi(QMainWindow *gestion_amira)
    {
        gestion_amira->setWindowTitle(QApplication::translate("gestion_amira", "MainWindow", Q_NULLPTR));
        actionadd_sponsor->setText(QApplication::translate("gestion_amira", "add_sponsor", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionadd_sponsor->setShortcut(QApplication::translate("gestion_amira", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actiondelete_sponsor->setText(QApplication::translate("gestion_amira", "delete_sponsor", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actiondelete_sponsor->setShortcut(QApplication::translate("gestion_amira", "Ctrl+D", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionstats->setText(QApplication::translate("gestion_amira", "stats", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionstats->setShortcut(QApplication::translate("gestion_amira", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        rech->setPlaceholderText(QApplication::translate("gestion_amira", "Recherche", Q_NULLPTR));
        sel_col->clear();
        sel_col->insertItems(0, QStringList()
         << QApplication::translate("gestion_amira", "All", Q_NULLPTR)
         << QApplication::translate("gestion_amira", "ID", Q_NULLPTR)
         << QApplication::translate("gestion_amira", "Nom", Q_NULLPTR)
         << QApplication::translate("gestion_amira", "Adresse", Q_NULLPTR)
         << QApplication::translate("gestion_amira", "Type", Q_NULLPTR)
         << QApplication::translate("gestion_amira", "Montant", Q_NULLPTR)
        );
        export_excel->setText(QApplication::translate("gestion_amira", "Export Excel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("gestion_amira", "video", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("gestion_amira", "crud", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("gestion_amira", "Send", Q_NULLPTR));
        subject->setPlaceholderText(QApplication::translate("gestion_amira", "subject", Q_NULLPTR));
        browseBtn->setText(QApplication::translate("gestion_amira", "Browse ...", Q_NULLPTR));
        file->setPlaceholderText(QApplication::translate("gestion_amira", "attachement here", Q_NULLPTR));
        msg->setPlaceholderText(QApplication::translate("gestion_amira", "type your message here ...", Q_NULLPTR));
        rcpt->setPlaceholderText(QApplication::translate("gestion_amira", "recipient", Q_NULLPTR));
        mail_pass->setPlaceholderText(QApplication::translate("gestion_amira", "your mail password", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("gestion_amira", "mail", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("gestion_amira", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gestion_amira: public Ui_gestion_amira {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_AMIRA_H
