#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

#include "myplane.h"
#include "bullet.h"
#include "enemy.h"

MyPlane::MyPlane()
{
    //
}

void MyPlane::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        if (x() > 0)
        {
            setX(x() - 10);
        }
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (x() < scene()->width() - rect().width())
        {
            setX(x() + 10);
        }
    }

    // TODO - tento kod vytvori strelu, vytvor strelu pouze pokud je stisknut mezernik

//    Bullet *bullet = new Bullet();
//    bullet->setPos(x(), y());
//    scene()->addItem(bullet);
}
