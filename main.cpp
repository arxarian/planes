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
    scene->setSceneRect(0, 0, 800, 600);

    // reprezentuje obdelnik, ktery je mozne pridat do sceny
    MyPlane *myPlane = new MyPlane();
    myPlane->setRect(0, 0, 100, 100);
    myPlane->setFlag(QGraphicsItem::ItemIsFocusable);
    myPlane->setFocus();

    scene->addItem(myPlane);

    myPlane->setPos((scene->width() - myPlane->rect().width()) / 2,
                    scene->height() - myPlane->rect().height());

    // zobrazuje scenu
    QGraphicsView *view = new QGraphicsView(scene);

    view->show();

    return a.exec();
}
