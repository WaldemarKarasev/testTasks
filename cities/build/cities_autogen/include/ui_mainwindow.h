/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QComboBox *comboBox;
    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *reselectTable;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(2225, 1444);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 20, 1541, 1231));
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setGeometry(QRect(40, 1280, 170, 48));
        DeleteButton = new QPushButton(centralwidget);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));
        DeleteButton->setGeometry(QRect(250, 1280, 170, 48));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(1620, 40, 431, 41));
        comboBox->setMaxVisibleItems(9);
        submitButton = new QPushButton(centralwidget);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setGeometry(QRect(500, 1280, 170, 48));
        revertButton = new QPushButton(centralwidget);
        revertButton->setObjectName(QString::fromUtf8("revertButton"));
        revertButton->setGeometry(QRect(710, 1280, 170, 48));
        reselectTable = new QPushButton(centralwidget);
        reselectTable->setObjectName(QString::fromUtf8("reselectTable"));
        reselectTable->setGeometry(QRect(920, 1290, 261, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 2225, 39));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        AddButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        DeleteButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1000", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "10000", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "25000", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "50000", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "100000", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "250000", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "500000", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "1000000", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("MainWindow", "2000000", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("MainWindow", "20000000", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("MainWindow", "0", nullptr));
        submitButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        revertButton->setText(QCoreApplication::translate("MainWindow", "Revert", nullptr));
        reselectTable->setText(QCoreApplication::translate("MainWindow", "ReselectTable", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
