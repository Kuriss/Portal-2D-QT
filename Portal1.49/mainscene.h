//设置开始界面
#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include<chooselevelscene.h>
#include <QMediaPlayer>
#include<QSoundEffect>
QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    //画背景图
    void paintEvent(QPaintEvent *);
    //背景音乐设置
    QSoundEffect *music;
    //选择关卡界面
    ChooseLevelScene *chooseScene=NULL;
private slots:
    //开关音乐的槽函数
    void toggleMusic();
    //查看说明书的槽函数
    void toggleInstructionsImage();
private:
    Ui::MainScene *ui;

    QPixmap instructionsImage;
    //音乐，说明书的开关标志
    bool isInstructionsVisible;
    bool isMusicPlaying;
};
#endif // MAINSCENE_H
