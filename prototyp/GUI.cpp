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
Fl_Button *destroyWindow;
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

SelectLike *selectLikeWindow;
SelectNotLike *selectNotLikeWindow;
SelectMinOrMax *selectMinOrMaxWindow;
SelectMinOrMaxWhere *selectMinOrMaxWhereWindow;
SelectLimitWhereOrderBy *selectLimitWhereOrderByWindow;
SelectWhereOneColumn *selectWhereOneColumnWindow;
SelectWhere *selectWhereWindow;
SelectWhereBool *selectWhereBoolWindow;
SelectWhereOrderBy *selectWhereOrderByWindow;
SelectSortTable *selectSortTableWindow;
SelectCount *selectCountWindow;
SelectDistinct *selectDistinctWindow;
SelectCountDistinct *selectCountDistinctWindow;
SelectAverageSum *selectAverageSumWindow;
SelectSum *selectSumWindow;
SelectUnion *selectUnionWindow;
SelectIn *selectInWindow;
SelectBetween *selectBetweenWindow;
SelectColumnsAlias *selectColumnsAliasWindow;
SelectTableAlias *selecTableAliasWindow;
SelectGroupBy *selectGroupByWindow;
SelectGroupByOrderBy *selectGroupByOrderByWindow;
SelectCountGroupByOrderBy *selectCountGroupByOrderByWindow;
SelectNull *selectNullWindow;
SelectInnerJoin *selectInnerJoinWindow; 
SelectLeftJoin *selectLeftJoinWindow;
SelectRightJoin *selectRightJoinWindow;
OutputWindow *outputWindow;



Fl_Input *databasename;

Fl_Input *tablename;
Fl_Input *columnname;
Fl_Input *entry;
Fl_Input *condition;
Fl_Input *oldEntry;
Fl_Input *newEntry; 
Fl_Input *rowEntry; 
Fl_Input *toSortColumnName;
Fl_Input *aliases;
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
Fl_Input *toSearchColumn;
Fl_Input *pattern; 
Fl_Input *search; 
Fl_Input *minMaxColumn; 
Fl_Input *minMaxValue;
Fl_Input *aliasColumn;
Fl_Input *aliasTable;
Fl_Input *conditionColumn;
Fl_Input *conditionValue;
Fl_Input *conditionColumnTwo;
Fl_Input *conditionValueTwo;
Fl_Input *conditionTwo;
Fl_Input * operators;
Fl_Input_Choice *sortBy;
Fl_Input *sortColumn;
Fl_Input *countColumn;
Fl_Input *averageSumColumn;
Fl_Input *sumColumn;
Fl_Input * aliasColumns;
Fl_Input *groupByColumns;
Fl_Input *firstTable;
Fl_Input *firstTableIDColumn;
Fl_Input *firstTableColumns;
Fl_Input *secondTable;
Fl_Input *secondTableColumns;
Fl_Input *limitNumber;


Fl_Input *sqlStatement;
Fl_Output *sqlCommand;
Fl_Output *messageerror;
Fl_Output *feedback;
Fl_Output *connectoutput;
Fl_Output *tableOutput;

