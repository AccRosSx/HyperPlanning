/********************************************************************************
** Form generated from reading UI file 'stagiaire.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAGIAIRE_H
#define UI_STAGIAIRE_H

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

class Ui_stagiaire
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *loadTableDay;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *loadTableWeek;
    QPushButton *loadTableMonth;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QLabel *errorLabel;

    void setupUi(QDialog *stagiaire)
    {
        if (stagiaire->objectName().isEmpty())
            stagiaire->setObjectName(QStringLiteral("stagiaire"));
        stagiaire->resize(640, 341);
        widget = new QWidget(stagiaire);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(370, 290, 241, 27));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        loadTableDay = new QPushButton(widget);
        loadTableDay->setObjectName(QStringLiteral("loadTableDay"));

        horizontalLayout_3->addWidget(loadTableDay);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        loadTableWeek = new QPushButton(widget);
        loadTableWeek->setObjectName(QStringLiteral("loadTableWeek"));

        horizontalLayout_2->addWidget(loadTableWeek);

        loadTableMonth = new QPushButton(widget);
        loadTableMonth->setObjectName(QStringLiteral("loadTableMonth"));

        horizontalLayout_2->addWidget(loadTableMonth);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        widget1 = new QWidget(stagiaire);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 50, 582, 239));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(widget1);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout->addWidget(listWidget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        calendarWidget = new QCalendarWidget(widget1);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));

        verticalLayout->addWidget(calendarWidget);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        errorLabel = new QLabel(widget1);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));

        verticalLayout_3->addWidget(errorLabel);


        horizontalLayout->addLayout(verticalLayout_3);


        retranslateUi(stagiaire);

        QMetaObject::connectSlotsByName(stagiaire);
    } // setupUi

    void retranslateUi(QDialog *stagiaire)
    {
        stagiaire->setWindowTitle(QApplication::translate("stagiaire", "Dialog", nullptr));
        loadTableDay->setText(QApplication::translate("stagiaire", "LOAD DAY", nullptr));
        loadTableWeek->setText(QApplication::translate("stagiaire", "LOAD WEEK", nullptr));
        loadTableMonth->setText(QApplication::translate("stagiaire", "LOAD MONTH", nullptr));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class stagiaire: public Ui_stagiaire {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAGIAIRE_H
