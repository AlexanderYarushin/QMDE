#include "panel.h"

Panel::Panel(QRect geometry, QWidget *parent) : QWidget(parent)
{

    QFontDatabase::addApplicationFont(":/fonts/HelveticaNeueCyr-Light.ttf");


    this->setGeometry(geometry.x(),geometry.y(),geometry.width(),geometry.height());
    this->setStyleSheet("background: rgba(0,0,0,.4); border-bottom: 1px solid rgba(0,0,0,.4);");

    QLabel *logo = new QLabel(this);
    logo->setText("λ");
    logo->move(5,0);
    logo->setFixedHeight(this->height());
    logo->setStyleSheet("color: #EEE; background: rgba(0,0,0,0);");
    logo->setFont(QFont("HelveticaNeueCyr",13));
    logo->setAlignment(Qt::AlignVCenter);

    QLabel *time = new QLabel(this);
    time->setScaledContents(true);
    time->setStyleSheet("color: #EEE; background: rgba(0,0,0,0);");
    time->setFont(QFont("HelveticaNeueCyr",11));
    time->setText("5:28 PM");
    time->setGeometry(this->width()-100-5,0,100,this->height());
    time->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
}
