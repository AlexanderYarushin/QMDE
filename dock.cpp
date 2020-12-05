#include "dock.h"

Dock::Dock(QRect geometry, QWidget *parent) : QWidget(parent)
{
    this->setGeometry(geometry.x(),geometry.y(),geometry.width(),geometry.height());
    this->setStyleSheet("background: rgba(0,0,0,.5);"
                        "border-left: 1px solid #444;"
                        "border-top: 1px solid #444;"
                        "border-right: 1px solid #444;"
                        "border-top-left-radius: 5px;"
                        "border-top-right-radius: 5px;");
}
