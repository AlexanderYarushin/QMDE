#include "panel.h"

Panel::Panel(QRect geometry, QWidget *parent) : QWidget(parent)
{
    QFontDatabase::addApplicationFont(":/fonts/Inter-Regular-slnt=0.ttf");


    this->setGeometry(geometry.x(),geometry.y(),geometry.width(),geometry.height());
    this->setStyleSheet("background: rgba(0,0,0,0.6);");

    QLabel *logo = new QLabel(this);
    logo->setText("λ");
    logo->move(5,0);
    logo->setFixedHeight(this->height());
    logo->setStyleSheet("color: #EEE; background: rgba(0,0,0,0);");
    logo->setFont(QFont("Tahoma",15,50));
    logo->setAlignment(Qt::AlignCenter);

    QLabel *time = new QLabel(this);
    time->setScaledContents(true);
    time->setStyleSheet("color: #EEE; background: rgba(0,0,0,0);");
    time->setFont(QFont("Inter-Regular-slnt=0",11));
    time->setText("23:42:33");
    time->setGeometry(this->width()-100-5,0,100,this->height());
    time->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
}
