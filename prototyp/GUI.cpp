#include "GUI.hpp"

Fl_Box *box1;
Fl_Input *host;
Fl_Input *name;
Fl_Input *pwd;
Fl_Input *database;
Fl_Input *port;
Fl_Button *connect;
Fl_Button *databaseButton;
Fl_Button *tableButton;
Fl_Button *entryButton;
Fl_Button *selectRequestButton;
Fl_Button *backButton;
Fl_Button *executeButton;
Fl_Input_Choice *databasesCommands;
Fl_Input_Choice *tableCommands;
Fl_Input_Choice *entryCommands;
Fl_Input_Choice *selectRequestCommands;


Fl_Input *databasename;

Fl_Output *sqlCommand;
ConnectionWindow *connectionWindow;
CategoryWindow *categoryWindow;
DatabaseWindow *databaseWindow;
DatabaseCommand *databaseCommandWindow;
ShowDatabase *showDatabaseWindow;
TableWindow *tableWindow;
TableCommand *tableCommandWindow;
ShowTable *showTableWindow;
EntryWindow *entryWindow;
EntryCommand *entryCommandWindow;
ShowEntry *showEntryWindow;
<<<<<<< HEAD
SelectRequestWindow *selectRequestWindow;
SelectRequestCommand *selectRequestCommandWindow;
ShowSelectRequest *showSelectRequestWindow;



=======
StatementWindow *statementWindow;
StatementWindow *showStatementWindow;
Fl_Input *sqlStatement;
Fl_Output *messageerror;
Fl_Output *feedback;
Fl_Output *connectoutput;
>>>>>>> 16c54bc187836b66a27532ea8c175a9773bfcffc
//Destruktoren fehlen

     void whenPushedConnect(Fl_Widget* w, void*){

		if ( ((Fl_Button*) w)->value()){
		} 
		else {
			int port1 = atoi(port->value());
			if(!(port==0)){
				
				if (connectionless(host->value(),name->value(),pwd->value(),database->value(),port1,pathto,0)==1){
				connectionWindow->hide();
				categoryWindow = new CategoryWindow();
				}else {
					connectoutput->value("Verbindung fehlgeschlagen");

				}

			}
			else{
				//Exception
			}
		}
		
	}

	void whenPushedDisconnect(Fl_Widget* w, void*){
		//need to Fix
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
			categoryWindow->hide();
			connectionWindow->show();
			disconnect();
		}
		
	}

	void whenPushedDatabaseWindow(Fl_Widget* w, void*){
		//need to Fix
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
			categoryWindow->hide();
			databaseWindow = new DatabaseWindow();	
		}
		
	}
	void whenPushedNextDatabaseCommand(Fl_Widget* w, void*){
		//need to Fix
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
				databaseWindow->hide();
				databaseCommandWindow = new DatabaseCommand();
		}
		
	}
	void whenPushedDatabaseShowButton(Fl_Widget* w, void*){
		//need to Fix
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
				databaseCommandWindow->hide();
				showDatabaseWindow = new ShowDatabase();
				//NUR AUSSERHALB VON DATENBANKEN NUTZBAR 
				if(databasesCommands->value()=="create Database"){
<<<<<<< HEAD
					sqlCommand->value("CREATE DATABASE databaseName;"); 
=======
>>>>>>> 16c54bc187836b66a27532ea8c175a9773bfcffc
					createDatabase(databasename->value());
				}
		}
		
	}

	void whenPushedTableWindow(Fl_Widget* w, void*){
		//need to Fix
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
			categoryWindow->hide();
			tableWindow= new TableWindow();	
		}
		
	}



	void whenPushedNextTableCommand(Fl_Widget* w, void*){
		//need to Fix
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
				tableWindow->hide();
				tableCommandWindow = new TableCommand();
		}
		
	}

		void whenPushedTableShowButton(Fl_Widget* w, void*){
		//need to Fix
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
				tableCommandWindow->hide();
				showTableWindow = new ShowTable();

				if(databasesCommands->value()=="create Database"){
					//sqlCommand->insert("CREATE DATABASE databaseName;"); falscher befehl?
					createDatabase(databasename->value());
				}
		}
	}
		
//Methods Entry
	void whenPushedEntryWindow(Fl_Widget* w, void*){
		//need to Fix
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
			categoryWindow->hide();
			entryWindow= new EntryWindow();	
		}
		
	}
	void whenPushedNextEntryCommand(Fl_Widget* w, void*){
		//need to Fix
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
				entryWindow->hide();
				entryCommandWindow = new EntryCommand();
		}
	}
	
	void whenPushedEntryShowButton(Fl_Widget* w, void*){
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
				entryCommandWindow->hide();
				showEntryWindow = new ShowEntry();
		}
		
	}

