#include <QKeyEvent>
#include <QGraphicsScene>

#include "myplane.h"
#include "bullet.h"

MyPlane::MyPlane()
{

}

void MyPlane::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        setX(x() - 10);
    }
    else if (event->key() == Qt::Key_Right)
    {
        setX(x() + 10);
    }
    else if (event->key() == Qt::Key_Up)
    {
        setY(y() - 10);
    }
    else if (event->key() == Qt::Key_Down)
    {
        setY(y() + 10);
    }
    else if (event->key() == Qt::Key_Space)
    {
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }
}
