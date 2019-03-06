#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>

Enemy::Enemy(QObject *parent) : QObject(parent)
{
    setRect(0, 0, 100, 100);

    // TODO - get scene with. This is not working, because item is added to scene after creation => segfault
    int randomPosition = rand() % (static_cast<int>(/*scene()->width()*/800 - rect().width()));
    setPos(randomPosition, 0);

    QTimer *timer = new QTimer(this);
    timer->setInterval(50);
    connect(timer, &QTimer::timeout, this, &Enemy::move);
    timer->start();
}

int Enemy::type() const
{
    return Type;
}

void Enemy::move()
{
    setY(y() + 5);

    if (y() > scene()->height())
    {
        qDebug("enemy deleted");
        scene()->removeItem(this);
        this->deleteLater();
    }
}
