#include "playscene.h"
#include<QPixmap>
#include<QDebug>
#include<QImage>
#include<QGraphicsProxyWidget>

PlayScene::PlayScene(int n)
{
if(n>0)
{
    scene=new QGraphicsScene();//创建场景
    scene->setSceneRect(0,0,1200,720);//设置场景大小
    QPixmap background(":/res/237659.jpg");
    background= background.scaled(600, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    this->setBackgroundBrush(background);
    setFocusPolicy(Qt::StrongFocus);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // 场景坐标原点(0,0)对应视图坐标（视图坐标）

    this->setScene(scene);
    this->setWindowTitle(u8"传送门");
    this->setWindowIcon(QIcon(":/res/game.ico"));//设置窗口标题和图标
    this->setFixedSize(1200,720);
    setMouseTracking(true);

    // 场景左上角对应视图坐标（视图坐标）
    this->setAlignment(Qt::AlignCenter);
    this->setRenderHint(QPainter::Antialiasing);//启用抗锯齿
    this->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);//当场景内容发生变化时，只更新视图中需要更新的部分，提高渲染效率
    this->setOptimizationFlag(QGraphicsView::DontAdjustForAntialiasing, true);//关闭抗锯齿调整优化，保留原始像素细节，提高渲染性能
    this->setOptimizationFlag(QGraphicsView::DontSavePainterState, true);//关闭绘画状态保存优化，避免因为过多的状态保存导致内存占用过大
    this->setCacheMode(QGraphicsView::CacheBackground);//缓存背景，减少重复渲染和绘制操作，提高性能
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//禁用水平和垂直滚动条
    this->setAlignment(Qt::AlignCenter);//设置视图的对齐方式为居中
    this->centerOn(0,0);//设置初始视角中心为（0，0）点
    Chell=new Player();
    //初始化地图设置
    level=n;
    if(n>0)
    {
        createWindow = new CreateSceneWindow();
        connect(createWindow,&CreateSceneWindow::saveBtnClicked,this,&PlayScene::savePlaySceneItem);
        connect(createWindow,&CreateSceneWindow::startPlayScene,this,&PlayScene::startPlaySceneGame);
        //更改
        connect(this,&PlayScene::initSign,createWindow,&CreateSceneWindow::initCreateItem);
        if(level==1)
        {
            InitLevel1();
        }
        else if(level==2)
        {
            InitLevel2();
        }
        else if(level==3)
        {
            InitLevel3();
        }
        else if(level==4)
        {
            InitLevel4();
        }
        else if(level == 5)
        {
            InitLevel5();
        }
        quitScene=new QuitScene;
        successScene= new SuccessScene;
        // 处理退出按钮点击事件
        connect(quitScene, &QuitScene::cancelClicked, [=]() {
            quitScene->hide();
        });
        connect(quitScene, &QuitScene::ensureClicked, [=]() {
            //退出游戏
            quitScene->hide();
            emit this->back();
        });
        // 处理下一关点击事件
        connect(successScene, &SuccessScene::nextLevelClicked, [=]() {
            successScene->hide();
            emit this->success2();
        });
        connect(successScene, &SuccessScene::returnToMenuClicked, [=]() {
            //返回上一个界面
            successScene->hide();
            emit this->back2();
        });
        //定时器
        //帧率控制
        gun=new Gun(":/res/portalGun.png", scene);
        int gunWidth = gun->boundingRect().width(); // 获取枪的宽度
        int gunHeight = gun->boundingRect().height(); // 获取枪的高度
        int windowWidth = this->width(); // 获取窗口的宽度

        int gunX = (windowWidth - gunWidth) / 2; // 让枪水平居中
        int gunY = this->height() - gunHeight; // 将枪放置在底部

        gun->setPos(gunX, gunY);
        Chell->setFlag(QGraphicsItem::ItemIsMovable);
        gun->setZValue(1);
        gun->setParentItem(Chell);
        gun->setPos(-10,50);
        gun->setData(1,gunId);

        bluePortal=new Portal(1,scene);
        yellowPortal=new Portal(0,scene);

        timer=new QTimer;
        moveTimer=new QTimer;
        jumpTimer=new QTimer;

        connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));

        connect(timer,&QTimer::timeout,this,&PlayScene::MainGame);
        connect(timer,&QTimer::timeout,this,&PlayScene::CollisionDetection);
        connect(moveTimer, &QTimer::timeout, this, &PlayScene::updatePlayerPosition);
        connect(jumpTimer, &QTimer::timeout, this, &PlayScene::updatePlayerHeigth);

        connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
        if(n!=5){
            timer->start(30);
            moveTimer->start(30);
            jumpTimer->start(30);
        }
    }
}
}
void PlayScene::CollisionDetection()
{
    isPortal();
    if(isEnd(Chell,End))
    {
        successScene->show();
        timer->stop();
        moveTimer->stop();
        jumpTimer->stop();
    }
}
//摆放地图
void PlayScene::PlayMap(int direction,int x,int y,int num,int color)
{
    //通过传入格子来摆放墙壁与地板，几个格子，横还是竖，第几个位置，其中横长1200/40=30个格子,竖长18个格子
    //调用参数direction控制横竖位置，n为格子数量，k为第几个格子color控制颜色color=1控制白色0控制黑色
    //横方向向右边延展，竖方向向下延展
    if(direction==1)
    {
            for(int i=x*40;i<(x+num)*40;i+=40)//地板
            {
            //墙壁应该位于中间
            side=new SideWall();
            side->setScale(0.2);
            side->setZValue(-1);
            side2=new SideWall();
            side2->setScale(0.2);
            side2->setZValue(-1);
            //天花板应该位于中间
            ceil=new Ceiling();
            ceil->setScale(0.2);
            ceil->setZValue(-1);
            //地板应该位于中间
            ground=new Ground();
            ground->setScale(0.2);
            ground->setZValue(-1);

            side->setPos(i-1,y*40+10);
            scene->addItem(side);
            side2->setPos(i+31,y*40+10);
            scene->addItem(side2);
            this->rightSideArr.push_back(side);
            this->leftSideArr.push_back(side2);

            scene->addItem(ceil);
            ceil->setPos(i+16.5,y*40+41);
            this->CeilingArr.push_back(ceil);

            ground->setPos(i+16.5,y*40-1);
            scene->addItem(ground);
            this->GroundArr.push_back(ground);

            brick=new Wall(color);
            brick->setScale(0.2);
            brick->setZValue(0);
            scene->addItem(brick);
            brick->setPos(i,y*40);
            if(color==1)
            {
                this->BlackWallArr.push_back(brick);
            }
            else
            {
                this->WhiteWallArr.push_back(brick);
            }
        }
    }
    else
    {
        for(int i=y*40;i<(y+num)*40;i+=40)//墙壁
        {
            //墙壁应该位于中间
            side=new SideWall();
            side->setScale(0.2);
            side->setZValue(-1);
            side2=new SideWall();
            side2->setScale(0.2);
            side2->setZValue(-1);
            //天花板应该位于中间
            ceil=new Ceiling();
            ceil->setScale(0.2);
            ceil->setZValue(-1);
            //地板应该位于中间
            ground=new Ground();
            ground->setScale(0.2);
            ground->setZValue(-1);

            side->setPos(x*40-1,i+10);
            scene->addItem(side);
            side2->setPos(x*40+31,i+10);
            scene->addItem(side2);
            this->rightSideArr.push_back(side);
            this->leftSideArr.push_back(side2);

            scene->addItem(ceil);
            ceil->setPos(x*40+16.5,i+41);
            this->CeilingArr.push_back(ceil);


            ground->setPos(x*40+16.5,i-1);
            scene->addItem(ground);
            this->GroundArr.push_back(ground);

            brick=new Wall(color);
            brick->setScale(0.2);
            brick->setZValue(0);
            brick->setPos(x*40,i);
            scene->addItem(brick);
            if(color==1)
            {
                this->BlackWallArr.push_back(brick);
            }
            else
            {
                this->WhiteWallArr.push_back(brick);
            }
        }
    }
}
//摆放起点终点
void PlayScene::PlaceStrEnd(int xPos1,int yPos1,int xPos2,int yPos2)
{
    QImage end(":/res/gameEnd.png");
    QPixmap position;
    position=QPixmap::fromImage(end);
    Start = new QGraphicsPixmapItem();
    Start->setPixmap(position);//
    Start->setZValue(-1);
    Start->setScale(0.3);
    Start->setPos(xPos1*40,yPos1*40);
    scene->addItem(Start);
    position=QPixmap::fromImage(end);

    End = new QGraphicsPixmapItem(QPixmap::fromImage(end));
    QTransform transform;
    transform.scale(-1, 1);  // 水平镜像
    End->setTransform(transform);
    End->setPixmap(position);
    End->setZValue(-1);
    End->setScale(0.3);
    End->setPos(xPos2*40,yPos2*40);
    endXPos=End->x();
    endYPos=End->y();
    scene->addItem(End);
}