Fl_Check_Button *feedbackM;
Fl_Check_Button *feedbackAllM;
Fl_Check_Button *queryM;

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

	std::vector<std::string> charToVec(const char* value){

		std::vector<std::string> strvec;
		const char *val = columns->value(); 
		char delimiter[]= ", ";

		char *tempval = std::strtok(strdup(val), delimiter);

		while(tempval != NULL) {
			strvec.push_back(tempval);
			std::cout << tempval << std::endl;
			tempval = std::strtok(NULL, delimiter);
		}

		return strvec;

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

				if((strcmp(databasesCommands->value(),"rename Databases"))==0){
					databaseWindow->hide();
					deleteDatabaseWindow=new DeleteDatabase();
					sqlCommand->value("  + databaseName;"); 
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
				
				if((strcmp(selectRequestCommands->value(),"selectCount"))==0){
					selectRequestWindow->hide();
					selectCountWindow= new SelectCount();
					sqlCommand->value("SELECT COUNT( countColumn AS aliasColumnName FROM tableName + ;");
				}

				if((strcmp(selectRequestCommands->value(),"selectIn"))==0){
				selectRequestWindow->hide();
				selectInWindow= new SelectIn();
				sqlCommand->value("SELECT allColumns FROM tableName WHERE  searchInColumn IN (comperativValues);");
				}
				if((strcmp(selectRequestCommands->value(),"selectDistinct"))==0){
				selectRequestWindow->hide();
				selectDistinctWindow= new SelectDistinct();
				sqlCommand->value("SELECT DISTINCT allColumns FROM tableName;");
				}
				if((strcmp(selectRequestCommands->value(),"selectCountDistinct"))==0){
				selectRequestWindow->hide();
				selectCountDistinctWindow = new SelectCountDistinct();
				sqlCommand->value("SELECT COUNT(DISTINCT countColumn FROM tableName ");
				}
				if((strcmp(selectRequestCommands->value(),"selectLike"))==0){
				selectRequestWindow->hide();
				selectLikeWindow= new SelectLike();
				sqlCommand->value("SELECT allColumns  FROM tableName WHERE toSearchColumn  LIKE'toSearch %' ");
				}
				if((strcmp(selectRequestCommands->value(),"selectNotLike"))==0){
				selectRequestWindow->hide();
				selectNotLikeWindow= new SelectNotLike();
				sqlCommand->value("SELECT allColumns  FROM tableName WHERE toSearchColumn  LIKE'toSearch %'");
				}
				if((strcmp(selectRequestCommands->value(),"selectSum"))==0){
				selectRequestWindow->hide();
				selectSumWindow= new SelectSum();
				sqlCommand->value("SELECT SUM( columnName )AS aliasColumnName FROM tableName");
				}
				if((strcmp(selectRequestCommands->value(),"selectAverageSum"))==0){
				selectRequestWindow->hide();
				selectAverageSumWindow= new SelectAverageSum();
				sqlCommand->value("SELECT AVG(columnName + FROM tableName");
				}

				if((strcmp(selectRequestCommands->value(),"selectSortTable"))==0){
				selectRequestWindow->hide();
				selectSortTableWindow= new SelectSortTable();
				sqlCommand->value("SELECT * FROM tableName ORDER BY toSortColumnName ASC");
				}

				if((strcmp(selectRequestCommands->value(),"selectBetween"))==0){
				selectRequestWindow->hide();
				selectBetweenWindow= new SelectBetween();
				sqlCommand->value("SELECT * FROM tableName WHERE conditionColumn conditionString condition AND conditionColumnTwo conditionString conditionTwo;");
				}

				if((strcmp(selectRequestCommands->value(),"selectMinOrMax"))==0){
				selectRequestWindow->hide();
				selectMinOrMaxWindow = new SelectMinOrMax();
				sqlCommand->value("SELECT MIN(minOrMaxColumn)AS aliasColumn FROM tableName");
				}

				if((strcmp(selectRequestCommands->value(),"selectMinOrMaxWhere"))==0){
				selectRequestWindow->hide();
				selectMinOrMaxWhereWindow= new SelectMinOrMaxWhere();
				sqlCommand->value("SELECT MAX( minOrMaxColumn ) AS aliasColumn FROM tableName WHERE conditionColumn =' conditionValue '");
				}

				if((strcmp(selectRequestCommands->value(),"selectWhere"))==0){
				selectRequestWindow->hide();
				selectWhereWindow= new SelectWhere();
				sqlCommand->value("SELECT allColumns FROM tableName WHERE conditionColumn 'conditionValue '");
				}

				if((strcmp(selectRequestCommands->value(),"selectWhereOrderBy"))==0){
				selectRequestWindow->hide();
				selectWhereOrderByWindow= new SelectWhereOrderBy();
				sqlCommand->value("SELECT allColumns FROM tableName WHERE conditionColumn 'conditionValue 'ORDER BY toSortcolumnName ASC");
				}
				if((strcmp(selectRequestCommands->value(),"selectWhereOneColumn"))==0){
				selectRequestWindow->hide();
				selectWhereOneColumnWindow= new SelectWhereOneColumn();
				sqlCommand->value("SELECT * FROM tableName WHERE conditionColumn = 'conditionValue'");
				}


				if((strcmp(selectRequestCommands->value(),"selectWhereBool"))==0){
				selectRequestWindow->hide();
				selectWhereBoolWindow= new SelectWhereBool();
				sqlCommand->value(" SELECT allColumns FROM tableName WHERE conditionOperatorString ");
				}

				if((strcmp(selectRequestCommands->value(),"selectLimitWhereOrderBy"))==0){
				selectRequestWindow->hide();
				selectLimitWhereOrderByWindow = new SelectLimitWhereOrderBy();
				sqlCommand->value("SELECT allColumns FROM tableName WHERE conditionColumn 'conditionValue 'ORDER BY toSortcolumnName ASC LIMIT limitNumber");
				}

				if((strcmp(selectRequestCommands->value(),"selectUnion"))==0){
				selectRequestWindow->hide();
				selectUnionWindow= new SelectUnion();
				sqlCommand->value("SELECT columnName.at(i) FROM tableName.at(i)UNION SELECT columnName.at(i) FROM tableName.at(i) ");
				}

				if((strcmp(selectRequestCommands->value(),"selectColumnAlias"))==0){
				selectRequestWindow->hide();
				selectColumnsAliasWindow = new SelectColumnsAlias();
				sqlCommand->value("SELECT columnAlias FROM tableName");
				}

				if((strcmp(selectRequestCommands->value(),"selectTableAlias"))==0){
				selectRequestWindow->hide();
				//selectTableAliass = new selectTableAlias(); // fix
				sqlCommand->value("SELECT columnAlias FROM tableName AS aliasTableName");
				}

				if((strcmp(selectRequestCommands->value(),"selectGroupBy"))==0){
				selectRequestWindow->hide();
				selectGroupByWindow = new SelectGroupBy();
				sqlCommand->value("SELECT allColumns FROM tableName WHERE conditionColumn ' conditionValue ' GROUP BY allGroupByColumns ");
				}

				if((strcmp(selectRequestCommands->value(),"selectGroupByOrderBy"))==0){
				selectRequestWindow->hide();
				selectGroupByOrderByWindow= new SelectGroupByOrderBy();
				sqlCommand->value("SELECT allColumns FROM tableName WHERE conditionColumn = 'conditionValue ' GROUP BY allGroupByColumns ORDER BY  toSortcolumnName ASC");
				}
				if((strcmp(selectRequestCommands->value(),"selectInnerJoin"))==0){
				selectRequestWindow->hide();
				selectInnerJoinWindow = new SelectInnerJoin();
				sqlCommand->value("select <Auswahl> FROM TabelleA INNER JOIN TabelleB B ON A.ID = B.ID");
				}

				if((strcmp(selectRequestCommands->value(),"selectLeftJoin"))==0){
				selectRequestWindow->hide();
				selectLeftJoinWindow = new SelectLeftJoin(); 
				sqlCommand->value("select <Auswahl> FROM TabelleA LEFT JOIN TabelleB B ON A.ID = B.ID");
				}

				if((strcmp(selectRequestCommands->value(),"selectRightJoin"))==0){
				selectRequestWindow->hide();
				selectRightJoinWindow= new SelectRightJoin();
				sqlCommand->value("select <Auswahl> FROM TabelleA LEFT JOIN TabelleB B ON A.ID = B.ID");
				}

				if((strcmp(selectRequestCommands->value(),"selectNull"))==0){
				selectRequestWindow->hide();
				selectNullWindow= new SelectNull();
				sqlCommand->value("SELECT *  FROM tableName WHERE columnName IS NULL OR ' '");
				}
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
				std::string outputvalue ="";
				
				messageerror->value(" ");

				if(queryM->value()==true){
					connection_query(sqlStatement->value());
					std::string errormsg = check_error();
 					messageerror->value(errormsg.c_str());
 					std::string msg = sqlStatement->value(); 
 					feedback->value(msg.c_str()); 

				}

				 else if(feedbackM->value()==true){
					connection_feedback(sqlStatement->value());
					
					std::string errormsg = check_error();
 					messageerror->value(errormsg.c_str());
 					std::string msg = sqlStatement->value(); 
 					feedback->value(msg.c_str()); 
 					outputWindow = new OutputWindow();
 					outputWindow ->show();
 					tableOutput->value();
				}

				else if (feedbackAllM->value()==true){
					connection_feedbackAll(sqlStatement->value());
					std::string errormsg = check_error();
 					messageerror->value(errormsg.c_str());
 					std::string msg = sqlStatement->value();
 					feedback->value(msg.c_str()); 

				}

				else {

					messageerror->value("Bitte den Methodenaufruf ankreuzen");

				}

			
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

	//database execute

	void whenPushedCreateDatabaseExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				createDatabase(databasename->value());
			}
	
	}

	void whenPushedShowDatabasesExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				showDatabases();
			}

	}

	void whenPushedDeleteDatabasesExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				deleteDatabase(databasename->value());
			}

	}	

	//rename database fehlt ! ! ! 


	//entry execute

	void whenPushedSetEntryExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				setEntry(tablename->value(),columnname->value(),entry->value());

			}
	
	}

	void whenPushedSetAllEntryExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				std::vector<std::string> rows = charToVec(rowEntry->value());
				setAllEntry(tablename->value(),rows);

			}
	
	}

	void whenPushedModifierEntryExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				modifierEntry(tablename->value(), columnname->value(), oldEntry->value(), newEntry->value());

			}
	
	}

	void whenPushedDeleteEntryExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				deleteEntry(tablename->value(), columnname->value(),condition->value());

			}
	
	}


	void whenPushedCreateTableExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				std::vector<std::string> col = charToVec(columns->value());
				createTable(primaryKeyCheck->value(), tableName->value(), col);

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

	void whenPushedShowColumnTypeExecute(Fl_Widget* w, void*){
			if(((Fl_Button*)w) -> value()){}
			else{
				showColumnTyp(tableName->value(), datatype->value());//exceptionhandling
		}	
	}	

	void whenPushedDeleteColumnExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				deleteColumn(tableName->value(), columnName->value());
		}	
	}	

	void whenPushedModifierColumnNameExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				modifierColumnName(tableName->value(), oldColumnName->value(), newColumnName->value(), datatype->value());
		}	
	}	

	void whenPushedsetColumnWithPrimaryExecute(Fl_Widget* w, void*){

	if(((Fl_Button*)w) -> value()){}
		else{
			setColumnWithPrimary(tableName->value(), columnName->value(), datatype->value(),autoIncrement->value());
		}	
	}	

	void whenPushedsetPrimaryKeyExecute(Fl_Widget* w, void*){

	if(((Fl_Button*)w) -> value()){}
		else{
			setPrimaryKey(tableName->value(), primaryKey->value());
		}	
	}	

	void whenPushedDeletePrimaryKeyExecute(Fl_Widget* w, void*){

	if(((Fl_Button*)w) -> value()){}
		else{
			deletePrimaryKey(tableName->value());
		}	
	}	

	void whenPushedSetSecondaryKeyExecute(Fl_Widget* w, void*){

	if(((Fl_Button*)w) -> value()){}
		else{
			setSecondaryKey(tableNameSecondary->value(), foreignKey->value(),tableNamePrimary->value(),primaryKey->value(),constraint->value());
		}	
	}	

	void whenPushedDeleteSecondaryKeyExecute(Fl_Widget* w, void*){

	if(((Fl_Button*)w) -> value()){}
		else{
			deleteSecondaryKey(tableName->value(), constraint->value());
		}	
	}	

	void whenPushedChangeTheDatatypeExecute(Fl_Widget* w, void*){

	if(((Fl_Button*)w) -> value()){}
		else{
			changeTheDatatype(tableName->value(), columnName->value(), datatype->value());
		}	
	}	

	void whenPushedCountDatasetsExecute(Fl_Widget* w, void*){

	if(((Fl_Button*)w) -> value()){}
		else{
			countDatasets(tableName->value());
		}	
	}	


	void whenPushedBackSelectCount(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectCountWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectIn(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectInWindow->hide();
				selectRequestWindow->show();
		}	
	}
	
	void whenPushedBackSelectDistinct(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectDistinctWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectCountDistinct(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectCountDistinctWindow->hide();
				selectRequestWindow->show();
		}	
	}



	void whenPushedBackSelectLike(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectLikeWindow->hide();
				selectRequestWindow->show();
		}	
	}	

	void whenPushedBackSelectNotLike(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectNotLikeWindow->hide();
				selectRequestWindow->show();
		}	
	}	

	void whenPushedBackSelectSum(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectSumWindow->hide();
				selectRequestWindow->show();
		}	
	}	

	void whenPushedBackSelectAverageSum(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectAverageSumWindow->hide();
				selectRequestWindow->show();
		}	
	}	

	void whenPushedBackSelectSortTable(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectSortTableWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectBetween(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectBetweenWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectMinOrMax(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectMinOrMaxWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectMinOrMaxWhere(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectMinOrMaxWhereWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectWhere(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectWhereWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectWhereOrderBy(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectWhereOrderByWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectWhereOneColumn(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectWhereOneColumnWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectWhereBool(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectWhereBoolWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectWhereLimitOrderBy(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectLimitWhereOrderByWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectUnion(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectUnionWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectColumnsAlias(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectColumnsAliasWindow->hide();
				selectRequestWindow->show();
		}	
	}


	void whenPushedBackSelectTableAlias(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selecTableAliasWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectGroupBy(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectGroupByWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectGroupByOrderBy(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectGroupByOrderByWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectInnerJoin(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectInnerJoinWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectLeftJoin(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectLeftJoinWindow->hide();
				selectRequestWindow->show();
		}	
	}

	void whenPushedBackSelectRightJoin(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectRightJoinWindow->hide();
				selectRequestWindow->show();
		}	
	}


	void whenPushedBackSelectNull(Fl_Widget* w, void*){

		if(((Fl_Button*)w) -> value()){}
			else{
				selectNullWindow->hide();
				selectRequestWindow->show();
		}	
	}


// Execute Methoden für die SelectionRequest-Anweisungen




	void whenPushedSelectCountExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{

				selectCount(tableName->value(),countColumn->value(),aliasColumn->value());
			
			}
	}

	void whenPushedSelectInExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
	
			else{
					std::vector<std::string> col = charToVec(columns->value());
					std::vector<std::string> conditionVal = charToVec(conditionValue->value());
				
					selectIn(tableName->value(),col,toSearchColumn->value(),conditionVal);
				}

			}
		

	void whenPushedSelectDistinctExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				std::vector<std::string> col = charToVec(columns->value());
				selectDistinct(tableName->value(),col);

			}
	}

	void whenPushedSelectCountDistinctExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				selectCountDistinct(tableName->value(),countColumn->value());

			}
	}

	void whenPushedSelectLikeExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
			std::vector<std::string> col = charToVec(columns->value());				
			selectLike(tableName->value(),col,toSearchColumn->value(),pattern->value(),search->value());
			
			}

	}

	void whenPushedSelectNotLikeExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				std::vector<std::string> col = charToVec(columns->value());
				selectNotLike(tableName->value(),col ,toSearchColumn->value(),pattern->value(),search->value());

			}
	}

	void whenPushedSelectSumExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				selectSum(tableName->value(),  sumColumn->value(), aliasColumn->value());

			}
	}

	void whenPushedSelectAverageSumExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				selectAverageSum(tableName->value(),averageSumColumn->value());

			}
	}

	void whenPushedSelectSortTableExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				selectSortTable(tableName->value(),sortColumn->value(), sortBy->value());

			}
	}

	void whenPushedSelectBetweenExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				selectBetween(conditionValue->value(),conditionValueTwo->value(),tableName->value(),conditionColumn->value(),conditionColumnTwo->value(), condition->value(),conditionTwo->value());

			}

	}

	void whenPushedSelectMinOrMaxExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				selectMinOrMax(tableName->value(),minMaxValue->value(),minMaxColumn->value(),aliasColumn->value());

			}
	}

	void whenPushedSelectMinOrMaxWhereExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				selectMinOrMaxWhere(tableName->value(),minMaxValue->value(), minMaxColumn->value(),aliasColumn->value(),conditionColumn->value(),conditionValue->value());

			}
	}


	void whenPushedSelectWhereExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{

				std::vector<std::string> colum = charToVec(columns->value());

				selectWhere(tableName->value(),colum,conditionColumn->value(),conditionValue->value());

			}
	}

	void whenPushedSelectWhereOrderByExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				std::vector<std::string> col = charToVec(columns->value());
				selectWhereOrderBy(tableName->value(),col,conditionColumn->value(),conditionValue->value(), sortColumn->value(),sortBy->value());
			}
	}


	void whenPushedSelectWhereOneColumnExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				selectWhereOneColumn(tableName->value(),conditionColumn->value(),conditionValue->value());

			}
	}

	void whenPushedSelectWhereBoolExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{

				std::vector<std::string> col = charToVec(columns->value());
				std::vector<std::string> con = charToVec(conditionColumn->value());
				std::vector<std::string> conVal = charToVec(conditionValue->value());
				std::vector<std::string> conTwo = charToVec(conditionValueTwo->value());
				std::vector<std::string> conValTwo = charToVec(conditionValueTwo->value());
				std::vector<std::string> op = charToVec(operators -> value());

				selectBool(tableName->value(), col, con, conVal, conTwo, conValTwo, op);

			}
	}

	void whenPushedSelectLimitWhereOrderByExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				std::vector<std::string> col = charToVec(columns->value());

				selectLimitWhereOrderBy(tableName->value(),col,limitNumber->value(), conditionColumn->value(), conditionValue->value(),toSortColumnName->value(),sortBy->value());

			}
	}

void whenPushedSelectUnionExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				std::vector<std::string> tabNam = charToVec(tableName->value());
				std::vector<std::string> colNam = charToVec(columnName->value());
				
				selectUnion(tabNam,colNam);

			}
	}

void whenPushedSelectColumnAliasExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				std::vector<std::string> col = charToVec(columns->value());
				std::vector<std::string> alias = charToVec(aliases->value());
				
				selectColumnsAlias(tableName->value(),col,alias);

			}
	}

void whenPushedSelectTableAliasExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				std::vector<std::string> col = charToVec(columns->value());

				selectTableAlias(tableName->value(), col, aliasTable->value());

			}
 	} 

void whenPushedSelectGroupByExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				std::vector<std::string> col = charToVec(columns->value());
				std::vector<std::string> groupColumns = charToVec(groupByColumns->value());

				selectGroupBy(tableName->value(),col,conditionColumn->value(),conditionValue->value(),groupColumns);

			}
	}

void whenPushedSelectGroupByOrderByExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				std::vector<std::string> col = charToVec(columns->value());
				std::vector<std::string> groupColum = charToVec(groupByColumns->value());

				selectGroupByOrderBy(tableName->value(),col,conditionColumn->value(),conditionValue->value(),groupColum, sortColumn->value(), sortBy->value());
			}
	}

void whenPushedSelectInnerJoinExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				std::vector<std::string> colTableOne = charToVec(firstTableColumns->value());
				std::vector<std::string> colTabTwo = charToVec(secondTableColumns->value());

				selectInnerJoin(firstTable->value(),firstTableIDColumn->value(),colTableOne, secondTable->value(),colTabTwo);

			}
	}

void whenPushedSelectLeftJoinExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				std::vector<std::string> colTableOne = charToVec(firstTableColumns->value());
				std::vector<std::string> colTableTwo = charToVec(secondTableColumns->value());

				selectLeftJoin(firstTable->value(),firstTableIDColumn->value(),colTableOne, secondTable->value(),colTableTwo);

			}
	}

void whenPushedSelectRightJoinExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				std::vector<std::string> colTableOne = charToVec(firstTableColumns->value());
				std::vector<std::string> colTableTwo = charToVec(secondTableColumns->value());

				selectRightJoin(firstTable->value(),firstTableIDColumn->value(),colTableOne, secondTable->value(),colTableTwo);

			}
	}


void whenPushedSelectNullExecute(Fl_Widget* w, void*){
		if(((Fl_Button*)w) -> value()){}
			else{
				selectNull(tableName->value(), columnName->value());
			}
	}



	GUI::GUI(){
	connectionWindow = new ConnectionWindow();
		

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
		connectoutput = new Fl_Output(170,260,200,30, "Meldung"); 
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
 	sending->callback((Fl_Callback*) whenPushedSend); 
 	feedback = new Fl_Output (100,100,400,100, "SQL-Befehl:");
 	messageerror = new Fl_Output(100,200,400,50,"Fehlermeldung:"); // Kein Automatischer Zeilenumbruch 
 	disconnectButton->callback((Fl_Callback*) whenPushedSelfDisconnect); 
	backButton = new Fl_Button(95, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*)whenPushedBackSelf);

	feedbackM = new Fl_Check_Button(50,270,105,15, "feedback-Aufruf"); 
	feedbackAllM = new Fl_Check_Button(200,270,105,15, "feedbackAll-Aufruf");
	queryM = new Fl_Check_Button(350,270,105,15, "Query-Aufruf");

	Fl_Check_Button(275, 90, 105, 15, "PrimaryKey");


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
	selectRequestCommands->add("selectCountDistinct");
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

	executeButton->callback((Fl_Callback*) whenPushedCreateDatabaseExecute);
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

	executeButton->callback((Fl_Callback*) whenPushedShowDatabasesExecute);
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

	executeButton->callback((Fl_Callback*) whenPushedDeleteDatabasesExecute);
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
    executeButton->callback((Fl_Callback*) whenPushedSetEntryExecute);

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
    executeButton->callback((Fl_Callback*)whenPushedModifierEntryExecute);


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
    executeButton->callback((Fl_Callback*) whenPushedSetAllEntryExecute);


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
    executeButton->callback((Fl_Callback*)whenPushedDeleteEntryExecute);


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
    executeButton->callback((Fl_Callback*)whenPushedCountDatasetsExecute);
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
    executeButton->callback((Fl_Callback*) whenPushedsetColumnWithPrimaryExecute);
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
    executeButton->callback((Fl_Callback*)whenPushedModifierColumnNameExecute);
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
    executeButton->callback((Fl_Callback*) whenPushedChangeTheDatatypeExecute);
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
    executeButton->callback((Fl_Callback*) whenPushedShowColumnTypeExecute);
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
    executeButton->callback((Fl_Callback*) whenPushedDeleteColumnExecute);
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
    executeButton->callback((Fl_Callback*)whenPushedSetSecondaryKeyExecute);

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
    executeButton->callback((Fl_Callback*) whenPushedDeleteSecondaryKeyExecute);
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
    executeButton->callback((Fl_Callback*)whenPushedsetPrimaryKeyExecute);
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
    executeButton->callback((Fl_Callback*) whenPushedDeletePrimaryKeyExecute);
   	tableName = new Fl_Input(100, 91, 140, 24, "Tablename:");


	backButton->callback((Fl_Callback*) whenPushedBackDeletePrimaryKey);

	end();
	show();
}

