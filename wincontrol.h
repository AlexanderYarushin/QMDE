#ifndef WINCONTROL_H
#define WINCONTROL_H

#include <QDebug>
#include <QProcess>
#include <QThread>
#include <QWindow>
#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <cmath>
#include <fixx11h.h>
#include <unistd.h>

struct win_list {
    Window* list;
    unsigned long count;
};

class WinControl : public QThread {
    Q_OBJECT
public:
    WinControl(QObject* parent = nullptr);

private:
    void run();
    char* get_property(Display* disp, Window win, Atom xa_prop_type, char* prop_name, unsigned long* size);
    Window* get_client_list(Display* disp, unsigned long* size);
    win_list list_windows(Display* disp);
    win_list oldWin;
    win_list newWin;
    bool is_work = false;

signals:
    void sendWindow(ulong window);
public slots:
    void stopFind();
    void startFind();
};

#endif // WINCONTROLTHREAD_H
