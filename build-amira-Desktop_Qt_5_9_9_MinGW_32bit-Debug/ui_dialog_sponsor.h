/********************************************************************************
** Form generated from reading UI file 'dialog_sponsor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SPONSOR_H
#define UI_DIALOG_SPONSOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog_sponsor
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_9;
    QLineEdit *nom;
    QLabel *label_7;
    QLineEdit *id;
    QComboBox *type;
    QLabel *label_10;
    QLabel *label_8;
    QLabel *label_11;
    QLineEdit *adresse;
    QDoubleSpinBox *montant;

    void setupUi(QDialog *Dialog_sponsor)
    {
        if (Dialog_sponsor->objectName().isEmpty())
            Dialog_sponsor->setObjectName(QStringLiteral("Dialog_sponsor"));
        Dialog_sponsor->resize(400, 300);
        buttonBox = new QDialogButtonBox(Dialog_sponsor);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_9 = new QLabel(Dialog_sponsor);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 140, 61, 16));
        nom = new QLineEdit(Dialog_sponsor);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(130, 100, 113, 20));
        label_7 = new QLabel(Dialog_sponsor);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 180, 101, 16));
        id = new QLineEdit(Dialog_sponsor);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(130, 60, 113, 20));
        type = new QComboBox(Dialog_sponsor);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(130, 140, 111, 22));
        label_10 = new QLabel(Dialog_sponsor);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(60, 100, 47, 14));
        label_8 = new QLabel(Dialog_sponsor);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(60, 60, 47, 14));
        label_11 = new QLabel(Dialog_sponsor);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(60, 210, 47, 14));
        adresse = new QLineEdit(Dialog_sponsor);
        adresse->setObjectName(QStringLiteral("adresse"));
        adresse->setGeometry(QRect(130, 210, 113, 20));
        montant = new QDoubleSpinBox(Dialog_sponsor);
        montant->setObjectName(QStringLiteral("montant"));
        montant->setGeometry(QRect(130, 180, 111, 21));

        retranslateUi(Dialog_sponsor);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_sponsor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_sponsor, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_sponsor);
    } // setupUi

    void retranslateUi(QDialog *Dialog_sponsor)
    {
        Dialog_sponsor->setWindowTitle(QApplication::translate("Dialog_sponsor", "Dialog", Q_NULLPTR));
        label_9->setText(QApplication::translate("Dialog_sponsor", "Type", Q_NULLPTR));
        nom->setText(QApplication::translate("Dialog_sponsor", "mira", Q_NULLPTR));
        label_7->setText(QApplication::translate("Dialog_sponsor", "Montant", Q_NULLPTR));
        id->setText(QApplication::translate("Dialog_sponsor", "8785", Q_NULLPTR));
        type->clear();
        type->insertItems(0, QStringList()
         << QApplication::translate("Dialog_sponsor", "            --", Q_NULLPTR)
         << QApplication::translate("Dialog_sponsor", "type 1", Q_NULLPTR)
         << QApplication::translate("Dialog_sponsor", "type 2", Q_NULLPTR)
         << QApplication::translate("Dialog_sponsor", "type 3", Q_NULLPTR)
         << QApplication::translate("Dialog_sponsor", "type 4", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("Dialog_sponsor", "Nom", Q_NULLPTR));
        label_8->setText(QApplication::translate("Dialog_sponsor", "ID", Q_NULLPTR));
        label_11->setText(QApplication::translate("Dialog_sponsor", "Adresse", Q_NULLPTR));
        adresse->setText(QApplication::translate("Dialog_sponsor", "manai.amira@", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_sponsor: public Ui_Dialog_sponsor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SPONSOR_H
