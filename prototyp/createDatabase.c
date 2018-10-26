#include <stdio.h>
#include <iostream>
#include <string>
#include "/usr/local/mysql/include/mysql.h"
//#include "/usr/include/mysql/mysql.h"
#include "connection.h"

using namespace std;


	void createDatabase (MYSQL *mysql, char *databaseName){


		mysql = mysql_init(mysql);
		check_error();

		string sqlQuery =  "CREATE DATABASE" + (string) databaseName;
		mysql_query (mysql, sqlQuery.c_str());

	}


