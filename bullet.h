#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal animatedY READ animatedY WRITE setAnimatedY NOTIFY animatedYChanged)

public:
    enum
    {
        Type = UserType + 2
    };

    Bullet();
    int type() const override;

    qreal animatedY() const;

public slots:
    void detectCollisions();
    void startMoving();
    void setAnimatedY(qreal y);

private:
    void removeBullet();
    qreal m_animatedY;

signals:
    void animatedYChanged();
};

#endif // BULLET_H
