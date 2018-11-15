#include "tables.hpp"



	void createTable (bool primary_key, std::string tableName,std::vector<std::string> columns){

		//to notice (primary key and secondary key)
		std::string columnnamesAndDatatype;
		columnnamesAndDatatype=columns.at(0)+  " " + columns.at(1);

		if (primary_key == true){

			std::string sqlCommand = "CREATE TABLE " + tableName + " ( ID int NOT NULL  PRIMARY KEY AUTO_INCREMENT, " + columnnamesAndDatatype + " );";
			check_error();
			connection_query(sqlCommand.c_str());
		}
		else{
			std::string sqlCommand = "CREATE TABLE " + tableName + " ( " + columnnamesAndDatatype  + " );";
			check_error();
			connection_query(sqlCommand.c_str());
		}

		//insert the other Columns

		for(int i=2; i<columns.size()-1; i++){ //i=2 because the first column and datatype are already added

			if(i%2==0){
				setColumn(tableName,columns.at(i),columns.at(i+1));
			}
		}

		std::cout << tableName + " successfully created" << std::endl;

	}
	//need a bugfix, just screening the first value of the column
	void showTable (std::string tableName){

		std::string sqlCommand ="SELECT * FROM " + tableName;
		check_error();
		connection_feedbackAll(sqlCommand.c_str());

	}

	void deleteTable (std::string tableName){

		std::string sqlCommand = "DROP TABLE " + tableName ;
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << tableName + " successfully deleted" << std::endl;

	}

	void setColumn(std::string tableName, std::string ColumnName, std::string datatype){

		std::string sqlCommand =" ALTER TABLE " + tableName + " ADD " + ColumnName +  " " + datatype;
		check_error();
		connection_query(sqlCommand.c_str());

	}

	void modifierColumnName(std::string tableName, std::string oldColumnName, std::string newColumnName,std::string datatype){

		std::string sqlCommand= "ALTER TABLE " + tableName + " CHANGE " + oldColumnName + " " + newColumnName + " " + datatype;
		check_error();
		connection_query(sqlCommand.c_str());

	}

	void changeTheDatatype(std::string tableName, std::string columnName, std::string datatype){
		//has to be tested

		std::string sqlCommand="AlTER TABLE " + tableName + " MODIFY " + columnName + " " + datatype;
		check_error();
		connection_query(sqlCommand.c_str());

	}

	void getAllColumn(std::string tableName){

		std::string sqlCommand ="SHOW COLUMNS FROM " + tableName;
		check_error();
		connection_feedback(sqlCommand.c_str());

	}

	void showColumnTyp(std::string tableName,std::string datatype){

		std::string sqlCommand="SHOW COLUMNS FROM " + tableName + " WHERE TYPE LIKE '" + datatype + "%'";
		check_error();
		connection_feedbackAll(sqlCommand.c_str());

	}


	void deleteColumn(std::string tableName, std::string columnName){

		std::string sqlCommand= "ALTER TABLE " + tableName + " DROP " + columnName;
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << columnName + " successfully deleted" << std::endl;

	}

	void setSecondaryKey(std::string tableNameSecondary, std::string foreignKey, std::string id, std::string tableNamePrimary, std::string primaryKey, std::string constraint ){

		std::string sqlCommand ="ALTER TABLE " + tableNameSecondary + " ADD CONSTRAINT " +constraint + 
					" ADD FOREIGN KEY (" + foreignKey + ") REFERENCES " + tableNamePrimary + "( " + primaryKey + ");";
		check_error();
		connection_query(sqlCommand.c_str());
		std::cout << "Secondary key set on " + foreignKey  + "with the MasterKey on Table: " + tableNamePrimary + " and primary key " + primaryKey << std::endl;

        }

	void deleteSecondaryKey(std::string tableName, std::string constraint){
			//need a fix 
		std::string sqlCommand = "ALTER TABLE " + tableName + " DROP CONSTRAINT " + constraint + ";";
		check_error();
		connection_query (sql.Command.c_str());
		std::cout << "deleted the foreign key on the Field " + contraint << std::endl;

	}



//	void insertTable(){}