SelectLike::SelectLike() :  Fl_Window(1280,400,620,310,"SQL-Interface"){	 
		
    color(FL_WHITE);
    begin();
  
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton-> callback((Fl_Callback*)whenPushedBackSelectLike);
	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);

	tableName =new Fl_Input(150, 91, 185, 24, "Tablename:");
   
    columns= new Fl_Input(150, 122, 350, 23, "Displayed Columns:");
  
    toSearchColumn = new Fl_Input(150, 151, 185, 24, "ToSearchColumn:");
  
    pattern =new Fl_Input(150, 181, 185, 24, "Pattern:");
  
    search = new Fl_Input(150, 211, 185, 24, "Search");

    end();
    show();
}

SelectNotLike::SelectNotLike() :  Fl_Window(1280,400,620,310,"SQL-Interface"){	 
		
    color(FL_WHITE);
    begin();
  
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton-> callback((Fl_Callback*) whenPushedBackSelectNotLike);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);

	tableName =new Fl_Input(150, 91, 185, 24, "Tablename:");
   
    columns= new Fl_Input(150, 122, 350, 23, "Displayed Columns:");
  
    toSearchColumn = new Fl_Input(150, 151, 185, 24, "ToSearchColumn:");
  
    pattern =new Fl_Input(150, 181, 185, 24, "Pattern:");
  
    search = new Fl_Input(150, 211, 185, 24, "Search");

    end();
    show();
}

