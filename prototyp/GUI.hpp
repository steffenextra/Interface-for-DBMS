#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Editor.H>
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
    ~CategoryWindow();

};
//-- Databases
class DatabaseWindow : public Fl_Window{
    public:
    DatabaseWindow();
    ~DatabaseWindow(){}
};

class DatabaseCommand : public Fl_Window{
    public:
   DatabaseCommand();
    ~DatabaseCommand(){}
};

class ShowDatabase : public Fl_Window{
    public:
    ShowDatabase();
    ~ShowDatabase(){}
};

//-- Table
class TableWindow : public Fl_Window{
    public:
    TableWindow();
    ~TableWindow(){}
};

class TableCommand : public Fl_Window{
    public:
   TableCommand();
    ~TableCommand(){}
};

class ShowTable : public Fl_Window{
    public:
    ShowTable();
    ~ShowTable(){}
};
//-- Entry
class EntryWindow : public Fl_Window{
    public:
    EntryWindow();
    ~EntryWindow(){}
};

class EntryCommand : public Fl_Window{
    public:
   EntryCommand();
    ~EntryCommand(){}
};

class ShowEntry : public Fl_Window{
    public:
    ShowEntry();
    ~ShowEntry(){}
};

class StatementWindow : public Fl_Window{
    public:
        StatementWindow();
            ~StatementWindow();
};