#ifndef WIDGET_H
#define WIDGET_H

#include "wincontrol.h"
#include "panel.h"
#include "dock.h"
#include "program.h"

#include <QWidget>
#include <QPainter>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

private:
    WinControl *win_control;
    QImage background;
    Panel *panel;

    void paintEvent(QPaintEvent*) override;

private slots:
    void getNewWindow(ulong window);
};
#endif // WIDGET_H
