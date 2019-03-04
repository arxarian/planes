#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "myplane.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // poskytuje plochu pro zobrazeni vetsiho poctu QGraphicsItems
    // poskytuje collision detection
    QGraphicsScene *scene = new QGraphicsScene();

    // reprezentuje obdelnik, ktery je mozne pridat do sceny
    MyPlane *myPlane = new MyPlane();
    myPlane->setRect(0, 0, 100, 100);
    myPlane->setFlag(QGraphicsItem::ItemIsFocusable);
    myPlane->setFocus();

    scene->addItem(myPlane);

    // zobrazuje scenu
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800, 600);
    view->setSceneRect(0, 0, 800, 600);

    myPlane->setPos((view->width() - myPlane->rect().width()) / 2,
                    view->height() - myPlane->rect().height());

    view->show();

    return a.exec();
}