//处理玩家
void PlayScene::PlacePlayer(int xPos,int yPos)
{
    //添加玩家部分，后期改成初始化传入参数
    Chell->setScale(0.3);
    Chell->setPos(xPos*40,yPos*40);
    Chell->xPos=xPos*40;
    Chell->yPos=yPos*40-10;

    Chell->setZValue(-2);
    scene->addItem(Chell);
}
//初始化关卡界面
void PlayScene::InitLevel1()
{
    //天花板
    this->PlayMap(1,0,0,30,1);
    this->PlayMap(1,0,1,30,1);
    //左墙
    this->PlayMap(0,0,2,1,1);
    this->PlayMap(0,1,2,1,1);
    this->PlayMap(0,0,3,6,0);
    this->PlayMap(0,1,3,6,0);
    //地板
    this->PlayMap(1,0,16,30,1);
    this->PlayMap(1,0,17,30,1);
    this->PlayMap(1,18,8,13,1);
    this->PlayMap(1,19,9,12,1);
    this->PlayMap(1,0,10,10,1);
    this->PlayMap(1,0,9,9,1);
    //右墙
    this->PlayMap(1,28,2,2,1);

    this->PlayMap(0,29,3,5,0);
    this->PlayMap(0,28,3,5,0);
    this->PlayMap(0,29,10,6,0);
    this->PlayMap(0,28,10,6,0);
    //修补

    //设置起点终点
    QImage img(":/res/escape.png");
    QImage mirroredImg = img.mirrored(true, false);
    QGraphicsPixmapItem *img2=new QGraphicsPixmapItem(QPixmap::fromImage(mirroredImg));
    img2->setPos(12*40,3*40);
    img2->setScale(0.3);
    img2->setZValue(-5);
    scene->addItem(img2);
    this->PlaceStrEnd(0,13,25,5);
    PlacePlayer(0,13);
    this->setFocus();
}
void PlayScene::InitLevel2()
{
    //天花板
    this->PlayMap(1,0,0,30,1);
    this->PlayMap(1,0,1,13,1);
    this->PlayMap(1,13,1,15,0);

    //左墙
    this->PlayMap(0,0,2,10,1);
    this->PlayMap(0,1,2,5,1);
    this->PlayMap(0,1,6,6,0);

    this->PlayMap(0,8,2,5,1);
    this->PlayMap(0,9,2,5,1);

    //地板
    this->PlayMap(1,0,16,30,1);
    this->PlayMap(1,0,17,30,1);
    this->PlayMap(1,8,6,9,1);

    this->PlayMap(1,0,15,15,1);
    this->PlayMap(1,0,14,15,1);
    this->PlayMap(1,0,13,12,1);
    this->PlayMap(1,0,12,12,1);

    this->PlayMap(1,21,11,8,1);
    //右墙
    this->PlayMap(0,29,1,11,1);
    this->PlayMap(0,28,1,10,0);

    //设置起点终点
    QImage img(":/res/escape.png");
    QImage mirroredImg = img.mirrored(true, false);
    QGraphicsPixmapItem *img2=new QGraphicsPixmapItem(QPixmap::fromImage(mirroredImg));
    img2->setPos(12*40,3*40);
    img2->setScale(0.3);
    img2->setZValue(-5);
    scene->addItem(img2);
    this->PlaceStrEnd(28,13,12,3);
    PlacePlayer(28,13);
    this->setFocus();
}
void PlayScene::InitLevel3()
{
    //天花板
    //左墙
    this->PlayMap(0,0,0,16,1);
    this->PlayMap(0,1,0,3,1);
    this->PlayMap(0,1,3,4,0);
    this->PlayMap(0,1,7,2,1);
    this->PlayMap(0,1,9,2,1);
    this->PlayMap(0,1,11,5,0);

    this->PlayMap(0,14,0,4,1);
    this->PlayMap(0,14,6,1,1);

    //地板
    this->PlayMap(1,0,16,15,1);
    this->PlayMap(1,0,17,30,1);
    this->PlayMap(1,14,7,5,1);

    this->PlayMap(1,1,7,4,1);
    this->PlayMap(1,16,12,3,1);
    //右墙
    this->PlayMap(0,29,0,17,1);
    this->PlayMap(0,28,0,17,0);

    this->PlayMap(0,15,12,5,1);
    this->PlayMap(0,19,7,6,1);
    this->PlayMap(0,18,8,4,0);

    //设置起点终点
    QImage img(":/res/escape.png");
    QImage mirroredImg = img.mirrored(true, false);
    QGraphicsPixmapItem *img2=new QGraphicsPixmapItem(QPixmap::fromImage(mirroredImg));
    img2->setPos(18*40,14*40);
    img2->setScale(0.3);
        img2->setZValue(-5);
    scene->addItem(img2);
    this->PlaceStrEnd(13,13,18,14);
    PlacePlayer(12,13);
    this->setFocus();
}
void PlayScene::InitLevel4()
{
    //天花板
    this->PlayMap(1,0,0,4,1);
    this->PlayMap(1,4,0,5,0);
    this->PlayMap(1,9,0,21,1);

    //地板
    this->PlayMap(1,0,16,4,1);
    this->PlayMap(1,0,17,4,1);
    this->PlayMap(1,4,16,5,0);
    this->PlayMap(1,9,16,21,1);


    this->PlayMap(1,0,8,8,1);
    this->PlayMap(1,12,8,7,1);
    this->PlayMap(1,24,8,8,1);

    //设置起点终点
    QImage img(":/res/escape.png");
    QGraphicsPixmapItem *img2=new QGraphicsPixmapItem(QPixmap::fromImage(img));
    img2->setPos(24*40,5*40);
    img2->setScale(0.3);
        img2->setZValue(-5);
    scene->addItem(img2);

    this->PlaceStrEnd(25,13,28,5);
    PlacePlayer(25,12);
    this->setFocus();
}
//更改
void PlayScene::InitLevel5()
{
    createWindow->setFixedSize(1298,810);

    emit initSign();

    createWindow->show();
    this->PlaceStrEnd(13,13,18,14);
    Start->setPos(1000,500);
    End->setPos(150,100);
    Chell->setScale(0.3);
    Chell->setPos(1000,500);
    Chell->xPos=1000;
    Chell->yPos=500;

    Chell->setZValue(-2);

    scene->addItem(Chell);

    Chell->xPos=1000;
    Chell->yPos=500;
    Chell->setPos(1000,500);
}

