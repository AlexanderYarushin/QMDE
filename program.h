#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include <QWindow>
#include <QProcess>
#include <QWidget>
#include <QDebug>
#include <QFrame>

class Program : public QWidget
{
public:
    Program(QWidget *parent = Q_NULLPTR);
    void setWindow(QWindow *window);
    void setProcess(QProcess *process);
private:
    int header_height;
    QWidget *parent;
    QWindow *window;
    QProcess *process;
};

#endif // PROGRAM_H
