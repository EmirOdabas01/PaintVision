#include "customview.h"
#include <QMouseEvent>
#include <QDebug>

CustomView::CustomView(QWidget *parent)
    : QGraphicsView(parent)
{
}

void CustomView::mousePressEvent(QMouseEvent* event)
{
    QPoint viewPos = event->pos();
    QPointF scenePos = this->mapToScene(viewPos);


    emit cordinateChanged(scenePos);
}
void CustomView::mouseMoveEvent(QMouseEvent* event)
{
    QPoint viewPos = event->pos();
    QPointF scenePos = this->mapToScene(viewPos);


    emit cordinateChanged(scenePos);
}
