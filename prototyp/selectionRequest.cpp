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

	void selectLike(std::string tableName,std::vector<std::string>columns,std::string toSearchColumn,std::string pattern,std::string toSearch){
		
		std::string allColumnString;
		for(int i=0; i< columns.size();i++)
		{
			if (i != columns.size()-1){
					allColumnString += " " + columns.at(i) + ",";
			}
			else{
					allColumnString += " " + columns.at(i) + " ";
			}
		}

		if(pattern=="start"){
			std::string sqlCommand="SELECT " + allColumnString + " FROM " + tableName + " WHERE " + toSearchColumn + "  LIKE " + "'" + toSearch + "%';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(pattern=="end"){
			std::string sqlCommand="SELECT " + allColumnString + " FROM " + tableName + " WHERE " + toSearchColumn + "  LIKE " + "'%" + toSearch + "';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(pattern=="anyPosition"){
			std::string sqlCommand="SELECT " + allColumnString + " FROM " + tableName + " WHERE " + toSearchColumn + "  LIKE " + "'%" + toSearch + "%';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(pattern=="secondPosition"){
			std::string sqlCommand="SELECT " + allColumnString + " FROM " + tableName + " WHERE " + toSearchColumn + "  LIKE " + "'_" + toSearch + "%';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(pattern=="startandEnd"){
			std::string sqlCommand="SELECT " + allColumnString + " FROM " + tableName + " WHERE " + toSearchColumn + "  LIKE " + "'" + toSearch.at(0) + "%" + toSearch.at(1) + "';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}
		else{
			//exception handling
		}
	}

		void selectNotLike(std::string tableName,std::vector<std::string>columns,std::string toSearchColumn,std::string pattern,std::string toSearch){
		
		std::string allColumnString;
		for(int i=0; i< columns.size();i++)
		{
			if (i != columns.size()-1){
					allColumnString += " " + columns.at(i) + ",";
			}
			else{
					allColumnString += " " + columns.at(i) + " ";
			}
		}

		if(pattern=="start"){
			std::string sqlCommand="SELECT " + allColumnString + " FROM " + tableName + " WHERE " + toSearchColumn + " NOT LIKE " + "'" + toSearch + "%';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(pattern=="end"){
			std::string sqlCommand="SELECT " + allColumnString + " FROM " + tableName + " WHERE " + toSearchColumn + " NOT LIKE " + "'%" + toSearch + "';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(pattern=="anyPosition"){
			std::string sqlCommand="SELECT " + allColumnString + " FROM " + tableName + " WHERE " + toSearchColumn + " NOT LIKE " + "'%" + toSearch + "%';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(pattern=="secondPosition"){
			std::string sqlCommand="SELECT " + allColumnString + " FROM " + tableName + " WHERE " + toSearchColumn + " NOT LIKE " + "'_" + toSearch + "%';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(pattern=="startandEnd"){
			std::string sqlCommand="SELECT " + allColumnString + " FROM " + tableName + " WHERE " + toSearchColumn + " NOT LIKE " + "'" + toSearch.at(0) + "%" + toSearch.at(1) + "';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}
		else{
			//exception handling
		}
	}

	void selectMinOrMax(std::string tableName,std::string minOrMax,std::string minOrMaxColumn,std::string asColumn){

		if(minOrMax == "min" || minOrMax=="MIN"){
			std::string sqlCommand="SELECT MIN(" + minOrMaxColumn +")" + " AS " + asColumn + " FROM " +  tableName + ";";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());	
		}

		if(minOrMax == "MAX" || minOrMax=="MAX"){
			std::string sqlCommand="SELECT MAX(" + minOrMaxColumn +")" + " AS " + asColumn + " FROM " +  tableName + ";";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());	
		}

		else{
			check_error();
		}

	}

	void selectMinOrMaxWithWhere(std::string tableName, std::string minOrMax,std::string minOrMaxColumn,std::string asColumn,std::string comparisonColumn,std::string comparativeWorth){
		
		if(minOrMax == "min" || minOrMax=="MIN"){
			std::string sqlCommand="SELECT MIN(" + minOrMaxColumn +")" +" AS " + asColumn + " FROM " +  tableName + " WHERE " + comparisonColumn  + " = '" + comparativeWorth + "'" + ";";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());	
		}

		if(minOrMax == "MAX" || minOrMax=="MAX"){
			std::string sqlCommand="SELECT MAX(" + minOrMaxColumn +")" +" AS " + asColumn + " FROM " +  tableName + " WHERE " + comparisonColumn  + " = '" + comparativeWorth + "'" + ";";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());	
		}

		else{
			check_error();
		}
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

	void selectWhereAndOr(std::string tableName,std::vector<std::string> columns, std::vector<std::string>conditions,std::vector<std::string>conditionValue,std::vector<std::string> conditions2,std::vector<std::string>conditionValue2,std::vector<std::string>operators){
			
			int i=0;
			std::string allColumns;
			std::string conditionOperatorString;
			
			while(i<columns.size()){
				if (i != columns.size()-1){
					allColumns +=  columns.at(i) + ", ";
				}
				else{
					allColumns +=  columns.at(i) + " ";
				}
				i++;
			}
			i=0;

			while(i<conditions.size()){
				if(i != conditions.size()-1){
					if(conditionValue.at(i).at(0)<=60  && conditionValue2.at(i).at(0)<=60){
						conditionOperatorString += " " + conditions.at(i) +  "=" + conditionValue.at(i) + " " + operators.at(i) + " " + conditions2.at(i) +  "=" + conditionValue2.at(i) + " " + operators.at(i+1);
					}

					if(conditionValue.at(i).at(0)<=60){
						conditionOperatorString += " " + conditions.at(i) +  "=" + conditionValue.at(i) + " " + operators.at(i) + " " + conditions2.at(i) +  "='" + conditionValue2.at(i) + "' "  + operators.at(i+1);
					}
					if(conditionValue2.at(i).at(0)<=60){
						conditionOperatorString += " " + conditions.at(i) +  "='" + conditionValue.at(i) + "' " + operators.at(i) + " " + conditions2.at(i) +  "=" + conditionValue2.at(i) + " "  + operators.at(i+1);
					}
					else{
						conditionOperatorString += " " + conditions.at(i) +  "='" + conditionValue.at(i) + "' " + operators.at(i) + " " + conditions2.at(i) +  "='" + conditionValue2.at(i) + "' "  + operators.at(i+1);
					}
				}
				else{
					if(conditionValue.at(i).at(0)<=60  && conditionValue2.at(i).at(0)<=60){
						conditionOperatorString += " " + conditions.at(i) +  "=" + conditionValue.at(i) + " " + operators.at(i) + " " + conditions2.at(i) +  "=" + conditionValue2.at(i) + " ";
					}

					if(conditionValue.at(i).at(0)<=60){
						conditionOperatorString += " " + conditions.at(i) +  "=" + conditionValue.at(i) + " " + operators.at(i) + " " + conditions2.at(i) +  "='" + conditionValue2.at(i) + "' ";
					}
					if(conditionValue2.at(i).at(0)<=60){
						conditionOperatorString += " " + conditions.at(i) +  "='" + conditionValue.at(i) + "' " + operators.at(i) + " " + conditions2.at(i) +  "=" + conditionValue2.at(i) + " ";
					}
					else{
						conditionOperatorString += " " + conditions.at(i) +  "='" + conditionValue.at(i) + "' " + operators.at(i) + " " + conditions2.at(i) +  "='" + conditionValue2.at(i) + "' ";
					}
				}
				i++;
			}
			
			std::string sqlCommand ="SELECT " + allColumns + " FROM " + tableName + " WHERE "  + conditionOperatorString + ";";
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

	void selectCount(std::string tableName,std::string countColumn,std::string asColumnName){
		std::string sqlCommand = "SELECT COUNT(" + countColumn + ") AS " + asColumnName + " FROM " + tableName + ";";
		check_error();
		connection_feedbackAll(sqlCommand.c_str());
	}

	void selectDistinct(std::string tableName,std::vector<std::string> columns){
		std::string allColumnString;

		for(int i=0; i< columns.size();i++)
		{
			allColumnString += columns.at(i);
			if (i != columns.size()-1){
					allColumnString += ", ";
			}
		}

		std::string sqlCommand = "SELECT DISTINCT " + allColumnString + " FROM " + tableName + ";";
		check_error();
		connection_feedbackAll(sqlCommand.c_str());
	}

	void selectCountDistinct(std::string tableName,std::string countColumn){

		std::string sqlCommand = "SELECT COUNT(DISTINCT " + countColumn + ") FROM " + tableName + ";";
		check_error();
		connection_feedback(sqlCommand.c_str());
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

	void selectIn(std::string tableName,std::vector<std::string>columns,std::string searchInColumn,std::vector<std::string>comparativValues){
		
		int i=0;
		std::string column;
		std::string comparativValue;

		while(i<columns.size()){
			if (i != columns.size()-1){
				column +=  columns.at(i) + ", ";
			}
			else{
				column +=  columns.at(i) + " ";
			}
			i++;
		}
		
		i=0;

		while(i<comparativValues.size()){
			if (i != comparativValues.size()-1){
				comparativValue +=  "'" + comparativValues.at(i) + "'" + ", ";
			}
			else{
				comparativValue += "'" + comparativValues.at(i) + "'" + " ";
			}
			i++;
		}

		std::string sqlCommand = "SELECT " + column + " FROM " + tableName + " WHERE " + searchInColumn + " IN " + " (" + comparativValue + ");";
		check_error();
		connection_feedbackAll(sqlCommand.c_str()); 
	}

	void selectBetween(std::string conditionString, std::string conditionStringTwo, std::string tableName, std::string conditionColumn, std::string conditionColumnTwo, std::string condition, std::string conditionTwo){

		std::string first = "SELECT * ";
		std::string sqlCommand = first + " FROM " + tableName + " WHERE " + conditionColumn + " " + conditionString + " " + condition
                                             + " AND " + conditionColumnTwo + " " + conditionString + " " + conditionTwo;
		check_error();
		connection_feedbackAll(sqlCommand.c_str());

	}

	void selectColumnsAlias(std::string tableName,std::vector<std::string>columns,std::vector<std::string>aliases){
		//Entry i of the alias vector is the Alias for the Entry i of the columns vector 
		
		std::string columnAlias;
		int i =0;

		while(i<columns.size()){
			if (i != columns.size()-1){
				columnAlias +=  columns.at(i) + " AS " + aliases.at(i) + ", ";
			}
			else{
				columnAlias +=  columns.at(i) + " AS " + aliases.at(i) + " ";
			}
			i+=2;
		}

		std::string sqlCommand ="SELECT " + columnAlias + " FROM " + tableName + ";";
		check_error();
		connection_feedbackAll(sqlCommand.c_str());
	}

	void selectTableAlias(std::string tableName,std::string aliasTableName,std::vector<std::string>columns){
		std::string columnAlias;
		int i =0;

		while(i<columns.size()){
			if (i != columns.size()-1){
				columnAlias +=  columns.at(i) + ", ";
			}
			else{
				columnAlias +=  columns.at(i) + " ";
			}
			i++;
		}
	
		std::string sqlCommand ="SELECT " + columnAlias + " FROM " + tableName + " AS " + aliasTableName +";";
		check_error();
		connection_feedbackAll(sqlCommand.c_str());
	}

	void selectGroupBy(std::string tableName, std::vector<std::string>columns,std::string comparisonColumn,std::string comparativeWorth,std::vector<std::string>groupByColumns){
		int i=0;
		std::string allColumns;
		std::string allGroupByColumns;
		while(i<columns.size()){
			
			if (i != columns.size()-1){
				allColumns +=  columns.at(i) + ", ";
			}
			else{
				allColumns +=  columns.at(i) + " ";
			}
			i++;
		}
		i=0;
		
		while(i<groupByColumns.size()){
			if (i != columns.size()-1){
				allGroupByColumns +=  groupByColumns.at(i) + ", ";
			}
			else{
				allGroupByColumns +=  groupByColumns.at(i) + " ";
			}
			i++;
		}

		std::string sqlCommand ="SELECT " + allColumns + " FROM " + tableName + " WHERE " + comparisonColumn  + " = '" + comparativeWorth + "' GROUP BY " + allGroupByColumns + ";";
		check_error(); 
		connection_feedbackAll(sqlCommand.c_str());
	}

	void selectGroupBy(std::string tableName, std::vector<std::string>columns,std::string comparisonColumn,std::string comparativeWorth,std::vector<std::string>groupByColumns,std::string toSortcolumnName,std::string sort_by){
		int i=0;
		std::string allColumns;
		std::string allGroupByColumns;
		while(i<columns.size()){
			
			if (i != columns.size()-1){
				allColumns +=  columns.at(i) + ", ";
			}
			else{
				allColumns +=  columns.at(i) + " ";
			}
			i++;
		}
		i=0;
		
		while(i<groupByColumns.size()){
			if (i != columns.size()-1){
				allGroupByColumns +=  groupByColumns.at(i) + " ";
			}
			else{
				allGroupByColumns +=  groupByColumns.at(i) + " ";
			}
			i++;
		}

		if(sort_by=="ASC" || sort_by=="asc"){
			std::string sqlCommand ="SELECT " + allColumns + " FROM " + tableName + " WHERE " + comparisonColumn  + " = '" + comparativeWorth + "' GROUP BY " + allGroupByColumns +  " ORDER BY " + toSortcolumnName  + " ASC;";
			check_error(); 
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(sort_by=="DESC" || sort_by=="desc"){
			std::string sqlCommand ="SELECT " + allColumns + " FROM " + tableName + " WHERE " + comparisonColumn  + " = '" + comparativeWorth + "' GROUP BY " + allGroupByColumns + " ORDER BY " + toSortcolumnName  + " DESC;";
			check_error(); 
			connection_feedbackAll(sqlCommand.c_str());
		}
		else{
			//exception Handling
		}
	}

	void selectNull(std::string tableName, std::string columnName){

		std::string first = "SELECT * ";
		std::string sqlCommand = first + " FROM " + tableName + " WHERE " + columnName + " IS NULL" + " OR ' '; ";
		check_error();
		connection_feedbackAll(sqlCommand.c_str());

	}


