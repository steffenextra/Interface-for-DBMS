#include "selectionRequest.hpp"


/*
* Die Methode "sqlCommand" gibt einen vom Nutzer eingegebenen String(SQL Befehl) direkt weiter zum SQL Server,
* zu dem wird der Befehlstyp unterschieden. Es wird zwischen 3 Befehlstypen unterschieden: 
*	-Query -> simple Abfrage an den SQL Server
*	-feedback-> zeigt den Inhalt einer Spalte an
*	-feedbackAll-> zeigt die komplette Tabelle mit Spaltenbezeichnugen an
*	
*@param 
*	-sqlCommand-> enthält dem vom Nutzer eingegebenen String der später als SQL Befehl fungiert
*	-commandType-> enhält dem vom Nutzer gewählten Befehlstyp
*	
*@return 
*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
*
* @author Martin Meyer
*
* @version 1.0
*/
	
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

	/*
	* Die Methode "selectLike" ermöglicht eine Suche auf der Grundlage eines vorher definierten regulären Musters.
	*Muster:
	*	Findet einen Datzensatz der z.B mit einem "a" beginnt.
	*	Findet einen Datzensatz der z.B mit einem "a" endet.
	*	Findet einen Datensatz der z.b ein "or" an beliebiger Positon enhält. 
	*	Findet einen Datensatz der z.B ein "r" an der zweiten Position enthält.
	*	Findet einen Datensatz der z.B mit einem "a" beginnt und einem O anfängt. 
	*		->(Bedingung nur bei zwei Buchstaben erfüllt -> Fehlermeldung bei mehr als zwei Buchstaben)
	*	
	*Die Struktur des SQL Befehl:
	*	SELECT Spaltenname(n) FROM Tabellenname WHERE Spaltenname LIKE 'MUSTER'
	*	
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-columns-> Enhält die Liste der angezeigten Spalten
	*	-toSearchColumn > Enhält die zu suchende Spalte
	*	-pattern-> enhält das ausgewählte Muster
	*	-toSearch-> enhält das zu suchende Element
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

	void selectLike(std::string tableName,std::vector<std::string>columns,std::string toSearchColumn,std::string pattern,std::string toSearch){
		int i=0;
		std::string allColumns;

		while(i<columns.size()){
			if(columns.size()==1){
				allColumns +=  columns.at(i) + " ";
			}
			else{
				if (i != columns.size()-1){
					allColumns +=  columns.at(i) + ", ";
				}
				else{
					allColumns +=  columns.at(i) + " ";
				}
			}
			i++;
		}

		if(pattern=="start"){
			std::string sqlCommand="SELECT " + allColumns + " FROM " + tableName + " WHERE " + toSearchColumn + "  LIKE " + "'" + toSearch + "%';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(pattern=="end"){
			std::string sqlCommand="SELECT " + allColumns + " FROM " + tableName + " WHERE " + toSearchColumn + "  LIKE " + "'%" + toSearch + "';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(pattern=="anyPosition"){
			std::string sqlCommand="SELECT " + allColumns + " FROM " + tableName + " WHERE " + toSearchColumn + "  LIKE " + "'%" + toSearch + "%';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(pattern=="secondPosition"){
			std::string sqlCommand="SELECT " + allColumns + " FROM " + tableName + " WHERE " + toSearchColumn + "  LIKE " + "'_" + toSearch + "%';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(pattern=="startandEnd"){
			std::string sqlCommand="SELECT " + allColumns + " FROM " + tableName + " WHERE " + toSearchColumn + "  LIKE " + "'" + toSearch.at(0) + "%" + toSearch.at(1) + "';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}
		else{
			//exception handling
		}
	}

	/*
	* Die Methode "selectNotLike" ermöglicht eine Suche auf der Grundlage eines vorher definierten regulären Musters.
	*Muster:
	*	Findet einen Datzensatz der z.B nicht mit einem "a" beginnt.
	*	Findet einen Datzensatz der z.B nicht mit einem "a" endet.
	*	Findet einen Datensatz der z.b nicht ein "or" an beliebiger Positon enhält. 
	*	Findet einen Datensatz der z.B nicht ein "r" an der zweiten Position enthält.
	*	Findet einen Datensatz der z.B nicht mit einem "a" beginnt und einem O anfängt. 
	*		->(Bedingung nur bei zwei Buchstaben erfüllt -> Fehlermeldung bei mehr als zwei Buchstaben)
	*	
	*Die Struktur des SQL Befehl:
	*	SELECT Spaltenname(n) FROM Tabellenname WHERE Spaltenname NOT LIKE 'MUSTER'
	*	
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-columns-> Enhält die Liste der angezeigten Spalten
	*	-toSearchColumn > Enhält die zu suchende Spalte
	*	-pattern-> enhält das ausgewählte Muster
	*	-toSearch-> enhält das zu suchende Element
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

	void selectNotLike(std::string tableName,std::vector<std::string>columns,std::string toSearchColumn,std::string pattern,std::string toSearch){
		int i=0;
		std::string allColumns;

		while(i<columns.size()){
			if(columns.size()==1){
				allColumns +=  columns.at(i) + " ";
			}
			else{
				if (i != columns.size()-1){
					allColumns +=  columns.at(i) + ", ";
				}
				else{
					allColumns +=  columns.at(i) + " ";
				}
			}
			i++;
		}

		if(pattern=="start"){
			std::string sqlCommand="SELECT " + allColumns + " FROM " + tableName + " WHERE " + toSearchColumn + " NOT LIKE " + "'" + toSearch + "%';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(pattern=="end"){
			std::string sqlCommand="SELECT " + allColumns + " FROM " + tableName + " WHERE " + toSearchColumn + " NOT LIKE " + "'%" + toSearch + "';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(pattern=="anyPosition"){
			std::string sqlCommand="SELECT " + allColumns + " FROM " + tableName + " WHERE " + toSearchColumn + " NOT LIKE " + "'%" + toSearch + "%';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(pattern=="secondPosition"){
			std::string sqlCommand="SELECT " + allColumns + " FROM " + tableName + " WHERE " + toSearchColumn + " NOT LIKE " + "'_" + toSearch + "%';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(pattern=="startandEnd"){
			std::string sqlCommand="SELECT " + allColumns + " FROM " + tableName + " WHERE " + toSearchColumn + " NOT LIKE " + "'" + toSearch.at(0) + "%" + toSearch.at(1) + "';";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());
		}
		else{
			//exception handling
		}
	}
	/*
	* Die Methode "selectMinOrMax" ermittelt den höchsten bzw. niedrigsten Wert 
	* einer Tabellenspalte und liefert die Spalte mit einem Aliasnamen zurück.
	*	
	*Die Struktur der beiden SQL Befehlen:	
	*	SELECT MIN(Spaltenname1) AS Aliasspalte FROM Tabellenname 
	*	SELECT MAX(Spaltenname1) AS Aliasspalte FROM Tabellenname 
	*	
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-minOrMax-> Gibt an welcher Befehl ausgeführt werden soll.
	*	-minOrMaxColumn -> Gibt die Spalte an, die den Min/Max Wert enthalten soll
	*	-asColumn-> Enhält den gewählten Aliasnamen für die Min/Max Spalte
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/
	void selectMinOrMax(std::string tableName,std::string minOrMax,std::string minOrMaxColumn,std::string aliasColumn){

		if(minOrMax == "min" || minOrMax=="MIN"){
			std::string sqlCommand="SELECT MIN(" + minOrMaxColumn +")" + " AS " + aliasColumn + " FROM " +  tableName + ";";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());	
		}

		if(minOrMax == "MAX" || minOrMax=="MAX"){
			std::string sqlCommand="SELECT MAX(" + minOrMaxColumn +")" + " AS " + aliasColumn + " FROM " +  tableName + ";";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());	
		}

		else{
			check_error();
		}

	}

	/*
	* Die Methode "selectMinOrMaxWhere" ermittelt den höchsten bzw. niedrigsten Wert 
	* einer Tabellenspalte verknüpft mit einer Bedigungs Klausel und liefert die Aliasspalte zurück.
	*	
	*Die Struktur der beiden SQL Befehlen:	
	*	SELECT MIN(Spaltenname(n)) AS Aliasspaltennamen FROM Tabellennamen WHERE Bedingungsspalte ='Bedingungswert'; 
	*	SELECT MAX(Spaltenname(n)) AS Aliasspaltennamen FROM Tabellennamen WHERE Bedingungsspalte ='Bedingungswert';
	*	
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-minOrMax-> Gibt an welcher Befehl ausgeführt werden soll.
	*	-minOrMaxColumn > Gibt die Spalte an, die den Min/Max Wert enthalten soll
	*	-asColumn-> Enhält den gewählten Aliasnamen für die Min/Max Spalte
	*	-conditionColumn->Enhält den Namen der Bedingungsspalte
	*	-conditionValue->Enhält den Bedigungswert
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

	void selectMinOrMaxWhere(std::string tableName, std::string minOrMax,std::string minOrMaxColumn,std::string aliasColumn,std::string conditionColumn,std::string conditionValue){
		
		if(minOrMax == "min" || minOrMax=="MIN"){
			std::string sqlCommand="SELECT MIN(" + minOrMaxColumn +")" +" AS " + aliasColumn + " FROM " +  tableName + " WHERE " + conditionColumn  + " = '" + conditionValue + "'" + ";";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());	
		}

		if(minOrMax == "MAX" || minOrMax=="MAX"){
			std::string sqlCommand="SELECT MAX(" + minOrMaxColumn +")" +" AS " + aliasColumn + " FROM " +  tableName + " WHERE " + conditionColumn  + " = '" + conditionValue + "'" + ";";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());	
		}

		else{
			check_error();
		}
	}

	/*
	* Die Methode "selectLimitWhere" dient dazu eine vom Nutzer festgelegte Anzahl an Datensätzen abzufragen, verknüpft mit einer Bedingungs Klausel. 
	* Zudem wird es Aufsteigend bzw. Absteigend sotiert
	*	
	*Die Struktur der beiden SQL Befehlen:	
	*	SELECT Spaltenname(n) FROM Tabellennamen WHERE Bedigungsspalte = 'Bedingungswert' ORDER BY Sotierendespalte ASC;
	*	SELECT Spaltenname(n) FROM Tabellennamen WHERE Bedigungsspalte = 'Bedingungswert' ORDER BY Sotierendespalte DESC;
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-columns-> Enhält die Liste der angezeigten Spalten
	*	-limitNumber-> Anzahl der angezeigten Datensätze
	*	-conditionColumn->Enhält den Namen der Bedingungsspalte
	*	-conditionValue->Enhält den Bedigungswert
	*	-toSortColumnName-> Enhält die Spalte zu der sotiert werden soll
	*	-SortBy-> Gibt an ob es Aufsteigend bzw Absteigend sotoiert werden soll
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

	void selectLimitWhereOrderBy(std::string tableName,std::vector<std::string> columns,std::string limitNumber,std::string conditionColumn,std::string conditionValue,std::string toSortColumnName,std::string sortBy){
		
		int i=0;
		std::string allColumns;
		
		while(i<columns.size()){
			if(columns.size()==1){
				allColumns +=  columns.at(i) + " ";
			}
			else{
				if (i != columns.size()-1){
					allColumns +=  columns.at(i) + ", ";
				}
				else{
					allColumns +=  columns.at(i) + " ";
				}
			}
			i++;
		}

		if(sortBy == "ASC" || sortBy=="asc"){
			std::string sqlCommand="SELECT " + allColumns + " FROM " + tableName + " WHERE " + conditionColumn  + " = '" + conditionValue + "'" + "  ORDER BY " + toSortColumnName + " ASC " + " LIMIT " + limitNumber + ";";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());	
		}

		if(sortBy== "DESC" ||  sortBy=="desc"){
			std::string sqlCommand="SELECT " + allColumns + " FROM " + tableName + " WHERE " + conditionColumn  + " = '" + conditionValue + "'" + "  ORDER BY " + toSortColumnName + " ASC " + " LIMIT " + limitNumber + ";";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());	
		}

		else{
			//Exception-Handling
		}
	}

	/*
	* Mithilfe der "selectOneColumn" Methode werden die SQL Abfragen nur bestimmter Datensätze in einer bestimmten Spalten abgefragt. 
	* Es wird nur die Spalte angzeigt, wo der Datensatz verglichen worden ist.
	*	
	*Die Struktur der beiden SQL Befehlen:	
	*SELECT * FROM Tabellennamen WHERE Bedigungsspalte ='Bedingungswert';
	*
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-conditionColumn->Enhält den Namen der Bedingungsspalte
	*	-conditionValue->Enhält den Bedingungswert
	*
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

	void selectWhereOneColumn(std::string tableName,std::string conditionColumn,std::string conditionValue){
		
		std::string sqlCommand ="SELECT * FROM " + tableName + " WHERE " + conditionColumn + " = " + "'" + conditionValue + "';";
		check_error();
		connection_feedback(sqlCommand.c_str());
	}

	/*
	* Mithilfe der "selectWhere" Methode werden die SQL Abfragen nur bestimmter Datensätze in einer bestimmten Spalten abgefragt.
	* Es werden die Spalten angezeigt, die der Nutzer in dem Vektor übergeben hat.
	*	
	*Die Struktur der beiden SQL Befehlen:	
	*SELECT Spaltenname(n) FROM Tabellennamen WHERE Bedigungsspalte ='Bedingungswert';
	*
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-columns-> Enhält die Liste der angezeigten Spalten
	*	-conditionColumn->Enhält den Namen der Bedingungsspalte
	*	-conditionValue->Enhält den Bedingungswert
	*
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

	void selectWhere(std::string tableName,std::vector<std::string> columns,std::string conditionColumn,std::string conditionValue){
	
		int i =0;
		std::string allColumns;
		
		while(i<columns.size()){
			if(columns.size()==1){
				allColumns +=  columns.at(i) + " ";
			}
			else{
				if (i != columns.size()-1){
					allColumns +=  columns.at(i) + ", ";
				}
				else{
					allColumns +=  columns.at(i) + " ";
				}
			}
			i++;
		}

		std::string sqlCommand ="SELECT " + allColumns + " FROM " + tableName + " WHERE " + conditionColumn  + " = '" + conditionValue + "';";
		check_error();
		connection_feedbackAll(sqlCommand.c_str());		
	}
	/*
	* Mithilfe der "selectBool" Methode werden die SQL Abfragen nur bestimmter Datensätze in einer bestimmten Spalten abgefragt.
	* Zudem kann man ,dank der Funktion mit mehrere Bool-Bedingungen verknüpfen. 
	* Es werden zwei Bedignungsspalten Vektoren, zwei BedingungswertVektoren sowieo ein Vektor der die Operationen enhält übergeben.  
	* Ein Schleifendurchlauf holt sich die zwei Namen der Bedingungsspalten sowie die beiden Bedingungswerte dazu wird dann der boolische Operator hinzugefügt.
	* Die beiden Conditionsvektoren müssen gleich groß sein.
	* Es werden die Spalten angezeigt, die der Nutzer in dem Vektor übergeben hat.
	*	
	*Die Struktur der beiden SQL Befehlen:	
	*SELECT Spaltenname(n) FROM Tabellennamen WHERE Bedigungsspalte ='Bedingungswert' boolischer Operator(And,Or,Xor) Bedingungsspalte2 ='Bedingungswert2'...;
	*
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-columns-> Enhält die Liste der angezeigten Spalten
	*	-conditionColumn->Enhält den Namen der Bedingungsspalte
	*	-conditionValue->Enhält den Bedingungswert
	*	-conditionColumn2->Enhält den Namen der zweiten zu vergleichnen Bedingungsspalte
	*	-conditionValue2->Enhält den zweiten zu vergleichnenen Bedingungswert
	*	-operators-> Enhält die Liste der boolischen Ausdrücke
	*
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/
	void selectBool(std::string tableName,std::vector<std::string> columns, std::vector<std::string>conditions,std::vector<std::string>conditionValue,std::vector<std::string> conditions2,std::vector<std::string>conditionValue2,std::vector<std::string>operators){
			
			int i=0;
			std::string allColumns;
			std::string conditionOperatorString;
			
		while(i<columns.size()){
			if(columns.size()==1){
				allColumns +=  columns.at(i) + " ";
			}
			else{
				if (i != columns.size()-1){
					allColumns +=  columns.at(i) + ", ";
				}
				else{
					allColumns +=  columns.at(i) + " ";
				}
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

	void selectWhereOrderBy(std::string tableName,std::vector<std::string> columns,std::string conditionColumn,std::string conditionValue,std::string toSortcolumnName,std::string sortBy){

		int i =0;
		std::string allColumns;

		while(i<columns.size()){
			if(columns.size()==1){
				allColumns +=  columns.at(i) + " ";
			}
			else{
				if (i != columns.size()-1){
					allColumns +=  columns.at(i) + ", ";
				}
				else{
					allColumns +=  columns.at(i) + " ";
				}
			}
			i++;
		}

		if(sortBy == "ASC" || sortBy=="asc"){
			std::string sqlCommand ="SELECT " + allColumns + " FROM " + tableName + " WHERE " + conditionColumn  + " = '" + conditionValue + "'" + " ORDER BY " + toSortcolumnName  + " ASC;";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());	
		}

		if(sortBy== "DESC" ||  sortBy=="desc"){
			std::string sqlCommand ="SELECT " + allColumns + " FROM " + tableName + " WHERE " + conditionColumn  + " = '" + conditionValue + "'" + " ORDER BY " + toSortcolumnName  + " DESC;";
			check_error();
			connection_feedbackAll(sqlCommand.c_str());	
		}

		else{
			//Exception_Handling
		}
	}

	void selectSortTable(std::string tableName,std::string toSortColumnName,std::string sortBy){

		if(sortBy == "ASC" || sortBy=="asc"){
			std::string sqlCommand = "SELECT * FROM " + tableName + " ORDER BY " + toSortColumnName  + " ASC;";
			check_error();
			connection_feedback(sqlCommand.c_str());

	}

		else if(sortBy== "DESC" ||  sortBy=="desc"){
			std::string sqlCommand = "SELECT * FROM " + tableName + " ORDER BY " + toSortColumnName + " DESC;";
			check_error();
			connection_feedback(sqlCommand.c_str());
		}
		else{
			check_error();
		}
	}

	void selectCount(std::string tableName,std::string countColumn,std::string aliasColumnName){
		std::string sqlCommand = "SELECT COUNT(" + countColumn + ") AS " + aliasColumnName + " FROM " + tableName + ";";
		check_error();
		connection_feedbackAll(sqlCommand.c_str());
	}

	void selectDistinct(std::string tableName,std::vector<std::string> columns){
		int i =0;
		std::string allColumns;


		while(i<columns.size()){
			if(columns.size()==1){
				allColumns +=  columns.at(i) + " ";
			}
			else{
				if (i != columns.size()-1){
					allColumns +=  columns.at(i) + ", ";
				}
				else{
					allColumns +=  columns.at(i) + " ";
				}
			}
			i++;
		}

		std::string sqlCommand = "SELECT DISTINCT " + allColumns + " FROM " + tableName + ";";
		check_error();
		connection_feedbackAll(sqlCommand.c_str());
	}

	void selectCountDistinct(std::string tableName,std::string countColumn){

		std::string sqlCommand = "SELECT COUNT(DISTINCT " + countColumn + ") FROM " + tableName + ";";
		check_error();
		connection_feedback(sqlCommand.c_str());
	}

	void selectAverageSum(std::string tableName, std::string columnName){

		std::string sqlCommand = "SELECT AVG(" + columnName + ") FROM " + tableName;
		check_error();
		connection_feedback(sqlCommand.c_str());

	}

	void selectSum(std::string tableName, std::string columnName, std::string aliasColumnName){

		std::string sqlCommand = "SELECT SUM(" + columnName + ") AS " + aliasColumnName+ " FROM " + tableName;
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
			}
			else{
				sqlCommand  += "SELECT " + columnName.at(i) + " FROM " + tableName.at(i) + " UNION ";
			}
		}

		check_error();
		connection_feedbackAll(sqlCommand.c_str());

	}

	void selectIn(std::string tableName,std::vector<std::string>columns,std::string searchInColumn,std::vector<std::string>conditionValue){
		
		int i=0;
		std::string allColumns;
		std::string comparativValues;

		while(i<columns.size()){
			if(columns.size()==1){
				allColumns +=  columns.at(i) + " ";
			}
			else{
				if (i != columns.size()-1){
					allColumns +=  columns.at(i) + ", ";
				}
				else{
					allColumns +=  columns.at(i) + " ";
				}
			}
			i++;
		}
		
		i=0;

		while(i<conditionValue.size()){
			if(comparativValues.size()==1){
				comparativValues += "'" + conditionValue.at(i) + "'" + " ";
			}
			else{
				if (i != comparativValues.size()-1){
					comparativValues +=  "'" + conditionValue.at(i) + "'" + ", ";
				}
				else{
					comparativValues += "'" + conditionValue.at(i) + "'" + " ";
				}
			}
			i++;
		}

		std::string sqlCommand = "SELECT " + allColumns + " FROM " + tableName + " WHERE " + searchInColumn + " IN " + " (" + comparativValues + ");";
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
			if(columns.size()==1){
				columnAlias +=  columns.at(i) + " AS " + aliases.at(i) + " ";
			}
			else{
				if (i != columns.size()-1){
					columnAlias +=  columns.at(i) + " AS " + aliases.at(i) + ", ";
				}
				else{
					columnAlias +=  columns.at(i) + " AS " + aliases.at(i) + " ";
				}
			}
			i+=2;
		}

		std::string sqlCommand ="SELECT " + columnAlias + " FROM " + tableName + ";";
		check_error();
		connection_feedbackAll(sqlCommand.c_str());
	}

	void selectTableAlias(std::string tableName,std::vector<std::string>columns,std::string aliasTableName){
		std::string columnAlias;
		int i =0;

		while(i<columns.size()){
			if(columns.size()==1){
				columnAlias +=  columns.at(i) + " ";
			}
			else{
				if (i != columns.size()-1){
					columnAlias +=  columns.at(i) + ", ";
				}
				else{
					columnAlias +=  columns.at(i) + " ";
				}
			}
			i++;
		}
	
		std::string sqlCommand ="SELECT " + columnAlias + " FROM " + tableName + " AS " + aliasTableName +";";
		check_error();
		connection_feedbackAll(sqlCommand.c_str());
	}

	void selectGroupBy(std::string tableName, std::vector<std::string>columns,std::string conditionColumn,std::string conditionValue,std::vector<std::string>groupByColumns){
		int i=0;
		std::string allColumns;
		std::string allGroupByColumns;
		
		while(i<columns.size()){
			if(columns.size()==1){
				allColumns +=  columns.at(i) + " ";
			}
			else{
				if (i != columns.size()-1){
					allColumns +=  columns.at(i) + ", ";
				}
				else{
					allColumns +=  columns.at(i) + " ";
				}
			}
			i++;
		}
		i=0;
		
		while(i<groupByColumns.size()){
			if(groupByColumns.size()==1){
				allGroupByColumns +=  groupByColumns.at(i) + " ";
			}
			else{
				if (i != columns.size()-1){
					allGroupByColumns +=  groupByColumns.at(i) + ", ";
				}
				else{
					allGroupByColumns +=  groupByColumns.at(i) + " ";
				}

			}
			i++;
		}

		std::string sqlCommand ="SELECT " + allColumns + " FROM " + tableName + " WHERE " + conditionColumn  + " = '" + conditionValue + "' GROUP BY " + allGroupByColumns + ";";
		check_error(); 
		connection_feedbackAll(sqlCommand.c_str());
	}

	void selectGroupByOrderBy(std::string tableName, std::vector<std::string>columns,std::string conditionColumn,std::string conditionValue,std::vector<std::string>groupByColumns,std::string toSortcolumnName,std::string sortBy){
		int i=0;
		std::string allColumns;
		std::string allGroupByColumns;
		
		while(i<columns.size()){
			if(columns.size()==1){
				allColumns +=  columns.at(i) + " ";
			}
			else{
				if (i != columns.size()-1){
					allColumns +=  columns.at(i) + ", ";
				}
				else{
					allColumns +=  columns.at(i) + " ";
				}
			}
			i++;
		}
		i=0;
		
		while(i<groupByColumns.size()){
			if(groupByColumns.size()==1){
				allGroupByColumns +=  groupByColumns.at(i) + " ";
			}
			else{
				if (i != columns.size()-1){
					allGroupByColumns +=  groupByColumns.at(i) + ", ";
				}
				else{
					allGroupByColumns +=  groupByColumns.at(i) + " ";
				}

			}
			i++;
		}

		if(sortBy=="ASC" || sortBy=="asc"){
			std::string sqlCommand ="SELECT " + allColumns + " FROM " + tableName + " WHERE " + conditionColumn  + " = '" + conditionValue + "' GROUP BY " + allGroupByColumns +  " ORDER BY " + toSortcolumnName  + " ASC;";
			check_error(); 
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(sortBy=="DESC" || sortBy=="desc"){
			std::string sqlCommand ="SELECT " + allColumns + " FROM " + tableName + " WHERE " + conditionColumn  + " = '" + conditionValue + "' GROUP BY " + allGroupByColumns + " ORDER BY " + toSortcolumnName  + " DESC;";
			check_error(); 
			connection_feedbackAll(sqlCommand.c_str());
		}
		else{
			//exception Handling
		}
	}
	void selectCountGroupByOrderBy(std::string tableName, std::string countColumn,std::vector<std::string>columns,std::string conditionColumn,std::string conditionValue,std::vector<std::string>groupByColumns,std::string sortBy){
		int i=0;
		std::string allColumns;
		std::string allGroupByColumns;
		while(i<columns.size()){
			if(columns.size()==1){
				allColumns +=  columns.at(i) + " ";
			}
			else{
				if (i != columns.size()-1){
					allColumns +=  columns.at(i) + ", ";
				}
				else{
					allColumns +=  columns.at(i) + " ";
				}
			}
			i++;
		}

		i=0;
		
		while(i<groupByColumns.size()){
			if(groupByColumns.size()==1){
				allGroupByColumns +=  groupByColumns.at(i) + " ";
			}
			else{
				if (i != columns.size()-1){
					allGroupByColumns +=  groupByColumns.at(i) + " ";
				}
				else{
					allGroupByColumns +=  groupByColumns.at(i) + ", ";
				}

			}
			i++;
		}


		if(sortBy=="ASC" || sortBy=="asc"){
			std::string sqlCommand ="SELECT COUNT(" + countColumn +")," + allColumns + " FROM " + tableName + " WHERE " + conditionColumn  + " = '" + conditionValue + "' GROUP BY " + allGroupByColumns +  " ORDER BY COUNT(" + countColumn +") ASC;";
			check_error(); 
			connection_feedbackAll(sqlCommand.c_str());
		}

		if(sortBy=="DESC" || sortBy=="desc"){
			std::string sqlCommand ="SELECT COUNT(" + countColumn +")," + allColumns + " FROM " + tableName + " WHERE " + conditionColumn  + " = '" + conditionValue + "' GROUP BY " + allGroupByColumns +  " ORDER BY COUNT(" + countColumn +") DESC;";
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


