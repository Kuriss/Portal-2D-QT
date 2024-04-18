#ifndef BULLET_H
#define BULLET_H
#define PI 3.14159
#include<QGraphicsItem>
#include<QGraphicsView>
#include <QGraphicsScene>

#include <QSettings>
#include <QApplication>
#include<QIcon>
#include<QDebug>

#include<QPainter>

#include<QRectF>
#include <QtMath>
#include <cmath>

#include<wall.h>
#include<portal.h>
class bullet:public QGraphicsItem
{
public:
    //有参构造函数;
    bullet(const QString &fileName, QGraphicsScene *scene, qreal angle, const QPointF &gunPosition,std::vector<Wall*>BlackWallArr,std::vector<Wall*>WhiteWallArr,
           std::vector<Ceiling*>CeilingArr,std::vector<Ground*>GroundArr,std::vector<SideWall*>rightSideArr,std::vector<SideWall*>leftSideArr,Portal *colorPortal);

    virtual QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    //子弹移动;
    void advance(int phase);
    QPixmap porBullet;

    //墙壁
    Wall * wall;
    std::vector<Wall*>BlackWallArr;
    std::vector<Wall*>WhiteWallArr;
    std::vector<Ceiling*>CeilingArr;
    std::vector<Ground*>GroundArr;
    std::vector<SideWall*>rightSideArr;
    std::vector<SideWall*>leftSideArr;

    Portal *portal;

private:
    QGraphicsScene *scene;
};

#endif // BULLET_H
