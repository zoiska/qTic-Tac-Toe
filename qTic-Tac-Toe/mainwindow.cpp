#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter linie1(this);
    QPainter circle1(this);
    QPainter painter(this);

    QRectF rectangle(305.0, 105.0, 90.0, 90.0);

    linie1.drawLine(200, 100, 200, 400);
    linie1.drawLine(300, 100, 300, 400);
    linie1.drawLine(100, 200, 400, 200);
    linie1.drawLine(100, 300, 400, 300);

    linie1.drawLine(105, 105, 185, 185);
    linie1.drawLine(105, 185, 185, 105);
    painter.drawEllipse(rectangle);
}