//碰撞检测
int PlayScene::isPortal()//检测墙壁颜色
{
    if(Chell->collidesWithItem(bluePortal))
    {
        switch(yellowPortal->getD())
        {
            case 1:
            {
                Chell->setPos(yellowPortal->x(),yellowPortal->y()+40);
                Chell->xPos=yellowPortal->x();
                Chell->yPos=yellowPortal->y()+40;
                break;
            }
            case 2:
            {
                Chell->setPos(yellowPortal->x(),yellowPortal->y()-40-403*0.3);
                Chell->xPos=yellowPortal->x();
                Chell->yPos=yellowPortal->y()-40-403*0.3;
                break;
            }
            case 3:
            {
                Chell->setPos(yellowPortal->x()+40,yellowPortal->y());
                Chell->xPos=yellowPortal->x()+40;
                Chell->yPos=yellowPortal->y();
                break;
            }
            case 4:
            {
                Chell->setPos(yellowPortal->x()-314*0.3-20,yellowPortal->y());
                Chell->xPos=yellowPortal->x()-314*0.3-20;
                Chell->yPos=yellowPortal->y();
                break;
            }
        }
    }
    if(Chell->collidesWithItem(yellowPortal))
    {
        switch(bluePortal->getD())
        {
        case 1:
        {
            Chell->setPos(bluePortal->x(),bluePortal->y()+40);
            Chell->xPos=bluePortal->x();
            Chell->yPos=bluePortal->y()+40;
            break;
        }
        case 2:
        {
            Chell->setPos(bluePortal->x(),bluePortal->y()-40-403*0.3);
            Chell->xPos=bluePortal->x();
            Chell->yPos=bluePortal->y()-40-403*0.3;
            break;
        }
        case 3:
        {
            Chell->setPos(bluePortal->x()+40,bluePortal->y());
            Chell->xPos=bluePortal->x()+40;
            Chell->yPos=bluePortal->y();
            break;
        }
        case 4:
        {
            Chell->setPos(bluePortal->x()-314*0.3-20,bluePortal->y());
            Chell->xPos=bluePortal->x()-314*0.3-20;
            Chell->yPos=bluePortal->y();
            break;
        }
        }
    }
    return 0;
}

