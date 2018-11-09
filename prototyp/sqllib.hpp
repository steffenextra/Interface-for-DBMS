
#ifdef __APPLE__
#include "/usr/local/mysql/include/mysql.h"
#elif defined __linux__
#include "/usr/include/mysql/mysql.h"
#endif


#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 


#include "connection.hpp"
#include "database.hpp"
#include "tables.hpp"
#include "entry.hpp"
#include <vector>



//---Connection---

void check_error(void);
void connection_feedback(std::string sqlCommand);
void connection_query(std::string sqlcommand);
void connectionless(const char *host,const char *user,const char *passwort, const char *db, unsigned int port,const char *unix_socket,unsigned int client_flag);
void disconnect();


//---database---

void createDatabase (std::string databaseName);
void deleteDatabase (std::string databaseName);

//--table

void createTable (bool primary_key, std::string tableName,std::vector<std::string> columns);
void showTable (std::string tableName);
void deleteTable (std::string tableName);
void setColumn(std::string tableName, std::string ColumnName,std::string datatype);
void modifierColumnName(std::string tableName, std::string oldColumnName, std::string newColumnName,std::string datatype);
void changeTheDatatype(std::string tableName, std::string columnName, std::string datatype);
void getColumn(std::string tableName);
void deleteColumn(std::string tableName, std::string columnName);

//--entry
void setEntry(std::string tableName, std::string columnName, std::string entry);
void modifierEntry(std::string tableName, std::string columnName, std::string oldEntry,std::string newEntry);

void deleteEntry(std::string tableName, std::string columnName, std::string entry);

