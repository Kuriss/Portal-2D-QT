#include "gun.h"

Gun::Gun(const QString & filename, QGraphicsScene *scence)
{
    porgun.load(filename);
    setScale(0.2);scence->addItem(this);
}
QRectF Gun::boundingRect() const
{
    return QRectF(0,0,280,400);
}
void Gun::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    painter->drawPixmap(0,0,porgun);
}
