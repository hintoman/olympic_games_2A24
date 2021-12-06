/********************************************************************************
** Form generated from reading UI file 'maps.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPS_H
#define UI_MAPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_maps
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *maps)
    {
        if (maps->objectName().isEmpty())
            maps->setObjectName(QStringLiteral("maps"));
        maps->resize(1024, 768);
        centralwidget = new QWidget(maps);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        maps->setCentralWidget(centralwidget);
        menubar = new QMenuBar(maps);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 26));
        maps->setMenuBar(menubar);
        statusbar = new QStatusBar(maps);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        maps->setStatusBar(statusbar);

        retranslateUi(maps);

        QMetaObject::connectSlotsByName(maps);
    } // setupUi

    void retranslateUi(QMainWindow *maps)
    {
        maps->setWindowTitle(QApplication::translate("maps", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class maps: public Ui_maps {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPS_H
