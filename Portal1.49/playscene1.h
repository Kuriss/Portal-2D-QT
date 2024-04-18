//设置游戏场景
#pragma once
#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include<QDebug>
#include<QGraphicsItem>
#include<QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QSettings>
#include <QApplication>
class PlayScene :public QGraphicsView
{
    Q_OBJECT
public:
    explicit PlayScene();
    QGraphicsScene* scene;
    QGraphicsPixmapItem * g_background;
    void PlaceWall(QString &back,int n,int direction,int color);//n循环摆放砖块,direction来判断是水平还是垂直
    void PlayMap();
    // void paintEvent(QPaintEvent *);//布置地图
    void PlaceStrEnd(int xPos1,int yPos1,int xPos2,int yPos2);
private:

protected:
//    void keyPressEvent(QKeyEvent *event) override;
//    void keyReleaseEvent(QKeyEvent *event) override;
//    void mouseMoveEvent(QMouseEvent *event) override;
//    void mousePressEvent(QMouseEvent *event) override;
//    void mouseReleaseEvent(QMouseEvent *event) override;
signals:

};
#endif // PLAYSCENE_H

