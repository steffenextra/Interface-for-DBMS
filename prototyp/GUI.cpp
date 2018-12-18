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

ConnectionWindow *connectionWindow;
CategoryWindow *categoryWindow;
DatabaseWindow *databaseWindow;
CreateDatabase *createDatabaseWindow;       
ShowDatabases *showDatabasesWindow;
DeleteDatabase *deleteDatabaseWindow;
DatabaseCommand *databaseCommandWindow;
ShowDatabase *showDatabaseWindow;

TableWindow *tableWindow;
TableCommand *tableCommandWindow;
ShowTable *showTableWindow;
CreateTable *createTableWindow;
ShowTableCommand *showTableCommandWindow;
RenameTable *renameTableWindow;
DeleteTable *deleteTableWindow;
SetColumn *setColumnWindow;
SetColumnWithPrimary *setColumnWithPrimaryWindow;
ModifierColumnName *modifierColumnNameWindow;
ChangeDatatype *changeDatatypeWindow;
GetAllColumns *getAllColumnsWindow;
CountDatasets *countDatasetsWindow;
ShowColumnType *showColumnTypeWindow;
DeleteColumn *deleteColumnWindow;
SetSecondaryKey *setSecondaryKeyWindow;
DeleteSecondaryKey *deleteSecondaryKeyWindow;
SetPrimaryKey *setPrimaryKeyWindow;
DeletePrimaryKey *deletePrimaryKeyWindow;




EntryWindow *entryWindow;
EntryCommand *entryCommandWindow;
ShowEntry *showEntryWindow;
SetEntry *setEntryWindow;
SetAllEntry *setAllEntryWindow;
DeleteEntry *deleteEntryWindow;
ModifierEntry *modifierEntryWindow;


SelectRequestWindow *selectRequestWindow;
SelectRequestCommand *selectRequestCommandWindow;
ShowSelectRequest *showSelectRequestWindow;
StatementWindow *statementWindow;
StatementWindow *showStatementWindow;

Fl_Input *databasename;

Fl_Input *tablename;
Fl_Input *columnname;
Fl_Input *entry;
Fl_Input *condition;
Fl_Input *oldEntry;
Fl_Input *newEntry; 
Fl_Input *rowEntry; 

Fl_Input *tableName;
Fl_Check_Button *primaryKeyCheck;
Fl_Input *columnName;
Fl_Input *columns;
Fl_Input *oldTableName;
Fl_Input *newTableName;
Fl_Input_Choice *datatype;
Fl_Check_Button *autoIncrement;
Fl_Input *oldColumnName;
Fl_Input *newColumnName;
Fl_Input *tableNameSecondary;
Fl_Input *foreignKey;
Fl_Input *tableNamePrimary ;
Fl_Input *primaryKey;
Fl_Input *constraint;

