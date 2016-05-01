#include "mainwindow.h"
#include "gamehandler.h"
#include <QApplication>
#include <thread>

void backgroundTask(MainWindow* main_window)
{
    GameHandler game_handler(main_window);
    game_handler.start();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::thread background_thread(backgroundTask, &w);
    background_thread.detach();
    return a.exec();
}

