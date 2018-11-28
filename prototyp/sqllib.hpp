
#ifdef __APPLE__
#include "/usr/local/mysql/include/mysql.h"
#define pathto "/Applications/MAMP/tmp/mysql/mysql.sock"
#elif defined __linux__
#undef pathto
#define pathto  "/opt/lampp/var/mysql/mysql.sock"
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
#include "selectionRequest.hpp"
#include <vector>



//---Connection---

void check_error(void);
void connection_feedback(std::string sqlCommand);
void connection_query(std::string sqlcommand);
void connectionless(const char *host,const char *user,const char *passwort, const char *db, unsigned int port,const char *unix_socket,unsigned int client_flag);
void disconnect();


//---database---

void createDatabase (std::string databaseName);
void showDatabases();
void renameDatabase(std::string databaseName, std::string newDatabaseName);
void deleteDatabase (std::string databaseName);


//---table---

void createTable (bool primary_key, std::string tableName,std::vector<std::string> columns);
void showTable (std::string tableName);
void renameTable(std::string tablename, std::string newTableName);
void deleteTable (std::string tableName);
void setColumn(std::string tableName, std::string ColumnName,std::string datatype);
void setColumnWithPrimary(std::string tableName, std::string ColumnName, std::string datatype, bool autoinc);
void modifierColumnName(std::string tableName, std::string oldColumnName, std::string newColumnName,std::string datatype);
void changeTheDatatype(std::string tableName, std::string columnName, std::string datatype);
void getAllColumn(std::string tableName);
void countDatasets(std::string tableName);
void showColumnTyp(std::string tableName,std::string datatype);
void deleteColumn(std::string tableName, std::string columnName);
void setSecondaryKey(std::string tableNameSecondary, std::string foreignKey, std::string tableNamePrimary, std::string primaryKey, std::string constraint);
void deleteSecondaryKey(std::string tableName, std::string constraint);
void setPrimaryKey(std::string tableName, std::string primaryKey);
void deletePrimaryKey (std::string tableName);

//---entry---
void setEntry(std::string tableName, std::string columnName, std::string entry);
void modifierEntry(std::string tableName, std::string columnName, std::string oldEntry,std::string newEntry);
void setAllEntry(std::string tableName,std::vector<std::string> row);
void deleteEntry(std::string tableName, std::string columnName, std::string condition);

//---selectionRequest---
void sqlCommand(std::string sqlCommand,std::string commandType);
void selectLike(std::string tableName,std::vector<std::string>columns,std::string toSearchColumn,std::string pattern,std::string toSearch);
void selectMinOrMax(std::string tableName,std::string minOrMax,std::string minOrMaxColumn,std::string asColumn);
void selectMinOrMaxWithWhere(std::string tableName, std::string minOrMax,std::string minOrMaxColumn,std::string asColumn,std::string comparisonColumn,std::string comparativeWorth);
void selectLimitWhere(std::string tableName,std::string entryNumber,std::string comparisonColumn,std::string comparativeWorth,std::vector<std::string> columns,std::string toSortColumnName,std::string sort_by);
void selectOneColumn(std::string tableName,std::string columnName,std::string selected_at);
void selectWhere(std::string tableName,std::string comparisonColumn,std::string comparativeWorth,std::vector<std::string> columns);
void selectWhereWithSort(std::string tableName,std::string comparisonColumn,std::string comparativeWorth,std::vector<std::string> columns,std::string toSortcolumnName,std::string sort_by);
void sortTable(std::string tableName,std::string columnName,std::string sort_by);
void selectCount(std::string tableName,std::string countColumn,std::string asColumnName);
void selectDistinct(std::string tableName,std::vector<std::string> columns);
void selectCountDistinct(std::string tableName,std::string countColumn);
void averageSum(std::string tableName, std::string columnName);
void sum(std::string tableName, std::string columnName, std::string alias);
void unionSelect(std::vector <std::string> tableName, std::vector <std::string> columnName);
void selectIn(std::string tableName,std::vector<std::string>columns,std::string searchInColumn,std::vector<std::string>comparativValues);
void selectBetween(std::string conditionString, std::string conditionStringTwo, std::string tableName, std::string conditionColumn, std::string conditionColumnTwo, std::string condition, std::string conditionTwo);
void selectColumnAlias(std::string tableName,std::vector<std::string>columns,std::vector<std::string>aliases);
void selectTableAlias(std::string tableName,std::string aliasTableName,std::vector<std::string>columns);
void selectNull(std::string tableName, std::string columnName);
