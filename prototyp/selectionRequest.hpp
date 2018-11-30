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
void selectMinOrMax(std::string tableName,std::string minOrMax,std::string minOrMaxColumn,std::string aliasColumn);
void selectMinOrMaxWhere(std::string tableName, std::string minOrMax,std::string minOrMaxColumn,std::string aliasColumn,std::string conditionColumn,std::string conditionValue);
void selectLimitWhereOrderBy(std::string tableName,std::vector<std::string> columns,std::string limitNumber,std::string conditionColumn,std::string conditionValue,std::string toSortColumnName,std::string sortBy);
void selectOneColumn(std::string tableName,std::string columnName,std::string selected_at);
void selectWhere(std::string tableName,std::vector<std::string> columns,std::string conditionColumn,std::string conditionValue);
void selectWhereAndOr(std::string tableName,std::vector<std::string> columns, std::vector<std::string>conditions,std::vector<std::string>conditionValue,std::vector<std::string> conditions2,std::vector<std::string>conditionValue2,std::vector<std::string>operators);
void selectWhereOrderBy(std::string tableName,std::vector<std::string> columns,std::string conditionColumn,std::string conditionValue,std::string toSortcolumnName,std::string sortBy);
void selectSortTable(std::string tableName,std::string toSortColumnName,std::string sortBy);
void selectCount(std::string tableName,std::string countColumn,std::string aliasColumnName);
void selectDistinct(std::string tableName,std::vector<std::string> columns);
void selectCountDistinct(std::string tableName,std::string countColumn);
void selectAverageSum(std::string tableName, std::string columnName);
void selectSum(std::string tableName, std::string columnName, std::string aliasColumnName);
void unionSelect(std::vector <std::string> tableName, std::vector <std::string> columnName);
void selectIn(std::string tableName,std::vector<std::string>columns,std::string searchInColumn,std::vector<std::string>conditionValue);
void selectBetween(std::string conditionString, std::string conditionStringTwo, std::string tableName, std::string conditionColumn, std::string conditionColumnTwo, std::string condition, std::string conditionTwo);
void selectColumnsAlias(std::string tableName,std::vector<std::string>columns,std::vector<std::string>aliases);
void selectTableAlias(std::string tableName,std::vector<std::string>columns,std::string aliasTableName);
void selectGroupBy(std::string tableName, std::vector<std::string>columns,std::string conditionColumn,std::string conditionValue,std::vector<std::string>groupByColumns);
void selectGroupByOrderBy(std::string tableName, std::vector<std::string>columns,std::string conditionColumn,std::string conditionValue,std::vector<std::string>groupByColumns,std::string toSortcolumnName,std::string sortBy);
void selectCountGroupByOrderBy(std::string tableName, std::string countColumn,std::vector<std::string>columns,std::string conditionColumn,std::string conditionValue,std::vector<std::string>groupByColumns,std::string sortBy);
void selectNull(std::string tableName, std::string columnName);
