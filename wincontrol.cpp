#include "wincontrol.h"

#define MAX_PROPERTY_VALUE_LEN 4096

WinControl::WinControl(QObject* parent)
    : QThread(parent)
{

    Display* dpy;
    if ((dpy = XOpenDisplay(NULL))) {
        oldWin = list_windows(dpy);
    }
}

void WinControl::run()
{
    Display* dpy;
    bool find = false;

    while (true) {
        if (this->is_work) {
            if ((dpy = XOpenDisplay(NULL))) {
                QThread::msleep(300);

                newWin = list_windows(dpy);

                for (unsigned long i = 0; i < newWin.count; ++i) {
                    find = false;
                    for (unsigned long j = 0; j < oldWin.count; ++j) {
                        if (newWin.list[i] == oldWin.list[j]) {
                            find = true;
                            break;
                        }
                    }

                    if (!find) {
                        emit sendWindow(newWin.list[i]);
                    }
                }

                oldWin = newWin;
            }
        } else {
            break;
        }
    }
}

void WinControl::startFind()
{
    this->is_work = true;
    this->start();
}

void WinControl::stopFind()
{
    this->is_work = false;
}

char* WinControl::get_property(Display* disp, Window win, Atom xa_prop_type, char* prop_name, unsigned long* size)
{
    Atom xa_prop_name;
    Atom xa_ret_type;
    int ret_format;
    unsigned long ret_nitems;
    unsigned long ret_bytes_after;
    unsigned long tmp_size;
    unsigned char* ret_prop;
    char* ret;

    xa_prop_name = XInternAtom(disp, prop_name, False);

    if (XGetWindowProperty(disp, win, xa_prop_name, 0, MAX_PROPERTY_VALUE_LEN / 4, False,
                           xa_prop_type, &xa_ret_type, &ret_format,
                           &ret_nitems, &ret_bytes_after, &ret_prop)
        != Success) {

        return NULL;
    }

    if (xa_ret_type != xa_prop_type) {

        XFree(ret_prop);
        return NULL;
    }

    tmp_size = (ret_format / (32 / sizeof(long))) * ret_nitems;
    ret = (char*)malloc(tmp_size + 1);
    memcpy(ret, ret_prop, tmp_size);
    ret[tmp_size] = '\0';

    if (size) {
        *size = tmp_size;
    }

    XFree(ret_prop);
    return ret;
}

Window* WinControl::get_client_list(Display* disp, unsigned long* size)
{
    Window* client_list;

    if ((client_list = (Window*)get_property(disp, DefaultRootWindow(disp),
                                               XA_WINDOW, "_NET_CLIENT_LIST", size))
        == NULL) {
        if ((client_list = (Window*)get_property(disp, DefaultRootWindow(disp),
                                                   XA_CARDINAL, "_WIN_CLIENT_LIST", size))
            == NULL) {
            fputs("Cannot get client list properties. \n"
                  "(_NET_CLIENT_LIST or _WIN_CLIENT_LIST)"
                  "\n",
                  stderr);
            return NULL;
        }
    }

    return client_list;
}

win_list WinControl::list_windows(Display* disp)
{
    Window* client_list;
    unsigned long client_list_size;

    client_list = get_client_list(disp, &client_list_size);

    win_list result;
    result.list = client_list;
    result.count = client_list_size / sizeof(Window);

    XCloseDisplay(disp);

    return result;
}
