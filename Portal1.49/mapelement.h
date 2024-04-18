//设置地图物品
#pragma once
#ifndef MAPELEMENT_H
#define MAPELEMENT_H
#include<QPixmap>
#include <QObject>
#include<QGraphicsItem>

class MapElement:public QObject
{
    Q_OBJECT
private:

    int yPos;
    int xPos;
public:
    explicit MapElement(QString path,qreal scale);
    QGraphicsPixmapItem* brick;
    int width;
    int height;
    bool meetflag=0;//判断能否产生门
    bool _active=0;
    inline void SetActive(const bool &value)
    {
        _active=value;
    }
    inline bool GetActive(){return _active;}

    virtual QRectF boundingRect() const;
protected:
    QPixmap pix;
};

#endif // MAPELEMENT_H
