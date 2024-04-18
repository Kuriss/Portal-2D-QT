#ifndef MAP_H
#define MAP_H
#include<QPixmap>
#include<QGraphicsPixmapItem>
#include <QGraphicsScene>

#include<QGraphicsItem>
#include<QGraphicsView>
#include<QPainter>

class Map: public QGraphicsItem
{
public:
    Map(QGraphicsScene *scene);
    QGraphicsPixmapItem* map;
    void PlaceWall(QString &back,int n,int direction,int color);//n循环摆放砖块,direction来判断是水平还是垂直
    void PlaceStrEnd(int xPos,int yPos,int xPos2,int yPos2);
    void PlaceElement(int xPos,int yPos);
protected:
    QPixmap wall;//边缘
    QPixmap start;//起点
    QPixmap end;//终点
    QPixmap background;
    QGraphicsScene *scene;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    QRectF boundingRect() const;
};

#endif // MAP_H
