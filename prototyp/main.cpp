#include "sqllib.hpp"


int main (int argc, char *argv[]) {


        const char* host ="localhost";
        const char* user ="root";
        const char* passwort ="root";
        const char* db = "test";
        unsigned int port=8889;
//       const char *unix_socket="/opt/lampp/var/mysql/mysql.sock";
	const char* macOS_socket = "/Applications/MAMP/tmp/mysql/mysql.sock";
        unsigned int client_flag=0;
	connectionless(host, user, passwort, db, port, /*unix_socket*/macOS_socket, client_flag);
//	createTable("testtest", "Name varchar(255)");
	deleteTable("testtest");
	disconnect();

}

