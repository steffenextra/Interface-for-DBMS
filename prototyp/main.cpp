#include "sqllib.hpp"


int main (int argc, char *argv[]) {


        const char* host ="localhost";
        const char* user ="root";
        const char* passwort ="root";
        const char* db = "DatabaseNumberOne1";
        unsigned int port=3306;
        unsigned int client_flag=0;
	connectionless(host, user, passwort, db, port,pathto, client_flag);
	
        
        //method-tests


        std::vector<std::string> columns; // jede gerade Index der Spaltennamen, Ungerade der Datentyp
        columns.push_back("Name");
        columns.push_back("char(50)");
        columns.push_back ("Nachname");
        columns.push_back("char(50)");
        columns.push_back("PLZ");
        columns.push_back("int");
	columns.push_back("Adresse");
	columns.push_back("char(50)");
	columns.push_back("Zwischenname");
	columns.push_back("char(50)");

	std::vector<std::string> row; // jede gerade Index der Spaltennamen, Ungerade der Datensatz

                                    //string mit '' versehen
        row.push_back("Name");
        row.push_back("'Dieter'");
        row.push_back("Nachname");
        row.push_back("'Saathoff'");
        row.push_back("PLZ");
        row.push_back("'26817'");
        row.push_back("Adresse");
        row.push_back("'Straße 1'");
        row.push_back("Zwischenname");
        row.push_back("'Heinrich'");


	showTable("tabelle2");
//	showColumnTyp("tabelle2", "char");
	disconnect();

}

