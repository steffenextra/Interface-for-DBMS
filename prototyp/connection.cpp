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

	*/

		std::string connection_feedback(std::string sqlCommand){

                std::cout << std::endl;
             /*   std::cout <<"\033[1;31m DEBUG : INPUT FOR THE MYSQL_QUERY\033[0m" << std::endl;
                std::cout << sqlCommand << std::endl;
                std::cout << std::endl;*/
                mysql_query(mysql, sqlCommand.c_str());
                check_error();
                result=mysql_use_result(mysql);
                std::vector <std::string> rowvec;
			while((row=mysql_fetch_row(result))!=NULL){
				std::cout<< *row << std::endl;
				 rowvec.push_back(*row);
			}
			std::string rowvecst;
			for(int i=0;i<rowvec.size();i++){
				rowvecst += rowvec[i]; 
				rowvecst += "\n";
			}
		
			mysql_free_result(result);
			return rowvecst.c_str();
		}


	/**

	@brief Rückgabe aller Datensätze

	Die Methode "connection_feedbackAll" liefert den kompletten Datensatz zurück der Abfrage zurück.

	@param sqlCommand = enhält den auszuführenden SQL-Befehl

	@return void


	*/


	std::string connection_feedbackAll(std::string sqlCommand){
		std::cout << std::endl;
       /* std::cout <<"\033[1;31m DEBUG : INPUT FOR THE MYSQL_QUERY\033[0m" << std::endl;
        std::cout << sqlCommand << std::endl;
        std::cout << std::endl;*/
        std::string output;
        std::vector<std::string> rowvec;
        std::vector<std::string> colvec;
	   // std::vector<std::vector<std::string> > insgesamt;
        check_error();
		mysql_query(mysql,sqlCommand.c_str());
		MYSQL_RES *result = mysql_store_result(mysql);
		
		int rowresult = mysql_num_rows(result);
		int num_fields = mysql_num_fields(result);
		int insg = rowresult * num_fields;
		
		if (result == NULL){
		check_error();

		}

		std::cout << rowresult << std::endl;
		while ((row = mysql_fetch_row(result))!=NULL){

			for(int i = 0; i < num_fields; i++){

				if (i == 0){

					while(field = mysql_fetch_field(result)){
						printf("%s", field->name);
						colvec.push_back(field->name);
					}

					printf("\n");
				}

				printf("%s  ", row[i] ? row[i] : "NULL");
				rowvec.push_back(row[i]);
				
			}
	
		}

		for(int i = 0; i<num_fields;i++){
		
			output+=colvec[i] + " ";
		
		}	
		
		for(int i =0; i<(num_fields*rowresult);i++){
		
			if(i%6==0|| i == 0){
		
				output+= "\n" + rowvec[i] + " ";
		
			}else{
		
			output+=rowvec[i]+ " ";
		
			}
		
		}
		printf("\n");
		mysql_free_result(result);
		return output.c_str();
	}

	/**

	@brief Sendet eine Abfrage zum SQL-Server

	Die Methode "connection_query" sendet eine eindeutige Abfrage (mehrere Abfragen werden nicht unterstützt) 
	an die derzeit aktive Datenbank auf dem Server, der dem angegebenen Server zugeordnet ist. <br>

	@param sqlCommand = enhält den auszuführenden SQL-Befehl

	@return void

	*/

	std::string connection_query(std::string sqlCommand){

		std::cout << std::endl;
		std::cout <<"\033[1;31m DEBUG : INPUT FOR THE MYSQL_QUERY\033[0m" << std::endl;
		std::cout << sqlCommand << std::endl;
		std::cout << std::endl;
		check_error();
		mysql_query (mysql, sqlCommand.c_str());
		check_error();
		std::string statement = sqlCommand;
	return statement.c_str();
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

	*/

	void disconnect(){

		mysql_close(mysql);
	
	}



