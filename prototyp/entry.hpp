#ifdef __APPLE__
#include "/usr/local/mysql/include/mysql.h"
#elif defined __linux__
#include "/usr/include/mysql/mysql.h"
#endif

#include <stdio.h>
#include <string>
#include "connection.hpp"
#include <iostream>


void setEntry(std::string tableName, std::string columnName, std::string entry);
void modifierEntry(std::string tableName, std::string columnName, std::string oldEntry,std::string newEntry);

void deleteEntry(std::string tableName, std::string columnName, std::string entry);