Fl_Input *sqlStatement;
Fl_Output *sqlCommand;
Fl_Output *messageerror;
Fl_Output *feedback;
Fl_Output *connectoutput;


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
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
			categoryWindow->hide();
			connectionWindow->show();
			disconnect();
		}
		
	}

	void whenPushedDatabaseWindow(Fl_Widget* w, void*){
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
			categoryWindow->hide();
			databaseWindow = new DatabaseWindow();	
		}
		
	}
	void whenPushedNextDatabaseCommand(Fl_Widget* w, void*){
		//unbedingt anschauen ... Für jedes neue Klasse muss das Fenster wieder geschlossen werden also erhalten alle Klassen wie cerate Database noch die die back methode
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
				if((strcmp(databasesCommands->value(),"create Database"))==0){
					databaseWindow->hide();
					createDatabaseWindow=new CreateDatabase();
					sqlCommand->value("CREATE DATABASE  + databaseName;"); 
				}

				if((strcmp(databasesCommands->value(),"show Databases"))==0){
					databaseWindow->hide();
					showDatabasesWindow=new ShowDatabases();
					sqlCommand->value("SHOW DATABASES;"); 
				}
				if((strcmp(databasesCommands->value(),"delete Databases"))==0){
					databaseWindow->hide();
					deleteDatabaseWindow=new DeleteDatabase();
					sqlCommand->value("DROP DATABASE  + databaseName;"); 
				}

			/*	else{
					sqlCommand->value("Unknown SQL-Command"); 
				}*/
		}
		
	}
	void whenPushedDeleteDatabaseShowButton(Fl_Widget* w, void*){
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
				createDatabaseWindow->hide();
				showDatabaseWindow = new ShowDatabase();
		}
		
	}

	void whenPushedTableWindow(Fl_Widget* w, void*){
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
			categoryWindow->hide();
			tableWindow= new TableWindow();	
		}
		
	}



	void whenPushedNextTableCommand(Fl_Widget* w, void*){
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
				if((strcmp(tableCommands->value(),"createTable"))==0){
					tableWindow->hide();
					createTableWindow=new CreateTable();
					sqlCommand->value("CREATE TABLE tableName( ID int NOT NULL PRIMARY KEY AUTO_INCREMENT, columnnamesAndDatatype);"); 
				}

				if((strcmp(tableCommands->value(),"showTable"))==0){
					tableWindow->hide();
					showTableCommandWindow=new ShowTableCommand();
					sqlCommand->value("SELECT * FROM tableName;"); 
				}
				if((strcmp(tableCommands->value(),"renameTable"))==0){
					tableWindow->hide();
					renameTableWindow = new RenameTable();
					sqlCommand->value("ALTER TABLE tablename RENAME TO newTableName;"); 
				}
				if((strcmp(tableCommands->value(),"deleteTable"))==0){
					tableWindow->hide();

					deleteTableWindow = new DeleteTable();
					sqlCommand->value("DROP TABLE  tableName;"); 
				}
				if((strcmp(tableCommands->value(),"setColumn"))==0){
					tableWindow->hide();
					setColumnWindow = new SetColumn();
					sqlCommand->value("ALTER TABLE tableName  ADD  ColumnName  datatype;"); 
				}
				if((strcmp(tableCommands->value(),"modifierColumnName"))==0){
					tableWindow->hide();
					modifierColumnNameWindow = new ModifierColumnName();
					sqlCommand->value("ALTER TABLE tableName CHANGE oldColumnName  newColumnName datatype"); 
				}
				if((strcmp(tableCommands->value(),"setColumnWithPrimary"))==0){
					tableWindow->hide();
					setColumnWithPrimaryWindow = new SetColumnWithPrimary();
					sqlCommand->value("ALTER TABLE tableName ADD ColumnName datatype PRIMARY KEY AUTO_INCREMENT;"); 
				}
				if((strcmp(tableCommands->value(),"changeTheDatatype"))==0){
					tableWindow->hide();
					changeDatatypeWindow = new ChangeDatatype();
					sqlCommand->value("ALTER TABLE tableName ADD  ColumnName datatype"); 
				}
				if((strcmp(tableCommands->value(),"getAllColumn"))==0){
					tableWindow->hide();
					getAllColumnsWindow = new GetAllColumns();
					sqlCommand->value("SHOW COLUMNS FROM tableName;"); 
				}
				if((strcmp(tableCommands->value(),"countDatasets"))==0){
					tableWindow->hide();
					countDatasetsWindow = new CountDatasets();
					sqlCommand->value("SELECT COUNT (*) FROM tableName;"); 
				}
				if((strcmp(tableCommands->value(),"showColumnType"))==0){
					tableWindow->hide();
					showColumnTypeWindow = new ShowColumnType();
					sqlCommand->value("SHOW COLUMNS FROM tableName WHERE TYPE LIKE 'datatype%';"); 
				}
				if((strcmp(tableCommands->value(),"deleteColumn"))==0){
					tableWindow->hide();
					deleteColumnWindow = new DeleteColumn();
					sqlCommand->value("ALTER TABLE tableName DROP columnName;"); 
				}
				if((strcmp(tableCommands->value(),"setSecondaryKey"))==0){
					tableWindow->hide();
					setSecondaryKeyWindow = new SetSecondaryKey();
					sqlCommand->value("ALTER TABLE tableNameSecondary ADD CONSTRAINT constraint FOREIGN KEY (foreignKey) REFERENCES tableNamePrimary primaryKey);"); 
				}
				if((strcmp(tableCommands->value(),"deleteSecondaryKey"))==0){
					tableWindow->hide();
					deleteSecondaryKeyWindow = new DeleteSecondaryKey();
					sqlCommand->value("ALTER TABLE tableName DROP FOREIGN KEY constraint;"); 
				}
				if((strcmp(tableCommands->value(),"setPrimaryKey"))==0){
					tableWindow->hide();
					setPrimaryKeyWindow = new SetPrimaryKey();
					sqlCommand->value("ALTER TABLE tableName ADD PRIMARY KEY (primaryKey);"); 
				}
				if((strcmp(tableCommands->value(),"deletePrimaryKey"))==0){
					tableWindow->hide();
					deletePrimaryKeyWindow = new DeletePrimaryKey();
					sqlCommand->value("ALTER TABLE tableName DROP PRIMARY KEY"); 
				}

			/*	else{
					sqlCommand->value("Unknown SQL-Command"); 
				}*/
		}
		
	}

		void whenPushedTableShowButton(Fl_Widget* w, void*){
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
				//createDatabaseWindow->hide();
				//showTableWindow = new ShowTable();
				createDatabase(databasename->value());
				if(databasesCommands->value()=="create Database"){
					//sqlCommand->insert("CREATE DATABASE databaseName;"); falscher befehl?
					createDatabase(databasename->value());
				}
		}
	}
		
