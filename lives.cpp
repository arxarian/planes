#include "lives.h"
#include <QTextDocument>

Lives::Lives(QGraphicsItem *parent)
    : QGraphicsTextItem(parent)
{
    setPlainText(QString("Lives: %1").arg(m_lives)); // Lives: 3
    setDefaultTextColor(Qt::red);

    setScale(2);
    setZValue(1);
}

void Lives::Descrease()
{
    m_lives--;
    setPlainText(QString("Lives: %1").arg(m_lives)); // Lives: 2
}

int Lives::GetLifes()
{
    return m_lives;
}