SelectMinOrMax::SelectMinOrMax() : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectMinOrMax);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);

    tableName =new Fl_Input(150, 91, 185, 24, "Tablename:");
  
    minMaxColumn = new Fl_Input(150, 151, 185, 24, "Min/Max Value:");
  
  	minMaxValue =new Fl_Input(150, 181, 185, 24, "Min/Max Value:");
  
    aliasColumn = new Fl_Input(150, 211, 185, 24, "AliasColumn");

    end();
    show();
}

SelectMinOrMaxWhere::SelectMinOrMaxWhere() : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectMinOrMaxWhere);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);

    tableName =new Fl_Input(150, 91, 185, 24, "Tablename:");
   
    aliasColumn= new Fl_Input(150, 122, 350, 23, "Displayed Columns:");
  
    minMaxColumn = new Fl_Input(150, 151, 185, 24, "Min/Max Column:");
  
    minMaxValue =new Fl_Input(150, 181, 185, 24, "Min/Max Value:");
  
    conditionColumn =  new Fl_Input(150, 211, 185, 24, "Condition Column:");

    conditionValue =  new Fl_Input(150, 241, 185, 24, "Condition Value:");

    end();
    show();
}

SelectWhereOneColumn::SelectWhereOneColumn() : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectWhereOneColumn);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);

    tableName =new Fl_Input(150, 91, 185, 24, "Tablename:");
   
    conditionColumn= new Fl_Input(150, 121, 185, 24, "Condition Column:");
  
    conditionValue  =  new Fl_Input(150, 151, 185, 24, "Condition Value:");

    end();
    show();
}

SelectWhere::SelectWhere()  : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectWhere);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);

    tableName = new Fl_Input(150, 91, 185, 24, "Tablename:");
   
   columns = new Fl_Input(150, 122, 350, 23, "Displayed Columns:");
  
    conditionColumn  = new Fl_Input(150, 151, 185, 24, "Min/Max Column:");
  
    conditionValue =  new Fl_Input(150, 181, 185, 24, "Conditon Column:");

    end();
    show();

}

SelectWhereBool::SelectWhereBool() : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectWhereBool);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);


    tableName =new Fl_Input(150, 91, 185, 24, "Tablename:");
   
    columns= new Fl_Input(150, 122, 350, 23, "Displayed Columns:");
  
    conditionColumn =  new Fl_Input(155, 151, 350, 24, "1.Conditon Columns:");
  
    conditionValue =  new Fl_Input(155, 181, 350, 24, "1.Condition Values:");

    conditionColumnTwo =  new Fl_Input(155, 211, 350, 24, "2.Conditon Columns:");
    conditionValueTwo =  new Fl_Input(155, 241, 350, 24, "2.Condition Values:");
    operators = new Fl_Input(155, 271, 350, 24, "Operators:");

    end();
    show();
}