//Methods Entry
	void whenPushedEntryWindow(Fl_Widget* w, void*){
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
			categoryWindow->hide();
			entryWindow = new EntryWindow();	
		}
		
	}
	void whenPushedNextEntryCommand(Fl_Widget* w, void*){
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
				if((strcmp(entryCommands->value(),"setEntry"))==0){
					entryWindow->hide();
					setEntryWindow = new SetEntry();
					sqlCommand->value("INSERT INTO tableName (columnName) VALUES ('entry');"); 
				}

				if((strcmp(entryCommands->value(),"modifierEntry"))==0){
					entryWindow->hide();
					modifierEntryWindow = new ModifierEntry();
					sqlCommand->value("UPDATE tableName SET columnName='newEntry' WHERE columnName='oldEntry';"); 
				}
				if((strcmp(entryCommands->value(),"deleteEntry"))==0){
					entryWindow->hide();
					deleteEntryWindow = new DeleteEntry();
					sqlCommand->value("DELETE FROM tableName WHERE columnName='condition';"); 
				}
				if((strcmp(entryCommands->value(),"setAllEntry"))==0){
					entryWindow->hide();
					setAllEntryWindow = new SetAllEntry();
					sqlCommand->value("INSERT INTO tableName (columnName) VALUES(insertData);"); 
				}
			/*	else{
					sqlCommand->value("Unknown SQL-Command"); 
				}*/

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
		if ( ((Fl_Button*) w)->value()){
		} 
		else {
			categoryWindow->hide();
			selectRequestWindow = new SelectRequestWindow();	
		}
		
	}



	void whenPushedNextselectRequestCommand(Fl_Widget* w, void*){
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

	void whenPushedSelfDisconnect(Fl_Widget*w, void*){
	if (((Fl_Button*) w) ->value()){}
			else {
				statementWindow->hide();
				connectionWindow->show();
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

	void whenPushedBackSelectRequest(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else {
				selectRequestWindow->hide();
				categoryWindow->show();
			}
	}

	void whenPushedBackSelectRequestCommand(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else {
				selectRequestCommandWindow->hide();
				selectRequestWindow->show();
			}
	}

	

	void whenPushedBackDatabaseCommand(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else {
				databaseCommandWindow->hide();
				databaseWindow->show();
			}
	}

	void whenPushedBackSetEntry(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				setEntryWindow->hide();
				entryWindow->show();
			}
	}

	void whenPushedBackModfierEntry(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				modifierEntryWindow->hide();
				entryWindow->show();
			}
	}

	void whenPushedBacksetAllEntry(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				setAllEntryWindow->hide();
				entryWindow->show();
			}
	}

	/*	void whenPushedBackDeleteEntry(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				deleteEntryWindow->hide();
				entryWindow->show();
			}
	}*/

	void whenPushedBackCreateTable(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				createTableWindow->hide();
				tableWindow->show();
			}
	}

		void whenPushedBackShowTable(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				showTableCommandWindow->hide();
				tableWindow->show();
			}
	}

	void whenPushedBackRenameTable(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				renameTableWindow->hide();
				tableWindow->show();
			}
	}

		void whenPushedBackDeleteEntry(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				deleteEntryWindow->hide();
				tableWindow->show();
			}
	}
		void whenPushedBackSetColumn(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				setColumnWindow->hide();
				tableWindow->show();
			}
	}
		void whenPushedBackGetAllColumn(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				getAllColumnsWindow->hide();
				tableWindow->show();
			}
	}

		void whenPushedBackShowColumnType(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				showColumnTypeWindow->hide();
				tableWindow->show();
			}
	}

		void whenPushedBackDeleteColumn(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				deleteColumnWindow->hide();
				tableWindow->show();
			}
	}
		void whenPushedBackModifierColumnName(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				modifierColumnNameWindow->hide();
				tableWindow->show();
			}
	}

		void whenPushedBackSetColumnWithPrimary(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				setColumnWithPrimaryWindow->hide();
				tableWindow->show();
			}
	}

		void whenPushedBackSetPrimaryKey(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				setPrimaryKeyWindow->hide();
				tableWindow->show();
			}
	}

	void whenPushedBackDeletePrimaryKey(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				deletePrimaryKeyWindow->hide();
				tableWindow->show();
			}
	}

		void whenPushedBackSetSecondaryKey(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				setSecondaryKeyWindow->hide();
				tableWindow->show();
			}
	}

		void whenPushedBackDeleteSecondaryKey(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				deleteSecondaryKeyWindow->hide();
				tableWindow->show();
			}
	}

		void whenPushedBackChangeDatatype(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				changeDatatypeWindow->hide();
				tableWindow->show();
			}
	}

		void whenPushedBackCountDatases(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				countDatasetsWindow->hide();
				tableWindow->show();
			}
	}

	void whenPushedBackDeleteTable(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				deleteTableWindow->hide();
				tableWindow->show();
			}
	} 

	void whenPushedBackGetAllColumns(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				getAllColumnsWindow->hide();
				tableWindow->show();
			}
	} 

	void whenPushedBackCreateDatabase(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				createDatabaseWindow->hide();
				databaseWindow->show();
			}
	} 

	void whenPushedBackShowDatabases(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				showDatabasesWindow->hide();
				databaseWindow->show();
			}
	} 

	void whenPushedBackDeleteDatabase(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				deleteDatabaseWindow->hide();
				databaseWindow->show();
			}
	} 


	void whenPushedDeleteDatabase(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				deleteDatabase(databasename->value());

			}

	}	

	void whenPushedCreateTableExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				//createTable(NULL, tableName->value(), );   // need to rework 

			}

	}	

	void whenPushedRenameTable(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				renameTable(oldTableName->value(), newTableName->value());
			}
	}

	
	void whenPushedDeleteTableExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				deleteTable(tableName->value());
		}	
	}

	void whenPushedSetColumnExecute(Fl_Widget* w, void*){
			if(((Fl_Button*)w) -> value()){}
			else{
				setColumn(tableName->value(), columnName ->value(), datatype->value());
		}	
	}

	void whenPushedGetAllColumnsExecute(Fl_Widget* w, void*){
			if(((Fl_Button*)w) -> value()){}
			else{
				getAllColumn(tableName->value());
		}	
	}













	GUI::GUI(){
		 connectionWindow = new ConnectionWindow();
	//	categoryWindow = new CategoryWindow();
		

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
 	disconnectButton->callback((Fl_Callback*) whenPushedSelfDisconnect); // Absturz durch alloc 
	backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*)whenPushedBackSelf);
    end();
    show();

 }
