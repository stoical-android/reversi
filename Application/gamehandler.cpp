#include "gamehandler.h"

GameHandler::GameHandler(MainWindow* main_window) :
    main_window(main_window),
    running{false}
{
}

void GameHandler::start()
{
    if (!running)
    {
        running = true;
        runGameLoop();
    }
}

void GameHandler::runGameLoop()
{
    while (true)
    {
        if (main_window->exitRequested())
            return main_window->confirmExit();

        if (main_window->newGameRequested())
        {
            main_window->setUpGame();

            while (!main_window->cancelRequested())
            {
                if (main_window->exitRequested())
                   return main_window->confirmExit();
            }

            main_window->clearGame();
        }
    }
}
