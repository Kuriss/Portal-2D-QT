#ifndef GUN_H
#define GUN_H
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

#include"player.h"
class Gun:public QObject,public QGraphicsPixmapItem
{
public:
    Gun(const QString & filename, QGraphicsScene *scene);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    Player *Chell;
    QPixmap porgun;
};

#endif // GUN_H
