//选择关卡界面
#include "chooselevelscene.h"
#include "ui_chooselevelscene.h"
#include"mypushbutton.h"
#include<QtWidgets>
#include<QPainter>
#include<QFile>
#include <QApplication>
#include<QListWidget>
#include<QDebug>
#include"playscene.h"


ChooseLevelScene::ChooseLevelScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseLevelScene)
{
    ui->setupUi(this);
//外观设计
    this->setFixedSize(1200,720);
    this->setWindowIcon(QPixmap(":/res/game.ico"));
    this->setWindowTitle(u8"传送门");
    //返回按钮设置
    MyPushButton * backBtn = new MyPushButton(":/res/back1",":/res/back2");
    backBtn->setParent(this);
    backBtn->move(this->width()*0.1-backBtn->width()*0.9,this->height()*0.9);
    connect(backBtn, &MyPushButton::pressed, [=]() {
        QPixmap pressPix;
        bool pressRet = pressPix.load(":/res/back2");
        if (pressRet) {
            backBtn->setIcon(pressPix);
        }
    });
    connect(backBtn, &MyPushButton::released, [=]() {
        QPixmap normalPix;
        bool normalRet = normalPix.load(":/res/back1");

        if (normalRet) {
            backBtn->setIcon(normalPix);
        }
        QTimer::singleShot(200,this,[=](){
            emit this->chooseBack();
        });
    });
    //外观设计
    imageLabel = new QLabel(this);
    imageLabel->setGeometry(800, 0, 500*0.9, 865*0.9);
    QPixmap image(":/res/ui1.png");
    imageLabel->setPixmap(image);
    imageLabel->setScaledContents(true);
    ui->menu->resize(this->width()*0.5,this->height()*0.6);
    ui->menu->setStyleSheet("QListWidget::item:hover{background-color:rgb(0,180,214,175);}"
                            "QListWidget{background-image:url(:/res/wall.png)}");
    InitChooseScene();
}
void ChooseLevelScene::InitChooseScene()
{
    //初始化地图关卡
    level = new PlayScene(0);
    QListWidgetItem * No1=new QListWidgetItem(ui->menu);
    No1->setText(tr(u8"第一关"));
    No1->setSizeHint(QSize(90,106));
    QListWidgetItem * No2=new QListWidgetItem(ui->menu);
    No2->setText(tr(u8"第二关"));
    No2->setSizeHint(QSize(90,106));
    QListWidgetItem * No3=new QListWidgetItem(ui->menu);
    No3->setText(tr(u8"第三关"));
    No3->setSizeHint(QSize(90,106));
    QListWidgetItem * No4=new QListWidgetItem(ui->menu);
    No4->setText(tr(u8"第四关"));
    No4->setSizeHint(QSize(90,106));
    QListWidgetItem * No5=new QListWidgetItem(ui->menu);
    No5->setText(tr(u8"自定义关卡"));
    No5->setSizeHint(QSize(90,106));
    connect(ui->menu,&QListWidget::itemClicked,[=](QListWidgetItem *item){
        QString levelname=item->text();
        //以横轴30竖轴18原点左上角从0开始
        if(levelname==tr(u8"第一关"))
        {
            this->hide();
            level=new PlayScene(1);
            level->show();
            level->setFocus();
        }
        else if(levelname==tr(u8"第二关"))
        {
            this->hide();
            level=new PlayScene(2);
            level->show();level->setFocus();
        }
        else if(levelname==tr(u8"第三关"))
        {
            this->hide();
            level=new PlayScene(3);
            level->show();level->setFocus();
        }
        else if(levelname==tr(u8"第四关"))
        {
            this->hide();
            level=new PlayScene(4);
            level->show();level->setFocus();
        }
        else if(levelname==tr(u8"自定义关卡"))
        {
            this->hide();
            level=new PlayScene(5);
            //更改
            connect(level->createWindow,&CreateSceneWindow::returnChooseScene,this,&ChooseLevelScene::showChooseScene);
            qDebug()<<u8"进入自定义关卡";
        }
        connect(level,&PlayScene::back,this,[=](){
            level->hide();
            delete level;
            level=new PlayScene(0);
            this->show();
        });
        connect(level,&PlayScene::back2,this,[=](){
            level->hide();
            delete level;
            level=new PlayScene(0);
            this->show();
        });
        connect(level,&PlayScene::success2,this,[=](){
            level->hide();
            delete level;
            level=new PlayScene(0);
            this->show();
        });
    });
}
//用于自定义关卡返回
void ChooseLevelScene::showChooseScene()
{
    this->show();
}
//绘画事件
void ChooseLevelScene::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    QPainter painter(this);

    QPixmap backgroundImage(":/res/Choose.jpg");
    painter.drawPixmap(0, 0, backgroundImage.width()*0.6,backgroundImage.height()*0.6, backgroundImage);
}


ChooseLevelScene::~ChooseLevelScene()
{
    delete ui;
}
