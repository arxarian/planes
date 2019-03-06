#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsRectItem>

class Bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet();

public slots:
    void move();

private:
    void removeBullet();
};

#endif // BULLET_H
