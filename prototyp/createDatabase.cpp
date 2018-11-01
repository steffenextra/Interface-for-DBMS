#include <stdio.h>
#include <string.h>
#include "/usr/local/mysql/include/mysql.h"
//#include "/usr/include/mysql/mysql.h"
#include "connection.hpp"
#include <string>
#include <iostream>

	void createDatabase (std::string databaseName){

		std::string sqlCommand = "CREATE DATABASE " + databaseName;

		check_error();

		connection_query(sqlCommand.c_str());

	}

	void deleteDatabase(std::string databaseName){

		std::string sqlCommand = "DROP DATABASE " + databaseName;

		check_error();

		connection_query(sqlCommand.c_str());

		std::cout << "Datenbank " << databaseName << " erfolgreich gelöscht" << std::endl;

	}

