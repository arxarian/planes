#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

#include "myplane.h"
#include "bullet.h"
#include "enemy.h"

MyPlane::MyPlane()
    : QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/spaceship.png"));
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
        if (x() < scene()->width() - boundingRect().width())
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

    QGraphicsPixmapItem::keyPressEvent(event);
}
