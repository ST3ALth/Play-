/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_Game;
    QAction *actionStart_Game;
    QAction *actionExit;
    QAction *actionSettings;
    QAction *actionBoot_ELF;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QOpenGLWidget *openGLWidget;
    QMenuBar *menuBar;
    QMenu *menuFor_The;
    QMenu *menuEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 512);
        QIcon icon;
        icon.addFile(QStringLiteral("../../Downloads/ic_launcher.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpen_Game = new QAction(MainWindow);
        actionOpen_Game->setObjectName(QStringLiteral("actionOpen_Game"));
        actionStart_Game = new QAction(MainWindow);
        actionStart_Game->setObjectName(QStringLiteral("actionStart_Game"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionBoot_ELF = new QAction(MainWindow);
        actionBoot_ELF->setObjectName(QStringLiteral("actionBoot_ELF"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        openGLWidget = new QOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));

        gridLayout->addWidget(openGLWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 25));
        menuFor_The = new QMenu(menuBar);
        menuFor_The->setObjectName(QStringLiteral("menuFor_The"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFor_The->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFor_The->addAction(actionOpen_Game);
        menuFor_The->addAction(actionStart_Game);
        menuFor_The->addAction(actionBoot_ELF);
        menuFor_The->addSeparator();
        menuFor_The->addAction(actionExit);
        menuEdit->addAction(actionSettings);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Play!", 0));
        actionOpen_Game->setText(QApplication::translate("MainWindow", "Open Game", 0));
        actionOpen_Game->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionStart_Game->setText(QApplication::translate("MainWindow", "Start Game", 0));
        actionStart_Game->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", 0));
        actionBoot_ELF->setText(QApplication::translate("MainWindow", "Boot ELF", 0));
        menuFor_The->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
