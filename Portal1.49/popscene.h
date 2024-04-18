//设置弹窗
#pragma once
#ifndef POPSCENE_H
#define POPSCENE_H
#include <QMainWindow>
#include<QPainter>
#include<QPaintEvent>
#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

//弹窗基类
class PopScene: public QDialog{
      Q_OBJECT
public:
       PopScene(QWidget *parent=  nullptr) : QDialog(parent)
{
        setWindowFlags(Qt::Window | Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
        setWindowModality(Qt::ApplicationModal);
        // 创建垂直布局
        QHBoxLayout *layout = new QHBoxLayout(this);

        // 添加内容标签，派生类可以设置内容
        contentLabel = new QLabel(this);
        layout->addWidget(contentLabel);

        // 设置对话框的布局
        setLayout(layout);
    }

    // 派生类可以使用这个函数设置弹窗的内容
    void setContent(const QString &content) {
        contentLabel->setText(content);
    }
private:
    QLabel *contentLabel;
    QPushButton *closeButton;
};
//成功弹窗
class SuccessScene : public PopScene {
    Q_OBJECT
public:
    SuccessScene(QWidget *parent = nullptr) : PopScene(parent) {
        // 设置对话框的标题
        setWindowTitle(u8"过关");
        this->resize(500,200);

        // 添加一个按钮用于返回菜单
        QPushButton *returnToMenuButton = new QPushButton(u8"返回菜单", this);
        connect(returnToMenuButton, &QPushButton::clicked, this, &SuccessScene::returnToMenuClicked);
        returnToMenuButton->move(this->width()*0.4,this->height()*0.8);
        this->setStyleSheet("QDialog {border: 0px solid rgba(240, 240, 240, 200);background-image:url(:/res/success.png);background-color: rgba(255,255,255,250);}"
                            "QPushButton { background-color: white; }"
                            "QPushButton:hover { background-color: gray; }");
    }
signals:
    void nextLevelClicked();      // 当用户点击下一关按钮时触发的信号
    void returnToMenuClicked();   // 当用户点击返回菜单按钮时触发的信号
};
//失败弹窗
class FailScene:public PopScene
{
    Q_OBJECT
public:
    FailScene(QWidget *parent = nullptr) : PopScene(parent) {
        // 设置对话框的标题
        setWindowTitle(u8"失败");
this->resize(500,200);
        // 添加一个按钮用于重新开始
        QPushButton *restartButton = new QPushButton(u8"重新开始", this);
        connect(restartButton, &QPushButton::clicked, this, &FailScene::restartClicked);
        restartButton->move(this->width()*0.1,this->height()*0.8);
        // 添加一个按钮用于返回菜单
        QPushButton *returnToMenuButton = new QPushButton(u8"返回菜单", this);
        connect(returnToMenuButton, &QPushButton::clicked, this, &FailScene::returnToMenuClicked);
        returnToMenuButton->move(this->width()*0.7,this->height()*0.8);
        // 设置对话框的布局
        this->setStyleSheet("QDialog {border: 4px solid rgba(240, 240, 240, 200);background-image:url(:/res/wall.png);background-color: rgba(255,255,255,250);}"
                            "QPushButton { background-color: white; }"
                            "QPushButton:hover { background-color: gray; }");
    }

signals:
    void restartClicked();      // 当用户点击下一关按钮时触发的信号
    void returnToMenuClicked();   // 当用户点击返回菜单按钮时触发的信号
};
//退出弹窗
class QuitScene:public PopScene
{
    Q_OBJECT
public:
   QuitScene(QWidget *parent = nullptr) : PopScene(parent) {
        this->resize(500,200);
        // 添加一个按钮用于取消
        QPushButton *cancelButton = new QPushButton(u8"取消", this);
        connect(cancelButton, &QPushButton::clicked, this, &QuitScene::cancelClicked);
        cancelButton->move(this->width()*0.1,this->height()*0.8);
        // 添加一个按钮用于确定
        QPushButton *ensureButton = new QPushButton(u8"确定", this);
        connect(ensureButton, &QPushButton::clicked, this, &QuitScene::ensureClicked);
        ensureButton->move(this->width()*0.7,this->height()*0.8);
        // 设置对话框的布局
        this->setStyleSheet("QDialog {border: 2px solid rgba(240, 240, 240, 200);background-image:url(:/res/quitScene.png);background-color: rgba(255,255,255,250);}"
                      "QPushButton { background-color: white; }"
                      "QPushButton:hover { background-color: gray; }");
    }

signals:
    void cancelClicked();      // 当用户点击取消按钮时触发的信号
    void ensureClicked();   // 当用户点击确认按钮时触发的信号
};


#endif // POPSCENE_H
