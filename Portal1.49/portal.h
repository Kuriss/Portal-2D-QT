#ifndef PORTAL_H
#define PORTAL_H

#include<QGraphicsItem>
#include<QGraphicsView>
#include <QGraphicsScene>

class Portal:public QObject,public QGraphicsPixmapItem
{
public:
    Portal(int x, QGraphicsScene *scene);//x判断传送门颜色
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

    QPixmap imgDown;
    QPixmap imgUp;
    QPixmap imgLeft;
    QPixmap imgRight;
    QPixmap img;

    QGraphicsScene *scene;

    int D;
    void setD(int d);
    int getD();
    void setPortalImg(int direction);
};

#endif // PORTAL_H
