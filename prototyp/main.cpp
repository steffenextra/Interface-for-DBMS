#include "sqllib.hpp"


int main (int argc, char *argv[]) {


        const char* host ="localhost";
        const char* user ="root";
        const char* passwort ="";
        const char* db = "DatabaseNumberOne1";
        unsigned int port=3306;
        const char *unix_socket="/opt/lampp/var/mysql/mysql.sock";
	//const char* macOS_socket = "/Applications/MAMP/tmp/mysql/mysql.sock";
        unsigned int client_flag=0;
	connectionless(host, user, passwort, db, port,unix_socket/*macOS_socket*/, client_flag);
	
        
        //method-tests


        std::vector<std::string> columns; // jede gerade Index der Spaltennamen, Ungerade der Datentyp
        columns.push_back("Name");
        columns.push_back("char(50)");
        columns.push_back("Release");
        columns.push_back("char(50)");
        columns.push_back("genre");
        columns.push_back("char(50)");

        std::vector<std::string> row; // jede gerade Index der Spaltennamen, Ungerade der Datensatz

                                        //string mit '' versehen
        row.push_back("Name");
        row.push_back("'Dieter'");
        row.push_back("Nachname");
        row.push_back("'Saathoff'");
        row.push_back("PLZ");
        row.push_back("'26817'");
        row.push_back("Adressse");
        row.push_back("'Straße 1'");
        row.push_back("Zwischennamen");
        row.push_back("'Heinrich'");
       
        setAllEntry("tableNumberOne",row);

     //createTable(true,"tabelle2",columns);
       // setColumn("tabelle2","Release2","char(50)");
      //  setColumn("tabelle2","Zwischennamen","char(50)");
   //   deleteTable("tabelle2");
        
        
	disconnect();

}

