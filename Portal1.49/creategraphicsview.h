#ifndef CREATEGRAPHICSVIEW_H
#define CREATEGRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QKeyEvent>
class CreateGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CreateGraphicsView(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;

    //更改 鼠标施放事件
    void mouseReleaseEvent(QMouseEvent *event) override;
signals:
    void keyPress(QKeyEvent *event);
    //更改 鼠标释放传出信号给createwindow
    void mouseRelease();
};

#endif // CREATEGRAPHICSVIEW_H
