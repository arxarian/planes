#ifndef MYRECT_H
#define MYRECT_H

#include <QObject>
#include <QGraphicsPixmapItem>

class MyPlane : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    MyPlane();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // MYRECT_H
