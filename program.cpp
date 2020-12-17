#include "program.h"

Program::Program(QWidget *parent) : QWidget(parent),
    header_height(22)
{

    this->parent = parent;
    this->setGeometry(550,250,500,500);
   // this->setStyleSheet("border-left: 1px solid #000;");
    this->show();
    qDebug() << parent->x();

}

void Program::setWindow(QWindow *window)
{
    this->window = window;
    this->window->setFlag(Qt::WindowType::FramelessWindowHint);

    window->setGeometry(parent->x() + this->x(), parent->y() + this->y() + header_height,this->width(),this->height()-header_height);


    QWidget *handler = new QWidget(this);
    handler->setObjectName("handler");
    handler->setGeometry(0,0,this->width(),header_height);


        int btn_size = 12;

    QWidget *close_btn = new QWidget(handler);
    close_btn->setObjectName("handler_btn");
    close_btn->setGeometry(8,handler->height()/2-btn_size/2,btn_size,btn_size);



    QWidget *max_btn = new QWidget(handler);
    max_btn->setObjectName("handler_btn");
    max_btn->setGeometry(close_btn->x() + close_btn->width() + 8,handler->height()/2-btn_size/2,btn_size,btn_size);


    QWidget *min_btn = new QWidget(handler);
    min_btn->setObjectName("handler_btn");
    min_btn->setGeometry(max_btn->x() + max_btn->width() + 8,handler->height()/2-btn_size/2,btn_size,btn_size);



    handler->show();
}

void Program::setProcess(QProcess *process)
{
    this->process = process;
}
