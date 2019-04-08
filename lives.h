#ifndef LIVES_H
#define LIVES_H

#include <QGraphicsTextItem>

class Lives : public QGraphicsTextItem
{
public:
    Lives(QGraphicsItem * parent = 0);
    void Descrease();
    int GetLifes();

private:
    int lives = 3;
};

#endif // LIVES_H