int PlayScene::isGround(Player *player)
{
    for(int k=0;k<this->GroundArr.size();k++)//碰撞检测
    {
        if(player->collidesWithItem(GroundArr[k],Qt::IntersectsItemBoundingRect ))
        {
            return 1;
        }
    }
    return 0;
}
int PlayScene::isRightSide(Player *player)
{
    for(int k=0;k<this->rightSideArr.size();k++)//碰撞检测
    {
        if(player->collidesWithItem(rightSideArr[k],Qt::IntersectsItemBoundingRect ))
        {
            return 1;
        }
    }
    return 0;
}
int PlayScene::isLeftSide(Player *player)
{
    for(int k=0;k<this->leftSideArr.size();k++)//碰撞检测
    {
        if(player->collidesWithItem(leftSideArr[k],Qt::IntersectsItemBoundingRect ))
        {
            return 1;
        }
    }
    return 0;
}
int PlayScene::isCeiling(Player *player)
{
    for(int k=0;k<this->CeilingArr.size();k++)//碰撞检测
    {
        if(player->collidesWithItem(CeilingArr[k],Qt::IntersectsItemBoundingRect ))
        {
            return 1;
        }
    }
    return 0;
}
int PlayScene::isEnd(Player *player,QGraphicsPixmapItem *ending)
{
    if(player->collidesWithItem(ending,Qt::IntersectsItemBoundingRect ))
    {
        return 1;
    }
    return 0;
}

