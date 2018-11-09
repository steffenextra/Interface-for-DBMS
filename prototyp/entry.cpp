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

void setAllEntry(std::string tableName,std::vector<std::string> row)
{
	//INSERT INTO <Tabellenname>(<Spaltenname> [, weitere Spaltennamen])

	std::string columnName;
	std::string insertData;
	for(int i=0;i<row.size();i++){

		if(i%2==0){

			columnName=columnName + " " + row.at(i);

				if (i != row.size()-2){
					columnName+= ", ";
				}
		}
		else{
			insertData= insertData + " " + row.at(i);

				if (i != row.size()-1){
					insertData += ", ";
				}
		}
}

//	std::cout << columnName;
	std::string sqlCommand = "INSERT INTO " + tableName + "( " + columnName + " ) VALUES(" + insertData + ");";
	check_error();
	connection_query(sqlCommand.c_str());

}

void deleteEntry(std::string tableName, std::string columnName, std::string entry)
{
	std::string sqlCommand = "DELETE FROM " + tableName + " WHERE " + columnName + "= " + "'" + entry + "'";
	check_error();
	connection_query(sqlCommand.c_str());
	std::cout << entry + " successfully deleted" << std::endl;

}
