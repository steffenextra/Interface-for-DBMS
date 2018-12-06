#include "database.hpp"

	/**

	@brief Erstellen einer Datenbank

	Die Methode "createDatabase" sendet einen Befehl um eine Datenbank zu erstellen an den SQL Server

	SQL-Befehl: "CREATE DATABASE " + databaseName;

	@param databaseName = enthält den Namen für die zu erstellende Datenbank

	@return void

	@author Martin Meyer
	@author Steffen Extra

	*/

	void createDatabase (std::string databaseName){

		std::string sqlCommand = "CREATE DATABASE " + databaseName;
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << databaseName + " successfully deleted" << std::endl;;

	}

	/**

	@brief Anzeigen der Datenbanken

	Die Methode "showDatabase" senden dem Befehl alle Datenbanken anzuzeigen an den SQL Server. <br>

	SQL-Befehl: SHOW DATABASES;

	@param -

	@return void

	@author Martin Meyer
	@author Steffen Extra

	*/

	void showDatabases(){

		std::string sqlCommand = "SHOW DATABASES;" ;
		check_error();
		connection_feedback(sqlCommand.c_str());

	}

	/**

	@brief Datenbanknamen ändern

	Die Methode "renameDatabase" senden dem Befehl eine Datenbank umzubennen an den SQL Server.<br>
	Bis auf die gewählte Datenbank für die connectionless() Methode können alle Datenbanken umbenannt werden.<br>

	SQL-Befehl: "ALTER DATABASE " + databaseName + " MODIFY NAME = " + newDatabaseName + ";"

	@param databaseName = enhält den Namen für die zu unbennene Datenbank
	@param newDatabaseName = enhält den neunen Namen für die Datenbank

	@return void

	@author Martin Meyer
	@author Steffen Extra

	*/

	void renameDatabase(std::string databaseName, std::string newDatabaseName){
		//need to fix
		std::string sqlCommand ="ALTER DATABASE " + databaseName + " MODIFY NAME = " + newDatabaseName + ";";
		check_error();
		connection_query(sqlCommand.c_str());
	}

	/**

	@brief Löschen einer Datenbank

	Die Methode "deleteDatabase" senden dem Befehl eine Datenbank zu löschen.<br>
	Bis auf die gewählte Datenbank für die Connetionless Methode können alle Datenbanken ugelöscht werden.<br>

	SQL-Befehl: "DROP DATABASE " + databaseName;

	@param databaseName = enthält den Namen für die zu löschende Datenbank

	@return void

	@author Martin Meyer
	@author Steffen Extra

	*/

	void deleteDatabase(std::string databaseName){

		std::string sqlCommand = "DROP DATABASE " + databaseName;
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << databaseName + " successfully deleted" << std::endl;

	}

