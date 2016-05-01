#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "mainwindow.h"

class GameHandler
{
public:
    GameHandler(MainWindow* main_window);
    void start();

private:
    void runGameLoop();

    MainWindow* main_window;
    bool running;
};

#endif // GAMEHANDLER_H
