#include "createscenewindow.h"
#include "ui_createscenewindow.h"
#include <QEvent>
CreateSceneWindow::CreateSceneWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateSceneWindow)
{
    ui->setupUi(this);
    maxZvalue = 0;
    minZvalue = 0;

    setCentralWidget(ui->gView);

    scene = new QGraphicsScene(0,0,1200,720);

    ui->gView->setScene(scene);
    ui->gView->setCursor(Qt::CrossCursor);
    ui->gView->setMouseTracking(true);
    ui->gView->setDragMode(QGraphicsView::RubberBandDrag);

    ui->gView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    connect(ui->gView,SIGNAL(keyPress(QKeyEvent*)),this,SLOT(on_keyPress(QKeyEvent*)));

    //更改
    //让鼠标释放的时候方块自动对齐
    connect(ui->gView,SIGNAL(mouseRelease()),this,SLOT(mouseReleaseItemAlign()));

    srand(QTime::currentTime().second());

    //添加开始门位置和结束门位置
    QImage end(":/res/gameEnd.png");
    QPixmap position;


    position=QPixmap::fromImage(end);
    startDoor = new QGraphicsPixmapItem();
    startDoor->setPixmap(position);//
    startDoor->setZValue(-1);
    startDoor->setScale(0.3);
    startDoor->setPos(1000,500);
    startDoor->setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
    startDoor->setData(1,startDoorId);
    scene->addItem(startDoor);
    position=QPixmap::fromImage(end);

    endDoor = new QGraphicsPixmapItem(QPixmap::fromImage(end));
    QTransform transform;
    transform.scale(-1, 1);  // 水平镜像
    endDoor->setTransform(transform);
    endDoor->setPixmap(position);
    endDoor->setZValue(-1);
    endDoor->setScale(0.3);
    endDoor->setPos(150,100);
    endDoor->setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
    endDoor->setData(1,endDoorId);
    scene->addItem(endDoor);

}
CreateSceneWindow::~CreateSceneWindow()
{
    delete ui;
}

void CreateSceneWindow::on_keyPress(QKeyEvent *event)
{
    int cnt = scene->selectedItems().count();
    if(cnt == 0) return;

    switch (event->key()) {
    case Qt::Key_Left:{
        for(int i = 0;i<cnt;i++)
        {
            QGraphicsItem *item = scene->selectedItems().at(i);
            item->setX(item->x()-40);
        }
        break;
    }
    case Qt::Key_Right:{
        for(int i = 0;i<cnt;i++)
        {
            QGraphicsItem *item = scene->selectedItems().at(i);
            item->setX(item->x()+40);
        }
        break;
    }
    case Qt::Key_Up:{
        for(int i = 0;i<cnt;i++)
        {
            QGraphicsItem *item = scene->selectedItems().at(i);
            item->setY(item->y()-40);
        }
        break;
    }
    case Qt::Key_Down:{
        for(int i = 0;i<cnt;i++)
        {
            QGraphicsItem *item = scene->selectedItems().at(i);
            item->setY(item->y()+40);
        }
        break;
    }
    default:
        break;
    }
}

void CreateSceneWindow::on_blackBrick_triggered()
{
    Wall *item = new Wall(1);
    item->setScale(0.2);
    item->setZValue(0);
    item->setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
    int x=450+rand()%200,y=270+rand()%120;
    x=x-x%40;y=y-y%40;
    item->setPos(x,y);
    item->setData(1,blackId);
    scene->addItem(item);
    scene->clearSelection();
    item->setSelected(true);
}


void CreateSceneWindow::on_actRestore_triggered()
{
    int cnt = scene->selectedItems().count();
    if(cnt==0) {
        ui->gView->resetTransform();
        return;
    }
    for(int i = 0;i<cnt;i++)
    {
        QGraphicsItem *item = scene->selectedItems().at(i);
        item->setScale(1);

    }
}


void CreateSceneWindow::on_whiteBrick_triggered()
{
    Wall *item = new Wall(0);
    item->setScale(0.2);
    item->setZValue(0);
    item->setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
    int x=450+rand()%200,y=270+rand()%120;
    x=x-x%40;y=y-y%40;
    item->setPos(x,y);
    item->setData(1,whiteId);
    scene->addItem(item);
    scene->clearSelection();
    item->setSelected(true);

}


void CreateSceneWindow::on_actGroup_triggered()
{
    int cnt = scene->selectedItems().count();
    if(cnt<=1) {
        return;
    }

    QGraphicsItemGroup *group = new QGraphicsItemGroup;
    scene->addItem(group);

    for(int i = 0;i<cnt;i++)
    {
        QGraphicsItem *item = scene->selectedItems().at(0);
        item->setSelected(false);
        group->addToGroup(item);


    }
    group->setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
    //更改
    group->setData(1,groupId);
    //scene->clearSelection();
    group->setSelected(true);
}





void CreateSceneWindow::on_actGroupBreak_triggered()
{
    int cnt = scene->selectedItems().count();
    if(cnt == 0) {
        return;
    }


    QList <QGraphicsItemGroup*> list;
    for(int i = 0;i<cnt;i++)
    {
        QGraphicsItem *item = scene->selectedItems().at(i);
        if(item->type() == QGraphicsItemGroup::Type)
        {
            QGraphicsItemGroup *group = qgraphicsitem_cast<QGraphicsItemGroup *>(item);
            list.append(group);
        }
    }

    foreach(auto gItem,list)
    {
        scene->destroyItemGroup(gItem);
    }
}


