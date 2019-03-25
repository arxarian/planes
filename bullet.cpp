#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>

Bullet::Bullet()
{
    // velikost strely 10 x 50 px
    setRect(0, 0, 10, 50);

    // casovac, ktery kazdych 50 ms vola metodu move
    // vytvoreni casovace
    QTimer *timer = new QTimer(this);
    // nastaveni intervalu na 50 ms
    timer->setInterval(50);
    // propojeni signalu casovace a metody move
    connect(timer, &QTimer::timeout, this, &Bullet::move);
    // spusteni casovace
    timer->start();
}

void Bullet::move()
{
    // tato metoda je volana kazdych 50 ms casovacem vytvorenem v konstrukoru

    // TODO
    // strela se ma pohybovat zdola vzhuru (souradnice y)
    // az zmizi za okraj, zavolej metodu removeBullet
    // spolecne pridame detekci kolize strely a nepritele
}

void Bullet::removeBullet()
{
    // vypis o smazani strely
    qDebug("bullet deleted");
    // odstraneni strely ze sceny
    scene()->removeItem(this);
    // smazani dynamicky alokovaneho objektu strely
    this->deleteLater();
}
