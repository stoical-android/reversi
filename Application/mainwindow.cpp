#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createGameBoard();
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
            ui->grid_layout->addWidget(field, row, col);
        }
    }
    ui->grid_layout->setHorizontalSpacing(0);
    ui->grid_layout->setVerticalSpacing(0);
}
