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
void selectLike(std::string tableName,std::vector<std::string>columns,std::string toSearchColumn,std::string pattern,std::string toSearch);
void selectNotLike(std::string tableName,std::vector<std::string>columns,std::string toSearchColumn,std::string pattern,std::string toSearch);
void selectMinOrMax(std::string tableName,std::string minOrMax,std::string minOrMaxColumn,std::string asColumn);
void selectMinOrMaxWithWhere(std::string tableName, std::string minOrMax,std::string minOrMaxColumn,std::string asColumn,std::string comparisonColumn,std::string comparativeWorth);
void selectLimitWhere(std::string tableName,std::string entryNumber,std::string comparisonColumn,std::string comparativeWorth,std::vector<std::string> columns,std::string toSortColumnName,std::string sort_by);
void selectOneColumn(std::string tableName,std::string columnName,std::string selected_at);
void selectWhere(std::string tableName,std::string comparisonColumn,std::string comparativeWorth,std::vector<std::string> columns);
void selectWhereAndOr(std::string tableName,std::vector<std::string> columns, std::vector<std::string>conditions,std::vector<std::string>conditionValue,std::vector<std::string> conditions2,std::vector<std::string>conditionValue2,std::vector<std::string>operators);
void selectWhereWithSort(std::string tableName,std::string comparisonColumn,std::string comparativeWorth,std::vector<std::string> columns,std::string toSortcolumnName,std::string sort_by);
void sortTable(std::string tableName,std::string columnName,std::string sort_by);
void selectCount(std::string tableName,std::string countColumn,std::string asColumnName);
void selectDistinct(std::string tableName,std::vector<std::string> columns);
void selectCountDistinct(std::string tableName,std::string countColumn);
void averageSum(std::string tableName, std::string columnName);
void sum(std::string tableName, std::string columnName, std::string alias);
void unionSelect(std::vector <std::string> tableName, std::vector <std::string> columnName);
void selectIn(std::string tableName,std::vector<std::string>columns,std::string searchInColumn,std::vector<std::string>comparativValues);
void selectColumnAlias(std::string tableName,std::vector<std::string>columns,std::vector<std::string>aliases);
void selectTableAlias(std::string tableName,std::string aliasTableName,std::vector<std::string>columns);
void selectGroupBy(std::string tableName, std::vector<std::string>columns,std::string comparisonColumn,std::string comparativeWorth,std::vector<std::string>groupByColumns);
