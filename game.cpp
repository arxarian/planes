#include "game.h"

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QTimer>

#include "myplane.h"
#include "enemy.h"

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    // poskytuje plochu pro zobrazeni vetsiho poctu QGraphicsItems
    // poskytuje collision detection
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, resolution().width(), resolution().height());
    setScene(scene);

    // reprezentuje obdelnik, ktery je mozne pridat do sceny
    MyPlane *myPlane = new MyPlane();
    myPlane->setRect(0, 0, 100, 100);
    myPlane->setFlag(QGraphicsItem::ItemIsFocusable);
    myPlane->setFocus();

    scene->addItem(myPlane);

    // place the plane in the bottom middle
    myPlane->setPos((scene->width() - myPlane->rect().width()) / 2,
                    scene->height() - myPlane->rect().height());
}

void Game::Run()
{
    show();

    // casovac, ktery kazdych 50 ms vola metodu spawnEnemy
    // vytvoreni casovace
    QTimer *timer = new QTimer(this);
    // nastaveni intervalu na 2000 ms
    timer->setInterval(2000);
    // propojeni signalu casovace a metody spawnEnemy
    connect(timer, &QTimer::timeout, this, &Game::spawnEnemy);
    // spusteni casovace
    timer->start();
}

QSize Game::resolution()
{
    return QSize(800, 600);
}

void Game::spawnEnemy()
{
    // vytvoreni objektu nepritel
    Enemy *enemy = new Enemy();
    // pridani nepritele na scenu
    scene()->addItem(enemy);
}
