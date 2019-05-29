/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication3.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION3_H
#define UI_QTGUIAPPLICATION3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplication3Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApplication3Class)
    {
        if (QtGuiApplication3Class->objectName().isEmpty())
            QtGuiApplication3Class->setObjectName(QStringLiteral("QtGuiApplication3Class"));
        QtGuiApplication3Class->resize(600, 400);
        menuBar = new QMenuBar(QtGuiApplication3Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtGuiApplication3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiApplication3Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGuiApplication3Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtGuiApplication3Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtGuiApplication3Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtGuiApplication3Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGuiApplication3Class->setStatusBar(statusBar);

        retranslateUi(QtGuiApplication3Class);

        QMetaObject::connectSlotsByName(QtGuiApplication3Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplication3Class)
    {
        QtGuiApplication3Class->setWindowTitle(QApplication::translate("QtGuiApplication3Class", "QtGuiApplication3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplication3Class: public Ui_QtGuiApplication3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION3_H
