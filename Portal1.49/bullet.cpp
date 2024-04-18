//子弹
#include "bullet.h"
#include "qmath.h"

bullet::bullet(const QString &fileName, QGraphicsScene *scene, qreal angle, const QPointF &gunPosition,std::vector<Wall*>BlackWallArr,std::vector<Wall*>WhiteWallArr,
               std::vector<Ceiling*>CeilingArr,std::vector<Ground*>GroundArr,std::vector<SideWall*>rightSideArr,std::vector<SideWall*>leftSideArr,Portal * colorPortal)
{
    this->BlackWallArr=BlackWallArr;
    this->WhiteWallArr=WhiteWallArr;
    this->CeilingArr=CeilingArr;
    this->GroundArr=GroundArr;
    this->leftSideArr=leftSideArr;
    this->rightSideArr=rightSideArr;

    portal=colorPortal;

    this->scene = scene;
    this->setZValue(1);
    setPos(gunPosition);
    porBullet.load(fileName);
    scene->addItem(this);
    qreal dx, dy;
    qreal rad;
    rad = angle * 3.14/180;
    dx = 20 * qCos(rad);
    dy = -20 * qSin(rad);

    this->setPos(gunPosition.x()+ dx, gunPosition.y()-40 + dy);
    this->setRotation(-90-angle);
}

QRectF bullet::boundingRect() const
{
    return QRectF(0,0,135,135);
}

void bullet::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    painter->drawPixmap(-porBullet.width()/2, -porBullet.height(), porBullet);
}

void bullet::advance(int phase)
{
    //碰到边界,消失;
    if(mapToScene(0,0).x() <= 0 || mapToScene(0,0).x() >= 1300 || mapToScene(0,0).y() <= 0||mapToScene(0,0).y() >= 730)
    {
        delete this;
    }
    else//否则继续移动;
    {
        int isExist=1;
        if(isExist==1)
        {
            for(int i=0;i<BlackWallArr.size();i++)
            {
                if(this->collidingItems().contains(this->BlackWallArr[i]))
                {
                    isExist=0;
                    delete this;
                    break;
                }
            }
        }
        if(isExist==1)
        {
            for(int i=0;i<WhiteWallArr.size();i++)
            {
                if(this->collidingItems().contains(this->WhiteWallArr[i]))
                {
                    for(int j=0;j<CeilingArr.size();j++)
                    {
                        if(this->collidingItems().contains(this->CeilingArr[j]))
                        {
                            portal->setPortalImg(1);portal->setD(1);
                            portal->setPos(this->CeilingArr[j]->x(),this->CeilingArr[j]->y());
                            scene->addItem(portal);
                            isExist=0;
                            delete this;
                            break;
                        }
                    }
                    for(int j=0;j<GroundArr.size();j++)
                    {
                        if(this->collidingItems().contains(this->GroundArr[j]))
                        {
                            portal->setPortalImg(2);portal->setD(2);
                            portal->setPos(this->GroundArr[j]->x(),this->GroundArr[j]->y()-20);
                            scene->addItem(portal);
                            isExist=0;
                            delete this;
                            break;
                        }
                    }
                    for(int j=0;j<leftSideArr.size();j++)
                    {
                        if(this->collidingItems().contains(this->leftSideArr[j]))
                        {
                            portal->setPortalImg(3);portal->setD(3);
                            portal->setPos(this->leftSideArr[j]->x()+10,this->leftSideArr[j]->y()-50);
                            scene->addItem(portal);
                            isExist=0;
                            delete this;
                            break;
                        }
                    }
                    for(int j=0;j<rightSideArr.size();j++)
                    {
                        if(this->collidingItems().contains(this->rightSideArr[j]))
                        {
                            portal->setPortalImg(4);portal->setD(4);
                            portal->setPos(this->rightSideArr[j]->x()-20,this->rightSideArr[j]->y()-50);
                            scene->addItem(portal);
                            isExist=0;
                            delete this;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        if(isExist==1)
        {
            this->setPos(mapToScene(0, 15));
        }
    }
}
