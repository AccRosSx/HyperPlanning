/********************************************************************************
** Form generated from reading UI file 'formateur.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMATEUR_H
#define UI_FORMATEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formateur
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *loadTableDay;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *loadTableWeek;
    QPushButton *loadTableMonth;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QLabel *errorLabel;

    void setupUi(QDialog *formateur)
    {
        if (formateur->objectName().isEmpty())
            formateur->setObjectName(QStringLiteral("formateur"));
        formateur->resize(687, 362);
        layoutWidget = new QWidget(formateur);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(400, 290, 241, 27));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        loadTableDay = new QPushButton(layoutWidget);
        loadTableDay->setObjectName(QStringLiteral("loadTableDay"));

        horizontalLayout_3->addWidget(loadTableDay);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        loadTableWeek = new QPushButton(layoutWidget);
        loadTableWeek->setObjectName(QStringLiteral("loadTableWeek"));

        horizontalLayout_2->addWidget(loadTableWeek);

        loadTableMonth = new QPushButton(layoutWidget);
        loadTableMonth->setObjectName(QStringLiteral("loadTableMonth"));

        horizontalLayout_2->addWidget(loadTableMonth);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        layoutWidget_2 = new QWidget(formateur);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(60, 50, 582, 239));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(layoutWidget_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout->addWidget(listWidget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        calendarWidget = new QCalendarWidget(layoutWidget_2);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));

        verticalLayout->addWidget(calendarWidget);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        errorLabel = new QLabel(layoutWidget_2);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));

        verticalLayout_3->addWidget(errorLabel);


        horizontalLayout->addLayout(verticalLayout_3);


        retranslateUi(formateur);

        QMetaObject::connectSlotsByName(formateur);
    } // setupUi

    void retranslateUi(QDialog *formateur)
    {
        formateur->setWindowTitle(QApplication::translate("formateur", "Dialog", nullptr));
        loadTableDay->setText(QApplication::translate("formateur", "LOAD DAY", nullptr));
        loadTableWeek->setText(QApplication::translate("formateur", "LOAD WEEK", nullptr));
        loadTableMonth->setText(QApplication::translate("formateur", "LOAD MONTH", nullptr));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class formateur: public Ui_formateur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMATEUR_H
