#include "selectionRequest.hpp"

	void sqlCommand(std::string sqlCommand,std::string commandType){
		/*
		3 CommandType 
		 query, simple Query
		 feedback, shows the contents of a Column
		 feedbackAll, shows the whole table with Columns
		*/

		if(commandType=="query"){
			check_error();
			connection_query(sqlCommand.c_str());
		}

		if(commandType=="feedback"){
			check_error();
			connection_feedback(sqlCommand.c_str());
		}

		if(commandType=="feedbackAll"){
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		else{
			check_error();
		}
	}

	void selectMinOrMax(std::string tableName,std::string minOrMax,std::vector<std::string> columns, std::string newColumn){

	}

	void selectLimitWhere(std::string tableName,std::string entryNumber,std::string comparisonColumn,std::string comparativeWorth,std::vector<std::string> columns,std::string toSortColumnName,std::string sort_by){
		//The vector columns contains the Columns that should be displayed
		std::string allColumnString;
		for(int i=0; i< columns.size();i++)
		{
			allColumnString += columns.at(i);
			if (i != columns.size()-1){
					allColumnString += ", ";
			}
		}
		std::cout<<allColumnString << std::endl;

		
		if(sort_by == "ASC" || sort_by=="asc"){
			std::string sqlCommand="SELECT " + allColumnString + " FROM " + tableName + " WHERE " + comparisonColumn  + " = '" + comparativeWorth+ "'" + "  ORDER BY " + toSortColumnName + " ASC " + " LIMIT " + entryNumber + ";";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());	
		}

		if(sort_by== "DESC" ||  sort_by=="desc"){
			std::string sqlCommand="SELECT " + allColumnString + " FROM " + tableName + " WHERE " + comparisonColumn  + " = '" + comparativeWorth+ "'" + "  ORDER BY " + toSortColumnName + " ASC " + " LIMIT " + entryNumber + ";";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());	
		}

		else{
			check_error();
		}
	}


	void selectOneColumn(std::string tableName,std::string columnName,std::string selected_at){

		std::string sqlCommand ="SELECT * FROM " + tableName + " WHERE " + columnName + " = " + "'" + selected_at + "';";
		check_error();
		connection_feedback(sqlCommand.c_str());
	}

	void selectWhere(std::string tableName,std::string comparisonColumn,std::string comparativeWorth,std::vector<std::string> columns){
		//The vector columns contains the Columns that should be displayed
		std::string allColumnString;
		for(int i=0; i< columns.size();i++)
		{
			allColumnString += columns.at(i);
			if (i != columns.size()-1){
					allColumnString += ", ";
			}
		}

		std::string sqlCommand ="SELECT " + allColumnString + " FROM " + tableName + " WHERE " + comparisonColumn  + " = '" + comparativeWorth + "';";
		check_error();
		connection_feedbackAll(sqlCommand.c_str());		
	}

	void selectWhereWithSort(std::string tableName,std::string comparisonColumn,std::string comparativeWorth,std::vector<std::string> columns,std::string toSortcolumnName,std::string sort_by){
		//The vector columns contains the Columns that should be displayed
		
		std::string allColumnString;

		for(int i=0; i< columns.size();i++)
		{
			allColumnString += columns.at(i);
			if (i != columns.size()-1){
					allColumnString += ", ";
			}
		}
		std::cout << allColumnString << std::endl;

		if(sort_by == "ASC" || sort_by=="asc"){
			std::string sqlCommand ="SELECT " + allColumnString + " FROM " + tableName + " WHERE " + comparisonColumn  + " = '" + comparativeWorth + "'" + " ORDER BY " + toSortcolumnName  + " ASC;";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());	
		}

		if(sort_by== "DESC" ||  sort_by=="desc"){
			std::string sqlCommand ="SELECT " + allColumnString + " FROM " + tableName + " WHERE " + comparisonColumn  + " = '" + comparativeWorth + "'" + " ORDER BY " + toSortcolumnName  + " DESC;";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());	
		}

		else{
			check_error();
		}
	}

	void sortTable(std::string tableName,std::string toSortColumnName,std::string sort_by){

		if(sort_by == "ASC" || sort_by=="asc"){
			std::string sqlCommand = "SELECT * FROM " + tableName + " ORDER BY " + toSortColumnName  + " ASC;";
			check_error();
			connection_feedback(sqlCommand.c_str());

	}

		else if(sort_by== "DESC" ||  sort_by=="desc"){
			std::string sqlCommand = "SELECT * FROM " + tableName + " ORDER BY " + toSortColumnName + " DESC;";
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
