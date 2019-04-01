#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

#include "myplane.h"
#include "bullet.h"
#include "enemy.h"

MyPlane::MyPlane()
{
    //
}

void MyPlane::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        if (x() > 0)
        {
            setX(x() - 10);
        }
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (x() < scene()->width() - rect().width())
        {
            setX(x() + 10);
        }
    }
    else if (event->key() == Qt::Key_Space)
    {
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
        bullet->startMoving();
    }

    QGraphicsRectItem::keyPressEvent(event);
}