SelectWhereOrderBy::SelectWhereOrderBy() : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectWhereOrderBy);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);

    tableName =new Fl_Input(150, 91, 185, 24, "Tablename:");
   
    columns= new Fl_Input(150, 122, 350, 23, "Displayed Columns:");
  
    conditionColumn =  new Fl_Input(150, 151, 185, 24, "Conditon Column:");
  
    conditionValue =  new Fl_Input(150, 181, 185, 24, "Condition Value:");

    sortColumn =  new Fl_Input(150, 211, 185, 24, "Sort Column");
    sortBy =  new Fl_Input_Choice(430, 211, 75, 24, "Sort by:");
	sortBy->add("ASC");
	sortBy->add("DESC");
   


    end();
    show();
}

SelectSortTable::SelectSortTable() : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectSortTable);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);

    Fl_Input *tableName = new Fl_Input(150, 91, 185, 24, "Tablename:");
   
    Fl_Input *sortColumn =  new Fl_Input(150, 121, 185, 24, "Sort Column");
	sortBy = new Fl_Input_Choice(435, 121, 75, 24, "Sort by:");

    end();
    show();
}

SelectCount::SelectCount() : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectCount);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);

    tableName =new Fl_Input(150, 91, 185, 24, "Tablename:");
   
    countColumn= new Fl_Input(150, 122, 185, 23, "Count Column:");
  
    aliasColumn =  new Fl_Input(150, 151, 185, 24, "Alias Column:");  



    end();
    show();
}

SelectDistinct::SelectDistinct() : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectDistinct);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    tableName =new Fl_Input(150, 91, 185, 24, "Tablename:");
   
    columns= new Fl_Input(150, 122, 345, 23, "Displayed Columns:");

    end();
    show();
}

SelectCountDistinct::SelectCountDistinct() : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectCountDistinct);
	
	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    tableName =new Fl_Input(150, 91, 185, 24, "Tablename:");
    countColumn= new Fl_Input(150, 122, 185, 23, "Count Column:"); 

    end();
    show();
}

SelectAverageSum::SelectAverageSum()  : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectAverageSum);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);

    tableName =new Fl_Input(170, 91, 185, 24, "Tablename:");
   
    averageSumColumn= new Fl_Input(170, 117, 185, 23, "AverageSum Column");

    end();
    show();
}

SelectSum::SelectSum()  : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectSum);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);

   	tableName =new Fl_Input(150, 91, 185, 24, "Tablename:");
    sumColumn= new Fl_Input(150, 122, 185, 23, "Sum Column:");
    aliasColumn =   new Fl_Input(150, 151, 185, 24, "Alias Column:");

    end();
    show();
}

SelectIn::SelectIn()   : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectIn);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    executeButton->callback((Fl_Callback*)whenPushedSelectInExecute);
	
    tableName =new Fl_Input(150, 91, 185, 24, "Tablename:");
    columns= new Fl_Input(150, 122, 350, 23, "Displayed Columns:");
    toSearchColumn =  new Fl_Input(150, 151, 185, 24, "Search Column:");
	conditionValue =  new Fl_Input(150, 181, 185, 24, "Condition Value:");

    end();
    show();
}

SelectBetween::SelectBetween()  : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectBetween);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
	
    tableName =new Fl_Input(150, 91, 185, 24, "Tablename: ");
    condition= new Fl_Input(150, 122, 350, 23, "Condition 1: ");
    conditionTwo = new Fl_Input(150,151,350,23, "Condition 2: ");
    conditionValue =  new Fl_Input(150, 241, 185, 24, "Condition Value 1: ");
    conditionValueTwo =   new Fl_Input(150, 271, 185, 24, "Condition Value 2: ");
	conditionColumn =    new Fl_Input(150, 181, 185, 24, "Condition Column 1: ");
    conditionColumnTwo =    new Fl_Input(150, 211, 185, 24, "Condition Column 2: ");

    end();
    show();
}

SelectColumnsAlias::SelectColumnsAlias() : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectColumnsAlias);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    executeButton->callback((Fl_Callback*) whenPushedSelectColumnAliasExecute);
	tableName = new Fl_Input(120, 76, 140, 24, "Tablename: ");
	columns = new Fl_Input(120,106,149,24, "Columnname(s): ");
	aliases = new Fl_Input(120,136,149,24, "Alias(es): ");

    end();
    show();
}

SelectTableAlias::SelectTableAlias() : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectTableAlias);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    tableName = new Fl_Input(150, 91, 185, 24, "Tablename:");
    columns= new Fl_Input(150, 152, 350, 23, "Displayed Columns:");
    aliasTable =   new Fl_Input(150, 121, 185, 24, "Alias Table");

    end();
    show();
}

SelectGroupBy::SelectGroupBy() : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectGroupBy);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    tableName =new Fl_Input(150, 91, 185, 24, "Tablename:");
   
    columns= new Fl_Input(150, 122, 350, 23, "Displayed Columns:");
  
    conditionColumn =  new Fl_Input(150, 151, 185, 24, "Conditon Column:");

    conditionValue =  new Fl_Input(150, 181, 185, 24, "Condition Value:");
  
    groupByColumns =new Fl_Input(150, 211, 350, 24, "GroupBy Columns:");

    end();
    show();
}

