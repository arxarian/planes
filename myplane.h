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

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // MYRECT_H
