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
        columns.push_back("char(50)");;


       // createTable(true,"tabelle2",columns);
   
      //  deleteTable("tabelle2");
        
        
	disconnect();

}