//Methods SelectRequest

	void whenPushedSelectRequestWindow(Fl_Widget* w, void*){
		//need to Fix
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
			categoryWindow->hide();
			selectRequestWindow = new SelectRequestWindow();	
		}
		
	}



	void whenPushedNextselectRequestCommand(Fl_Widget* w, void*){
		//need to Fix
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
				selectRequestWindow->hide();
				selectRequestCommandWindow = new SelectRequestCommand();
		}
	}
		


	void whenPushedSelectRequestShowButton(Fl_Widget* w, void*){
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
				selectRequestCommandWindow->hide();
				showSelectRequestWindow= new ShowSelectRequest();

		}
		
	}


	void whenPushedSelf(Fl_Widget* w, void*){
		if (((Fl_Button*) w) ->value()){}
			else {
				categoryWindow->hide();
				statementWindow = new StatementWindow();
			}
	}

	void whenPushedSend(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else {
				connection_query(sqlStatement->value());
				std::string errormsg = check_error();
 				messageerror->value(errormsg.c_str());
 				std::string msg = connection_query(sqlStatement->value()); // Unterscheiden zwischen den einzelnen typen der query und Problemlösung für feedbackall 
 				feedback->value(msg.c_str()); 
			}
	}

	void whenPushedBackDatabase(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else {
				databaseWindow->hide();
				categoryWindow->show();
			}
	}

	void whenPushedBackTable(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else {
				tableWindow->hide();
				categoryWindow->show();
			}
	}

	void whenPushedBackSelf(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else {
				statementWindow->hide();
				categoryWindow->show();
			}
	}

	void whenPushedBackTableCommand(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else {
				tableCommandWindow->hide();
				tableWindow->show();
			}
	}

	void whenPushedBackEntry(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else {
				entryWindow->hide();
				categoryWindow->show();
			}
	}

	void whenPushedBackEntryCommand(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else {
				entryCommandWindow->hide();
				entryWindow->show();
			}
	}

	

	void whenPushedBackDatabaseCommand(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else {
				databaseCommandWindow->hide();
				databaseWindow->show();
			}
	}

	GUI::GUI(){
<<<<<<< HEAD
	//	 connectionWindow = new ConnectionWindow();
		 categoryWindow = new CategoryWindow();
	//	dbw = new DatabaseWindow();
	//tableWindow = new TableWindow();
	//selectRequestWindow = new SelectRequestWindow();
=======
		 connectionWindow = new ConnectionWindow();
>>>>>>> 16c54bc187836b66a27532ea8c175a9773bfcffc

	}

	ConnectionWindow::ConnectionWindow() : Fl_Window(600,400,560,310,"SQL-Interface"){
        color(FL_WHITE);
        begin();

	 	box1 = new Fl_Box(20,40,300,100,"");
		host = new Fl_Input(220,20,100,30,"Host");
		name = new Fl_Input(220,60,100,30,"Benutzer");
		pwd = new Fl_Input (220,100,100,30, "Passwort"); 
		database = new Fl_Input (220,140,100,30, "Datenbank");
		port = new Fl_Input (220,180,100,30, "Port");
		connect = new Fl_Button(220,220,100,30, "Connect");
		connect->callback((Fl_Callback*) whenPushedConnect);
		connectoutput = new Fl_Output(170,260,200,30, "Meldung"); // Eventuelle Ausgabe des spezifischen Fehlers
		connectoutput->callback((Fl_Callback*)whenPushedConnect);
        
        end();
        show();
    }

    ConnectionWindow::~ConnectionWindow() {
		
    }


 StatementWindow::StatementWindow() : Fl_Window(600,400,560,310, "SQL-Interface"){
 	color(FL_WHITE);
 	begin();

 	Fl_Button *disconnectButton = new Fl_Button(370,0,95,25, "Disconnect");
 	Fl_Button *sending = new Fl_Button(465,0,95,25,"Senden");
 	disconnectButton->color((Fl_Color)31);
 	sqlStatement = new Fl_Input(100,50,400,50,"Eingabe:");
 	sending->callback((Fl_Callback*) whenPushedSend); //Nach einem Befehl in Schleife
 	feedback = new Fl_Output (100,100,400,100, "Ausgabe:");
 	messageerror = new Fl_Output(100,200,400,50,"Fehlermeldung:"); // Kein Automatischer Zeilenumbruch 
 	disconnectButton->callback((Fl_Callback*) whenPushedDisconnect); // Absturz durch alloc 
	backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*)whenPushedBackSelf);
    end();
    show();

 }