//CategoryWindow
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
    selectRequestButton = new Fl_Button(280, 170, 280, 140, "Selection-Commands");
	selectRequestButton->color((Fl_Color)31);


	databaseButton->callback((Fl_Callback*) whenPushedDatabaseWindow);
	tableButton->callback((Fl_Callback*) whenPushedTableWindow);
    selectRequestButton->callback((Fl_Callback*) whenPushedSelectRequestWindow);
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
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
   	sqlCommand = new Fl_Output(0, 40, 560, 30, "SQL-Command");
	databasename = new Fl_Input(120, 76, 140, 24, "Databasename:");

	//executeButton->callback((Fl_Callback*) whenPushedDatabaseShowButton);
	backButton->callback((Fl_Callback*) whenPushedBackDatabaseCommand);

	end();
    show();
}

	ShowDatabase::ShowDatabase() : Fl_Window(1280,400,620,310,"SQL-Interface"){
   
    color(FL_WHITE);
    begin();
    //showDatabase = new Fl_Output(0, 40, 560, 30, "Datenbanken");
    
	
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
	tableCommands->add("getAllColumn");
	tableCommands->add("showColumnType");
	tableCommands->add("deleteColumn");
	tableCommands->add("modifierColumnName");
	tableCommands->add("setColumnWithPrimary");
	tableCommands->add("setPrimaryKey");
	tableCommands->add("deletePrimaryKey");
	tableCommands->add("setSecondaryKey");
	tableCommands->add("deleteSecondaryKey");
	tableCommands->add("changeTheDatatype");
	tableCommands->add("countDatasets");

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
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
   	sqlCommand = new Fl_Output(0, 40, 560, 30, "SQL-Command");
	databasename = new Fl_Input(120, 76, 140, 24, "Databasename:");

	executeButton->callback((Fl_Callback*) whenPushedTableShowButton);
	backButton->callback((Fl_Callback*) whenPushedBackTableCommand);

	end();
    show();
}

	ShowTable::ShowTable() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

	end();
	show();
}
//Entry 

  EntryWindow::EntryWindow() : Fl_Window(600,400,560,310,"SQL-Interface"){
	color(FL_WHITE);
	begin();
  
   	entryCommands = new Fl_Input_Choice(180, 42, 370, 23, "Entry-Commands:");
	entryCommands->add("setEntry");
	entryCommands->add("setAllEntry");
	entryCommands->add("modifierEntry");
	entryCommands->add("deleteEntry");

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
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
   	sqlCommand = new Fl_Output(0, 40, 560, 30, "SQL-Command");

	executeButton->callback((Fl_Callback*) whenPushedEntryShowButton);
	backButton->callback((Fl_Callback*) whenPushedBackEntryCommand);

	end();
    show();
}

