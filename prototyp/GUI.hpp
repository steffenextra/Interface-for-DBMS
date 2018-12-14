#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <stdio.h>
#include <stdlib.h>
#include "sqllib.hpp"

class GUI{
    public:
    GUI();
    ~GUI();
};

class ConnectionWindow : public Fl_Window{
    public:
    ConnectionWindow();
    ~ConnectionWindow();

};

class CategoryWindow : public Fl_Window{
    public:
    CategoryWindow();
    ~CategoryWindow(){}

};