//处理鼠标键盘事件
void PlayScene::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
    {
        quitScene->show();
    }
    switch (event->key()) {
    case Qt::Key_A:
    {
        if(isLeftSide(Chell)==0)
        {
            Chell->xSpeed=10;
            direction = -1;
        }
        break;
    }
    case Qt::Key_D:
    {
        if(isRightSide(Chell)==0)
        {
            Chell->xSpeed=10;
            direction = 1;
        }
        break;
    }
    // 处理其他按键
    case Qt::Key_Space:
        if (event->isAutoRepeat()) {
            return; // 忽略自动重复的按键事件
        }
        if(isGround(Chell)==1)
        {
            Chell->ySpeed=13;
            jumping=1;
        }
    }
}
void PlayScene::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_A:
    case Qt::Key_D:
        Chell->xSpeed=0;
        direction = 0;
        break;
    case Qt::Key_Space:
        jumping = 0;
        Chell->jumpFlag=0;
        Chell->update();
    }
}

void PlayScene::updatePlayerPosition() {
    movePlayer(direction);
}

void PlayScene::updatePlayerHeigth() {
    if (jumping == 1&&isCeiling(Chell)==0)
    {
        Chell->yPos -= Chell->ySpeed;
        Chell->jumpFlag=1;
        Chell->update();
        if(Chell->ySpeed>0)
        {
            Chell->ySpeed-=Chell->g;
        }
        else if(Chell->ySpeed==0||isCeiling(Chell))
        {
            jumping=0;//跳跃状态停止
            Chell->jumpFlag=0;
            Chell->update();
        }
        Chell->setPos(Chell->xPos, Chell->yPos);
    }
    //下落判断，碰到天花板，松开空格，到达最高点
    //需要判断是否浮空再判断下降
    if (jumping==0)
    {
        Chell->yPos += Chell->ySpeed;
        Chell->ySpeed+=Chell->g;
        Chell->setPos(Chell->xPos, Chell->yPos);
        if(isGround(Chell)==1)
        {
            Chell->ySpeed=0;//碰到地板停止
            for(int k=0;k<this->GroundArr.size();k++)//碰撞检测
            {
                if(Chell->collidesWithItem(GroundArr[k],Qt::IntersectsItemBoundingRect ))
                {
                    Chell->setPos(Chell->xPos, GroundArr[k]->y()-404*0.3);
                    break;
                }
            }
        }
    }
}
void PlayScene::movePlayer(int moveDirection) {
    // 根据当前移动方向来更新玩家的位置
    if (moveDirection == -1) {
        if(isLeftSide(Chell)==1||Chell->xPos<0)
        {
            Chell->xSpeed=0;
        }
        Chell->xPos -= Chell->xSpeed; // 向左移动
    }
    else if (moveDirection == 1) {
        if(isRightSide(Chell)==1||Chell->xPos+303*0.3>1200)
        {
            Chell->xSpeed=0;
        }
        Chell->xPos += Chell->xSpeed; // 向右移动
    }
    // 更新玩家的位置
    Chell->setPos(Chell->xPos, Chell->yPos);
}

