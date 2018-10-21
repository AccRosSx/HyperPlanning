/********************************************************************************
** Form generated from reading UI file 'consultation.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSULTATION_H
#define UI_CONSULTATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_consultation
{
public:
    QTableView *tableView;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QCheckBox *checkBox;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QLineEdit *lineEdit;

    void setupUi(QDialog *consultation)
    {
        if (consultation->objectName().isEmpty())
            consultation->setObjectName(QStringLiteral("consultation"));
        consultation->resize(622, 436);
        tableView = new QTableView(consultation);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(30, 90, 561, 321));
        layoutWidget = new QWidget(consultation);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 10, 561, 71));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 0, 0, 1, 3);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 2);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 1, 2, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 2, 1, 1, 2);


        retranslateUi(consultation);

        QMetaObject::connectSlotsByName(consultation);
    } // setupUi

    void retranslateUi(QDialog *consultation)
    {
        consultation->setWindowTitle(QApplication::translate("consultation", "Dialog", nullptr));
        checkBox->setText(QApplication::translate("consultation", "Ordre Alphab\303\251tique", nullptr));
        label->setText(QApplication::translate("consultation", "idGroupe", nullptr));
        label_2->setText(QApplication::translate("consultation", "Nom", nullptr));
    } // retranslateUi

};

namespace Ui {
    class consultation: public Ui_consultation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSULTATION_H
