#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "lives.h"
#include "score.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    void Run();

    static QSize resolution();

public slots:
    void spawnEnemy();

private:
    Lives *lives;
    Score *score;
};
