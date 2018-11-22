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

	void averageSum(std::string tableName, std::string columnName){

		std::string sqlCommand = "SELECT AVG(" + columnName + ") FROM " + tableName;
		check_error();
		connection_feedback(sqlCommand.c_str());

	}

	void sum(std::string tableName, std::string columnName, std::string alias){

		std::string sqlCommand = "SELECT SUM(" + columnName + ") AS " + alias + " FROM " + tableName;
		check_error();
		connection_feedbackAll(sqlCommand.c_str());

	}

/*	void join(std::vector <string> tables, std::string condition){



	}*/

	void unionSelect(std::vector <std::string> tableName, std::vector <std::string> columnName){

		std::string sqlCommand;

		for(int i = 0; i< tableName.size(); i++){

			if(i == tableName.size()-1 && i== columnName.size()-1){

                                sqlCommand += " SELECT " + columnName.at(i) + " FROM " + tableName.at(i) + " ";

                        }else {

			sqlCommand  += "SELECT " + columnName.at(i) + " FROM " + tableName.at(i) + " UNION ";

			}
		}

		check_error();
		connection_feedbackAll(sqlCommand.c_str());

	}
