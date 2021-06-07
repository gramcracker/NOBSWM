#include "wm.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include "rapidxml/rapidxml_utils.hpp"

  WindowManager::WindowManager() {

    configure();
    init();

  }


WindowManager::~WindowManager() {
  cout<<"Closing Display"<<endl;
  for (auto i : windowGrid)
   {
     for (auto j: i){
       delete j;
     }
     i.clear();
   } 
   windowGrid.clear();
  XCloseDisplay(display);
}



void WindowManager::sortWindowGrid(){
  int max_x = 0;
  int max_y = 0;
  for(auto i : windowGrid){
    for(auto j : i){
      XWindowAttributes attr;
         XGetWindowAttributes(display, *j, &attr);
      if(attr.x > max_x){
        max_x = attr.x;
        
      }
      if(attr.y > max_y){}
    }
  } 
}


void WindowManager::queryWindows(){
    cout<<"Query Tree"<<endl;
    XGrabServer(display);
    XQueryTree(display,
        XDefaultRootWindow(display),
        &root,
        &parent,
        &windows,
        &numWindows);
    for(int i = 0; i< numWindows; i++){
      windowGrid.at(0).push_back(&windows[i]);
    }
    XFree(windows);
    XUngrabServer(display);
}

int WindowManager::windowIndex(Window* windows, Window window){
    
    int position = 0;
    return position = distance(windows, find(windows, windows+sizeof(windows), window));
    
}

void WindowManager::swapWindows(int xa, int ya, int xb, int yb){
  // windowGrid.at()
}

void WindowManager::configure(){
  cout<<"Configuring"<<endl;
  ifstream infile;
  ifstream xmlDoc;
  infile.open(textConfName);
  file<> xmlFile(xmlConfName);
  char* c;
  string s;
  doc.parse<0>(xmlFile.data());
  while(getline(infile,s)){

    istringstream iss(s);
    string a,b;
    iss>>a>>b;
    keymap.insert(make_pair(a,b));
    
  }
  infile.close();
 
}

void WindowManager::onKeyPress(XKeyEvent& e){
  if(e.state & Mod2Mask){
    if(e.keycode==XKeysymToKeycode(display,XStringToKeysym("Left"))){
        unsigned int buf = 0;

    }
    else if(e.keycode==XKeysymToKeycode(display,XStringToKeysym("Right"))){
    
    }
    else if(e.keycode==XKeysymToKeycode(display,XStringToKeysym("Up"))){
      cout<<" ";
    }
    else if(e.keycode==XKeysymToKeycode(display,XStringToKeysym("Down"))){
      cout<<" ";
    }
    arrange();
  }
}

void WindowManager::init(){

  cout<<"Initializing"<<endl;

  if(!(display = XOpenDisplay(0x0))){
    cerr<<"Couldn't open display";
    return;
  }

  queryWindows();
  arrange();
  //tell x to intercept these keys
  for(auto i: keymap){
    XGrabKey(display, XKeysymToKeycode(display, XStringToKeysym(i.second.c_str())), AnyModifier,
            DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync);
  }

}

void WindowManager::arrange(){
    cout<<"Arranging"<<endl;
    unsigned int l_window_right_border = 0;
    for(unsigned int i = 0; i < numWindows; i++){
        XWindowAttributes attributes;
        XGetWindowAttributes(display, windows[i], &attributes);
        XMoveWindow(display, windows[i],l_window_right_border, 0);
        l_window_right_border += attributes.width;
    }
    
}

void WindowManager::run() {

  cout<<"Running"<<endl;

  for(;;){
    XEvent e;
    XNextEvent(display, &e);
    switch (e.type)
    {
    case KeyPress:
      cout<<"KeyPress"<<endl;
      onKeyPress(e.xkey);
      break;
    
    default:
      break;
    } 
  }
}
