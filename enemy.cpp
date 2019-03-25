#include "enemy.h"
#include <QGraphicsScene>
#include <QPropertyAnimation>

#include "game.h"

Enemy::Enemy(QObject *parent)
    : QObject(parent), QGraphicsRectItem (0, -101, 100, 100)
{
    const qint32 randomPosition = rand() % (static_cast<int>(Game::resolution().width() - rect().width()));
    setPos(randomPosition, 0);

    startMoving();
}

int Enemy::type() const
{
    return Type;
}

qreal Enemy::animatedY() const
{
    return m_animatedY;
}

void Enemy::startMoving()
{
    QPropertyAnimation *pMoveAnimation = new QPropertyAnimation(this, "animatedY");
    pMoveAnimation->setDuration(10000);
    pMoveAnimation->setStartValue(rect().y());
    pMoveAnimation->setEndValue(Game::resolution().height() + rect().height());

    pMoveAnimation->start();

    connect(pMoveAnimation, &QPropertyAnimation::valueChanged, this, [this]{
        this->setY(this->animatedY());
    });

    connect(pMoveAnimation, &QPropertyAnimation::finished, this, [this]{
        scene()->removeItem(this);
        this->deleteLater();
    });
}

void Enemy::setAnimatedY(qreal y)
{
    m_animatedY = y;
}
