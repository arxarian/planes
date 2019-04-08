#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

#include "myplane.h"
#include "bullet.h"
#include "enemy.h"

MyPlane::MyPlane(QObject *parent)
    : QObject(parent), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/spaceship.png"));
}

int MyPlane::type() const
{
    return Type;
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
        bullet->setPos(x() + boundingRect().width() / 2 - 2, y());
        scene()->addItem(bullet);
        bullet->startMoving();

        // TODO - muzes pridat vice strel
    }

    QGraphicsPixmapItem::keyPressEvent(event);
}
