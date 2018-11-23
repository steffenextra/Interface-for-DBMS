#ifdef __APPLE__
#include "/usr/local/mysql/include/mysql.h"
#elif defined __linux__
#include "/usr/include/mysql/mysql.h"
#endif

#include <stdio.h>
#include <string.h>
#include "connection.hpp"
#include <string>
#include <iostream>

void createDatabase (std::string databaseName);
void showDatabases();
void renameDatabase(std::string databaseName, std::string newDatabaseName);
void deleteDatabase (std::string databaseName);
