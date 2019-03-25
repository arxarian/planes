#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>

#include "game.h"

Enemy::Enemy(QObject *parent) : QObject(parent)
{
    setRect(0, 0, 100, 100);

    // nastaveni nahodne pozice na x souradnici
    const qint32 randomPosition = rand() % (static_cast<int>(Game::resolution().width() - rect().width()));
    setPos(randomPosition, 0);

    // TODO - vytvor casovac (jako u strely, ktery bude volat metodu move a tim pohybovat nepritelem)
}

int Enemy::type() const
{
    // vraci typ; urceno pro detekci kolizi
    return Type;
}

void Enemy::move()
{
    // TODO - pohybuj nepritelem dolu, smaz ho, az vyletne mimo obrazovku
}