StatementWindow::~StatementWindow(){

    }



  CategoryWindow::CategoryWindow() : Fl_Window(600,400,560,310,"SQL-Interface"){
    color(FL_WHITE);
    begin();

	Fl_Box *boxCategory = new Fl_Box(20,40,300,100,"");
    Fl_Button *disconnectButton = new Fl_Button(465, 0, 95, 25, "Disconnect");
    disconnectButton->color((Fl_Color)31);
    Fl_Button* selfButton = new Fl_Button(95, 0, 95, 25, "Self");
    databaseButton = new Fl_Button(0, 30, 280, 140, "Database-Commands");
    databaseButton->color((Fl_Color)31);
    selfButton->color((Fl_Color)31);
    tableButton = new Fl_Button(280, 30, 280, 140, "Table-Commands");
    tableButton->color((Fl_Color)31);
    Fl_Button* entryButton = new Fl_Button(0, 170, 280, 140, "Entry-Commands");
    entryButton->color((Fl_Color)31);
    Fl_Button* selectionButton = new Fl_Button(280, 170, 280, 140, "Selection-Commands");
	selectionButton->color((Fl_Color)31);
    Fl_Button* helpButton = new Fl_Button(0, 0, 95, 25, "Help");
    helpButton->color((Fl_Color)31);


	databaseButton->callback((Fl_Callback*) whenPushedDatabaseWindow);
	tableButton->callback((Fl_Callback*) whenPushedTableWindow);
    entryButton->callback((Fl_Callback*) whenPushedEntryWindow);
    selfButton->callback((Fl_Callback*) whenPushedSelf);
    disconnectButton->callback((Fl_Callback*) whenPushedDisconnect);
	end();
    show();
 }

 CategoryWindow::~CategoryWindow(){

 }

//Databases
  DatabaseWindow::DatabaseWindow() : Fl_Window(600,400,560,310,"SQL-Interface"){
	color(FL_WHITE);
	begin();
  
   	databasesCommands = new Fl_Input_Choice(180, 42, 370, 23, "Databases-Commands:");
	databasesCommands->add("create Database");
	databasesCommands->add("show Databases");
	databasesCommands->add("delete Databases");
    Fl_Button* helpButton = new Fl_Button(0, 0, 95, 25, "Help");
    helpButton->color((Fl_Color)31);
    Fl_Button* nextButton = new Fl_Button(465, 0, 95, 25, "Next");
    nextButton->color((Fl_Color)31);
    Fl_Button* backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*)whenPushedBackDatabase);

	nextButton->callback((Fl_Callback*) whenPushedNextDatabaseCommand);

	end();
    show();
    }

	DatabaseCommand::DatabaseCommand() : Fl_Window(600,400,560,310,"SQL-Interface"){
    color(FL_WHITE);
    begin();


    executeButton = new Fl_Button(465, 0, 95, 25, "Show");
    executeButton->color((Fl_Color)31);
    Fl_Button* helpButton = new Fl_Button(0, 0, 95, 25, "Help");
    helpButton->color((Fl_Color)31);
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
   	sqlCommand = new Fl_Output(0, 40, 560, 30, "SQL-Command");
	databasename = new Fl_Input(120, 76, 140, 24, "Databasename:");

	executeButton->callback((Fl_Callback*) whenPushedDatabaseShowButton);
	backButton->callback((Fl_Callback*) whenPushedBackDatabaseCommand);

	end();
    show();
}

	ShowDatabase::ShowDatabase() : Fl_Window(1280,400,620,310,"SQL-Interface"){
   
    color(FL_WHITE);
    begin();

    Fl_Button* helpButton = new Fl_Button(0, 0, 95, 25, "Help");
    helpButton->color((Fl_Color)31);
	
	end();
    show();
}
//Table

  TableWindow::TableWindow() : Fl_Window(600,400,560,310,"SQL-Interface"){
	color(FL_WHITE);
	begin();
  
   	tableCommands = new Fl_Input_Choice(180, 42, 370, 23, "Table-Commands:");
	tableCommands->add("createTable");
	tableCommands->add("showTable");
	tableCommands->add("renameTable");
	tableCommands->add("deleteTable");
	tableCommands->add("setColumn");
	tableCommands->add("modifierColumnName");
	tableCommands->add("setColumnWithPrimary");
	tableCommands->add("changeTheDatatype");
	tableCommands->add("getAllColumn");
	tableCommands->add("countDatasets");
	tableCommands->add("showColumnTyp");
	tableCommands->add("deleteColumn");
	tableCommands->add("setSecondaryKey");
	tableCommands->add("deleteSecondaryKey");
	tableCommands->add("setPrimaryKey");
	tableCommands->add("deletePrimaryKey");

    Fl_Button* helpButton = new Fl_Button(0, 0, 95, 25, "Help");
    helpButton->color((Fl_Color)31);
    Fl_Button* nextButton = new Fl_Button(465, 0, 95, 25, "Next");
    nextButton->color((Fl_Color)31);
    Fl_Button* backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	nextButton->callback((Fl_Callback*) whenPushedNextTableCommand);
	backButton->callback((Fl_Callback*) whenPushedBackTable);

	end();
    show();
    }

	TableCommand::TableCommand() : Fl_Window(600,400,560,310,"SQL-Interface"){
    color(FL_WHITE);
    begin();


    executeButton = new Fl_Button(465, 0, 95, 25, "Show");
    executeButton->color((Fl_Color)31);
    Fl_Button* helpButton = new Fl_Button(0, 0, 95, 25, "Help");
    helpButton->color((Fl_Color)31);
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
   	sqlCommand = new Fl_Text_Display(0, 40, 560, 30, "SQL-Command");
	databasename = new Fl_Input(120, 76, 140, 24, "Databasename:");

	executeButton->callback((Fl_Callback*) whenPushedTableShowButton);
	backButton->callback((Fl_Callback*) whenPushedBackTableCommand);

	end();
    show();
}

	ShowTable::ShowTable() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

	Fl_Button* helpButton = new Fl_Button(0, 0, 95, 25, "Help");
	helpButton->color((Fl_Color)31);
		
	end();
	show();
}
//Entry 

  EntryWindow::EntryWindow() : Fl_Window(600,400,560,310,"SQL-Interface"){
	color(FL_WHITE);
	begin();
  
   	entryCommands = new Fl_Input_Choice(180, 42, 370, 23, "Table-Commands:");
	entryCommands->add("setEntry");
	entryCommands->add("modifierEntry");
	entryCommands->add("setAllEntry");
	entryCommands->add("deleteEntry");

    Fl_Button* helpButton = new Fl_Button(0, 0, 95, 25, "Help");
    helpButton->color((Fl_Color)31);
    Fl_Button* nextButton = new Fl_Button(465, 0, 95, 25, "Next");
    nextButton->color((Fl_Color)31);
    Fl_Button* backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	nextButton->callback((Fl_Callback*) whenPushedNextEntryCommand);
	backButton->callback((Fl_Callback*) whenPushedBackEntry);
	end();
    show();
    }

	EntryCommand::EntryCommand() : Fl_Window(600,400,560,310,"SQL-Interface"){
    color(FL_WHITE);
    begin();


    executeButton = new Fl_Button(465, 0, 95, 25, "Show");
    executeButton->color((Fl_Color)31);
    Fl_Button* helpButton = new Fl_Button(0, 0, 95, 25, "Help");
    helpButton->color((Fl_Color)31);
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
   	sqlCommand = new Fl_Text_Display(0, 40, 560, 30, "SQL-Command");

	executeButton->callback((Fl_Callback*) whenPushedEntryShowButton);
	backButton->callback((Fl_Callback*) whenPushedBackEntryCommand);

	end();
    show();
}

	ShowEntry::ShowEntry() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

	Fl_Button* helpButton = new Fl_Button(0, 0, 95, 25, "Help");
	helpButton->color((Fl_Color)31);
		
	end();
	show();
}

