#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    int screen_width = 1920;
    int screen_height = 1080;
    int app_width = 1376;
    int app_height = 768;

    this->setMinimumSize(800,600);

    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);

    this->setGeometry(screen_width/2-app_width/2,screen_height/2-app_height/2,
                      app_width, app_height);

    this->background = QImage(":/images/wallpaper.jpg");
    this->background = this->background.scaled(app_width, app_height, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    this->panel = new Panel(QRect(0,0,this->width(),25),this);

    this->win_control = new WinControl(this);
    connect(this->win_control, &WinControl::sendWindow, this, &Widget::getNewWindow);

    this->win_control->startFind();

    //this->setStyleSheet("border: 1px solid #999;");


    Dock *dock = new Dock(QRect(this->width() / 2 - 400 / 2,this->height()-50,400,50),this);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawImage(-(this->background.width()-this->width()) / 2,
                      -(this->background.height()-this->height()) / 2, this->background);
}


void Widget::getNewWindow(ulong window)
{
    if(this->winId() != window){
        qDebug() << window;
    }
}

