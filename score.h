#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
public:
    Score();
    void AddPoints();

private:
    int m_points = 0;
};

#endif // SCORE_H
