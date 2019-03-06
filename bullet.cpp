#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>

Bullet::Bullet()
{
    setRect(0, 0, 10, 50);

    QTimer *timer = new QTimer(this);
    timer->setInterval(50);
    connect(timer, &QTimer::timeout, this, &Bullet::move);
    timer->start();
}

void Bullet::move()
{
    const QList<QGraphicsItem *> arrCollidingItems = collidingItems();

    for (const auto item : arrCollidingItems)
    {
        if (item->type() == Enemy::Type)
        {
            scene()->removeItem(item);
            delete item;

            removeBullet();

            return;
        }
    }

    setY(y() - 10);

    if (y() < - rect().height())
    {
        removeBullet();
    }
}

void Bullet::removeBullet()
{
    qDebug("bullet deleted");
    scene()->removeItem(this);
    this->deleteLater();
}
