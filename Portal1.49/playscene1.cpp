#include "playscene1.h"
#include"popscene.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include"QDebug"
#include<QGraphicsView>
PlayScene::PlayScene()
{
    this->setWindowTitle(u8"传送门");
    this->setWindowIcon(QIcon(":/res/game.ico"));//设置窗口标题和图标
    setFixedSize(1200,600);


    this->scene=new QGraphicsScene(this);//创建场景
    scene->setSceneRect(0,0,500,500);//设置场景大小
    QGraphicsView view=new QGraphicsView(scene);view.setAlignment(Qt::AlignCenter);
     view.setBackgroundBrush(QPixmap(":/res/MainScene.jpg"));
    view.resize(1200,600);
    view.show();

    QPixmap background(":/res/MainScene.jpg");

    g_background = new QGraphicsPixmapItem;
    g_background->setPixmap(background);//g_background->setZValue(-0x3ffffff);
    //g_background->setScale(0.5);
    scene->addItem(g_background);


}

void PlayScene::PlaceWall(QString &back,int n,int direction,int color)
{

}
void PlayScene:: PlaceStrEnd(int xPos1,int yPos1,int xPos2,int yPos2)
{
//    start.load(":/res/Gamestart.png");
//    end.load(":/res/Gamestart.png");
//    QGraphicsItem *startPoint=new QGraphicsPixmapItem(start);
//    QGraphicsItem *endPoint=new QGraphicsPixmapItem(end);
//    startPoint->setPos(xPos1,yPos1);
//    endPoint->setPos(xPos2,yPos2);
}
//void keyPressEvent(QKeyEvent *event)
//{

//}
//void keyReleaseEvent(QKeyEvent *event)
//{

//}
//void mouseMoveEvent(QMouseEvent *event)
//{

//}
//void mousePressEvent(QMouseEvent *event)
//{

//}
//void mouseReleaseEvent(QMouseEvent *event)
//{

//}
