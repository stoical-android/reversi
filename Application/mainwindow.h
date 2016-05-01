#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <chrono>
#include <thread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool newGameRequested(){ return new_game_flag; }
    bool cancelRequested(){ return cancel_flag; }
    bool exitRequested(){ return exit_flag; }
    void setUpGame();
    void clearGame();
    void confirmExit() {bg_thread_finished = true; }

private slots:
    void fieldClicked();
    void startBtnClicked();

private:
    Ui::MainWindow *ui;
    void createGameBoard();
    void closeEvent(QCloseEvent *event);

    bool new_game_flag;
    bool game_running;
    bool cancel_flag;
    bool exit_flag;
    bool bg_thread_finished;
};

#endif // MAINWINDOW_H
