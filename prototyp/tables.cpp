#include "tables.hpp"


	/**

	@brief Erstellen einer Tabelle

        Die Methode dient zum erstellen einer Tabelle in einer vorgegebenen Datenbank. <br>
        Zu beachten ist hier, dass direkt bei der Übergabe von
        Parametern der Primärschlüssel, sowie der Sekundärschlüssel gesetzt werden kann. <br>


        @param primary_key = Lässt das automatische setzten des Primärschlüssels zu
        @param foreign_key =  Lässt das automatische setzen des Sekundärschlüssels zu
        @param tableName = Gibt den Namen der zu erstellenden Tabelle an
        @param columns = Der Programmierer kann über einen Vektor den Namen der Spalten sowie die Anzahl der Spalten bestimmen

	@return void 

	@author Steffen Extra
                */


	void createTable (bool primary_key, bool foreign_key, std::string tableName,std::vector<std::string> columns){



		std::string columnnamesAndDatatype;
		columnnamesAndDatatype=columns.at(0)+  " " + columns.at(1);

		if (primary_key == true){

			std::string sqlCommand = "CREATE TABLE " + tableName + " ( ID int NOT NULL  PRIMARY KEY AUTO_INCREMENT, " + columnnamesAndDatatype + " );";
			check_error();
			connection_query(sqlCommand.c_str());
		}
		else{
			std::string sqlCommand = "CREATE TABLE " + tableName + " ( " + columnnamesAndDatatype  + " );";
			check_error();
			connection_query(sqlCommand.c_str());
		}

		//insert the other Columns

		for(int i=2; i<columns.size()-1; i++){ //i=2 because the first column and datatype are already added

			if(i%2==0){
				setColumn(tableName,columns.at(i),columns.at(i+1));
			}
		}

		std::cout << tableName + " successfully created" << std::endl;

	}

	/**

	@brief Ausgabe der Tabelle

	Diese Methode dient zur Ausgabe des kompletten Tabelleninhalts innerhalb einer Datenbank.

	@param tableName = Übergibt den Namen der auszugebenden  Tabelle

	@return void

	@author Steffen Extra

	*/

	void showTable (std::string tableName){

		std::string sqlCommand ="SELECT * FROM " + tableName;
		check_error();
		connection_feedbackAll(sqlCommand.c_str());

	}

	/**

	@brief Änderung des Tabellennamens

	Sollte der Fall eintreten, dass Tabellennamen mit ihrem Inhalt nicht mehr übereinstimmen oder eine Umstrukturierung eintritt,
	kann über diese Methode der Tabellenname innerhalb einer Datenbank geändert werden.

	@param tableName = Angabe des zu ersetzenden Tabellennamens
	@param newTableName = Angabe des neuen Tabellennamens

	@return void 

	@author Steffen Extra 

	*/

	void renameTable(std::string tablename, std::string newTableName){
		std::string sqlCommand ="ALTER TABLE " + tablename + " RENAME TO " + newTableName+ ";" ;
		check_error();
		connection_query(sqlCommand.c_str());
	}

	/**

	@brief Löschen einer Tabelle 

	Durch das Übergeben des Tabellennamens wird die angegebene Tabelle mit dessen Inhalt gelöscht

	@param tableName = Name der Tabelle

	@return void 

	@author Steffen Extra

	*/

	void deleteTable (std::string tableName){

		std::string sqlCommand = "DROP TABLE " + tableName ;
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << tableName + " successfully deleted" << std::endl;

	}

     /**

        @brief Bearbeiten der Spalten in einer Tabelle

	Über diese Methoden können einzelne Spalten zu einer Tabelle hinzugefügt werden <br>
	Zu beachten ist, dass über diese Methode kein Schlüssel gesetzt werden kann <br>

        @param tableName = Name der Tabelle
	@param ColumnName = Name der Spalte die hinzugefügt werden soll
	@param datatype = Angabe des Datentyps bezogen auf die Spalte

        @return void 

        @author Steffen Extra

        */


	void setColumn(std::string tableName, std::string ColumnName, std::string datatype){

		std::string sqlCommand =" ALTER TABLE " + tableName + " ADD " + ColumnName +  " " + datatype;
		check_error();
		connection_query(sqlCommand.c_str());

	}

        /**

        @brief Setzen des Primärschlüssels

	Durch diese Methode kann nachträglich der Primärschlüssel zu einer Spalte hinzugefügt werden. <br>
	Zudem kann entschieden werden, ob die Spalte mit dem Primärschlüssel direkt die AUTO_INCREMENT-Funktion nutzen soll 
	oder über eigene Werte definiert wird.

        @param tableName = Name der Tabelle
	@param ColumnName = Name der Spalte
	@param datatype = Datentyp der Spalte
	@param autoinc = Boolean um zwischen AUTO_INCREMENT und eigener Wertzuweisung zu wechseln

        @return void

        @author Steffen Extra

        */

	void setColumnWithPrimary(std::string tableName, std::string ColumnName, std::string datatype, bool autoinc){

		if (autoinc == true){
			std::string sqlCommand =" ALTER TABLE " + tableName + " ADD " + ColumnName +  " " + datatype + " PRIMARY KEY AUTO_INCREMENT";
			check_error();
			connection_query(sqlCommand.c_str());

		}else{
			std::string sqlCommand =" ALTER TABLE " + tableName + " ADD " + ColumnName +  " " + datatype + " PRIMARY KEY";
                        check_error();
                        connection_query(sqlCommand.c_str());
		}

	}

        /**

        @brief Modifizieren des Spaltennamens

	Ersetzt den Spaltennamen sowie den Datentyp falls gewünscht <br>
	Soll der Datentyp nicht geändert werden, wird der Datentyp des Feldes nochmal angegeben.

        @param tableName = Name der Tabelle
	@param oldColumnName = Alter Name der Spalte
	@param newColumnName = Neuer Name der Spalte
	@param datatype = Datentyp der Spalte

        @return void 

        @author Steffen Extra

        */

	void modifierColumnName(std::string tableName, std::string oldColumnName, std::string newColumnName,std::string datatype){

		std::string sqlCommand= "ALTER TABLE " + tableName + " CHANGE " + oldColumnName + " " + newColumnName + " " + datatype;
		check_error();
		connection_query(sqlCommand.c_str());

	}



	void changeTheDatatype(std::string tableName, std::string columnName, std::string datatype){
		//has to be tested
		std::string sqlCommand="AlTER TABLE " + tableName + " MODIFY " + columnName + " " + datatype;
		check_error();
		connection_query(sqlCommand.c_str());

	}

	void getAllColumn(std::string tableName){

		std::string sqlCommand ="SHOW COLUMNS FROM " + tableName;
		check_error();
		connection_feedback(sqlCommand.c_str());

	}

	void countDatasets(std::string tableName){

		std::string sqlCommand = "SELECT COUNT (*) FROM " + tableName;
		check_error();
		connection_query(sqlCommand.c_str());

	}

	void showColumnTyp(std::string tableName,std::string datatype){

		std::string sqlCommand="SHOW COLUMNS FROM " + tableName + " WHERE TYPE LIKE '" + datatype + "%'";
		check_error();
		connection_feedbackAll(sqlCommand.c_str());

	}


	void deleteColumn(std::string tableName, std::string columnName){

		std::string sqlCommand= "ALTER TABLE " + tableName + " DROP " + columnName;
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << columnName + " successfully deleted" << std::endl;

	}


	void setSecondaryKey(std::string tableNameSecondary, std::string foreignKey, std::string tableNamePrimary, std::string primaryKey, std::string constraint){


		std::string sqlCommand ="ALTER TABLE " + tableNameSecondary + " ADD CONSTRAINT "+ constraint + " FOREIGN KEY (" + foreignKey + ") REFERENCES " + tableNamePrimary + " (" + primaryKey + ");";
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << "Secondary key set on " + foreignKey  + " with the PrimaryKey " + primaryKey + " on Table: " + tableNamePrimary  << std::endl;

        }

	void deleteConstraint(std::string tableName, std::string constraint){

                std::string sqlCommand = "ALTER TABLE " + tableName + " DROP INDEX " + constraint;
                check_error();
                connection_query(sqlCommand.c_str());

        }


	void deleteSecondaryKey(std::string tableName, std::string constraint){
		std::string sqlCommand = "ALTER TABLE " + tableName + " DROP FOREIGN KEY " + constraint + "; ";
		check_error();
		connection_query (sqlCommand.c_str());
		deleteConstraint(tableName, constraint);
		std::cout << "deleted the foreign key on the Field " + constraint << std::endl;

	}

	void setPrimaryKey(std::string tableName, std::string primaryKey){

		std::string sqlCommand = "ALTER TABLE " + tableName + " ADD PRIMARY KEY (" + primaryKey + ");"; 
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << "Primary key set on: " + primaryKey << std::endl;
	}


	void deletePrimaryKey (std::string tableName){

		std::string sqlCommand = "ALTER TABLE " + tableName + " DROP PRIMARY KEY";
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << "Primary key successfully deleted" << std::endl;

	}


