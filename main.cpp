#include <QApplication>
#include <QTime>

#include "game.h"

int main(int argc, char *argv[])
{
    qsrand(QTime::currentTime().msec());

    QApplication a(argc, argv);

    Game game;
    game.Run();

    return a.exec();
}
