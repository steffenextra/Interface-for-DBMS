#include "database.hpp"

/*
* Die Methode "createDatabase" senden dem Befehl eine Datenbank zu erstellen an den SQL Server
*
* Die Struktur des SQL Befehl:	
* CREATE DATABASE datenbanknamen;
*	
*@param 
*	-databaseName-> enhält den Namen für die zu erstellende Datenbank
*
*	
*@return 
*	-
*
* @author Martin Meyer
*
* @version 1.0
*/

	void createDatabase (std::string databaseName){

		std::string sqlCommand = "CREATE DATABASE " + databaseName;
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << databaseName + " successfully deleted" << std::endl;;

	}
/*
* Die Methode "showDatabase" senden dem Befehl alle Datenbanken anzuzeigen an den SQL Server
*
 *Die Struktur des SQL Befehl:	
* SHOW DATABASES;
*	
*@param 
*
*	
*@return 
*	-
*
* @author Martin Meyer
*
* @version 1.0
*/

	void showDatabases(){

		std::string sqlCommand = "SHOW DATABASES;" ;
		check_error();
		connection_feedback(sqlCommand.c_str());

	}
/*
* Die Methode "renameDatabase" senden dem Befehl eine Datenbank umzubennen an den SQL Server.
* Bis auf die gewählte Datenbank für die Connetionless Methode können alle Datenbanken unbenannt werden.
*
* Die Struktur des SQL Befehl:	
* ALTER DATABASE datenbanknamen MODIFY NAME = neuerDatenbanknamen
*	
*@param 
*	-databaseName-> enhält den Namen für die zu unbennene Datenbank
*	-newDatabaseName-> enhält den neunen Namen für die Datenbank
*
*	
*@return 
*	-
*
* @author Martin Meyer
*
* @version 1.0
*/

	void renameDatabase(std::string databaseName, std::string newDatabaseName){
		//need to fix
		std::string sqlCommand ="ALTER DATABASE " + databaseName + " MODIFY NAME = " + newDatabaseName + ";";
		check_error();
		connection_query(sqlCommand.c_str());
	}

/*
* Die Methode "deleteDatabase" senden dem Befehl eine Datenbank zu löschen.
* Bis auf die gewählte Datenbank für die Connetionless Methode können alle Datenbanken ugelöscht werden.
*
* Die Struktur des SQL Befehl:	
* DROP DATABASE datenbanknamen;
*	
*@param 
*	-databaseName-> enhält den Namen für die zu löschende Datenbank
*
*	
*@return 
*	-
*
* @author Martin Meyer
*
* @version 1.0
*/

	void deleteDatabase(std::string databaseName){

		std::string sqlCommand = "DROP DATABASE " + databaseName;
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << databaseName + " successfully deleted" << std::endl;

	}

