/********************************************************************************
** Form generated from reading UI file 'chooselevelscene.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSELEVELSCENE_H
#define UI_CHOOSELEVELSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseLevelScene
{
public:
    QWidget *centralwidget;
    QListWidget *menu;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChooseLevelScene)
    {
        if (ChooseLevelScene->objectName().isEmpty())
            ChooseLevelScene->setObjectName("ChooseLevelScene");
        ChooseLevelScene->resize(800, 600);
        centralwidget = new QWidget(ChooseLevelScene);
        centralwidget->setObjectName("centralwidget");
        menu = new QListWidget(centralwidget);
        menu->setObjectName("menu");
        menu->setEnabled(true);
        menu->setGeometry(QRect(144, 100, 614, 360));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menu->sizePolicy().hasHeightForWidth());
        menu->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        menu->setFont(font);
        menu->setAutoFillBackground(false);
        menu->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        menu->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        menu->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        menu->setAutoScroll(false);
        menu->setAutoScrollMargin(10);
        ChooseLevelScene->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChooseLevelScene);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        ChooseLevelScene->setMenuBar(menubar);
        statusbar = new QStatusBar(ChooseLevelScene);
        statusbar->setObjectName("statusbar");
        ChooseLevelScene->setStatusBar(statusbar);

        retranslateUi(ChooseLevelScene);

        QMetaObject::connectSlotsByName(ChooseLevelScene);
    } // setupUi

    void retranslateUi(QMainWindow *ChooseLevelScene)
    {
        ChooseLevelScene->setWindowTitle(QCoreApplication::translate("ChooseLevelScene", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseLevelScene: public Ui_ChooseLevelScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSELEVELSCENE_H