ShowEntry::ShowEntry() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();
		
	end();
	show();
}

SelectRequestWindow::SelectRequestWindow() : Fl_Window(600,400,560,310,"SQL-Interface"){
	color(FL_WHITE);
	begin();
  
   	selectRequestCommands = new Fl_Input_Choice(210, 42, 320, 23, "Select-Request-Commands:");
	selectRequestCommands->add("selectCount");
	selectRequestCommands->add("selectIn");
	selectRequestCommands->add("selectDistinct");
	selectRequestCommands->add("selechtCountDistinct");
	selectRequestCommands->add("selectLike");
	selectRequestCommands->add("selectNotLike");
	selectRequestCommands->add("selectSum");
	selectRequestCommands->add("selectAverageSum");
	selectRequestCommands->add("selectSortTable");
	selectRequestCommands->add("selectBetween");
	selectRequestCommands->add("selectMinOrMax");
	selectRequestCommands->add("selectMinOrMaxWhere");
	selectRequestCommands->add("selectWhere");
	selectRequestCommands->add("selectWhereOrderBy");
	selectRequestCommands->add("selectWhereOneColumn");
	selectRequestCommands->add("selectWhereBool");
	selectRequestCommands->add("selectLimitWhereOrderBy");
	selectRequestCommands->add("selectUnion");
	selectRequestCommands->add("selectColumnAlias");
	selectRequestCommands->add("selectTableAlias");
	selectRequestCommands->add("selectGroupBy");
	selectRequestCommands->add("selectGroupByOrderBy");
	selectRequestCommands->add("selectInnerJoin");
	selectRequestCommands->add("selectLeftJoin");
	selectRequestCommands->add("selectRightJoin");
	selectRequestCommands->add("selectFullJoin");
	selectRequestCommands->add("selectNull");



    Fl_Button* nextButton = new Fl_Button(465, 0, 95, 25, "Next");
    nextButton->color((Fl_Color)31);
    Fl_Button* backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	nextButton->callback((Fl_Callback*) whenPushedNextselectRequestCommand);
	backButton->callback((Fl_Callback*) whenPushedBackSelectRequest);

	end();
    show();
    }

	SelectRequestCommand::SelectRequestCommand() : Fl_Window(600,400,560,310,"SQL-Interface"){
    color(FL_WHITE);
    begin();


    executeButton = new Fl_Button(465, 0, 95, 25, "Show");
    executeButton->color((Fl_Color)31);
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
   	sqlCommand = new Fl_Output(0, 40, 560, 30, "SQL-Command");

	executeButton->callback((Fl_Callback*) whenPushedSelectRequestShowButton);
	backButton->callback((Fl_Callback*) whenPushedBackSelectRequestCommand);

	end();
    show();
}

	ShowSelectRequest::ShowSelectRequest() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		color(FL_WHITE);
	begin();
		
	end();
	show();	
}


