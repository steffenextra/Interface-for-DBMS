
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
//#include "my_global.h"
//#include "/usr/include/mysql/mysql.h"
#include "/usr/local/mysql/include/mysql.h"


MYSQL *mysql;

	void check_error(void){

		if (mysql_errno(mysql) != 0) {

			fprintf(stderr, "Fehler: %s\n", mysql_error(mysql));

			exit(EXIT_FAILURE);

		}

	}

	void connection_query(char* sqlcommand){

		mysql_query (mysql, sqlcommand);

	}

	void connectionless(const char host [], const char user [], const char passwort [], unsigned int port,const char *macOS_socket, unsigned int client_flag){

		mysql=mysql_init(mysql);

		check_error();
							/* mit dem Server verbinden */
		if( mysql_real_connect (
			mysql,					/* Zeiger auf MYSQL-Handler */
			host,					/* Host-Name */
			user,					/* User-Name */
			passwort,				/* Passwort für user_name */
			NULL,					/* Name der Datenbank */
			port,					/* Port (default=0) */
			macOS_socket,				/* Angesprochener Socket (je nach Betriebssystem) */
			0               )  == NULL) {		/* keine Flags */

			fprintf(stderr, "Fehler mysql_real_connect():" "%u (%s)\n", mysql_errno (mysql), mysql_error (mysql));

		}

		else{

			printf("Erfolgreich mit dem MySQL-Server verbunden\n");

		}

	}

	void disconnect(){

		mysql_close(mysql);

}

