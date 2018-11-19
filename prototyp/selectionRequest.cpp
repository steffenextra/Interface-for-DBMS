#include "selectionRequest.hpp"


	void selectOneColumn(std::string tableName,std::string ColumnName,std::string selected_at){

		std::string sqlCommand ="SELECT * FROM " + tableName + " WHERE " + ColumnName + " = " + "'" + selected_at + "';";
		check_error();
		connection_feedback(sqlCommand.c_str());
	}

	void sortTable(std::string tableName,std::string ColumnName,std::string sort_by){

		if(sort_by == "ASC" || sort_by=="asc"){
			std::string sqlCommand = "SELECT * FROM " + tableName + " ORDER BY " + ColumnName  + " ASC;";
			check_error();
			connection_feedback(sqlCommand.c_str());

	}

		else if(sort_by== "DESC" ||  sort_by=="desc"){
			std::string sqlCommand = "SELECT * FROM " + tableName + " ORDER BY " + ColumnName  + " DESC;";
			check_error();
			connection_feedback(sqlCommand.c_str());
		}
		else{
			check_error();
		}
	}
