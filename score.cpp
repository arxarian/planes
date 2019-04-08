#include "score.h"

Score::Score()
{
    setPlainText(QString("Points: %1").arg(m_points));
    setDefaultTextColor(Qt::red);

    setScale(2);
    setZValue(1);
}

void Score::AddPoints()
{
    m_points += 10;
    setPlainText(QString("Points: %1").arg(m_points));
}