SelectGroupByOrderBy::SelectGroupByOrderBy(): Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectGroupByOrderBy);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    tableName =new Fl_Input(150, 91, 185, 24, "Tablename:");
   
    columns= new Fl_Input(150, 122, 350, 23, "Displayed Columns:");
  
    conditionColumn =  new Fl_Input(150, 151, 185, 24, "Conditon Column:");

    conditionValue =  new Fl_Input(150, 181, 185, 24, "Condition Value:");
  	sortColumn =  new Fl_Input(150, 241, 185, 24, "Sort Column");
    sortBy = new Fl_Input_Choice(425, 241, 75, 24, "Sort by:");
	sortBy->add("ASC");
	sortBy->add("DESC");
    groupByColumns = new Fl_Input(150, 212, 350, 23, "GroupBy Columns:");

    end();
    show();
}

SelectCountGroupByOrderBy::SelectCountGroupByOrderBy(): Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectGroupByOrderBy);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    tableName =new Fl_Input(150, 91, 185, 24, "Tablename:");
   
    columns= new Fl_Input(150, 122, 350, 23, "Displayed Columns:");
  
    conditionColumn =  new Fl_Input(150, 151, 185, 24, "Conditon Column:");

    conditionValue =  new Fl_Input(150, 181, 185, 24, "Condition Value:");
  	sortColumn =  new Fl_Input(150, 241, 185, 24, "Sort Column");
    sortBy = new Fl_Input_Choice(425, 241, 75, 24, "Sort by:");
	sortBy->add("ASC");
	sortBy->add("DESC");
    groupByColumns = new Fl_Input(150, 212, 350, 23, "GroupBy Columns:");
	countColumn = new Fl_Input(150, 146, 185, 24, "Count Column:");

    end();
    show();
}

SelectNull::SelectNull(): Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectNull);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    tableName =  new Fl_Input(150, 91, 185, 24, "Tablename:");
   
    columns=  new Fl_Input(150, 121, 185, 24, "Column:");;

    end();
    show();
}

SelectInnerJoin::SelectInnerJoin() : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectInnerJoin);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    firstTable =new Fl_Input(175, 86, 185, 24, "First Table:");
    firstTableIDColumn=  new Fl_Input(175, 146, 185, 24, "First Table ID Column");
    firstTableColumns =  new Fl_Input(175, 176, 355, 24, "First Table Columns:");
    secondTable =  new Fl_Input(175, 116, 185, 24, "Second Table:");
    secondTableColumns =   new Fl_Input(175, 206, 355, 24, "Second Table Columns:");

    end();
    show();
}

SelectRightJoin::SelectRightJoin() : Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectRightJoin);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    firstTable =new Fl_Input(175, 86, 185, 24, "First Table:");
    firstTableIDColumn=  new Fl_Input(175, 146, 185, 24, "First Table ID Column");
    firstTableColumns =  new Fl_Input(175, 176, 355, 24, "First Table Columns:");
    secondTable =  new Fl_Input(175, 116, 185, 24, "Second Table:");
    secondTableColumns =   new Fl_Input(175, 206, 355, 24, "Second Table Columns:");

    end();
    show();
}

SelectLeftJoin::SelectLeftJoin(): Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectLeftJoin);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    firstTable =new Fl_Input(175, 86, 185, 24, "First Table:");
    firstTableIDColumn=  new Fl_Input(175, 146, 185, 24, "First Table ID Column");
    firstTableColumns =  new Fl_Input(175, 176, 355, 24, "First Table Columns:");
    secondTable =  new Fl_Input(175, 116, 185, 24, "Second Table:");
    secondTableColumns =   new Fl_Input(175, 206, 355, 24, "Second Table Columns:");

    end();
    show();
}

SelectLimitWhereOrderBy::SelectLimitWhereOrderBy(): Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectWhereLimitOrderBy);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    executeButton->callback((Fl_Callback*)whenPushedSelectLimitWhereOrderByExecute);
    tableName =new Fl_Input(175, 86, 185, 24, "Tablename: ");
    columns=  new Fl_Input(175, 116, 185, 24, "Columns: ");
    limitNumber =  new Fl_Input(175, 146, 355, 24, "LimitNumber: ");
    conditionColumn =  new Fl_Input(175, 176, 185, 24, "ConditionColumn: ");
    conditionValue =   new Fl_Input(175, 206, 355, 24, "ConditionValue: ");
    toSortColumnName = new Fl_Input(175,236,185,24, "SortColumnName: ");
    end();
    show();
}

SelectUnion::SelectUnion(): Fl_Window(1280,400,620,310,"SQL-Interface"){ 
		
    color(FL_WHITE);
    begin();
   	sqlCommand = new Fl_Output(110, 40, 500, 30, "SQL-Command");
    backButton = new Fl_Button(0, 0, 95, 25, "Back");
    backButton->color((Fl_Color)31);
    backButton->callback((Fl_Callback*) whenPushedBackSelectUnion);

	executeButton = new Fl_Button(525, 0, 95, 25, "execute");
    executeButton->color((Fl_Color)31);
    executeButton->callback((Fl_Callback*)whenPushedSelectUnionExecute);

    tableName =new Fl_Input(175, 86, 185, 24, "Tablename(s): ");
    columns=  new Fl_Input(175, 116, 185, 24, "Column(s): ");
 	
    end();
    show();
}




OutputWindow::OutputWindow(): Fl_Window(1280,400,620,310,"SQL-Interface"){
	
	color(FL_WHITE);
    begin();

    tableOutput = new Fl_Output(0,0,620,310,"");


}







