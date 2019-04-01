#include "enemy.h"
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QRandomGenerator>

#include "game.h"

Enemy::Enemy(QObject *parent)
    : QObject(parent), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/meteorit.png"));
    setScale(qBound(0.3, QRandomGenerator::global()->generateDouble(), 1.0));

    const qint32 randomPosition = rand() % (static_cast<int>(Game::resolution().width() - boundingRect().width()));
    setPos(randomPosition, 0);
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
    pMoveAnimation->setStartValue(scenePos().y());
    pMoveAnimation->setEndValue(Game::resolution().height() + boundingRect().height());

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
