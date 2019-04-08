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
    scene->setBackgroundBrush(QBrush(QPixmap(":/images/space.jpg")));

    // reprezentuje obdelnik, ktery je mozne pridat do sceny
    MyPlane *myPlane = new MyPlane();
    myPlane->setFlag(QGraphicsItem::ItemIsFocusable);
    myPlane->setFocus();

    scene->addItem(myPlane);

    // place the plane in the bottom middle
    myPlane->setPos((scene->width() - myPlane->boundingRect().width()) / 2,
                    scene->height() - myPlane->boundingRect().height());

    lives = new Lives();
    scene->addItem(lives);
}

void Game::Run()
{
    show();

    QTimer *timer = new QTimer(this);
    timer->setInterval(2000);
    connect(timer, &QTimer::timeout, this, &Game::spawnEnemy);
    timer->start();
}

QSize Game::resolution()
{
    return QSize(800, 600);
}

void Game::spawnEnemy()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
    enemy->startMoving();

    connect(enemy, &Enemy::planeHit, this, &Game::PlaneHit);
}

void Game::PlaneHit()
{
    lives->Descrease();
}
