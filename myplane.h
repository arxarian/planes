#ifndef MYRECT_H
#define MYRECT_H

#include <QObject>
#include <QGraphicsPixmapItem>

class MyPlane : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    enum
    {
        Type = UserType + 3
    };

    explicit MyPlane(QObject *parent = nullptr);
    int type() const override;

    int GetLives() const;
    void SetLives(int lives);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    int lives = 3;
};

#endif // MYRECT_H
