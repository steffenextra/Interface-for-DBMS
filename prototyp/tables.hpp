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

void createTable (bool primary_key, std::string tableName,std::vector<std::string> columns);
void showTable (std::string tableName);
void deleteTable (std::string tableName);
void setColumn(std::string tableName, std::string ColumnName,std::string datatype);
void setColumnWithPrimary(std::string tableName, std::string ColumnName, std::string datatype, bool autoinc);
void modifierColumnName(std::string tableName, std::string oldColumnName, std::string newColumnName,std::string datatype);
void changeTheDatatype(std::string tableName, std::string columnName, std::string datatype);
void getAllColumn(std::string tableName);
void showColumnTyp(std::string tableName,std::string datatype);
void deleteColumn(std::string tableName, std::string columnName);
void setSecondaryKey(std::string tableNameSecondary, std::string foreignKey, std::string tableNamePrimary, std::string primaryKey, std::string constraint);
void deleteSecondaryKey(std::string tableName, std::string constraint);
void setPrimaryKey(std::string tableName, std::string primaryKey);
void deletePrimaryKey (std::string tableName);
