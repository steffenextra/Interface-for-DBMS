#include <stdio.h>
#include "/usr/local/mysql/include/mysql.h"
#include <iostream>
#include <string>

using namespace std;

	void connection (){

		MYSQL *connection;
		MYSQL_RES *result;
		MYSQL_ROW row;

		char server [] = "localhost";
		char user [] = "root";
		char password [] = "root";
		char database [] = "mysql";
		char socket [] = "/Applications/MAMP/tmp/mysql/mysql.sock";
		string table = "testetet";
		connection = mysql_init(NULL);

  /* Connecting to the database with real_connect and send the query to the socket*/

		mysql_real_connect(connection, server, user, password, database, 8889, socket, 0);
		string SQLquery = "CREATE TABLE " + table + " (NR int)";
		mysql_query (connection, SQLquery.c_str());

/*		result = mysql_use_result(connection);  // save the result in MYSQL_RES and print it with MYSQL_ROW

		cout << "Tables in the mysql database:\n" << endl;

		while ((row = mysql_fetch_row(result)) != NULL)

		printf("%s \n", row[0]);
*/
		mysql_close(connection);

	}
