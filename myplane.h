#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>

class MyPlane : public QGraphicsRectItem
{

public:
    MyPlane();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // MYRECT_H
