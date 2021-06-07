# NOBSWM
A linux window manager without the BS
## This is still a work in progress
Even though this code compiles and runs, it is a work in progress, and is pretty much useless at this stage.
## Why this WM superior
This window manager is highly configurable and extremely powerful while maintaining a tiny footprint. It is meant to fit perfectly with my NOBS environment project, which is a linux environment targeted at developers who don't want the BS.
## Prerequisites
This requires Xlib and Xephyr.
## compile and run
To compile:
```g++ -o a main.cpp wm.cpp `pkg-config --libs x11 liblog` ```
To run:
(on first run)
```chmod +x run.sh ```
then
```./run.sh ```

