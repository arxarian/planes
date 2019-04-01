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
    void startMoving();
    void setAnimatedY(qreal animatedY);

private:
    qreal m_animatedY;

signals:
    void animatedYChanged();
};

#endif // ENEMY_H