void PlayScene::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p;
    p=event->pos();
    QPointF gunScenePos = Chell->mapToScene(gun->pos());
    //画线
    gun->setTransformOriginPoint(gun->boundingRect().center());
    QLine line(gunScenePos.x(),gunScenePos.y(),p.x(),p.y());
    QLineF linef(line);
    gun->setRotation(-linef.angle());

    qreal angle = qAtan2(p.y() - gunScenePos.y(), p.x() - gunScenePos.x()) * 180.0 / 3.14159;

    // 旋转枪
    gun->setTransformOriginPoint(gun->boundingRect().center());
    gun->setRotation(angle);

}
void PlayScene::mousePressEvent(QMouseEvent *event)
{
    QPoint p = event->pos();
    QPointF gunScenePos = Chell->mapToScene(gun->pos());
    QLineF linef(gunScenePos, p);
    itemsInScene = scene->items();
    // 遍历列表，检查图形项是否存在于场景中
    for (QGraphicsItem *item : itemsInScene) {
        if (item == BlueBullet) {
            canBlueShoot=0;
            break;
        }
    }
    for (QGraphicsItem *item : itemsInScene) {
        if (item == YellowBullet) {
            canYellowShoot=0;
            break;
        }
    }
    if (event->button() == Qt::LeftButton&&canBlueShoot==1) {
        // 鼠标左键点击，发射蓝色子弹
        BlueBullet = new bullet(":/res/blueBullet.png",scene, linef.angle(), gun->scenePos(),BlackWallArr,WhiteWallArr,
                                CeilingArr,GroundArr,rightSideArr,leftSideArr,bluePortal);
        BlueBullet->setScale(0.3);
    } else if (event->button() == Qt::RightButton&&canYellowShoot==1) {
        // 鼠标右键点击，发射黄色子弹
        YellowBullet = new bullet(":/res/yellowBullet.png",scene,  linef.angle(), gun->scenePos(),BlackWallArr,WhiteWallArr,
                                  CeilingArr,GroundArr,rightSideArr,leftSideArr,yellowPortal);
        YellowBullet->setScale(0.3);
    }
    canBlueShoot=1;
    canYellowShoot=1;
}

