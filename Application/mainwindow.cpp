#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    new_game_flag{false},
    game_running{false},
    cancel_flag{false},
    exit_flag{false},
    bg_thread_finished{false}
{
    ui->setupUi(this);
    createGameBoard();
    QObject::connect(ui->start_button, SIGNAL(clicked()), this, SLOT(startBtnClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createGameBoard()
{
    for (unsigned row = 0; row < 8; ++row)
    {
        for (unsigned col = 0; col < 8; ++col)
        {
            QPushButton* field = new QPushButton();
            field->setFixedSize(45, 45);
            QObject::connect(field, SIGNAL(clicked()), this, SLOT(fieldClicked()));
            ui->grid_layout->addWidget(field, row, col);
        }
    }
    ui->grid_layout->setHorizontalSpacing(0);
    ui->grid_layout->setVerticalSpacing(0);
}

void MainWindow::fieldClicked()
{
    QPushButton* field = (QPushButton*) QObject::sender();
    int index = ui->grid_layout->indexOf(field);
    int row{0}, column{0}, row_span{0}, column_span{0};
    ui->grid_layout->getItemPosition(index, &row, &column, &row_span, &column_span);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    exit_flag = true;
    while(!bg_thread_finished){}
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    event->accept();
}

void MainWindow::startBtnClicked()
{
    if(!game_running)
    {
        new_game_flag = true;
    }
    else
    {
        cancel_flag = true;
    }
}

void MainWindow::setUpGame()
{
    new_game_flag = false;
    game_running = true;
    ui->start_button->setText("Abandon");
}

void MainWindow::clearGame()
{
    cancel_flag = false;
    game_running = false;
    ui->start_button->setText("New Game");
}
