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

void sqlCommand(std::string sqlCommand,std::string commandType);
void selectOneColumn(std::string tableName,std::string columnName,std::string selected_at);
void selectWhere(std::string tableName,std::string comparisonColumn,std::string comparativeWorth,std::vector<std::string> columns);
void sortTable(std::string tableName,std::string columnName,std::string sort_by);
void averageSum(std::string tableName, std::string columnName);
void sum(std::string tableName, std::string columnName, std::string alias);
void unionSelect(std::vector <std::string> tableName, std::vector <std::string> columnName);
