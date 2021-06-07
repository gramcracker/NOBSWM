#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H
extern "C" {
#include <X11/Xlib.h>
}
#include <iostream>
#include <map>
#include <vector>
#include "rapidxml/rapidxml.hpp"


using namespace std;
using namespace rapidxml;

class WindowManager {

public:

    WindowManager();
    // Disconnects from the X server.
    ~WindowManager();
    // The entry point to this class. Enters the main event loop.

    void configure();

    void init();

    void run();
    
private:

    void sortWindowGrid();

    void queryWindows();

    void arrange();

    void onKeyPress(XKeyEvent &e);

    void swapWindows(int xa, int ya, int xb, int yb);

    int windowIndex(Window* windows, Window window);

    string textConfName = "wm.conf";
    char* xmlConfName = "config.xml";
    Display * display;
    Window root, parent;
    Window * windows; 
    map <string, string> keymap;
    unsigned int numWindows = 0;
    xml_document <> doc;
    vector <vector<Window*>> windowGrid;
};

#endif
