#ifndef CREATESCENEWINDOW_H
#define CREATESCENEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <wall.h>
#include <QTime>
#include <QKeyEvent>
//更改
#include <QTextStream>
#include <QFile>
namespace Ui {
class CreateSceneWindow;
}



class CreateSceneWindow : public QMainWindow
{
    Q_OBJECT

private:

    int maxZvalue;
    int minZvalue;
    int blackId = 1;
    int whiteId = 2;
    int startDoorId = 3;
    int endDoorId = 4;

    //更改
    int groupId = 6;

    QGraphicsPixmapItem * startDoor;
    QGraphicsPixmapItem * endDoor;


signals:
    void saveBtnClicked();//保存按钮
    void startPlayScene();//开始游戏按钮
    void returnChooseScene();

public:
    QGraphicsScene *scene;
    explicit CreateSceneWindow(QWidget *parent = nullptr);
    ~CreateSceneWindow();


private slots:
    void on_keyPress(QKeyEvent *event);


    void on_blackBrick_triggered();

    //    void on_actZoomln_triggered();

    //    void on_actZoomOut_triggered();

    void on_actRestore_triggered();

    void on_whiteBrick_triggered();

    void on_actGroup_triggered();

    void on_actGroupBreak_triggered();

    void on_actEditFront_triggered();

    void on_actEditBack_triggered();

    void on_actEditDelete_triggered();

    void on_actSave_triggered();

    void on_actPlay_triggered();

    void on_actResetStart_triggered();

    void on_actResetEnd_triggered();

    //更改
    void mouseReleaseItemAlign();

    //更改
    void on_actQuit_triggered();

    //更改
public slots:
    void initCreateItem();



private:
    Ui::CreateSceneWindow *ui;
};

#endif // CREATESCENEWINDOW_H
