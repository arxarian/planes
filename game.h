#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    void Run();

    static QSize resolution();

public slots:
    void spawnEnemy();
};
