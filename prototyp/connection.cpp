#include "connection.hpp"

MYSQL *mysql;
MYSQL_ROW row;
MYSQL_RES *result;

	void check_error(void){

		if (mysql_errno(mysql) != 0) {
			fprintf(stderr, "Fehler: %s\n", mysql_error(mysql));
			exit(EXIT_FAILURE);
		}

	}

	void connection_feedback(std::string sqlCommand)
	{
		mysql_query(mysql, sqlCommand.c_str());
		check_error();
		result=mysql_use_result(mysql);
		
		while((row=mysql_fetch_row(result))!=NULL)
		{
			std::cout<< *row << std::endl;
		}
	}

	void connection_query(std::string sqlCommand){

		mysql_query (mysql, sqlCommand.c_str());
		check_error();
	}

	void connectionless(const char host [], const char user [], const char passwort [],const char db [], unsigned int port,const char *macOS_socket, unsigned int client_flag){

		mysql=mysql_init(mysql);
		check_error();
							/* mit dem Server verbinden */
		if( mysql_real_connect (
			mysql,					/* Zeiger auf MYSQL-Handler */
			host,					/* Host-Name */
			user,					/* User-Name */
			passwort,				/* Passwort für user_name */
			db,					/* Name der Datenbank */
			port,					/* Port (default=0) */
			macOS_socket,				/* Angesprochener Socket (je nach Betriebssystem) */
			0               )  == NULL) {		/* keine Flags */
		fprintf(stderr, "Fehler mysql_real_connect():" "%u (%s)\n", mysql_errno (mysql), mysql_error (mysql));
		}
		else{
			printf("Erfolgreich mit dem MySQL-Server auf %s%s",  host, " verbunden\n");
		}

	}

	void disconnect(){

		mysql_close(mysql);

	}



