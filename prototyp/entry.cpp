#include "entry.hpp"

	/**

	@brief Erstellen eines Eintrags

	Die Methode "setEntry" sendet den Befehl einen neuen Eintrag in die dementsprechende Tabelle einzufügen.<br>

	SQL-Befehl: "INSERT INTO " + tableName + " (" + columnName + ") VALUES ("+ "'" + entry + "'" + ")" ;

	@param tablename = Name der Tabelle
	@param ColumnName = Name der Spalte
	@param entry = enhält den Eintrag, der hinzugefügt werden soll

	@return void

	@author Martin Meyer
	@author Steffen Extra

	*/

	void setEntry(std::string tableName, std::string columnName, std::string entry){

		std::string sqlCommand = "INSERT INTO " + tableName + " (" + columnName + ") VALUES ("+ "'" + entry + "'" + ")" ;
		check_error();
		connection_query(sqlCommand.c_str());

	}

	/**

	@brief Einträge modifizieren

	Die Methode "modifierEntry" senden dem Befehl einen bereits vorhandenen Eintrag einer Tabelle zu modifizieren.<br>

	SQL-Befehl: "UPDATE " + tableName + " SET " + columnName + " = " + "'" + newEntry + "'" + " WHERE " + columnName + "= " + "'" + oldEntry + "'";

	@param tablename = Name der Tabelle
	@param columnName = Name der Spalte in den der Eintrag getätigt werden soll 
	@param oldEntry =  Alter Eintrag
	@param newEntry = enthält den Eintrag, der den alten Eintrag ersetzen soll.

	@return void

	@author Martin Meyer
	@author Steffen Extra

	*/

	void modifierEntry(std::string tableName, std::string columnName, std::string oldEntry,std::string newEntry){

		std::string sqlCommand="UPDATE " + tableName + " SET " + columnName + " = " + "'" + newEntry + "'" + " WHERE " + columnName + "= " + "'" + oldEntry + "'";
		check_error();
		connection_query(sqlCommand.c_str());

	}

	/**

	@brief Beliebige Anzahl von Einträgen hinzufügen

	Die Methode "setAllEntry" senden dem Befehl eine komplette Zeile mit Einträgen einer Tabelle hinzuzufügen.<br>
	Um beliebig viele Einträge zu erstellen, muss der Anwender einen Vektoren anfertigen und diesen übergeben. <br>
	Der Vektor hat für den Insert die Form : jede gerade Index der Spaltennamen, Ungerade der Datensatz.<br>

	SQL-Befehl: "INSERT INTO " + tableName + "( " + columnName + " ) VALUES(" + insertData + ");";

	@param tableName = Name der Tabelle
	@param row = Enhält eine Liste, die eine Zeile repräsentieren soll, gefüllt mit Einträgen.

	@return void

	@author Martin Meyer
	@author Steffen Extra

	*/

	void setAllEntry(std::string tableName,std::vector<std::string> row){
		std::string columnName;
		std::string insertData;

		for(int i=0;i<row.size();i++){
			if(i%2==0){
				columnName=columnName + " " + row.at(i);
					if (i != row.size()-2){
						columnName+= ", ";
					}
			}
			else{
				insertData= insertData + " " + row.at(i);
				if (i != row.size()-1){
					insertData += ", ";
				}
			}
		}

		std::string sqlCommand = "INSERT INTO " + tableName + "( " + columnName + " ) VALUES(" + insertData + ");";
		check_error();
		connection_query(sqlCommand.c_str());

	}

	/**

	@brief Löschen von Einträgen

	Die Methode "deleteEntry" senden dem Befehl einen Eintrag einer Tabelle zu löschen.<br>

	SQL-Befehl: DELETE FROM " + tableName + " WHERE " + columnName + " = " + "'" + condition + "'";

	@param tableName = Name der Tabelle
	@param columnName = Enhält den Spaltennamen in der, der Eintrag gelöscht werden soll
	@paramentry = enhält den Eintrag, der gelöscht werden soll

	@return void

	@author Martin Meyer
	@author Steffen Extra

	*/

	void deleteEntry(std::string tableName, std::string columnName, std::string condition){

		std::string sqlCommand = "DELETE FROM " + tableName + " WHERE " + columnName + " = " + "'" + condition + "'";
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << "Dataset at Column "+  columnName + " with condition: " + condition + " successfully deleted" << std::endl;

	}

