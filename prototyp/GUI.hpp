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
#include <FL/Fl_Check_Button.H>
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
    ~ ShowEntry(){}
};

//--Select-Request
class SelectRequestWindow : public Fl_Window{
    public:
    SelectRequestWindow ();
    ~SelectRequestWindow (){}
};

class SelectRequestCommand : public Fl_Window{
    public:
   SelectRequestCommand();
    ~SelectRequestCommand(){}
};

class ShowSelectRequest : public Fl_Window{
    public:
    ShowSelectRequest();
    ~ ShowSelectRequest(){}
};
//statement

class StatementWindow : public Fl_Window{
    public:
    StatementWindow ();
    ~StatementWindow (){}
};
//Databases Windows
class CreateDatabase : public Fl_Window{
    public:
    CreateDatabase();
    ~CreateDatabase(){}
};
class ShowDatabases : public Fl_Window{
    public:
    ShowDatabases();
    ~ShowDatabases(){}
};
class DeleteDatabase : public Fl_Window{
    public:
    DeleteDatabase();
    ~DeleteDatabase(){}
};

//Entry Windows

class SetEntry : public Fl_Window{
    public:
    SetEntry();
    ~SetEntry(){}
};
class ModifierEntry : public Fl_Window{
    public:
    ModifierEntry();
    ~ModifierEntry(){}
};
class SetAllEntry : public Fl_Window{
    public:
    SetAllEntry();
    ~SetAllEntry(){}
};

class DeleteEntry : public Fl_Window{
    public:
   DeleteEntry();
    ~DeleteEntry(){}
};

//Table-Windows
class CreateTable : public Fl_Window{
    public:
    CreateTable();
    ~CreateTable(){}
};
class ShowTableCommand : public Fl_Window{
    public:
   ShowTableCommand();
    ~ShowTableCommand(){}
};
class RenameTable : public Fl_Window{
    public:
    RenameTable();
    ~RenameTable(){}
};
class DeleteTable: public Fl_Window{
    public:
    DeleteTable();
    ~DeleteTable(){}
};
class SetColumn : public Fl_Window{
    public:
   SetColumn();
    ~SetColumn(){}
};
class setColumnWithPrimary : public Fl_Window{
    public:
    setColumnWithPrimary();
    ~setColumnWithPrimary(){}
};
class ModifierColumnName : public Fl_Window{
    public:
    ModifierColumnName();
    ~ModifierColumnName(){}
};
class ChangeDatatype : public Fl_Window{
    public:
    ChangeDatatype();
    ~ChangeDatatype(){}
};
class GetAllColumn : public Fl_Window{
    public:
    GetAllColumn();
    ~GetAllColumn(){}
};
class CountDatasets: public Fl_Window{
    public:
    CountDatasets();
    ~CountDatasets(){}
};
class ShowColumnTyp: public Fl_Window{
    public:
    ShowColumnTyp();
    ~ShowColumnTyp(){}
};
class DeleteColumn : public Fl_Window{
    public:
    DeleteColumn();
    ~DeleteColumn(){}
};
class SetSecondaryKey : public Fl_Window{
    public:
     SetSecondaryKey();
    ~ SetSecondaryKey(){}
};
class DeleteSecondaryKey: public Fl_Window{
    public:
    DeleteSecondaryKey();
    ~DeleteSecondaryKey(){}
};
class SetPrimaryKey : public Fl_Window{
    public:
    SetPrimaryKey();
    ~SetPrimaryKey(){}
};
class DeletePrimaryKey : public Fl_Window{
    public:
   DeletePrimaryKey();
    ~DeletePrimaryKey(){}
};
