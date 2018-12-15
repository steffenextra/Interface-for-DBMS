#include "sqllib.hpp"

/** @brief Variable für die Schnittstelle zum SQL-Server*/
MYSQL *mysql;
/** @brief Erhält als Ergebnis einer Reihe von einem Result-Set*/
MYSQL_ROW row;
/** @brief Enthält das Ergebnis einer Abfrage vom SQL-Server*/
MYSQL_RES *result;
/** @brief Variable für das Aufrufen der Methode mysql_fetch_field() um Datenbankinformationen ausgeben zu lassen */
MYSQL_FIELD *field;

	/**

	@brief Fehlermethode

	Die Methode "check_error" ist verantwortlich für die Ausnahme, die ausgelöst wird, wenn MySQL einen Fehler zurückgibt.<br>

	@param -

	@return void

	@author Martin Meyer
	@author Steffen Extra

	*/

	std::string check_error(void){

		if (mysql_errno(mysql) != 0) {
			fprintf(stderr, "Fehler: %s\n", mysql_error(mysql));
			//exit(EXIT_FAILURE); 
		}
		std::string message = mysql_error(mysql);
		return message.c_str();

	}
	/**

	@brief Rückgabe einzelner Ergebnisse

	Die Methode "connection_feedback" liefert eine Spalte des aktuellen Datensatzes.<br>
	Diese wird benutzt um einzelne Ergebnis zurückzugeben. (Bspw. selectCount() )

	@param sqlCommand = enthält den auszuführenden SQL-Befehl

	@return void

	@author Martin Meyer
	@author Steffen Extra

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


	/**

	@brief Rückgabe aller Datensätze

	Die Methode "connection_feedbackAll" liefert den kompletten Datensatz zurück der Abfrage zurück.

	@param sqlCommand = enhält den auszuführenden SQL-Befehl

	@return void

	@author Martin Meyer
	@author Steffen Extra

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

		while ((row = mysql_fetch_row(result))!=NULL){

			for(int i = 0; i < num_fields; i++){

				if (i == 0){

					while(field = mysql_fetch_field(result)){
					
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

	/**

	@brief Sendet eine Abfrage zum SQL-Server

	Die Methode "connection_query" sendet eine eindeutige Abfrage (mehrere Abfragen werden nicht unterstützt) 
	an die derzeit aktive Datenbank auf dem Server, der dem angegebenen Server zugeordnet ist. <br>

	@param sqlCommand = enhält den auszuführenden SQL-Befehl

	@return void

	@author Martin Meyer
	@author Steffen Extra

	*/

	void connection_query(std::string sqlCommand){

		std::cout << std::endl;
		std::cout <<"\033[1;31m DEBUG : INPUT FOR THE MYSQL_QUERY\033[0m" << std::endl;
		std::cout << sqlCommand << std::endl;
		std::cout << std::endl;
		mysql_query (mysql, sqlCommand.c_str());
		check_error();
	}
	/**

	@brief Verbindung zur Datenbank auf einem Server

	Die Methode "connectionless" wird verwendet, um eine Verbindung zu einer Datenbank mit all ihren nötigen Parametern(z.B User,Pw usw.) herzustellen.<br>
	Um eine Verbindung zu einem lokalen Computer herzustellen, geben Sie "localhost" oder die lokale IP-Adresse für den Server an. <br>
	

	@param host = Name des Hosts
	@param user = Name des Users
	@param passwort = benötigtes Passwort für den Verbindungsaufbau zum SQL-Server
	@param db = Name der Datenbank auf die zugegriffen werden soll
	@param port = Der zu verwendende Port
	@param socket = Der zu verwendende Socket
	@param flag = Optional (NULL)

	@return void

	@author Martin Meyer
	@author Steffen Extra

	*/

	bool connectionless(const char host [], const char user [], const char passwort [],const char db [], unsigned int port,const char *macOS_socket, unsigned int client_flag){

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
		return false;
		}
		else{
			printf("Erfolgreich mit dem MySQL-Server auf %s%s",  host, " verbunden\n");
			return true;
		}

	}

	/**

	@brief Verbindung schließen

	Die Methode "disconnect" setzt alle ausstehenden Transaktionen zurück. <br>
	Anschließend wird die Verbindung zum Verbindungspool freigegeben oder die Verbindung wird geschlossen, 
	wenn das Verbindungspooling deaktiviert ist.<br>

	@param -

	@return void 

	@author Martin Meyer
	@author Steffen Extra

	*/

	void disconnect(){

		mysql_close(mysql);
	
	}



