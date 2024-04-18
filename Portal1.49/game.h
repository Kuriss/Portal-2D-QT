//初始化以及更新游戏数据，使用定时器控制游戏帧率
#ifndef GAME_H
#define GAME_H
#include<QWidget>

class Game:public QWidget
{
    Q_OBJECT
public:
    Game(QWidget* parent=nullptr);
    void initGame(const QString &background);
    void updateGame();
    void drawGame(QPainter *painter);


private:
};

#endif // GAME_H
