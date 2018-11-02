#include <stdio.h>
#include <string>
#include "/usr/local/mysql/include/mysql.h"
//#include "/usr/include/mysql/mysql.h"
#include "connection.hpp"
#include <iostream>


	void createTable (std::string tableName, std::string column_one){

		std::string sqlCommand = "CREATE TABLE " + tableName + " ( " + column_one +  " );";
		check_error();
		connection_query(sqlCommand.c_str());

	}

	void deleteTable (std::string tableName){

		std::string sqlCommand = "DROP TABLE " + tableName ;
		check_error();
		connection_query(sqlCommand.c_str());

	}

//	void insertTable(){}
