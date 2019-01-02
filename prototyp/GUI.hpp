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
#include <FL/Fl_Multiline_Output.H>
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
class SetColumnWithPrimary : public Fl_Window{
    public:
    SetColumnWithPrimary();
    ~SetColumnWithPrimary(){}
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
class GetAllColumns : public Fl_Window{
    public:
    GetAllColumns();
    ~GetAllColumns(){}
};
class CountDatasets: public Fl_Window{
    public:
    CountDatasets();
    ~CountDatasets(){}
};
class ShowColumnType: public Fl_Window{
    public:
    ShowColumnType();
    ~ShowColumnType(){}
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

//Selection-Request Windows
class SelectLike : public Fl_Window{
    public:
    SelectLike();
    ~SelectLike(){}
};
class SelectNotLike : public Fl_Window{
    public:
    SelectNotLike();
    ~SelectNotLike(){}
};
class SelectMinOrMax : public Fl_Window{
    public:
    SelectMinOrMax();
    ~SelectMinOrMax(){}
};
class SelectMinOrMaxWhere : public Fl_Window{
    public:
   SelectMinOrMaxWhere();
    ~SelectMinOrMaxWhere(){}
};
class SelectLimitWhereOrderBy : public Fl_Window{
    public:
    SelectLimitWhereOrderBy();
    ~SelectLimitWhereOrderBy(){}
};
class SelectWhereOneColumn : public Fl_Window{
    public:
    SelectWhereOneColumn();
    ~SelectWhereOneColumn(){}
};
class SelectWhere : public Fl_Window{
    public:
   SelectWhere();
    ~SelectWhere(){}
};
class SelectWhereBool : public Fl_Window{
    public:
    SelectWhereBool();
    ~SelectWhereBool(){}
};
class SelectWhereOrderBy : public Fl_Window{
    public:
    SelectWhereOrderBy();
    ~SelectWhereOrderBy(){}
};
class SelectSortTable : public Fl_Window{
    public:
    SelectSortTable();
    ~SelectSortTable(){}
};
class SelectCount : public Fl_Window{
    public:
    SelectCount();
    ~SelectCount(){}
};
class SelectDistinct : public Fl_Window{
    public:
    SelectDistinct();
    ~SelectDistinct(){}
};
class SelectCountDistinct : public Fl_Window{
    public:
    SelectCountDistinct();
    ~SelectCountDistinct(){}
};
class SelectAverageSum : public Fl_Window{
    public:
    SelectAverageSum();
    ~SelectAverageSum(){}
};
class SelectSum : public Fl_Window{
    public:
    SelectSum();
    ~SelectSum(){}
};
class SelectUnion : public Fl_Window{
    public:
    SelectUnion();
    ~SelectUnion(){}
};
class SelectIn : public Fl_Window{
    public:
    SelectIn();
    ~SelectIn(){}
};
class SelectBetween : public Fl_Window{
    public:
    SelectBetween();
    ~SelectBetween(){}
};
class SelectColumnsAlias : public Fl_Window{
    public:
    SelectColumnsAlias();
    ~SelectColumnsAlias(){}
};
class SelectTableAlias : public Fl_Window{
    public:
    SelectTableAlias();
    ~SelectTableAlias(){}
};
class SelectGroupBy : public Fl_Window{
    public:
    SelectGroupBy();
    ~SelectGroupBy(){}
};
class SelectGroupByOrderBy : public Fl_Window{
    public:
    SelectGroupByOrderBy();
    ~SelectGroupByOrderBy(){}
};
class SelectCountGroupByOrderBy : public Fl_Window{
    public:
   SelectCountGroupByOrderBy();
    ~SelectCountGroupByOrderBy(){}
};
class SelectNull : public Fl_Window{
    public:
    SelectNull();
    ~SelectNull(){}
};
class SelectInnerJoin : public Fl_Window{
    public:
    SelectInnerJoin();
    ~SelectInnerJoin(){}
};
class SelectLeftJoin : public Fl_Window{
    public:
    SelectLeftJoin();
    ~SelectLeftJoin(){}
};
class SelectRightJoin : public Fl_Window{
    public:
    SelectRightJoin();
    ~SelectRightJoin(){}
};

class OutputWindow : public Fl_Window{
    public:
    OutputWindow();
    ~OutputWindow(){}
};
