#include "mypushbutton.h"
#include<QDebug>

MyPushButton::MyPushButton(QString normalImg,QString pressImg)
{
    this->normalImgPath=normalImg;
    this->pressImgPath=pressImg;
    QPixmap pix;
    bool ret =pix.load(normalImg);
    if(!ret)
    {
        qDebug()<<u8"图片加载失败";
        return;
    }
    //设置大小
    this->setFixedSize(pix.width()*0.55,pix.height()*0.55);
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width()*0.55,pix.height()*0.55));
}
