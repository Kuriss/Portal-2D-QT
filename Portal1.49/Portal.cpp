#include "portal.h"

Portal::Portal(int x, QGraphicsScene *scene)
{
    if(x==1)
    {
        imgDown.load(":/res/bluePortaldown.png");
        imgUp.load(":/res/bluePortalup.png");
        imgLeft.load(":/res/bluePortalleft.png");
        imgRight.load(":/res/bluePortalright.png");
    }
    else if(x==0)
    {
        imgDown.load(":/res/orgPortaldown.png");
        imgUp.load(":/res/orgPortalup.png");
        imgLeft.load(":/res/orgPortalleft.png");
        imgRight.load(":/res/orgPortalright.png");
    }
    this->scene=scene;
}
void Portal::setPortalImg(int direction)
{
    switch(direction)
    {
    case 1:
    {
        img=imgDown;
        break;
    }
    case 2:
    {
        img=imgUp;
        break;
    }
    case 3:
    {
        img=imgLeft;
        break;
    }
    case 4:
    {
        img=imgRight;
        break;
    }
    }
    this->setPixmap(img);
    this->setZValue(-1);
    this->setScale(0.2);
}

void Portal::setD(int d)
{
    this->D=d;
}
int Portal::getD()
{
    return this->D;
}


QRectF Portal::boundingRect() const
{
    return QRectF(0,0,200,200);
}

void Portal::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    painter->drawPixmap(0, 0, img);
}
