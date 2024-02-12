#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    setMouseTracking(true);
    initialize_Array();
    box1_x = false;
    box2_x = false;
    box3_x = false;
    box4_x = false;
    box5_x = false;
    box6_x = false;
    box7_x = false;
    box8_x = false;
    box9_x = false;
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    displayCount->move(40, 30);
    output->move(40, 40);
    displayCount->show();
    output->show();

    //QRectF rectangle(305.0, 105.0, 90.0, 90.0);
    //painter.drawEllipse(rectangle);

    painter.drawLine(200, 100, 200, 400);    //vertical left
    painter.drawLine(300, 100, 300, 400);    //vertical right
    painter.drawLine(100, 200, 400, 200);    //horizontal upper
    painter.drawLine(100, 300, 400, 300);    //horizontal lower

    if(box1_x){
        painter.drawLine(110, 110, 190, 190);
        painter.drawLine(110, 190, 190, 110);
    }
    if(box2_x){
        painter.drawLine(210, 110, 290, 190);
        painter.drawLine(210, 190, 290, 110);
    }
    if(box3_x){
        painter.drawLine(310, 110, 390, 190);
        painter.drawLine(310, 190, 390, 110);
    }
    if(box4_x){
        painter.drawLine(110, 210, 190, 290);
        painter.drawLine(110, 290, 190, 210);
    }
    if(box5_x){
        painter.drawLine(210, 210, 290, 290);
        painter.drawLine(210, 290, 290, 210);
    }
    if(box6_x){
        painter.drawLine(310, 210, 390, 290);
        painter.drawLine(310, 290, 390, 210);
    }
    if(box7_x){
        painter.drawLine(110, 310, 190, 390);
        painter.drawLine(110, 390, 190, 310);
    }
    if(box8_x){
        painter.drawLine(210, 310, 290, 390);
        painter.drawLine(210, 390, 290, 310);
    }
    if(box9_x){
        painter.drawLine(310, 310, 390, 390);
        painter.drawLine(310, 390, 390, 310);
    }
}

void MainWindow::mousePressEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton){
        if(event->pos().x() > 100 && event->pos().x() < 200 && event->pos().y() > 100 && event->pos().y() < 200){  //box 1
            eing(0);
        }
        if(event->pos().x() > 200 && event->pos().x() < 300 && event->pos().y() > 100 && event->pos().y() < 200){  //box 2
            eing(1);
        }
        if(event->pos().x() > 300 && event->pos().x() < 400 && event->pos().y() > 100 && event->pos().y() < 200){  //box 3
            eing(2);
        }
        if(event->pos().x() > 100 && event->pos().x() < 200 && event->pos().y() > 200 && event->pos().y() < 300){  //box 4
            eing(3);
        }
        if(event->pos().x() > 200 && event->pos().x() < 300 && event->pos().y() > 200 && event->pos().y() < 300){  //box 5
            eing(4);
        }
        if(event->pos().x() > 300 && event->pos().x() < 400 && event->pos().y() > 200 && event->pos().y() < 300){  //box 6
            eing(5);
        }
        if(event->pos().x() > 100 && event->pos().x() < 200 && event->pos().y() > 300 && event->pos().y() < 400){  //box 7
            eing(6);
        }
        if(event->pos().x() > 200 && event->pos().x() < 300 && event->pos().y() > 300 && event->pos().y() < 400){  //box 8
            eing(7);
        }
        if(event->pos().x() > 300 && event->pos().x() < 400 && event->pos().y() > 300 && event->pos().y() < 400){  //box 9
            eing(8);
        }
    }
}

void MainWindow::initialize_Array(){
    for(int i = 0; i < 9; i++){
        box[i] = '_';
    }
}

void MainWindow::eing(int place){
    if(box[place] != '_'){
        output->setText(QString("Ungueltige Eingabe!"));
    }
    else {
        box[place] = 'X';
        this->box1_x = true;
        update();
        count++;
        displayCount->setText(QString("count: %1").arg(count));
        check_Win(box, 'X');
    }
}

void MainWindow::check_Win(char *box, char player){
    if((box[0] == player && box[1] == player && box[2] == player)
       || (box[3] == player && box[4] == player && box[5] == player)
       || (box[6] == player && box[7] == player && box[8] == player)
       || (box[0] == player && box[3] == player && box[6] == player)
       || (box[1] == player && box[4] == player && box[7] == player)
       || (box[2] == player && box[5] == player && box[8] == player)
       || (box[0] == player && box[4] == player && box[8] == player)
       || (box[2] == player && box[4] == player && box[6] == player)){
        output->setText(QString("Spieler <%1> hat gewonnen").arg(player));
        exit(0);
    }
    else if(box[0] != '_' && box[1] != '_' && box[2] != '_' && box[3] != '_'&& box[4] != '_'
            && box[5] != '_' && box[6] != '_' && box[7] != '_' && box[8] != '_') {
        output->setText(QString("Unentschieden!"));
        exit(0);
    }
}