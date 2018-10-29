#include <stdio.h>
#include <string.h>
#include "/usr/local/mysql/include/mysql.h"
//#include "/usr/include/mysql/mysql.h"
#include "connection.h"


	void createDatabase (char* databaseName){
		char sqlcommand[30]= "CREATE DATABASE ";
		strcat(sqlcommand,databaseName);
		check_error();
		connection_query(sqlcommand);

	}


