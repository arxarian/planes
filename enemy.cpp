#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>

#include "game.h"

Enemy::Enemy(QObject *parent) : QObject(parent)
{
    setRect(0, 0, 100, 100);

    const qint32 randomPosition = rand() % (static_cast<int>(Game::resolution().width() - rect().width()));
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
        scene()->removeItem(this);
        this->deleteLater();
    }
}
