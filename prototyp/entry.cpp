#include "entry.hpp"



void setEntry(std::string tableName, std::string columnName, std::string entry)
{
        std::string sqlCommand = "INSERT INTO " + tableName + " (" + columnName + ") VALUES ("+ "'" + entry + "'" + ")" ;
        check_error();
		connection_query(sqlCommand.c_str());
}

void modifierEntry(std::string tableName, std::string columnName, std::string oldEntry,std::string newEntry)
{
        std::string sqlCommand="UPDATE " + tableName + " SET " + columnName + " = " + "'" + newEntry + "'" + " WHERE " + columnName + "= " + "'" + oldEntry + "'";
        check_error();
		connection_query(sqlCommand.c_str());
}

void setAllEntry()
{

}

void deleteEntry(std::string tableName, std::string columnName, std::string entry)
{
	std::string sqlCommand = "DELETE FROM " + tableName + " WHERE " + columnName + "= " + "'" + entry + "'";
	check_error();
		connection_query(sqlCommand.c_str());
}
