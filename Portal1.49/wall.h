#ifndef WALL_H
#define WALL_H

#include<QGraphicsItem>
#include<QGraphicsView>
#include <QGraphicsScene>

#include <QSettings>
#include <QApplication>
#include<QIcon>
#include<QDebug>

#include<QPainter>

#include<QRectF>

class Wall:public QGraphicsItem
{
public:
    Wall(int x);

    virtual QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    QPixmap brick;
};
class Ceiling:public QGraphicsItem
{
public:
    Ceiling();

    virtual QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    QPixmap ceil;
};
class Ground:public QGraphicsItem
{
public:
    Ground();

    virtual QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    QPixmap ground;
};
class SideWall:public QGraphicsItem
{
public:
    SideWall();

    virtual QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    QPixmap sideWall;
};


#endif // WALL_H
