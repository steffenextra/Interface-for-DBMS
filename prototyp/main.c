#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
//#include "/usr/local/mysql/include/mysql.h"
#include "/usr/include/mysql/mysql.h"
#include "connection.h"
#include "createDatabase.h"



int main (int argc, char *argv[]) {
        const char *host="localhost";
        const char *user="root";
        const char *passwort="root";
        //const char *db;
        unsigned int port=3350;
       const char *unix_socket="/opt/lampp/var/mysql/mysql.sock";
//	const char *macOS_socket = "/Applications/MAMP/tmp/mysql/mysql.sock";
        unsigned int client_flag=0;
  connectionless(host,user,passwort,port,unix_socket/*macOS_socket*/,client_flag);
  createDatabase("meine_Datenbank");
  disconnect();
}

