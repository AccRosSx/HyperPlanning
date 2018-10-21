/********************************************************************************
** Form generated from reading UI file 'reservation.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESERVATION_H
#define UI_RESERVATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reservation
{
public:
    QLabel *errorLabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QLabel *label_2;
    QComboBox *idGrp;
    QSplitter *splitter_2;
    QLabel *label;
    QTimeEdit *hDeb;
    QSplitter *splitter_3;
    QLabel *label_4;
    QDateEdit *date;
    QSplitter *splitter_4;
    QLabel *label_3;
    QComboBox *salle;
    QPushButton *createResa;
    QTableView *tableView;
    QGridLayout *gridLayout;
    QSplitter *splitter_9;
    QLabel *label_9;
    QComboBox *idResa;
    QSplitter *splitter_8;
    QSplitter *splitter_7;
    QLabel *label_7;
    QTimeEdit *hDeb_2;
    QSplitter *splitter_5;
    QLabel *label_5;
    QDateEdit *date_2;
    QSplitter *splitter_6;
    QPushButton *modifyResa;
    QPushButton *dropResa;

    void setupUi(QDialog *reservation)
    {
        if (reservation->objectName().isEmpty())
            reservation->setObjectName(QStringLiteral("reservation"));
        reservation->resize(613, 273);
        errorLabel = new QLabel(reservation);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setGeometry(QRect(20, 230, 631, 21));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        errorLabel->setFont(font);
        widget = new QWidget(reservation);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 30, 578, 194));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        splitter = new QSplitter(widget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter);
        label_2->setObjectName(QStringLiteral("label_2"));
        splitter->addWidget(label_2);
        idGrp = new QComboBox(splitter);
        idGrp->setObjectName(QStringLiteral("idGrp"));
        splitter->addWidget(idGrp);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);

        splitter_2 = new QSplitter(widget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter_2);
        label->setObjectName(QStringLiteral("label"));
        splitter_2->addWidget(label);
        hDeb = new QTimeEdit(splitter_2);
        hDeb->setObjectName(QStringLiteral("hDeb"));
        hDeb->setMaximumDateTime(QDateTime(QDate(2000, 1, 1), QTime(20, 0, 0)));
        hDeb->setMinimumDateTime(QDateTime(QDate(2000, 1, 1), QTime(8, 0, 0)));
        splitter_2->addWidget(hDeb);

        gridLayout_2->addWidget(splitter_2, 1, 0, 1, 1);

        splitter_3 = new QSplitter(widget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(splitter_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        splitter_3->addWidget(label_4);
        date = new QDateEdit(splitter_3);
        date->setObjectName(QStringLiteral("date"));
        splitter_3->addWidget(date);

        gridLayout_2->addWidget(splitter_3, 2, 0, 1, 1);

        splitter_4 = new QSplitter(widget);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        splitter_4->addWidget(label_3);
        salle = new QComboBox(splitter_4);
        salle->setObjectName(QStringLiteral("salle"));
        splitter_4->addWidget(salle);

        gridLayout_2->addWidget(splitter_4, 3, 0, 1, 1);

        createResa = new QPushButton(widget);
        createResa->setObjectName(QStringLiteral("createResa"));

        gridLayout_2->addWidget(createResa, 4, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        tableView = new QTableView(widget);
        tableView->setObjectName(QStringLiteral("tableView"));

        horizontalLayout->addWidget(tableView);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter_9 = new QSplitter(widget);
        splitter_9->setObjectName(QStringLiteral("splitter_9"));
        splitter_9->setOrientation(Qt::Horizontal);
        label_9 = new QLabel(splitter_9);
        label_9->setObjectName(QStringLiteral("label_9"));
        splitter_9->addWidget(label_9);
        idResa = new QComboBox(splitter_9);
        idResa->setObjectName(QStringLiteral("idResa"));
        splitter_9->addWidget(idResa);

        gridLayout->addWidget(splitter_9, 0, 1, 1, 1);

        splitter_8 = new QSplitter(widget);
        splitter_8->setObjectName(QStringLiteral("splitter_8"));
        splitter_8->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(splitter_8, 1, 0, 1, 2);

        splitter_7 = new QSplitter(widget);
        splitter_7->setObjectName(QStringLiteral("splitter_7"));
        splitter_7->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(splitter_7);
        label_7->setObjectName(QStringLiteral("label_7"));
        splitter_7->addWidget(label_7);
        hDeb_2 = new QTimeEdit(splitter_7);
        hDeb_2->setObjectName(QStringLiteral("hDeb_2"));
        hDeb_2->setMaximumDateTime(QDateTime(QDate(2000, 1, 1), QTime(20, 0, 0)));
        hDeb_2->setMinimumDateTime(QDateTime(QDate(2000, 1, 1), QTime(8, 0, 0)));
        splitter_7->addWidget(hDeb_2);

        gridLayout->addWidget(splitter_7, 2, 0, 1, 2);

        splitter_5 = new QSplitter(widget);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(splitter_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        splitter_5->addWidget(label_5);
        date_2 = new QDateEdit(splitter_5);
        date_2->setObjectName(QStringLiteral("date_2"));
        splitter_5->addWidget(date_2);

        gridLayout->addWidget(splitter_5, 3, 0, 1, 2);

        splitter_6 = new QSplitter(widget);
        splitter_6->setObjectName(QStringLiteral("splitter_6"));
        splitter_6->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(splitter_6, 4, 0, 1, 2);

        modifyResa = new QPushButton(widget);
        modifyResa->setObjectName(QStringLiteral("modifyResa"));

        gridLayout->addWidget(modifyResa, 5, 0, 1, 1);

        dropResa = new QPushButton(widget);
        dropResa->setObjectName(QStringLiteral("dropResa"));

        gridLayout->addWidget(dropResa, 5, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(reservation);

        QMetaObject::connectSlotsByName(reservation);
    } // setupUi

    void retranslateUi(QDialog *reservation)
    {
        reservation->setWindowTitle(QApplication::translate("reservation", "Dialog", nullptr));
        errorLabel->setText(QApplication::translate("reservation", "Pas d'erreurs pour l'instant :)", nullptr));
        label_2->setText(QApplication::translate("reservation", "idGroupe", nullptr));
        label->setText(QApplication::translate("reservation", "D\303\251but", nullptr));
        hDeb->setDisplayFormat(QApplication::translate("reservation", "HH:00", nullptr));
        label_4->setText(QApplication::translate("reservation", "Date", nullptr));
        label_3->setText(QApplication::translate("reservation", "idSalle", nullptr));
        createResa->setText(QApplication::translate("reservation", "R\303\251server", nullptr));
        label_9->setText(QApplication::translate("reservation", "idResa", nullptr));
        label_7->setText(QApplication::translate("reservation", "D\303\251but", nullptr));
        hDeb_2->setDisplayFormat(QApplication::translate("reservation", "HH:00", nullptr));
        label_5->setText(QApplication::translate("reservation", "Date", nullptr));
        modifyResa->setText(QApplication::translate("reservation", "Modifier", nullptr));
        dropResa->setText(QApplication::translate("reservation", "Drop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reservation: public Ui_reservation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESERVATION_H