//Windows of the individual Commands(Database,Table,Entry,SelectRequest)

//Database

CreateDatabase::CreateDatabase() : Fl_Window(600,400,560,310,"SQL-Interface"){
 
  	color(FL_WHITE);
    begin();

    executeButton = new Fl_Button(465, 0, 95, 25, "Show");
    executeButton->color((Fl_Color)31);
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
   	sqlCommand = new Fl_Output(0, 40, 560, 30, "SQL-Command");
	databasename = new Fl_Input(120, 76, 140, 24, "Databasename:");

	executeButton->callback((Fl_Callback*) whenPushedTableShowButton);
	backButton->callback((Fl_Callback*) whenPushedBackCreateDatabase);

	end();
    show();
}

ShowDatabases::ShowDatabases() : Fl_Window(600,400,560,310,"SQL-Interface"){
 
  	color(FL_WHITE);
    begin();

    executeButton = new Fl_Button(465, 0, 95, 25, "Show");
    executeButton->color((Fl_Color)31);
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
   	sqlCommand = new Fl_Output(0, 40, 560, 30, "SQL-Command");

	//executeButton->callback((Fl_Callback*) whenPushedBackShowDatabases);
	backButton->callback((Fl_Callback*) whenPushedBackShowDatabases);

	end();
    show();
}

DeleteDatabase::DeleteDatabase() : Fl_Window(600,400,560,310,"SQL-Interface"){
 
  	color(FL_WHITE);
    begin();

    executeButton = new Fl_Button(465, 0, 95, 25, "Delete");
    executeButton->color((Fl_Color)31);
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
   	sqlCommand = new Fl_Output(0, 40, 560, 30, "SQL-Command");
	databasename = new Fl_Input(120, 76, 140, 24, "Databasename:");

	executeButton->callback((Fl_Callback*) whenPushedDeleteDatabase);
	backButton->callback((Fl_Callback*) whenPushedBackDeleteDatabase);

	end();
    show();
}

//Entry


SetEntry::SetEntry() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

    executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);

    tablename = new Fl_Input(120, 86, 140, 24, "Tablename:");
	columnname = new Fl_Input(120, 111, 140, 24, "Columnname:");
    entry = new Fl_Input(120, 136, 140, 24, "Entry:");

	backButton->callback((Fl_Callback*) whenPushedBackSetEntry);

	end();
	show();
}

ModifierEntry::ModifierEntry() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

    executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);

    tablename = new Fl_Input(120, 86, 140, 24, "Tablename:");
	columnname = new Fl_Input(120, 111, 140, 24, "Columnname:");
	oldEntry = new Fl_Input(120, 136, 140, 24, "OldEntry:");
	newEntry = new Fl_Input(120, 161, 140, 24, "NewEntry:");

	backButton->callback((Fl_Callback*) whenPushedBackModfierEntry);

	end();
	show();

}

 SetAllEntry::SetAllEntry() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

    executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);

    tablename = new Fl_Input(95, 86, 140, 24, "Tablename:");
	rowEntry = new Fl_Input(95, 116, 450, 24, "RowEntry");

	backButton->callback((Fl_Callback*) whenPushedBacksetAllEntry);

	end();
	show();

}

