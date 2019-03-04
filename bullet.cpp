#include "bullet.h"
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
    setY(y() - 10);

    if (y() < - rect().height())
    {
        scene()->removeItem(this);
        this->deleteLater();
    }
}
