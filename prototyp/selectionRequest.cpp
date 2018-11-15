#include "selectionRequest.hpp"


void selectOneColumn(std::string tableName,std::string ColumnName,std::string selected_at){
    // SELECT * FROM Schüler WHERE Name = 'Müller'
        std::string sqlCommand ="SELECT * FROM " + tableName + " WHERE " + ColumnName + " = " + "'" + selected_at + "';";
    	check_error();
		connection_feedback(sqlCommand.c_str());
}

void sortTable(std::string tableName,std::string ColumnName,std::string sort_by){
   //SELECT * FROM tabellen_name ORDER BY spalten_name ASC|DESC//
    if(sort_by == "ASC" || sort_by=="asc"){
        std::string sqlCommand = "SELECT * FROM " + tableName + " ORDER BY " + ColumnName  + " ASC;";
        check_error();
	    connection_feedback(sqlCommand.c_str());
    }  

    if(sort_by== "DESC" ||  sort_by=="desc"){
        std::string sqlCommand = "SELECT * FROM " + tableName + " ORDER BY " + ColumnName  + " DESC;";
        check_error();
	    connection_feedback(sqlCommand.c_str());
    }
    //hallo
    else{
        check_error();
    }
}
