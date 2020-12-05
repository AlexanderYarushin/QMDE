#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include <QWindow>
#include <QProcess>

class Program
{
public:
    Program(QObject *parent = Q_NULLPTR);
private:
    QWindow *window;
    QProcess *process;

};

#endif // PROGRAM_H
