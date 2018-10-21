/********************************************************************************
** Form generated from reading UI file 'adminmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMENU_H
#define UI_ADMINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_adminMenu
{
public:
    QSplitter *splitter;
    QPushButton *gerer;
    QPushButton *planifier;
    QPushButton *consulter;

    void setupUi(QDialog *adminMenu)
    {
        if (adminMenu->objectName().isEmpty())
            adminMenu->setObjectName(QStringLiteral("adminMenu"));
        adminMenu->resize(796, 420);
        splitter = new QSplitter(adminMenu);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(120, 170, 551, 81));
        splitter->setOrientation(Qt::Horizontal);
        gerer = new QPushButton(splitter);
        gerer->setObjectName(QStringLiteral("gerer"));
        splitter->addWidget(gerer);
        planifier = new QPushButton(splitter);
        planifier->setObjectName(QStringLiteral("planifier"));
        splitter->addWidget(planifier);
        consulter = new QPushButton(splitter);
        consulter->setObjectName(QStringLiteral("consulter"));
        splitter->addWidget(consulter);

        retranslateUi(adminMenu);

        QMetaObject::connectSlotsByName(adminMenu);
    } // setupUi

    void retranslateUi(QDialog *adminMenu)
    {
        adminMenu->setWindowTitle(QApplication::translate("adminMenu", "Dialog", nullptr));
        gerer->setText(QApplication::translate("adminMenu", "G\303\251rer", nullptr));
        planifier->setText(QApplication::translate("adminMenu", "Planifier", nullptr));
        consulter->setText(QApplication::translate("adminMenu", "Consulter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminMenu: public Ui_adminMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMENU_H
