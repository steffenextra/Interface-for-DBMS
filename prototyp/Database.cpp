#include "Database.hpp"


	void createDatabase (std::string databaseName){

		std::string sqlCommand = "CREATE DATABASE " + databaseName;
		check_error();
		connection_query(sqlCommand.c_str());

	}

	void deleteDatabase(std::string databaseName){

		std::string sqlCommand = "DROP DATABASE " + databaseName;
		check_error();
		connection_query(sqlCommand.c_str());

	}

