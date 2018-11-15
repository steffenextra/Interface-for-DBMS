#include "selectionRequest.hpp"


void selectOneColumn(std::string tableName,std::string ColumnName,std::string selected_at){
    // SELECT * FROM Schüler WHERE Name = 'Müller'
        std::string sqlCommand ="SELECT * FROM " + tableName + " WHERE " + ColumnName + " = " + "'" + selected_at + "';";
    	check_error();
		connection_feedback(sqlCommand.c_str());
}
