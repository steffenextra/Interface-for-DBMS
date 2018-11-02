
#include "/usr/local/mysql/include/mysql.h"
//#include "/usr/include/mysql/mysql.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 



#include "connection.hpp"
#include "createDatabase.hpp"
#include "tables.hpp"


//---Connection---

void check_error(void);
void connection_query(std::string sqlcommand);
void connectionless(const char *host,const char *user,const char *passwort, const char *db, unsigned int port,const char *unix_socket,unsigned int client_flag);
void disconnect();


//---database---

void createDatabase (std::string databaseName);
void deleteDatabase (std::string databaseName);

//--table

void createTable (std::string tableName, std::string column_one);
void deleteTable (std::string tableName);


