//玩家
#include "player.h"
#include<QMovie>
Player::Player()
{
    Chell.load(":/res/Player.png");
    setFlags(ItemIsFocusable);
}
QRectF Player::boundingRect() const
{
    return QRectF(0,0,314,404);
}
void Player::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    //跳跃图片切换
    if(jumpFlag==0)
    {
        Chell.load(":/res/Player.png");
    }
    else if(jumpFlag==1)
    {
        Chell.load(":/res/jump.png");
    }
    painter->drawPixmap(0, 0, Chell);
}
void Player::advance(int phase)
{
        this->setPos(mapToScene(10,0));
}
