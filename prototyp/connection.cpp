#include "connection.hpp"

MYSQL *mysql;
MYSQL_ROW row;
MYSQL_RES *result;
MYSQL_FIELD *field;

/*
* Die Methode "check_error" ist verantwortlich für die Ausnahme, die ausgelöst wird, wenn MySQL einen Fehler zurückgibt.
*	
*@param 
*	-
*	
*@return 
*	-
*
* @author Martin Meyer
*
* @version 1.0
*/

	void check_error(void){

		if (mysql_errno(mysql) != 0) {
			fprintf(stderr, "Fehler: %s\n", mysql_error(mysql));
			exit(EXIT_FAILURE);
		}

	}
	/*
* Die Methode "connection_feedback" liefert eine Spalte des aktuellen Datensatzes.
*	
*@param 
*	-sqlCommand-> enhält den auszuführenden SQL-Befehl
*
*	
*@return 
*	-
*
* @author Martin Meyer
*
* @version 1.0
*/

		void connection_feedback(std::string sqlCommand){

                std::cout << std::endl;
                std::cout <<"\033[1;31m DEBUG : INPUT FOR THE MYSQL_QUERY\033[0m" << std::endl;
                std::cout << sqlCommand << std::endl;
                std::cout << std::endl;
                mysql_query(mysql, sqlCommand.c_str());
                check_error();
                result=mysql_use_result(mysql);

			while((row=mysql_fetch_row(result))!=NULL){
				std::cout<< *row << std::endl;
			}
				std::cout << std::endl;
		}


/*
* Die Methode "connection_feedbackAll" liefert den kompletten aktuellen Datensatz.
*	
*@param 
*	-sqlCommand-> enhält den auszuführenden SQL-Befehl
*
*	
*@return 
*	-
*
* @author Martin Meyer
*
* @version 1.0
*/


	void connection_feedbackAll(std::string sqlCommand){
		//printf  substitute -> cout
		std::cout << std::endl;
                std::cout <<"\033[1;31m DEBUG : INPUT FOR THE MYSQL_QUERY\033[0m" << std::endl;
                std::cout << sqlCommand << std::endl;
                std::cout << std::endl;
		mysql_query(mysql,sqlCommand.c_str());
		MYSQL_RES *result = mysql_store_result(mysql);
		int num_fields = mysql_num_fields(result);

		if (result == NULL){
		check_error();
		}

		while ((row = mysql_fetch_row(result))!=NULL)
		{
			for(int i = 0; i < num_fields; i++)
			{
				if (i == 0)
				{
					while(field = mysql_fetch_field(result))
					{
						printf("%s ", field->name);
					}

					printf("\n");
				}

				printf("%s  ", row[i] ? row[i] : "NULL");
			}
		}

		printf("\n");

		mysql_free_result(result);
	}
/*
* Die Methode "connection_query" sendet eine eindeutige Abfrage (mehrere Abfragen werden nicht unterstützt) 
* an die derzeit aktive Datenbank auf dem Server, der dem angegebenen Server zugeordnet ist
*	
*@param 
*	-sqlCommand-> enhält den auszuführenden SQL-Befehl
*
*	
*@return 
*	-
*
* @author Martin Meyer
*
* @version 1.0
*/

	void connection_query(std::string sqlCommand){

		std::cout << std::endl;
		std::cout <<"\033[1;31m DEBUG : INPUT FOR THE MYSQL_QUERY\033[0m" << std::endl;
		std::cout << sqlCommand << std::endl;
		std::cout << std::endl;
		mysql_query (mysql, sqlCommand.c_str());
		check_error();

	}
	/*
* Die Methode "connectionless" wird verwendet, um eine Verbindung zu einer Datenbank mit all ihren nötigen Parametern(z.B User,Pw usw.) herzustellen.
* Um eine Verbindung zu einem lokalen Computer herzustellen, geben Sie "localhost" für den Server an. 
* Wenn Sie keinen Server angeben, wird localhost angenommen.
*	
*@param 
*	-host-> Name des Hosts
*	-user-> Name des Users
*	-passwort-> benötigtes Password für den Verbindungsaufbau zum SQL-Server
*	-db-> Name der Datenbank auf die zugegriffen werden soll
*	-port-> verwendeter Port
*	-socket-> verwendeter Socket
*	-flag->
*	
*@return 
*	-
*
* @author Martin Meyer
*
* @version 1.0
*/

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

/*
* Die Methode "disconnect" setzt alle ausstehenden Transaktionen zurück. 
* Anschließend wird die Verbindung zum Verbindungspool freigegeben oder die Verbindung wird geschlossen, 
* wenn das Verbindungspooling deaktiviert ist.
*	
*@param 
*	-
*	
*@return 
*	-
*
* @author Martin Meyer
*
* @version 1.0
*/
	void disconnect(){

		mysql_close(mysql);

	}



