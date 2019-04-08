#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QRandomGenerator>
#include <QDebug>

#include "enemy.h"
#include "myplane.h"
#include "bullet.h"
#include "game.h"

Enemy::Enemy(QObject *parent)
    : QObject(parent), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/meteorit.png"));

    const qint32 randomPosition = rand() % (static_cast<int>(Game::resolution().width() - boundingRect().width()));
    setPos(randomPosition, -boundingRect().height());

    // TODO - nastav ruzne velke asteroidy (metoda setScale), ruzne rychle (promenna m_speed), ruzne rotovane (metoda setRotation)
}

int Enemy::type() const
{
    return Type;
}

qreal Enemy::animatedY() const
{
    return m_animatedY;
}

void Enemy::detectCollisions()
{
    const QList<QGraphicsItem *> arrCollidingItems = collidingItems();

    for (const auto& item : arrCollidingItems)
    {
        if (item->type() == Bullet::Type)
        {
            if (scene())
            {
                scene()->removeItem(item);
            }
            delete item;

            if (scene())
            {
                scene()->removeItem(this);
            }
            this->deleteLater();
        }
        else if (item->type() == MyPlane::Type)
        {
            scene()->removeItem(this);
            this->deleteLater();

            emit planeHit();
        }
    }
}

void Enemy::startMoving()
{
    QPropertyAnimation *pMoveAnimation = new QPropertyAnimation(this, "animatedY");
    pMoveAnimation->setDuration(m_speed);
    pMoveAnimation->setStartValue(scenePos().y());
    pMoveAnimation->setEndValue(Game::resolution().height() + boundingRect().height());

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

void Enemy::setAnimatedY(qreal y)
{
    m_animatedY = y;
}
