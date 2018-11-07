#include "tables.hpp"

	

	void createTable (std::string tableName, std::string column_one, bool primaryKey){

		
		std::string sqlCommand = "CREATE TABLE " + tableName + " ( " + column_one +  " );";
		check_error();
		connection_query(sqlCommand.c_str());

	}

	void showTable (std::string tableName)
	{
		std::string sqlCommand ="SELECT * FROM " + tableName;
		check_error();
		connection_feedback(sqlCommand.c_str());
	}

	void deleteTable (std::string tableName){

		std::string sqlCommand = "DROP TABLE " + tableName ;
		check_error();
		connection_query(sqlCommand.c_str());

	}

	void setColumn(std::string tableName, std::string ColumnName, std::string datatype)
	{
		std::string sqlCommand =" ALTER TABLE " + tableName + " ADD " + ColumnName +  " " + datatype;
		check_error();
		connection_query(sqlCommand.c_str());
	}

	void modifierColumnName(std::string tableName, std::string oldColumnName, std::string newColumnName,std::string datatype)
	{
		std::string sqlCommand= "ALTER TABLE " + tableName + " CHANGE " + oldColumnName + " " + newColumnName + " " + datatype;
		check_error();
		connection_query(sqlCommand.c_str());
	}

	void changeTheDatatype(std::string tableName, std::string columnName, std::string datatype)
	{
		//has to be tested
		std::string sqlCommand="AlTER TABLE " + tableName + " MODIFY " + columnName + " " + datatype;
		check_error();
		connection_query(sqlCommand.c_str());
	}

	void getColumn(std::string tableName)
	{
		std::string sqlCommand ="SHOW COLUMNS FROM " + tableName;
		check_error();
		connection_feedback(sqlCommand.c_str());
	}

	void deleteColumn(std::string tableName, std::string columnName)
	{
		std::string sqlCommand= "ALTER TABLE " + tableName + " DROP " + columnName;
		check_error();
		connection_query(sqlCommand.c_str());
	}

//	void insertTable(){}
