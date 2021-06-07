#ifndef UTIL_H
#define UTIL_H
#include <X11/Xlib.h>
#include <algorithm>
using namespace std;

//windex?
int windowIdex(Window* windows, Window window){
    
    int position = 0;
    return position = distance(windows, find(windows, windows+sizeof(windows), window));
    
}

#endif