void PlayScene::mouseReleaseEvent(QMouseEvent *event)
{

}
//游戏主循环
void PlayScene::MainGame()
{
    scene->update();
}
void PlayScene::savePlaySceneItem()
{
    QList<QGraphicsItem*> allItems = createWindow->scene->items();//获取创建的所有item

    //保存的时候清空前面保存的东西

    QList<QGraphicsItem*> claerItems = scene->items();
    for (QGraphicsItem* item : claerItems) {
        //如果是开始结束门直接继续
        if(item->data(1).toInt() == 3||item->data(1).toInt() == 4||item->data(1).toInt() == 5)
            continue;
        scene->removeItem(item);

    }
    PlacePlayer(2,13);
    for (QGraphicsItem* item : allItems) {
        // 在这里对每个图形项执行操作
        qDebug()<<"sdwd";

        //如果是黑墙
        if(item->data(1).toInt() == 1)
        {
            //因为同一个Qgraphicsitem不可以同时加入到两个场景中，所以要复制一份放到scene中
            Wall *brick = new Wall(1);
            this->BlackWallArr.push_back(brick);
            brick->setScale(item->scale());
            brick->setZValue(item->zValue());
            brick->setPos(item->pos().x(),item->pos().y());
            scene->addItem(brick);

            //墙壁应该位于中间
            side=new SideWall();
            side->setScale(0.2);
            side->setZValue(-1);
            side2=new SideWall();
            side2->setScale(0.2);
            side2->setZValue(-1);
            //天花板应该位于中间
            ceil=new Ceiling();
            ceil->setScale(0.2);
            ceil->setZValue(-1);
            //地板应该位于中间
            ground=new Ground();
            ground->setScale(0.2);
            ground->setZValue(-1);

            side->setPos(item->pos().x()-1,item->pos().y()+20);
            scene->addItem(side);
            side2->setPos(item->pos().x()+41,item->pos().y()+20);
            scene->addItem(side2);
            this->rightSideArr.push_back(side);
            this->leftSideArr.push_back(side2);

            scene->addItem(ceil);
            ceil->setPos(item->pos().x()+10,item->pos().y()+41);
            this->CeilingArr.push_back(ceil);

            ground->setPos(item->pos().x()+5,item->pos().y()-1);
            scene->addItem(ground);
            this->GroundArr.push_back(ground);



        }
        //如果是白墙
        else if(item->data(1).toInt() == 2){

            Wall *brick = new Wall(0);
            this->WhiteWallArr.push_back(brick);
            brick->setScale(item->scale());
            brick->setZValue(item->zValue());
            brick->setPos(item->pos().x(),item->pos().y());
            scene->addItem(brick);

            //墙壁应该位于中间
            side=new SideWall();
            side->setScale(0.2);
            side->setZValue(-1);
            side2=new SideWall();
            side2->setScale(0.2);
            side2->setZValue(-1);
            //天花板应该位于中间
            ceil=new Ceiling();
            ceil->setScale(0.2);
            ceil->setZValue(-1);
            //地板应该位于中间
            ground=new Ground();
            ground->setScale(0.2);
            ground->setZValue(-1);

            side->setPos(item->pos().x()-1,item->pos().y()+20);
            scene->addItem(side);
            side2->setPos(item->pos().x()+41,item->pos().y()+20);
            scene->addItem(side2);
            this->rightSideArr.push_back(side);
            this->leftSideArr.push_back(side2);

            scene->addItem(ceil);
            ceil->setPos(item->pos().x()+10,item->pos().y()+41);
            this->CeilingArr.push_back(ceil);

            ground->setPos(item->pos().x()+5,item->pos().y()-1);
            scene->addItem(ground);
            this->GroundArr.push_back(ground);

        }

        //如果是开始门
        else if(item->data(1).toInt() == 3)
        {

            Start->setZValue(item->zValue());
            Start->setScale(item->scale());
            Start->setPos(item->pos().x(),item->pos().y());
            scene->addItem(Start);

            Chell->xPos = item->pos().x();
            Chell->yPos = item->pos().y();
            Chell->setPos(Chell->xPos,Chell->yPos);

        }


        //如果是结束门
        else if(item->data(1).toInt() == 4)
        {

            End->setZValue(item->zValue());
            End->setScale(item->scale());
            End->setPos(item->pos().x(),item->pos().y());
            endXPos=End->x();
            endYPos=End->y();
            scene->addItem(End);
        }


    }
}
void PlayScene::startPlaySceneGame()
{
    createWindow->hide();
    this->show();
    //PlacePlayer(5,5);
    timer->start(30);
    moveTimer->start(30);
    jumpTimer->start(30);
}
PlayScene::~PlayScene()
{
    scene->clear();
    timer->stop();
    moveTimer->stop();
    jumpTimer->stop();
}
