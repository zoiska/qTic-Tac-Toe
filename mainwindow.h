#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>
#include <QLabel>
#include <QMap>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    char *box = static_cast<char *>(malloc(9 * sizeof(char)));
    QLabel *displayCount = new QLabel("count: 0", this);
    QLabel *output = new QLabel("", this);

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent* event) override;
    void initialize_Array();
    void eing(int place);
    void check_Win(char *box, char player);

private:
    Ui::MainWindow *ui;
    int count = 0;
    bool *game_won = new bool(false);
    QMap<int, bool*> x_bools;
    QMap<int, bool*> o_bools;
    bool *box1_x = new bool(false);
    bool *box2_x = new bool(false);
    bool *box3_x = new bool(false);
    bool *box4_x = new bool(false);
    bool *box5_x = new bool(false);
    bool *box6_x = new bool(false);
    bool *box7_x = new bool(false);
    bool *box8_x = new bool(false);
    bool *box9_x = new bool(false);

    bool *box1_o = new bool(false);
    bool *box2_o = new bool(false);
    bool *box3_o = new bool(false);
    bool *box4_o = new bool(false);
    bool *box5_o = new bool(false);
    bool *box6_o = new bool(false);
    bool *box7_o = new bool(false);
    bool *box8_o = new bool(false);
    bool *box9_o = new bool(false);
};
#endif // MAINWINDOW_H
