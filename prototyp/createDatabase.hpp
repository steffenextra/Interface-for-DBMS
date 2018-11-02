#include <stdio.h>
#include <string.h>
#include "/usr/local/mysql/include/mysql.h"
//#include "/usr/include/mysql/mysql.h"
#include "connection.hpp"
#include <string>
#include <iostream>

void createDatabase (std::string databaseName);
void deleteDatabase (std::string databaseName);
