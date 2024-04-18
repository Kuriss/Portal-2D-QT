//设置人物
#ifndef OBJECT_H
#define OBJECT_H
#include<QPixmap>

class Object
{
public:
    Object();
    //设置速度接口
    inline void SetSpeed(const int &value)
    {
        speed=value;
    }
    inline int GetSpeed(){return speed;}
//设置hp接口
    inline void SetHP(const int &value)
    {
        HP=value;
    }
    inline int GetHP(){return HP;}
    inline void Destory(){HP=0;}
private:
    int HP=1;
    int speed=0;
    int xPos1;
    int yPos1;
protected:
    QPixmap pix;
};

#endif // OBJECT_H
