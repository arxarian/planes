#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QPropertyAnimation>

Bullet::Bullet()
{
    setRect(0, 0, 10, 50);
}

int Bullet::type() const
{
    return Type;
}

qreal Bullet::animatedY() const
{
    return m_animatedY;
}

void Bullet::startMoving()
{
    QPropertyAnimation *pMoveAnimation = new QPropertyAnimation(this, "animatedY");
    pMoveAnimation->setDuration(2500);

    pMoveAnimation->setStartValue(scenePos().y());
    pMoveAnimation->setEndValue(0 - rect().height());

    pMoveAnimation->start();

    connect(pMoveAnimation, &QPropertyAnimation::valueChanged, this, [this]{
        this->setY(this->animatedY());
        this->detectCollisions();
    });

    connect(pMoveAnimation, &QPropertyAnimation::finished, this, [this]{
        scene()->removeItem(this);
        this->deleteLater();
    });
}

void Bullet::setAnimatedY(qreal y)
{
    m_animatedY = y;
}

void Bullet::detectCollisions()
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
