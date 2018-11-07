#include "sqllib.hpp"


int main (int argc, char *argv[]) {


        const char* host ="localhost";
        const char* user ="root";
        const char* passwort ="";
        const char* db = "DatabaseNumberOne1";
        unsigned int port=3306;
       const char *unix_socket="/opt/lampp/var/mysql/mysql.sock";
//	const char* macOS_socket = "/Applications/MAMP/tmp/mysql/mysql.sock";
        unsigned int client_flag=0;
	connectionless(host, user, passwort, db, port, unix_socket/*macOS_socket*/, client_flag);
   
      //Methods test
     //createDatabase("DatabaseNumberOne1");
     //createTable("tableNumberOne", "Name varchar(255)");
      //showTable("tableNumberOne");
     // setColumn("tableNumberOne","PLZ","varchar(255)");
      //  modifierColumnName("tableNumberOne","Adr", "Adresse","varchar(255)");
    // deleteColumn("tableNumberOne","Adresse");
      getColumn("tableNumberOne");
//	deleteTable("testtest");
	disconnect();

}

