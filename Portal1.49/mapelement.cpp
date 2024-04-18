#include "mapelement.h"

MapElement::MapElement(QString path,qreal scale)
{
    QPixmap pix(path);//设置初始属性
    this->brick=new QGraphicsPixmapItem(pix);
    this->brick->setScale(scale);
    this->brick->setPos(0,518);
    this->width=pix.width()*scale;
    this->height=pix.height()*scale;
}
QRectF MapElement::boundingRect() const//碰撞体积
{
    return QRectF(this->brick->x(),this->brick->y(),this->brick->x()+this->width,this->brick->y()+this->height);
}
