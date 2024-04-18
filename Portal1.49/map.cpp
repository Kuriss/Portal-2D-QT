//创建游戏关卡对象，具体做好不同地图的类
#include "map.h"

Map::Map(QGraphicsScene *scene) {
    // 构造函数中初始化 scene 成员变量
    this->scene=scene;
}
void Map::PlaceWall(QString &back,int n,int direction,int color)
{
    background.load(back);//画背景brick->setScale(0.3);
    for(int i=0;i<n;i++)
    {
       QPixmap brickpix(":/res/BlackBrick.png");
       QGraphicsItem *brick=new QGraphicsPixmapItem(brickpix);
       brick->setPos(i*50,600);
       this->scene->addItem(brick);
    }
}
void Map:: PlaceElement(int xPos,int yPos)
{

}
QRectF Map::boundingRect() const
{
    double width=60;
    double height=30;
    return QRectF(-width/2, -height/2, width, height);
}
void Map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->drawRect(boundingRect());
}
