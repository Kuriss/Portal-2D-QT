//主菜单界面
#include "mainscene.h"
#include "ui_mainscene.h"
#include"QPainter"
#include<QDebug>
#include"mypushbutton.h"
#include<QTimer>

#include<QGraphicsItem>
#include<QGraphicsView>
#include <QGraphicsScene>

#include<popscene.h>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene),isInstructionsVisible(false)
{
    //背景音乐初始化
    isMusicPlaying = true;
    music = new QSoundEffect();
    music->setSource(QUrl::fromLocalFile(":/res/portal-misic-1.wav"));
    music->setLoopCount(QSoundEffect::Infinite);
    music->play();

    ui->setupUi(this);
    //主界面外观
    setFixedSize(1200,720);
    setWindowIcon(QIcon(":/res/game"));
    setWindowTitle(u8"传送门");
    //退出press
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    //开始按钮
    MyPushButton * startBtn = new MyPushButton(":/res/start1",":/res/start2");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.1-startBtn->width()*0.2+30,this->height()*0.6-70);
    //实例化选择关卡
    connect(startBtn, &MyPushButton::pressed, [=]() {
        QPixmap pressPix;
        bool pressRet = pressPix.load(":/res/start2");

        if (pressRet) {
            startBtn->setIcon(pressPix);
        }
    });
    connect(startBtn, &MyPushButton::released, [=]() {
        QPixmap normalPix;
        bool normalRet = normalPix.load(":/res/start1");

        if (normalRet) {
            startBtn->setIcon(normalPix);
        }
        QTimer::singleShot(200,this,[=](){
            this->hide();
            chooseScene->show();
        });
    });
    //退出按钮
    MyPushButton * quitBtn = new MyPushButton(":/res/quit1",":/res/quit2");
    quitBtn->setParent(this);
    quitBtn->move(this->width()*0.1-startBtn->width()*0.2+30,this->height()*0.7-70);
    connect(quitBtn, &MyPushButton::pressed, [=]() {
        QPixmap pressPix;
        bool pressRet = pressPix.load(":/res/quit2");

        if (pressRet) {
            quitBtn->setIcon(pressPix);
        }
    });
    QuitScene *quitsc=new QuitScene(this);
    connect(quitBtn, &MyPushButton::released, [=]() {
        QPixmap normalPix;
        bool normalRet = normalPix.load(":/res/quit1");

        if (normalRet) {
            quitBtn->setIcon(normalPix);
            quitsc->show();
        }
    });
    connect(quitsc, &QuitScene::cancelClicked, [=]() {
        // 处理退出按钮点击事件
        quitsc->hide();
    });
    connect(quitsc, &QuitScene::ensureClicked, [=]() {
        //退出游戏
        this->close();
    });

    chooseScene = new ChooseLevelScene;
    connect(chooseScene,&ChooseLevelScene::chooseBack,this,[=](){
        chooseScene->hide();
        this->show();
    });
//说明书按钮
    QPushButton *btn=new QPushButton(u8"说明书");
    btn->setParent(this);
    btn->setGeometry(this->width()*0.1-startBtn->width()*0.2+30,this->height()*0.6+70,220,24);
    btn->setStyleSheet("QPushButton {"
                       "background-color: #a1eafb;"
                       "border: 2px solid #b9bbdf;"
                       "color: #8c82fc;"
                       "font-size: 16px;"
                       "border-radius: 5px;"
                       "}"
                       "QPushButton:pressed {"
                       "background-color: #000080;"
                       "}");
    instructionsImage.load(":/res/Introduce.png");
    instructionsImage = instructionsImage.scaled(800, 747);

    connect(btn, &QPushButton::clicked, this, &MainScene::toggleInstructionsImage);
//音乐开关按钮
    QPushButton *musicButton = new QPushButton(u8"音乐", this);
    musicButton->setGeometry(this->width() -160, this->height() - 80, 80,30);
    connect(musicButton, &QPushButton::clicked, this, &MainScene::toggleMusic);
    musicButton->setStyleSheet("QPushButton {"
                               "background-color: #a1eafb;"
                               "border: 2px solid #b9bbdf;"
                               "color: #8c82fc;"
                               "font-size: 16px;"
                               "border-radius: 5px;"
                               "}"
                               "QPushButton:pressed {"
                               "background-color: #000080;"
                               "}");
}
void MainScene::toggleInstructionsImage()
{
    //说明书显示设置
    isInstructionsVisible = !isInstructionsVisible; // 切换图片的可见性状态
    update(); // 强制重绘以更新可见性
}
void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/MainScene.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()*0.3,pix.height()*0.3);
    painter.drawPixmap(10,20,pix);
    if (isInstructionsVisible) {
        // 如果图片可见，绘制它
        painter.drawPixmap(275,15,instructionsImage);
    }
}
void MainScene::toggleMusic()
{
    if (isMusicPlaying) {
        // 停止音乐
        music->stop();
        isMusicPlaying = false;
    } else {
        // 播放音乐
        music->play();
        isMusicPlaying = true;
    }
}
MainScene::~MainScene()
{
    delete ui;
}


