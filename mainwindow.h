#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>
#include <QLabel>
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
    bool box1_x;
    bool box2_x;
    bool box3_x;
    bool box4_x;
    bool box5_x;
    bool box6_x;
    bool box7_x;
    bool box8_x;
    bool box9_x;
};
#endif // MAINWINDOW_H
