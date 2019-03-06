#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsRectItem>

class Enemy : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    enum
    {
        Type = UserType + 1
    };

    explicit Enemy(QObject *parent = nullptr);
    int type() const override;

public slots:
    void move();
};

#endif // ENEMY_H
