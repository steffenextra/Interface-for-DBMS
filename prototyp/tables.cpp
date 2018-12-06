#include "tables.hpp"




	/**

	@brief Erstellen einer Tabelle

        Die Methode dient zum erstellen einer Tabelle in einer vorgegebenen Datenbank. <br>
        Zu beachten ist hier, dass direkt bei der Übergabe von
        Parametern der Primärschlüssel, sowie der Sekundärschlüssel gesetzt werden kann. <br>

	SQL-Befehl für den Primärschlüssel: "CREATE TABLE " + tableName + " ( ID int NOT NULL  PRIMARY KEY AUTO_INCREMENT, " + columnnamesAndDatatype + " );";<br>
	SQL-Befehl ohne Primärschlüssel:  "CREATE TABLE " + tableName + " ( " + columnnamesAndDatatype  + " );";<br>

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

	Diese Methode dient zur Ausgabe des kompletten Tabelleninhalts innerhalb einer Datenbank.<br>

	SQL-Befehl: "SELECT * FROM " + tableName;

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
	kann über diese Methode der Tabellenname innerhalb einer Datenbank geändert werden.<br>

	SQL-Befehl: ALTER TABLE " + tablename + " RENAME TO " + newTableName+ ";" ;

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

	Durch das Übergeben des Tabellennamens wird die angegebene Tabelle mit dessen Inhalt gelöscht.<br>

	SQL-Befehl: "DROP TABLE " + tableName;

	@param tableName = Name der Tabelle

	@return void

	@author Steffen Extra

	*/

	void deleteTable (std::string tableName){

		std::string sqlCommand = "DROP TABLE " + tableName;
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << tableName + " successfully deleted" << std::endl;

	}

	/**

	@brief Bearbeiten der Spalte in einer Tabelle

        Über diese Methoden kann man einzelne Spalten zu einer Tabelle hinzufügen.  <br>
        Zu beachten ist, dass über diese Methode kein Schlüssel gesetzt werden kann.<br>

        SQL-Befehl: "ALTER TABLE " + tableName + " ADD " + ColumnName +  " " + datatype;

        @param tableName = Name der Tabelle
        @param ColumnName = Name der Spalte die hinzugefügt werden soll
        @param datatype = Angabe des Datentyps bezogen auf die Spalte

	@return void 

	@author Steffen Extra

	*/

	void setColumn(std::string tableName, std::string ColumnName, std::string datatype){

		std::string sqlCommand ="ALTER TABLE " + tableName + " ADD " + ColumnName +  " " + datatype;
		check_error();
		connection_query(sqlCommand.c_str());

	}

        /**

        @brief Setzen des Primärschlüssels

	Durch diese Methode kann nachträglich der Primärschlüssel zu einer Spalte hinzugefügt werden. <br>
	Zudem kann entschieden werden, ob die Spalte mit dem Primärschlüssel direkt die AUTO_INCREMENT-Funktion nutzen soll 
	oder über eigene Werte definiert wird.<br>

	SQL-Befehl für AUTO_INCREMENT: " ALTER TABLE " + tableName + " ADD " + ColumnName +  " " + datatype + " PRIMARY KEY AUTO_INCREMENT";<br>
	SQL-Befehl ohne AUTO_INCREMENT: " ALTER TABLE " + tableName + " ADD " + ColumnName +  " " + datatype + " PRIMARY KEY";

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

	Ersetzt den Spaltennamen sowie den Datentyp falls gewünscht. <br>
	Soll der Datentyp nicht geändert werden, wird der Datentyp des Feldes nochmal angegeben.<br>

	SQL-Befehl: "ALTER TABLE " + tableName + " CHANGE " + oldColumnName + " " + newColumnName + " " + datatype; <br>

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

	/**

        @brief Ändern des Datentyps

	Ändern des Datentyps einer Spalte ohne den Namen der Spalte zu ändern. <br>
	Wenn der Datentyp der Spalte geändert wird, muss darauf geachtet werden, dass
	die Objekte in der Spalte dem Datentyp entsprechen. <br>

	SQL-Befehl: "AlTER TABLE " + tableName + " MODIFY " + columnName + " " + datatype;

        @param tableName = Name der Tabelle
	@param columnName = Name der Spalte
	@param datatype = Neuer Datentyp 

	@return void 

	@author Steffen Extra

        */


	void changeTheDatatype(std::string tableName, std::string columnName, std::string datatype){
		//has to be tested
		std::string sqlCommand="AlTER TABLE " + tableName + " MODIFY " + columnName + " " + datatype;
		check_error();
		connection_query(sqlCommand.c_str());

	}

	/**

	@brief Anzeigen von Spalten

	Es werden alle Spalten der Tabelle angezeigt. <br>

	SQL-Befehl: "SHOW COLUMNS FROM " + tableName;

	@param tableName = Name der Tabelle

	@return void 

	@author Steffen Extra

	*/

	void getAllColumn(std::string tableName){

		std::string sqlCommand ="SHOW COLUMNS FROM " + tableName;
		check_error();
		connection_feedback(sqlCommand.c_str());

	}

	/**

	@brief Zählen der Datensätze

	Alle Datensätze werden gezählt und ausgegeben.<br>

	SQL-Befehl: "SELECT COUNT (*) FROM " + tableName;

	@param tableName = Name der Tabelle;

	@return void

	@author Steffen Extra

	*/

	void countDatasets(std::string tableName){

		std::string sqlCommand = "SELECT COUNT (*) FROM " + tableName;
		check_error();
		connection_feedback(sqlCommand.c_str());

	}

	/**

	@brief Datentyp der Spalte anzeigen lassen

	Durch die Methode werden alle Spaltennamen gelistet, welche der Bedingung des Datentyps entsprechen.<br>

	SQL-Befehl: "SHOW COLUMNS FROM " + tableName + " WHERE TYPE LIKE '" + datatype + "%'";

	@param tableName = Name der Tabelle; 
	@param datatype = Datentyp

	@return void 

	@author Steffen Extra

	*/

	void showColumnTyp(std::string tableName,std::string datatype){

		std::string sqlCommand="SHOW COLUMNS FROM " + tableName + " WHERE TYPE LIKE '" + datatype + "%'";
		check_error();
		connection_feedbackAll(sqlCommand.c_str());

	}

	/**

	@brief Löschen von Spalten

	Durch die Angabe des Tabellen/- und Spaltennamens werden einzelne Spalten gelöscht.

	SQL-Befehl: "ALTER TABLE " + tableName + " DROP " + columnName;

	@param tableName = Name der Tabelle 
	@param columnName = Name der Spalte

	@return void 

	@author Steffen Extra

	*/

	void deleteColumn(std::string tableName, std::string columnName){

		std::string sqlCommand= "ALTER TABLE " + tableName + " DROP " + columnName;
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << columnName + " successfully deleted" << std::endl;

	}

	/**

	@brief Setzen des Sekundärschlüssels (Foreign Key)

	tableNamePrimary  und primaryKey  verbinden den Primärschlüssel aus einer Tabelle mit einer vom Programmierer gewünschten Spalte und setzt den ForeignKey auf diese.<br>
	So können die Abhängigkeiten vom Primärschlüssel im Bezug auf einer anderen Tabelle gelöst werden. <br>
	Zusätzlich kann durch die Angabe des Übergabeparameters constraint eine Schlüsselgruppe  definier werden.<br>

	SQL-Befehl  "ALTER TABLE " + tableNameSecondary + " ADD CONSTRAINT "+ constraint + " FOREIGN KEY (" + foreignKey + ") REFERENCES " + tableNamePrimary + " (" + primaryKey + ");";

	@param tableNameSecondary = Name der Tabelle für den Sekundärschlüssel
	@param foreignKey = Spaltenname für den Sekundärschlüssel
	@param tableNamePrimary = Name der Tabelle, welche den Primärschlüssel besitzt
	@param primaryKey = Spalte des Primärschlüssels
	@param constraint = Name der Schlüsselgruppe

	@return void 

	@author Steffen Extra 
	*/

	void setSecondaryKey(std::string tableNameSecondary, std::string foreignKey, std::string tableNamePrimary, std::string primaryKey, std::string constraint){
		std::string sqlCommand ="ALTER TABLE " + tableNameSecondary + " ADD CONSTRAINT "+ constraint + " FOREIGN KEY (" + foreignKey + ") REFERENCES " + tableNamePrimary + " (" + primaryKey + ");";
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << "Secondary key set on " + foreignKey  + " with the PrimaryKey " + primaryKey + " on Table: " + tableNamePrimary  << std::endl;

        }

	/**

	@brief Löschen der Schlüsselgruppe

	Diese Methode löscht die Schlüsselgruppe. <br>
	Konkreter Aufruf dieser Methode wird vermieden. <br>
	Aufruf dieser Methode in der deleteSecondaryKey() Methode. <br>

	SQL-Befehl: "ALTER TABLE " + tableName + " DROP INDEX " + constraint;

	@param tableName = Name der Tabelle
	@param constraint = Name der Schlüsselgruppe

	@return void 

	@author Steffen Extra

	*/

	void deleteConstraint(std::string tableName, std::string constraint){

                std::string sqlCommand = "ALTER TABLE " + tableName + " DROP INDEX " + constraint;
                check_error();
                connection_query(sqlCommand.c_str());

        }

	/**

	@brief Löschen des Sekundärschlüssels

	Der gesetzte Sekundärschlüssel im Bezug auf den gesetzten Primärschlüssel und die Schlüsselgruppe kann mit dieser Methode gelöscht werden.<br>

	SQL-Befehl: "ALTER TABLE " + tableName + " DROP FOREIGN KEY " + constraint + "; ";

	@param tableName = Name der Tabelle
	@param constraint = Name der Schlüsselgruppe

	@return void 

	@author Steffen Extra

	*/

	void deleteSecondaryKey(std::string tableName, std::string constraint){
		std::string sqlCommand = "ALTER TABLE " + tableName + " DROP FOREIGN KEY " + constraint + "; ";
		check_error();
		connection_query (sqlCommand.c_str());
		deleteConstraint(tableName, constraint);
		std::cout << "deleted the foreign key on the Field " + constraint << std::endl;

	}

	/**

	@brief Nachträgliches setzen eines Primärschlüssels

	Durch die Angabe der Spalte für den Primärschlüssels kann dieser gesetzt werden. <br>
	Sollte bereits ein Primärschlüssel in dieser Tabelle vorhanden sein, wird der Fehler abgefangen.<br>

	SQL-Befehl: "ALTER TABLE " + tableName + " ADD PRIMARY KEY (" + primaryKey + ");"; 

	@param tableName = Name der Tabelle
	@param primaryKey = Name der Spalte für das Setzen des Primärschlüssel 

	@return void 

	@author Steffen Extra

	*/

	void setPrimaryKey(std::string tableName, std::string primaryKey){

		std::string sqlCommand = "ALTER TABLE " + tableName + " ADD PRIMARY KEY (" + primaryKey + ");"; 
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << "Primary key set on: " + primaryKey << std::endl;
	}

	/** 

	@brief Löschen des Primärschlüssels

	Solange keine Verbindungen zu anderen Tabellen über den Primärschlüssel laufen, kann dieser ohne Probleme gelöscht werden. <br>
	In dieser Methode reicht die Übergabe des Tabellennamens, da der Primärschlüssel nicht mehr als einmal auftauchen kann. <br>

	SQL-Befehl: "ALTER TABLE " + tableName + " DROP PRIMARY KEY";

	@param tableName = Name der Tabelle

	@return void 

	@author Steffen Extra

	*/

	void deletePrimaryKey (std::string tableName){

		std::string sqlCommand = "ALTER TABLE " + tableName + " DROP PRIMARY KEY";
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << "Primary key successfully deleted" << std::endl;

	}