DeleteEntry::DeleteEntry() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

    executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);

    tablename = new Fl_Input(120, 86, 140, 24, "Tablename:");
	columnname = new Fl_Input(120, 111, 140, 24, "Columnname:");
	condition = new Fl_Input(120, 136, 140, 24, "Condition:");

	backButton->callback((Fl_Callback*) whenPushedBackDeleteEntry);

	end();
	show();
}

//Table-Window
CreateTable::CreateTable() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
     backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    executeButton->callback((Fl_Callback*) whenPushedCreateTableExecute);



    tableName = new Fl_Input(95, 86, 140, 24, "Tablename:");
    
    primaryKeyCheck = new Fl_Check_Button(275, 90, 105, 15, "PrimaryKey");
    primaryKeyCheck->down_box(FL_DOWN_BOX);
    columns = new Fl_Input(95, 111, 455, 24, "Columns:");

	backButton->callback((Fl_Callback*) whenPushedBackCreateTable);

	end();
	show();
}

ShowTableCommand::ShowTableCommand() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
     backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    tableName = new Fl_Input(95, 86, 140, 24, "Tablename:");
    

	backButton->callback((Fl_Callback*) whenPushedBackShowTable);

	end();
	show();
}

CountDatasets::CountDatasets() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
     backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    tableName = new Fl_Input(95, 86, 140, 24, "Tablename:");
    

	backButton->callback((Fl_Callback*) whenPushedBackCountDatases);

	end();
	show();
}

