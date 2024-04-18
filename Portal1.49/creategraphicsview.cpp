#include "creategraphicsview.h"

CreateGraphicsView::CreateGraphicsView(QWidget *parent)
    : QGraphicsView{parent}
{

}

void CreateGraphicsView::keyPressEvent(QKeyEvent *event)
{

    emit keyPress(event);

    QGraphicsView::keyPressEvent(event);
}
//更改
void CreateGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    emit mouseRelease();
    QGraphicsView::mouseReleaseEvent(event);
}
