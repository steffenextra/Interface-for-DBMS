#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include "/usr/include/mysql/mysql.h"
//#include "/usr/local/mysql/include/mysql.h"
#include <string>
#include <iostream>

void check_error(void);
void connection_query(std::string sqlcommand);
void connectionless(const char *host,const char *user,const char *passwort, const char *db, unsigned int port,const char *unix_socket,unsigned int client_flag);
void disconnect();

