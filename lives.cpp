#include "lives.h"
#include <QTextDocument>

Lives::Lives(QGraphicsItem *parent)
    : QGraphicsTextItem(parent)
{
    setPlainText(QString("Lives: %1").arg(lives)); // Lives: 3
    setDefaultTextColor(Qt::red);

    setScale(2);
    setZValue(1);
}

void Lives::Descrease()
{
    lives--;
    setPlainText(QString("Lives: %1").arg(lives)); // Lives: 2
}

int Lives::GetLifes()
{
    return lives;
}
