#include <stdio.h>
#include <string>
//#include "/usr/local/mysql/include/mysql.h"
#include "/usr/include/mysql/mysql.h"
#include "connection.hpp"
#include <iostream>

void createTable (std::string tableName, std::string column_one);
void deleteTable (std::string tableName);
void showTable (std::string tableName);
