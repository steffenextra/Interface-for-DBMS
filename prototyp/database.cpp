#include "database.hpp"


	void createDatabase (std::string databaseName){

		std::string sqlCommand = "CREATE DATABASE " + databaseName;
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << databaseName + " successfully deleted" << std::endl;;


	}

	void deleteDatabase(std::string databaseName){

		std::string sqlCommand = "DROP DATABASE " + databaseName;
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << databaseName + " successfully deleted" << std::endl;
	}

