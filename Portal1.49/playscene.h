#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QWidget>

#include<QGraphicsItem>
#include<QGraphicsView>
#include<QGraphicsScene>

#include <QSettings>
#include <QApplication>
#include<QIcon>
#include<QDebug>

#include<QPaintEvent>
#include<QKeyEvent>
#include<QMouseEvent>
#include<QPainter>
#include<QPushButton>

#include<QRectF>
#include<QLine>
#include<QLineF>

#include<QTimeLine>
#include<QTime>
#include<QTimer>


#include<createscenewindow.h>
#include"player.h"
#include"popscene.h"
#include"mypushbutton.h"
#include"wall.h"
#include"gun.h"
#include"bullet.h"
#include"portal.h"

#include <QCursor>
#include <QtMath>
#include<vector>
//更改
#include <QFile>
class PlayScene : public QGraphicsView
{
    Q_OBJECT
public:
    explicit PlayScene(int n);
    ~PlayScene();
    QGraphicsScene* scene= NULL;  
    QGraphicsView view;
    CreateSceneWindow *createWindow;

    //枪的id
    int gunId = 5;

    //不同地方存在动画的定时器
    QTimer *timer;//帧率控制
    QTimer* moveTimer;
    QTimer* jumpTimer;
    //胜利条件
    int endXPos=0;
    int endYPos=0;
    //布置地图
    void PlayMap(int direction,int x,int y,int num,int color);
    //布置起点终点
    void PlaceStrEnd(int xPos1,int yPos1,int xPos2,int yPos2);
    Wall *brick;
    Ceiling *ceil;
    Ground *ground;
    SideWall *side;
    SideWall *side2;

    QGraphicsPixmapItem * Start;
    QGraphicsPixmapItem * End;

    int level;
    void InitLevel1();
    void InitLevel2();
    void InitLevel3();
    void InitLevel4();
    void InitLevel5();
    QList<QGraphicsItem *> itemsInScene;
    //弹窗设置
    MyPushButton * backBtn;
    QuitScene *quitScene;
    SuccessScene *successScene;
    Player *Chell;
    //布置人物
    void PlacePlayer(int xPos,int yPos);
    int jumping=1;

    //下落的东西
    void movePlayer(int moveDirection);
    Gun *gun;
    bullet *BlueBullet;
    bullet *YellowBullet;
    //处理碰撞

    int isRightSide(Player *player);
    int isLeftSide(Player *player);
    int isPortal();
    int isCeiling(Player *player);
    int isGround(Player *player);
    int isEnd(Player *player,QGraphicsPixmapItem *ending);

    //地图信息
    std::vector<Wall*>BlackWallArr;//黑色方块
    std::vector<Wall*>WhiteWallArr;//白色方块
    std::vector<Ceiling*>CeilingArr;//天花板，方块下方
    std::vector<Ground*>GroundArr;//地板，方块上方
    std::vector<SideWall*>rightSideArr;//玩家的右墙，方块的左边
    std::vector<SideWall*>leftSideArr;//玩家的左墙，方块的右边

    //子弹碰撞
    int isWall(bullet *bullet);
    int canBlueShoot=1;
    int canYellowShoot=1;

    Portal * bluePortal;
    Portal * yellowPortal;

private:
public slots:
    void MainGame(); //游戏主循环
    void savePlaySceneItem();//保存按钮的槽函数
    void startPlaySceneGame();//开始游戏的槽函数
signals:
    void back();
    void back2();
    void success2();
    //更改
    void initSign();
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    int direction;

    void updatePlayerPosition();
    void updatePlayerHeigth();
    void CollisionDetection();
signals:

};

#endif // PLAYSCENE_H
