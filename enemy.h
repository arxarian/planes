#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal animatedY READ animatedY WRITE setAnimatedY NOTIFY animatedYChanged)

public:
    enum
    {
        Type = UserType + 1
    };

    explicit Enemy(QObject *parent = nullptr);
    int type() const override;

    qreal animatedY() const;

public slots:
    void detectCollisions();
    void startMoving();
    void setAnimatedY(qreal animatedY);

private:
    qreal m_animatedY;
    qint32 m_speed = 10000;

signals:
    void animatedYChanged();
    void planeHit();
};

#endif // ENEMY_H
