#include <stdio.h>
#include <iostream>
#include <string>
#include "/usr/local/mysql/include/mysql.h"
//#include "/usr/include/mysql/mysql.h"
#include "connection.h"

using namespace std;


	void createDatabase (MYSQL *mysql, string databaseName){

		std::cout << mysql << std::endl;

		mysql = mysql_init(mysql);
		string sqlQuery = "CREATE DATABASE " + databaseName;
		std::cout << sqlQuery << std::endl;
		check_error();
		mysql_query (mysql, sqlQuery.c_str());
		

	}


