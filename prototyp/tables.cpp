#include "tables.hpp"



	void createTable (std::string tableName, std::string column_one){

		std::string sqlCommand = "CREATE TABLE " + tableName + " ( " + column_one +  " );";
		check_error();
		connection_query(sqlCommand.c_str());

	}

	void deleteTable (std::string tableName){

		std::string sqlCommand = "DROP TABLE " + tableName ;
		check_error();
		connection_query(sqlCommand.c_str());

	}

	void showTable (std::string tableName)
	{
		std::string sqlCommand = "SELECT * FROM " + tableName;

		connection_feedback(sqlCommand.c_str());
	}

//	void insertTable(){}
