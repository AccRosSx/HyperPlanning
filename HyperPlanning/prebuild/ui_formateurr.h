/********************************************************************************
** Form generated from reading UI file 'formateurr.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMATEURR_H
#define UI_FORMATEURR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_formateurR
{
public:
    QPushButton *gerer;
    QPushButton *consulter;

    void setupUi(QDialog *formateurR)
    {
        if (formateurR->objectName().isEmpty())
            formateurR->setObjectName(QStringLiteral("formateurR"));
        formateurR->resize(400, 300);
        gerer = new QPushButton(formateurR);
        gerer->setObjectName(QStringLiteral("gerer"));
        gerer->setGeometry(QRect(20, 110, 180, 81));
        consulter = new QPushButton(formateurR);
        consulter->setObjectName(QStringLiteral("consulter"));
        consulter->setGeometry(QRect(210, 110, 180, 81));

        retranslateUi(formateurR);

        QMetaObject::connectSlotsByName(formateurR);
    } // setupUi

    void retranslateUi(QDialog *formateurR)
    {
        formateurR->setWindowTitle(QApplication::translate("formateurR", "Dialog", nullptr));
        gerer->setText(QApplication::translate("formateurR", "G\303\251rer", nullptr));
        consulter->setText(QApplication::translate("formateurR", "Consulter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class formateurR: public Ui_formateurR {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMATEURR_H
