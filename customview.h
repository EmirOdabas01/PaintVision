#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>

class CustomView : public QGraphicsView
{
    Q_OBJECT

public:

    explicit CustomView(QWidget *parent = nullptr);

signals:
    void cordinateChanged(const QPointF &newCordinate);

protected:
    void mousePressEvent(QMouseEvent* event) override;

    explicit CustomView(QWidget *parent = nullptr) : QGraphicsView(parent) {}

protected:
    void mousePressEvent(QMouseEvent* event) override;

};

#endif // CUSTOMVIEW_H
