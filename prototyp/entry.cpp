#include "entry.hpp"

/*
* Die Methode "setEntry" senden dem Befehl einen neuen Eintrag in einer Tabelle einzufügen.
*
* Die Struktur des SQL Befehl:	
* INSERT INTO tabellennamen (spaltennamen) VALUES('Eintrag');
*	
*@param 
*	-tablename->Enhält den Tabellennamen in der, der Eintrag hinzugefügt werden soll
*	-columnName->Enhält den Spaltennamen in der, der Eintrag hinzugefügt werden soll
*	-entry-> enhält den Eintrag, der hinzugefügt werden soll
*
*	
*@return 
*	-
*
* @author Martin Meyer
*
* @version 1.0
*/
	void setEntry(std::string tableName, std::string columnName, std::string entry){

		std::string sqlCommand = "INSERT INTO " + tableName + " (" + columnName + ") VALUES ("+ "'" + entry + "'" + ")" ;
		check_error();
		connection_query(sqlCommand.c_str());

	}
/*
* Die Methode "modifierEntry" senden dem Befehl einen bereits vorhandenen Eintrag einer Tabelle zu modifizieren.
*
* Die Struktur des SQL Befehl:	
* "UPDATE Tabellennamen SET Spaltennamen = 'neuerEintrag' Bedingung Spaltennamen = 'alterEintrag';
*	
*@param 
*	-tablename->Enhält den Tabellennamen in der, der Eintrag hinzugefügt werden soll
*	-columnName->Enhält den Spaltennamen in der, der Eintrag hinzugefügt werden soll
*	-oldEntry-> enhält den Eintrag, der in der Spalte modifiziert werden soll
*	-newEntry-> enhält den Eintrag, der den alten Eintrag ersetzen soll.
*	
*@return 
*	-
*
* @author Martin Meyer
*
* @version 1.0
*/

	void modifierEntry(std::string tableName, std::string columnName, std::string oldEntry,std::string newEntry){

		std::string sqlCommand="UPDATE " + tableName + " SET " + columnName + " = " + "'" + newEntry + "'" + " WHERE " + columnName + "= " + "'" + oldEntry + "'";
		check_error();
		connection_query(sqlCommand.c_str());

	}
/*
* Die Methode "setAllEntry" senden dem Befehl eine komplette Zeile mit Einträgen einer Tabelle hinzuzufügen.
*
* Die Struktur des SQL Befehl:	
* 	//INSERT INTO <Tabellenname>(<Spaltenname> [, weitere Spaltennamen])
*	
*@param 
*	-tablename->Enhält den Tabellennamen in der, der Eintrag hinzugefügt werden soll.
*	-row-> Enhält eine Liste, die eine Zeile repräsentieren soll, gefüllt mit Einträgen.
*	
*@return 
*	-
*
* @author Martin Meyer
*
* @version 1.0
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
/*
* Die Methode "deleteEntry" senden dem Befehl einen Eintrag einer Tabelle zu löschen.
*
* Die Struktur des SQL Befehl:	
* DELETE FROM Tabellennamen Bedingung Spaltennamen  = 'zulöschenderEintrag';
*	
*@param 
*	-tablename->Enhält den Tabellennamen in der, der Eintrag hinzugefügt werden soll
*	-columnName->Enhält den Spaltennamen in der, der Eintrag hinzugefügt werden soll
*	-entry-> enhält den Eintrag, der gelöscht werden soll
*	
*@return 
*	-
*
* @author Martin Meyer
*
* @version 1.0
*/

	void deleteEntry(std::string tableName, std::string columnName, std::string condition){

		std::string sqlCommand = "DELETE FROM " + tableName + " WHERE " + columnName + " = " + "'" + condition + "'";
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << "Dataset at Column "+  columnName + " with condition: " + condition + " successfully deleted" << std::endl;

	}

