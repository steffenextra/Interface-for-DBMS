#include "selectionRequest.hpp"


void selectOneColumn(std::string tableName,std::string ColumnName,std::string selected_at,std::string sort_by){
    // SELECT * FROM Schüler WHERE Name = 'Müller' ORDER BY ColumnName ASC ||DESC
    if(sort_by=="ASC" || sort_by=="asc"){
        std::string sqlCommand ="SELECT * FROM " + tableName + " WHERE " + ColumnName + " = " + "'" + selected_at + "'" + "ORDER BY" + ColumnName + " ASC;";
		check_error();
		connection_feedback(sqlCommand.c_str());
    }

    if(sort_by=="DESC" || sort_by=="desc"){
        std::string sqlCommand ="SELECT * FROM " + tableName + " WHERE " + ColumnName + " = " + "'" + selected_at + "'" + "ORDER BY" + ColumnName + " DESC;";
    	check_error();
		connection_feedback(sqlCommand.c_str());
    }

    else{
        std::string sqlCommand ="SELECT * FROM " + tableName + " WHERE " + ColumnName + " = " + "'" + selected_at + "';";
    	check_error();
		connection_feedback(sqlCommand.c_str());
    }
}
