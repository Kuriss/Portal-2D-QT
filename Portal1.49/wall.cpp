#include "wall.h"

Wall::Wall(int x)
{
    if(x==1)
        {
            brick.load(":/res/BlackBrick.png");
        }
    else
    {
            brick.load(":/res/WriteBrick.png");
    }
}
QRectF Wall::boundingRect() const
{
    return QRectF(0,0,100,100);
}
void Wall::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    painter->drawPixmap(0,0,brick);
}

Ceiling::Ceiling()
{
    ceil.load(":/res/ceiling.png");
}
QRectF Ceiling::boundingRect() const
{
    return QRectF(0,0,5,5);
}
void Ceiling::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    painter->drawPixmap(0,0,ceil);
}
Ground::Ground()
{
    ground.load(":/res/ceiling.png");
}
QRectF Ground::boundingRect() const
{
    return QRectF(0,0,5,5);
}
void Ground::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    painter->drawPixmap(0,0,ground);
}
SideWall::SideWall()
{
    sideWall.load(":/res/side.png");
}
QRectF SideWall::boundingRect() const
{
    return QRectF(0,0,5,75);
}
void SideWall::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    painter->drawPixmap(0,0,sideWall);
}
