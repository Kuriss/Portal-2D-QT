#ifndef PLAYER_H
#define PLAYER_H
#include<QGraphicsItem>
#include<QGraphicsView>
#include <QGraphicsScene>

#include <QSettings>
#include <QApplication>
#include<QIcon>
#include<QDebug>
#include<QTimer>

#include<QPainter>
#include<QMovie>

#include<QRectF>
#include<QVector2D>
#include<QPointF>
#include<QString>
class Player:public QObject, public QGraphicsItem
{
public:
    Player();
    QPixmap Chell;
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

    void advance(int phase);
    //行动
    int xPos=0;//横坐标
    int yPos=0;//纵坐标
    int g=1;//纵向加速度
    int xSpeed=0;//水平速度初始状态
    int ySpeed=0;//竖直速度初始状态
    int jumpFlag=0;//跳跃标志

};

#endif // PLAYER_H
