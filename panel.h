#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QLabel>
#include <QFontDatabase>
#include <QDebug>

class Panel : public QWidget
{
public:
    Panel(QRect geometry, QWidget *parent = Q_NULLPTR);
};

#endif // PANEL_H