RenameTable::RenameTable() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    executeButton = new Fl_Button(525, 0, 95, 25, "Execute");
    executeButton->color((Fl_Color)31);
    executeButton->callback((Fl_Callback*) whenPushedRenameTable);
    oldTableName= new Fl_Input(130, 86, 140, 24, "Old Tablename:");
    newTableName =new Fl_Input(130, 111, 140, 24, "New Tablename:");


	backButton->callback((Fl_Callback*) whenPushedBackRenameTable);

	end();
	show();
}
DeleteTable::DeleteTable() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
     backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    executeButton->callback((Fl_Callback*)whenPushedDeleteTableExecute);
    tableName = new Fl_Input(95, 86, 140, 24, "Tablename:");
    

	backButton->callback((Fl_Callback*) whenPushedBackDeleteTable);

	end();
	show();	

}
SetColumn::SetColumn() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
     backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    columnName = new Fl_Input(95,130,140,24,"ColumnName");
	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    executeButton -> callback((Fl_Callback*)whenPushedSetColumnExecute);
    tableName = new Fl_Input(95, 86, 140, 24, "Tablename:");

    datatype = new Fl_Input_Choice(340, 86, 140, 24, "Datatype:");
	datatype->add("integer");
	datatype->add("float");
	datatype->add("char");
	datatype->add("varchar");
	datatype->add("date");
	datatype->add("time");
	datatype->add("datatime");
	datatype->add("text");
	datatype->add("blob");


	backButton->callback((Fl_Callback*) whenPushedBackSetColumn);

	end();
	show();
}
SetColumnWithPrimary::SetColumnWithPrimary() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
     backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    tableName = new Fl_Input(110, 86, 140, 24, "Tablename:");
    columnName = new Fl_Input(110, 111, 140, 24, "Columnname:");
    datatype = new Fl_Input_Choice(340, 111, 160, 24, "Datatype:");
	datatype->add("integer");
	datatype->add("float");
	datatype->add("char");
	datatype->add("varchar");
	datatype->add("date");
	datatype->add("time");
	datatype->add("datatime");
	datatype->add("text");
	datatype->add("blob");
	autoIncrement = new Fl_Check_Button(340, 85, 70, 15, "Auto Increment");

	backButton->callback((Fl_Callback*) whenPushedBackSetColumnWithPrimary);

	end();
	show();
}
 ModifierColumnName::ModifierColumnName() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
     backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
  	tableName= new Fl_Input(140, 86, 140, 24, "Tablename:");
    
    oldColumnName= new Fl_Input(140, 111, 140, 24, "Old Columnname:");
    newColumnName =new Fl_Input(140, 136, 140, 24, "New Columnname:");
    datatype = new Fl_Input_Choice(375, 136, 160, 24, "Datatype:");
	datatype->add("integer");
	datatype->add("float");
	datatype->add("char");
	datatype->add("varchar");
	datatype->add("date");
	datatype->add("time");
	datatype->add("datatime");
	datatype->add("text");
	datatype->add("blob");

	backButton->callback((Fl_Callback*) whenPushedBackModifierColumnName);

	end();
	show();
}

 ChangeDatatype::ChangeDatatype() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
     backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    tableName= new Fl_Input(140, 86, 140, 24, "Tablename:");
    columnName = new Fl_Input(140, 116, 140, 24, "Columnname:");
	datatype = new Fl_Input_Choice(375, 116, 160, 24, "Datatype:");
	datatype->add("integer");
	datatype->add("float");
	datatype->add("char");
	datatype->add("varchar");
	datatype->add("date");
	datatype->add("time");
	datatype->add("datatime");
	datatype->add("text");
	datatype->add("blob");

	backButton->callback((Fl_Callback*) whenPushedBackChangeDatatype);

	end();
	show();
}

 GetAllColumns::GetAllColumns() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    executeButton->callback((Fl_Callback*) whenPushedGetAllColumnsExecute);
    tableName=new Fl_Input(105, 86, 140, 24, "Tablename:");

	backButton->callback((Fl_Callback*) whenPushedBackGetAllColumns);

	end();
	show();
}
ShowColumnType::ShowColumnType() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
     backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    tableName = new Fl_Input(95, 86, 140, 24, "Tablename:");
    datatype = new Fl_Input_Choice(340, 86, 140, 24, "Datatype:");
	datatype->add("integer");
	datatype->add("float");
	datatype->add("char");
	datatype->add("varchar");
	datatype->add("date");
	datatype->add("time");
	datatype->add("datatime");
	datatype->add("text");
	datatype->add("blob");
	backButton->callback((Fl_Callback*) whenPushedBackShowColumnType);

	end();
	show();
}
DeleteColumn::DeleteColumn() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
     backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    tableName= new Fl_Input(140, 86, 140, 24, "Tablename:");

    columnName =new Fl_Input(140, 116, 140, 24, "Columnname:");


	backButton->callback((Fl_Callback*) whenPushedBackDeleteColumn);

	end();
	show();
}
SetSecondaryKey::SetSecondaryKey() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
     backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    tableNameSecondary = new Fl_Input(175, 86, 140, 24, "Tablename Secondary:");
    foreignKey = new Fl_Input(410, 86, 140, 24, "Foreign Key:");
    tableNamePrimary =new Fl_Input(175, 116, 140, 24, "Tablename Primary");
    primaryKey = new Fl_Input(410, 116, 140, 24, "Primary Key");
    constraint = new Fl_Input(175, 146, 140, 24, "Constraint");


	backButton->callback((Fl_Callback*) whenPushedBackSetSecondaryKey);

	end();
	show();
}

DeleteSecondaryKey::DeleteSecondaryKey() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
     backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
  	tableName =new Fl_Input(100, 91, 140, 24, "Tablename:");
    constraint = new Fl_Input(100, 116, 140, 24, "Constraint");


	backButton->callback((Fl_Callback*) whenPushedBackDeleteSecondaryKey);

	end();
	show();
}

SetPrimaryKey::SetPrimaryKey() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
     backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
   	tableName = new Fl_Input(100, 91, 140, 24, "Tablename:");
    primaryKey = new Fl_Input(100, 121, 140, 24, "Primary Key:");


	backButton->callback((Fl_Callback*) whenPushedBackSetPrimaryKey);

	end();
	show();
}
DeletePrimaryKey::DeletePrimaryKey() : Fl_Window(1280,400,620,310,"SQL-Interface"){	  
		
	color(FL_WHITE);
	begin();

   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
     backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
   	tableName = new Fl_Input(100, 91, 140, 24, "Tablename:");


	backButton->callback((Fl_Callback*) whenPushedBackDeletePrimaryKey);

	end();
	show();
}