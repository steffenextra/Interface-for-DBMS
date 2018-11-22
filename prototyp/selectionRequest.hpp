#ifdef __APPLE__
#include "/usr/local/mysql/include/mysql.h"
#elif defined __linux__
#include "/usr/include/mysql/mysql.h"
#endif

#include <stdio.h>
#include <string>
#include "connection.hpp"
#include <iostream>
#include <vector>

void selectOneColumn(std::string tableName,std::string ColumnName,std::string selected_at);
void sortTable(std::string tableName,std::string ColumnName,std::string sort_by);
void averageSum(std::string tableName, std::string columnName);
void sum(std::string tableName, std::string columnName, std::string alias);
void unionSelect(std::vector <std::string> tableName, std::vector <std::string> columnName);
