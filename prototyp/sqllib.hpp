
/**

/def Je nach Betriebssystem wird der Pfad für die mysql-Headerdatei includiert

*/
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
#include <vector>
#include <fstream>

//---conf_save---

void conf(const char host [], const char user [], const char password [], const char database [], int port, bool safeconf);
void loadConf(char *name);

//---Connection---

std::string check_error(void);
std::string connection_feedback(std::string sqlCommand);
std::string connection_feedbackAll(std::string sqlCommand);
std::string connection_query(std::string sqlcommand);
bool connectionless(const char *host,const char *user,const char *passwort, const char *db, unsigned int port,const char *unix_socket,unsigned int client_flag);
void disconnect();


//---database---

void createDatabase (std::string databaseName);
std::string showDatabases();
void renameDatabase(std::string databaseName, std::string newDatabaseName);
void deleteDatabase (std::string databaseName);


//---table---

void createTable (bool primary_key, std::string tableName,std::vector<std::string> columns);
std::string showTable (std::string tableName);
void renameTable(std::string tablename, std::string newTableName);
void deleteTable (std::string tableName);
void setColumn(std::string tableName, std::string ColumnName,std::string datatype);
void setColumnWithPrimary(std::string tableName, std::string ColumnName, std::string datatype, bool autoinc);
void modifierColumnName(std::string tableName, std::string oldColumnName, std::string newColumnName,std::string datatype);
void changeTheDatatype(std::string tableName, std::string columnName, std::string datatype);
std::string getAllColumn(std::string tableName);
std::string countDatasets(std::string tableName);
std::string showColumnTyp(std::string tableName,std::string datatype);
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
void ownCommand(std::string sqlCommand,std::string commandType);
std::string selectLike(std::string tableName,std::vector<std::string>columns,std::string toSearchColumn,std::string pattern,std::string toSearch);
std::string selectNotLike(std::string tableName,std::vector<std::string>columns,std::string toSearchColumn,std::string pattern,std::string toSearch);
std::string selectMinOrMax(std::string tableName,std::string minOrMax,std::string minOrMaxColumn,std::string aliasColumn);
std::string selectMinOrMaxWhere(std::string tableName, std::string minOrMax,std::string minOrMaxColumn,std::string aliasColumn,std::string conditionColumn,std::string conditionValue);
std::string selectLimitWhereOrderBy(std::string tableName,std::vector<std::string> columns,std::string limitNumber,std::string conditionColumn,std::string conditionValue,std::string toSortColumnName,std::string sortBy);
std::string selectWhereOneColumn(std::string tableName,std::string conditionColumn,std::string conditionValue);
std::string selectWhere(std::string tableName,std::vector<std::string> columns,std::string conditionColumn,std::string conditionValue);
std::string selectBool(std::string tableName,std::vector<std::string> columns, std::vector<std::string>conditions,std::vector<std::string>conditionValue,std::vector<std::string> conditions2,std::vector<std::string>conditionValue2,std::vector<std::string>operators);
std::string selectWhereOrderBy(std::string tableName,std::vector<std::string> columns,std::string conditionColumn,std::string conditionValue,std::string toSortcolumnName,std::string sortBy);
std::string selectSortTable(std::string tableName,std::string toSortColumnName,std::string sortBy);
std::string selectCount(std::string tableName,std::string countColumn,std::string aliasColumnName);
std::string selectDistinct(std::string tableName,std::vector<std::string> columns);
std::string selectCountDistinct(std::string tableName,std::string countColumn);
std::string selectAverageSum(std::string tableName, std::string columnName);
std::string selectSum(std::string tableName, std::string columnName, std::string aliasColumnName);
std::string selectUnion(std::vector <std::string> tableName, std::vector <std::string> columnName);
std::string selectIn(std::string tableName,std::vector<std::string>columns,std::string searchInColumn,std::vector<std::string>conditionValue);
std::string selectBetween(std::string conditionString, std::string conditionStringTwo, std::string tableName, std::string conditionColumn, std::string conditionColumnTwo, std::string condition, std::string conditionTwo);
std::string selectColumnsAlias(std::string tableName,std::vector<std::string>columns,std::vector<std::string>aliases);
std::string selectTableAlias(std::string tableName,std::vector<std::string>columns,std::string aliasTableName);
std::string selectGroupBy(std::string tableName, std::vector<std::string>columns,std::string conditionColumn,std::string conditionValue,std::vector<std::string>groupByColumns);
std::string selectGroupByOrderBy(std::string tableName, std::vector<std::string>columns,std::string conditionColumn,std::string conditionValue,std::vector<std::string>groupByColumns,std::string toSortcolumnName,std::string sortBy);
std::string selectCountGroupByOrderBy(std::string tableName, std::string countColumn,std::vector<std::string>columns,std::string conditionColumn,std::string conditionValue,std::vector<std::string>groupByColumns,std::string sortBy);
std::string selectNull(std::string tableName, std::string columnName);
std::string selectInnerJoin(std::string firstTableName, std::string columnIDTableOne,std:: vector <std::string> columnsTableOne,std::string secondTableName,std::vector <std::string> columnsTableTwo);
std::string selectLeftJoin(std::string firstTableName, std::string columnIDTableOne,std:: vector <std::string> columnsTableOne,std::string secondTableName,std::vector <std::string> columnsTableTwo);
std::string selectRightJoin(std::string firstTableName, std::string columnIDTableOne,std:: vector <std::string> columnsTableOne,std::string secondTableName,std::vector <std::string> columnsTableTwo);





