#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QPropertyAnimation>

Bullet::Bullet()
    : QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/greenlaser.png"));
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
    pMoveAnimation->setEndValue(0 - boundingRect().height());

    pMoveAnimation->start();

    connect(pMoveAnimation, &QPropertyAnimation::valueChanged, this, [this]{
        this->setY(this->animatedY());
    });

    connect(pMoveAnimation, &QPropertyAnimation::finished, this, [this]{
        this->removeBullet();
    });
}

void Bullet::setAnimatedY(qreal y)
{
    m_animatedY = y;
}

void Bullet::removeBullet()
{
    if (scene())
    {
        scene()->removeItem(this);
    }
    this->deleteLater();
}
