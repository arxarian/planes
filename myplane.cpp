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
        Bullet *bullet1 = new Bullet();
        bullet1->setPos(x() + 35, y());
        scene()->addItem(bullet1);
        bullet1->startMoving();

        Bullet *bullet2 = new Bullet();
        bullet2->setPos(x() + 61, y());
        scene()->addItem(bullet2);
        bullet2->startMoving();
    }

    QGraphicsPixmapItem::keyPressEvent(event);
}
