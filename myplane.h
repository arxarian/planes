#ifndef MYRECT_H
#define MYRECT_H

#include <QObject>
#include <QGraphicsRectItem>

class MyPlane : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    MyPlane();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // MYRECT_H