void CreateSceneWindow::on_actEditFront_triggered()
{
    int cnt = scene->selectedItems().count();
    if(cnt==0) {
        return;
    }
    for(int i = 0;i<cnt;i++)
    {
        QGraphicsItem *item = scene->selectedItems().at(i);
        item->setZValue(maxZvalue+1);
        //更改
        if(item->data(1) == groupId)
        {
            QList<QGraphicsItem*> itemsInGroup = item->childItems();
            for (QGraphicsItem* littleItem : itemsInGroup) {
                littleItem->setZValue(maxZvalue+1);

            }
        }
    }
    maxZvalue++;
}



void CreateSceneWindow::on_actEditBack_triggered()
{
    int cnt = scene->selectedItems().count();
    if(cnt==0) {
        return;
    }
    for(int i = 0;i<cnt;i++)
    {
        QGraphicsItem *item = scene->selectedItems().at(i);
        item->setZValue(minZvalue-1);
    }
    minZvalue--;
}


void CreateSceneWindow::on_actEditDelete_triggered()
{
    int cnt = scene->selectedItems().count();
    if(cnt == 0)
    {
        return;
    }

    for(int i = 0;i<cnt;i++)
    {
        QGraphicsItem *item = scene->selectedItems().at(0);
        scene->removeItem(item);
    }
}

//更改 保存到文件部分
void CreateSceneWindow::on_actSave_triggered()
{
    // 打开文件
    QFile qfs("itemSave.txt");

    // 进行写操作
    if(!qfs.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        qDebug()<<"打开文件失败，请生重新检查？";
    }

    QList<QGraphicsItem*> allItems = scene->items();//获取创建的所有item
    QTextStream stream(&qfs);

    for (QGraphicsItem* item : allItems) {
        // 在这里对每个图形项执行操作
        stream<<item->data(1).toString()<<" ";//输入data1
        stream<<item->zValue()<<" ";
        stream<<item->x()<<" ";
        stream<<item->y()<<"\n";
    }

    emit saveBtnClicked();
}

void CreateSceneWindow::on_actPlay_triggered()
{
    on_actSave_triggered();
    emit startPlayScene();
}


void CreateSceneWindow::on_actResetStart_triggered()
{
    startDoor->setPos(1000,500);

}


void CreateSceneWindow::on_actResetEnd_triggered()
{
    endDoor->setPos(150,100);
}

//更改
void CreateSceneWindow::mouseReleaseItemAlign()
{
    int cnt = scene->selectedItems().count();
    if(cnt == 0) {
        return;
    }



    for(int i = 0;i<cnt;i++)
    {

        QGraphicsItem *item = scene->selectedItems().at(i);

        if(item->data(1) != 3&&item->data(1) != 4)
        {
            int x,y;
            int x1 = (int)item->x() %40;
            int y1 = (int)item->y()%40;
            if(x1<20)
                x = item->x()-x1;
            else x = item->x()-x1+40;

            if(y1<20)
                y = item->y()-y1;
            else y = item->y()-y1+40;
            item->setPos(x,y);

            //            item->setPos(item->x()-(int)item->x()%40,item->y()-(int)item->y()%40);
        }

    }
}
//更改
void CreateSceneWindow::initCreateItem()
{
    // 1:创建QFile对象，指定操作的相关文件
    QFile qfs("itemSave.txt");

    // 2:打开文件进行写操作 ReadOnly ReadWrite Append Truncate
    if(!qfs.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<"打开文件失败，请生重新检查？";
    }

    else
    {

        QTextStream stream(&qfs);
        QList<QString> rowData;

        // 逐行读取文件
        while (!stream.atEnd())
        {
            QString line = stream.readLine(); // 读取一行文本

            // 使用空格分隔数据并存储在rowData中
            rowData = line.split(' ');

            // 处理rowData中的多个数据,分别是id、zvalue、x、y
            int dataId = rowData.value(0).toInt();
            int dataZvalue = rowData.value(1).toInt();
            int dataX = rowData.value(2).toInt();
            int dataY = rowData.value(3).toInt();


            //黑墙1,白墙2
            if(dataId == 1||dataId == 2)
            {
                int numOfWall;
                if(dataId == 1)//如果是黑墙
                    numOfWall = 1;
                else numOfWall = 0;//白墙


                Wall *item = new Wall(numOfWall);
                item->setScale(0.2);
                item->setZValue(dataZvalue);
                item->setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
                item->setPos(dataX,dataY);
                item->setData(1,dataId);
                scene->addItem(item);

            }

            //开始位置门
            if(dataId == 3)
            {
                startDoor->setZValue(dataZvalue);
                startDoor->setPos(dataX,dataY);
            }
            //结束位置门
            if(dataId == 4)
            {
                endDoor->setZValue(dataZvalue);
                endDoor->setPos(dataX,dataY);
            }
        }

    }

}

void CreateSceneWindow::on_actQuit_triggered()
{
    this->hide();
    emit returnChooseScene();

}
