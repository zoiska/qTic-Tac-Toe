#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    setMouseTracking(true);
    initialize_Array();
    x_bools[0] = box1_x;
    x_bools[1] = box2_x;
    x_bools[2] = box3_x;
    x_bools[3] = box4_x;
    x_bools[4] = box5_x;
    x_bools[5] = box6_x;
    x_bools[6] = box7_x;
    x_bools[7] = box8_x;
    x_bools[8] = box9_x;

    o_bools[0] = box1_o;
    o_bools[1] = box2_o;
    o_bools[2] = box3_o;
    o_bools[3] = box4_o;
    o_bools[4] = box5_o;
    o_bools[5] = box6_o;
    o_bools[6] = box7_o;
    o_bools[7] = box8_o;
    o_bools[8] = box9_o;
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    displayCount->move(40, 30);
    output->move(40, 40);
    output->resize(200, 50);
    displayCount->show();
    output->show();

    painter.drawLine(200, 100, 200, 400);    //vertical left
    painter.drawLine(300, 100, 300, 400);    //vertical right
    painter.drawLine(100, 200, 400, 200);    //horizontal upper
    painter.drawLine(100, 300, 400, 300);    //horizontal lower

    if(*box1_x){
        painter.drawLine(110, 110, 190, 190);
        painter.drawLine(110, 190, 190, 110);
    }
    if(*box2_x){
        painter.drawLine(210, 110, 290, 190);
        painter.drawLine(210, 190, 290, 110);
    }
    if(*box3_x){
        painter.drawLine(310, 110, 390, 190);
        painter.drawLine(310, 190, 390, 110);
    }
    if(*box4_x){
        painter.drawLine(110, 210, 190, 290);
        painter.drawLine(110, 290, 190, 210);
    }
    if(*box5_x){
        painter.drawLine(210, 210, 290, 290);
        painter.drawLine(210, 290, 290, 210);
    }
    if(*box6_x){
        painter.drawLine(310, 210, 390, 290);
        painter.drawLine(310, 290, 390, 210);
    }
    if(*box7_x){
        painter.drawLine(110, 310, 190, 390);
        painter.drawLine(110, 390, 190, 310);
    }
    if(*box8_x){
        painter.drawLine(210, 310, 290, 390);
        painter.drawLine(210, 390, 290, 310);
    }
    if(*box9_x){
        painter.drawLine(310, 310, 390, 390);
        painter.drawLine(310, 390, 390, 310);
    }
    if(*box1_o){
        QRectF rectangle(105.0, 105.0, 90.0, 90.0);
        painter.drawEllipse(rectangle);
    }
    if(*box2_o){
        QRectF rectangle(205.0, 105.0, 90.0, 90.0);
        painter.drawEllipse(rectangle);
    }
    if(*box3_o){
        QRectF rectangle(305.0, 105.0, 90.0, 90.0);
        painter.drawEllipse(rectangle);
    }
    if(*box4_o){
        QRectF rectangle(105.0, 205.0, 90.0, 90.0);
        painter.drawEllipse(rectangle);
    }
    if(*box5_o){
        QRectF rectangle(205.0, 205.0, 90.0, 90.0);
        painter.drawEllipse(rectangle);
    }
    if(*box6_o){
        QRectF rectangle(305.0, 205.0, 90.0, 90.0);
        painter.drawEllipse(rectangle);
    }
    if(*box7_o){
        QRectF rectangle(105.0, 305.0, 90.0, 90.0);
        painter.drawEllipse(rectangle);
    }
    if(*box8_o){
        QRectF rectangle(205.0, 305.0, 90.0, 90.0);
        painter.drawEllipse(rectangle);
    }
    if(*box9_o){
        QRectF rectangle(305.0, 305.0, 90.0, 90.0);
        painter.drawEllipse(rectangle);
    }
}

void MainWindow::mousePressEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton && !*game_won) {
        if (event->pos().x() > 100 && event->pos().x() < 200 && event->pos().y() > 100 && event->pos().y() < 200) {  //box 1
            eing(0);
        }
        if (event->pos().x() > 200 && event->pos().x() < 300 && event->pos().y() > 100 && event->pos().y() < 200) {  //box 2
            eing(1);
        }
        if (event->pos().x() > 300 && event->pos().x() < 400 && event->pos().y() > 100 && event->pos().y() < 200) {  //box 3
            eing(2);
        }
        if (event->pos().x() > 100 && event->pos().x() < 200 && event->pos().y() > 200 && event->pos().y() < 300) {  //box 4
            eing(3);
        }
        if (event->pos().x() > 200 && event->pos().x() < 300 && event->pos().y() > 200 && event->pos().y() < 300) {  //box 5
            eing(4);
        }
        if (event->pos().x() > 300 && event->pos().x() < 400 && event->pos().y() > 200 && event->pos().y() < 300) {  //box 6
            eing(5);
        }
        if (event->pos().x() > 100 && event->pos().x() < 200 && event->pos().y() > 300 && event->pos().y() < 400) {  //box 7
            eing(6);
        }
        if (event->pos().x() > 200 && event->pos().x() < 300 && event->pos().y() > 300 && event->pos().y() < 400) {  //box 8
            eing(7);
        }
        if (event->pos().x() > 300 && event->pos().x() < 400 && event->pos().y() > 300 && event->pos().y() < 400) {  //box 9
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
        char player = (count % 2) ? 'O' : 'X';
        box[place] = player;
        if (player == 'X') {
            *x_bools[place] = true;
        }
        else {
            *o_bools[place] = true;
        }
        update();
        count++;
        displayCount->setText(QString("count: %1").arg(count));
        check_Win(box, player);
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
        *game_won = true;
    }
    else if(box[0] != '_' && box[1] != '_' && box[2] != '_' && box[3] != '_'&& box[4] != '_'
            && box[5] != '_' && box[6] != '_' && box[7] != '_' && box[8] != '_') {
        output->setText(QString("Unentschieden!"));
    }
}