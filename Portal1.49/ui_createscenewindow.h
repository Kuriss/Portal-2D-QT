/********************************************************************************
** Form generated from reading UI file 'createscenewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESCENEWINDOW_H
#define UI_CREATESCENEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "creategraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_CreateSceneWindow
{
public:
    QAction *actQuit;
    QAction *actGroupBreak;
    QAction *actEditDelete;
    QAction *actGroup;
    QAction *actEditBack;
    QAction *actEditFront;
    QAction *actPlay;
    QAction *actSave;
    QAction *actRestore;
    QAction *actZoomln;
    QAction *actZoomOut;
    QAction *whiteBrick;
    QAction *blackBrick;
    QAction *actResetStart;
    QAction *actResetEnd;
    QAction *companionCube;
    QWidget *centralwidget;
    CreateGraphicsView *gView;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *CreateSceneWindow)
    {
        if (CreateSceneWindow->objectName().isEmpty())
            CreateSceneWindow->setObjectName(QString::fromUtf8("CreateSceneWindow"));
        CreateSceneWindow->resize(654, 555);
        actQuit = new QAction(CreateSceneWindow);
        actQuit->setObjectName(QString::fromUtf8("actQuit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/redmi airdots.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon);
        actGroupBreak = new QAction(CreateSceneWindow);
        actGroupBreak->setObjectName(QString::fromUtf8("actGroupBreak"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/bg4.png"), QSize(), QIcon::Normal, QIcon::Off);
        actGroupBreak->setIcon(icon1);
        actEditDelete = new QAction(CreateSceneWindow);
        actEditDelete->setObjectName(QString::fromUtf8("actEditDelete"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/title_sprite.png"), QSize(), QIcon::Normal, QIcon::Off);
        actEditDelete->setIcon(icon2);
        actGroup = new QAction(CreateSceneWindow);
        actGroup->setObjectName(QString::fromUtf8("actGroup"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actGroup->setIcon(icon3);
        actEditBack = new QAction(CreateSceneWindow);
        actEditBack->setObjectName(QString::fromUtf8("actEditBack"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/sdfusa.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actEditBack->setIcon(icon4);
        actEditFront = new QAction(CreateSceneWindow);
        actEditFront->setObjectName(QString::fromUtf8("actEditFront"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/safd.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actEditFront->setIcon(icon5);
        actPlay = new QAction(CreateSceneWindow);
        actPlay->setObjectName(QString::fromUtf8("actPlay"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/bg11.png"), QSize(), QIcon::Normal, QIcon::Off);
        actPlay->setIcon(icon6);
        actSave = new QAction(CreateSceneWindow);
        actSave->setObjectName(QString::fromUtf8("actSave"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/bg1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actSave->setIcon(icon7);
        actRestore = new QAction(CreateSceneWindow);
        actRestore->setObjectName(QString::fromUtf8("actRestore"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/images/27623808008111.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actRestore->setIcon(icon8);
        actZoomln = new QAction(CreateSceneWindow);
        actZoomln->setObjectName(QString::fromUtf8("actZoomln"));
        actZoomOut = new QAction(CreateSceneWindow);
        actZoomOut->setObjectName(QString::fromUtf8("actZoomOut"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/images/231.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomOut->setIcon(icon9);
        whiteBrick = new QAction(CreateSceneWindow);
        whiteBrick->setObjectName(QString::fromUtf8("whiteBrick"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/res/WriteBrick.png"), QSize(), QIcon::Normal, QIcon::Off);
        whiteBrick->setIcon(icon10);
        blackBrick = new QAction(CreateSceneWindow);
        blackBrick->setObjectName(QString::fromUtf8("blackBrick"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/res/BlackBrick.png"), QSize(), QIcon::Normal, QIcon::Off);
        blackBrick->setIcon(icon11);
        actResetStart = new QAction(CreateSceneWindow);
        actResetStart->setObjectName(QString::fromUtf8("actResetStart"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/res/gameEnd.png"), QSize(), QIcon::Normal, QIcon::Off);
        actResetStart->setIcon(icon12);
        actResetEnd = new QAction(CreateSceneWindow);
        actResetEnd->setObjectName(QString::fromUtf8("actResetEnd"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/res/gameStart.png"), QSize(), QIcon::Normal, QIcon::Off);
        actResetEnd->setIcon(icon13);
        companionCube = new QAction(CreateSceneWindow);
        companionCube->setObjectName(QString::fromUtf8("companionCube"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/res/CompanionCube.png"), QSize(), QIcon::Normal, QIcon::Off);
        companionCube->setIcon(icon14);
        centralwidget = new QWidget(CreateSceneWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gView = new CreateGraphicsView(centralwidget);
        gView->setObjectName(QString::fromUtf8("gView"));
        gView->setGeometry(QRect(10, 10, 351, 281));
        CreateSceneWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(CreateSceneWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CreateSceneWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(CreateSceneWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMinimumSize(QSize(0, 0));
        toolBar->setMaximumSize(QSize(16777215, 16777215));
        toolBar->setIconSize(QSize(40, 24));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        CreateSceneWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(CreateSceneWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        toolBar_2->setMinimumSize(QSize(0, 0));
        toolBar_2->setIconSize(QSize(24, 40));
        toolBar_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolBar_2->setFloatable(true);
        CreateSceneWindow->addToolBar(Qt::LeftToolBarArea, toolBar_2);

        toolBar->addAction(actEditFront);
        toolBar->addAction(actEditBack);
        toolBar->addSeparator();
        toolBar->addAction(actGroup);
        toolBar->addAction(actGroupBreak);
        toolBar->addSeparator();
        toolBar->addAction(actEditDelete);
        toolBar->addSeparator();
        toolBar->addAction(actSave);
        toolBar->addAction(actPlay);
        toolBar->addAction(actQuit);
        toolBar_2->addAction(blackBrick);
        toolBar_2->addAction(whiteBrick);
        toolBar_2->addAction(actResetStart);
        toolBar_2->addAction(actResetEnd);

        retranslateUi(CreateSceneWindow);

        QMetaObject::connectSlotsByName(CreateSceneWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CreateSceneWindow)
    {
        CreateSceneWindow->setWindowTitle(QCoreApplication::translate("CreateSceneWindow", "MainWindow", nullptr));
        actQuit->setText(QCoreApplication::translate("CreateSceneWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actQuit->setToolTip(QCoreApplication::translate("CreateSceneWindow", " \351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
#endif // QT_CONFIG(tooltip)
        actGroupBreak->setText(QCoreApplication::translate("CreateSceneWindow", "\346\211\223\346\225\243", nullptr));
#if QT_CONFIG(tooltip)
        actGroupBreak->setToolTip(QCoreApplication::translate("CreateSceneWindow", "\346\211\223\346\225\243", nullptr));
#endif // QT_CONFIG(tooltip)
        actEditDelete->setText(QCoreApplication::translate("CreateSceneWindow", "\345\210\240\351\231\244", nullptr));
#if QT_CONFIG(tooltip)
        actEditDelete->setToolTip(QCoreApplication::translate("CreateSceneWindow", "\345\210\240\351\231\244\351\200\211\344\270\255\347\232\204\345\233\276\345\205\203", nullptr));
#endif // QT_CONFIG(tooltip)
        actGroup->setText(QCoreApplication::translate("CreateSceneWindow", "\347\273\204\345\220\210", nullptr));
#if QT_CONFIG(tooltip)
        actGroup->setToolTip(QCoreApplication::translate("CreateSceneWindow", "\347\273\204\345\220\210", nullptr));
#endif // QT_CONFIG(tooltip)
        actEditBack->setText(QCoreApplication::translate("CreateSceneWindow", "\345\267\246\344\270\212\350\247\222", nullptr));
#if QT_CONFIG(tooltip)
        actEditBack->setToolTip(QCoreApplication::translate("CreateSceneWindow", "\345\267\246\344\270\212\350\247\222", nullptr));
#endif // QT_CONFIG(tooltip)
        actEditFront->setText(QCoreApplication::translate("CreateSceneWindow", "\347\202\271\345\207\273\346\226\271\345\235\227", nullptr));
#if QT_CONFIG(tooltip)
        actEditFront->setToolTip(QCoreApplication::translate("CreateSceneWindow", "\345\261\205\344\272\216\346\234\200\345\211\215\351\235\242", nullptr));
#endif // QT_CONFIG(tooltip)
        actPlay->setText(QCoreApplication::translate("CreateSceneWindow", "\344\277\235\345\255\230\345\271\266\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
#if QT_CONFIG(tooltip)
        actPlay->setToolTip(QCoreApplication::translate("CreateSceneWindow", "\344\277\235\345\255\230\345\271\266\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actSave->setText(QCoreApplication::translate("CreateSceneWindow", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(tooltip)
        actSave->setToolTip(QCoreApplication::translate("CreateSceneWindow", "\344\277\235\345\255\230\346\211\200\346\234\211\345\233\276\346\241\210\357\274\214\345\210\260playscene\344\270\255", nullptr));
#endif // QT_CONFIG(tooltip)
        actRestore->setText(QCoreApplication::translate("CreateSceneWindow", "\346\201\242\345\244\215", nullptr));
#if QT_CONFIG(tooltip)
        actRestore->setToolTip(QCoreApplication::translate("CreateSceneWindow", "\346\201\242\345\244\215", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomln->setText(QCoreApplication::translate("CreateSceneWindow", "\346\224\276\345\244\247", nullptr));
#if QT_CONFIG(tooltip)
        actZoomln->setToolTip(QCoreApplication::translate("CreateSceneWindow", "\346\224\276\345\244\247", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomOut->setText(QCoreApplication::translate("CreateSceneWindow", "\347\274\251\345\260\217", nullptr));
#if QT_CONFIG(tooltip)
        actZoomOut->setToolTip(QCoreApplication::translate("CreateSceneWindow", "\347\274\251\345\260\217", nullptr));
#endif // QT_CONFIG(tooltip)
        whiteBrick->setText(QCoreApplication::translate("CreateSceneWindow", "\347\231\275\350\211\262\347\240\226\345\235\227", nullptr));
#if QT_CONFIG(tooltip)
        whiteBrick->setToolTip(QCoreApplication::translate("CreateSceneWindow", "\346\267\273\345\212\240\347\231\275\350\211\262\347\240\226\345\235\227", nullptr));
#endif // QT_CONFIG(tooltip)
        blackBrick->setText(QCoreApplication::translate("CreateSceneWindow", "\351\273\221\350\211\262\347\240\226\345\235\227", nullptr));
#if QT_CONFIG(tooltip)
        blackBrick->setToolTip(QCoreApplication::translate("CreateSceneWindow", "\346\267\273\345\212\240\351\273\221\350\211\262\347\240\226\345\235\227", nullptr));
#endif // QT_CONFIG(tooltip)
        actResetStart->setText(QCoreApplication::translate("CreateSceneWindow", "\351\207\215\347\275\256\345\274\200\345\247\213\344\275\215\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        actResetStart->setToolTip(QCoreApplication::translate("CreateSceneWindow", "\351\207\215\347\275\256\345\274\200\345\247\213\344\274\240\351\200\201\351\227\250\347\232\204\344\275\215\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        actResetEnd->setText(QCoreApplication::translate("CreateSceneWindow", "\351\207\215\347\275\256\347\273\223\346\235\237\344\275\215\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        actResetEnd->setToolTip(QCoreApplication::translate("CreateSceneWindow", "\351\207\215\347\275\256\347\273\223\346\235\237\344\274\240\351\200\201\351\227\250\347\232\204\344\275\215\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        companionCube->setText(QCoreApplication::translate("CreateSceneWindow", "\351\207\215\345\212\233\347\240\226\345\235\227", nullptr));
#if QT_CONFIG(tooltip)
        companionCube->setToolTip(QCoreApplication::translate("CreateSceneWindow", "\347\224\250\344\272\216\345\216\213\345\216\213\345\212\233\346\235\277\344\273\245\350\276\276\345\210\260\345\274\200\351\227\250\347\255\211\347\233\256\347\232\204", nullptr));
#endif // QT_CONFIG(tooltip)
        toolBar->setWindowTitle(QCoreApplication::translate("CreateSceneWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("CreateSceneWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateSceneWindow: public Ui_CreateSceneWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESCENEWINDOW_H
