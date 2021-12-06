/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form
{
public:

    void setupUi(QWidget *form)
    {
        if (form->objectName().isEmpty())
            form->setObjectName(QStringLiteral("form"));
        form->resize(1300, 619);

        retranslateUi(form);

        QMetaObject::connectSlotsByName(form);
    } // setupUi

    void retranslateUi(QWidget *form)
    {
        form->setWindowTitle(QApplication::translate("form", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class form: public Ui_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
