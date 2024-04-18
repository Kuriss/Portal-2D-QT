//选择关卡界面
#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H
#include <QMainWindow>
#include <createscenewindow.h>
#include"playscene.h"
namespace Ui {
class ChooseLevelScene;
}
class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    ~ChooseLevelScene();
    void paintEvent(QPaintEvent *);
    //外观设计
    QLabel *imageLabel;
    //选择关卡对象
    PlayScene *level=nullptr;
public slots:
    //初始化关卡地图信息
    void InitChooseScene();
    //自定义关卡返回上一界面
    void showChooseScene();
signals:
    void chooseBack();
private:
    Ui::ChooseLevelScene *ui;
    //自定义界面
    CreateSceneWindow *createWindow;
};
#endif // CHOOSELEVELSCENE_H
