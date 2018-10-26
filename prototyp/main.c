#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h> 
#include "/usr/local/mysql/include/mysql.h"
//#include "/usr/include/mysql/mysql.h"
#include "connection.h"
#include "createDatabase.h"
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
        const char host [] ="localhost";
        const char user [] ="root";
        const char passwort [] ="root";
//        const char db [] = "mysql";
        unsigned int port=8889;
//       const char *unix_socket="/opt/lampp/var/mysql/mysql.sock";
	const char macOS_socket [] = "/Applications/MAMP/tmp/mysql/mysql.sock";
        unsigned int client_flag=0;
	MYSQL *mysql = connectionless(host,user,passwort,port,/*unix_socket*/macOS_socket,client_flag);
	std::cout << mysql << std::endl;
	string name = "yolo";
	createDatabase(mysql, name);



//	mysql_query(connectionless(host,user,passwort,port,/*unix_socket*/macOS_socket,client_flag), name.c_str());


  disconnect();
}