//Select-Request

 SelectRequestWindow::SelectRequestWindow() : Fl_Window(600,400,560,310,"SQL-Interface"){
	color(FL_WHITE);
	begin();
  
   	selectRequestCommands = new Fl_Input_Choice(210, 42, 320, 23, "Select-Request-Commands:");
	selectRequestCommands->add("setEntry");
	selectRequestCommands->add("modifierEntry");
	selectRequestCommands->add("setAllEntry");
	selectRequestCommands->add("deleteEntry");

    Fl_Button* helpButton = new Fl_Button(0, 0, 95, 25, "Help");
    helpButton->color((Fl_Color)31);
    Fl_Button* nextButton = new Fl_Button(465, 0, 95, 25, "Next");
    nextButton->color((Fl_Color)31);
    Fl_Button* backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	nextButton->callback((Fl_Callback*) whenPushedNextselectRequestCommand);

	end();
    show();
    }

	SelectRequestCommand::SelectRequestCommand() : Fl_Window(600,400,560,310,"SQL-Interface"){
    color(FL_WHITE);
    begin();


    executeButton = new Fl_Button(465, 0, 95, 25, "Show");
    executeButton->color((Fl_Color)31);
    Fl_Button* helpButton = new Fl_Button(0, 0, 95, 25, "Help");
    helpButton->color((Fl_Color)31);
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
   	sqlCommand = new Fl_Text_Display(0, 40, 560, 30, "SQL-Command");

	executeButton->callback((Fl_Callback*) whenPushedSelectRequestShowButton);

	end();
    show();
}

	ShowSelectRequest::ShowSelectRequest() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		color(FL_WHITE);
	begin();

	Fl_Button* helpButton = new Fl_Button(0, 0, 95, 25, "Help");
	helpButton->color((Fl_Color)31);
		
	end();
	show();	
}