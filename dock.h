#ifndef DOCK_H
#define DOCK_H

#include <QWidget>

class Dock : public QWidget
{
public:
    Dock(QRect geometry, QWidget *parent = Q_NULLPTR);
};

#endif // DOCK_H
