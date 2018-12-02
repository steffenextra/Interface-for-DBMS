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
	* einer Tabellenspalte verknüpft mit einer Bedigungs Klausel und liefert die Alias-Spalte zurück.
	*	
	*Die Struktur der beiden SQL Befehlen:	
	*	SELECT MIN(Spaltenname(n)) AS Aliasspaltennamen FROM Tabellennamen WHERE Bedingungsspalte ='Bedingungswert'; 
	*	SELECT MAX(Spaltenname(n)) AS Aliasspaltennamen FROM Tabellennamen WHERE Bedingungsspalte ='Bedingungswert';
	*	
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-minOrMax-> Gibt an welcher Befehl ausgeführt werden soll.
	*	-minOrMaxColumn > Gibt die Spalte an, die den Min/Max Wert enthalten soll
	*	-aliasColumn-> Enhält den gewählten Aliasnamen für die Min/Max Spalte
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
	*Die Struktur des SQL Befehl:	
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
	*Die Struktur des SQL Befehl:	
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
	*Die Struktur des SQL Befehl:	
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
	*Die Struktur des SQL Befehl:	
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
	/*
	* Mithilfe der "selectWhereOrderBy" Methode werden die SQL Abfragen nur bestimmter Datensätze in einer bestimmten Spalten abgefragt.
	* Es werden die Spalten angezeigt, die der Nutzer in dem Vektor übergeben hat. Zudem wird es Aufsteigend oder Absteigend sortiert.
	*	
	*Die Struktur der beiden SQL Befehlen:	
	*SELECT Spaltenname(n) FROM Tabellennamen WHERE Bedigungsspalte ='Bedingungswert' ORDER BY ASC;
	*SELECT Spaltenname(n) FROM Tabellennamen WHERE Bedigungsspalte ='Bedingungswert' ORDER BY DESC;
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-columns-> Enhält die Liste der angezeigten Spalten
	*	-conditionColumn->Enhält den Namen der Bedingungsspalte
	*	-conditionValue->Enhält den Bedingungswert
	*	-toSortColumnName-> Enhält die Spalte zu der sotiert werden soll
	*	-SortBy-> Gibt an ob es Aufsteigend bzw Absteigend sotoiert werden soll
	*
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

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

		/*
	* Mithilfe der "selectSortTable" Methode wird eine angebene Tabelle nach einer angebenen Spalte auf- bzw. -Absteigend sortiert.
	* Die ganze Tabelle wird ausgebenen.
	*	
	*Die Struktur der beiden SQL Befehlen:	
	*SELECT Spaltenname(n) FROM Tabellennamen ORDER BY ASC;
	*SELECT Spaltenname(n) FROM Tabellennamen ORDER BY DESC;
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-toSortColumnName-> Enhält die Spalte zu der sotiert werden soll
	*	-SortBy-> Gibt an ob es Aufsteigend bzw Absteigend sotoiert werden soll
	*
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

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
		/*
	* Die selectCount Methode zählt(COUNT) die Anzahl von ausgewählten Datensätzen.
	* Es werden alle Datensätze gezählt, deren Wert nicht NULL ist. 
	* Zudem wird die zurück gegebene Spalte mit einem vom Nutzer bestimmten Aliasnamen versehen.
	*	
	*Die Struktur des SQL Befehl:	
	* SELECT COUNT(Spaltenname) AS Alias-Spaltennamen FROM Tabellennamen;
	*
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-countColumn-> Enhält die zu zählende Spalte
	*	-aliasColumn-> Enhält den gewählten Aliasnamen für die zurückgegebene Spalte
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

	void selectCount(std::string tableName,std::string countColumn,std::string aliasColumnName){
		std::string sqlCommand = "SELECT COUNT(" + countColumn + ") AS " + aliasColumnName + " FROM " + tableName + ";";
		check_error();
		connection_feedbackAll(sqlCommand.c_str());
	}

	/*
	* Mithilfe der "selectDistinct" Methode werden Redundanzen, die in einer Tabellen auftreten können, 
	* eliminiert und die Werte werden jeweils nur einmal angezeigt.
	*	
	*Die Struktur des SQL Befehl:	
	* SELECT DISTINCT Spaltenname(n) FROM Tabellenname
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-columns-> Enhält die Liste der angezeigten Spalten
	*
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

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
	/*
	* Mithilfe der "selectCountDistinct" Methode werden Redundanzen, die in einer Tabellen auftreten können, 
	* eliminiert und die Werte werden jeweils nur einmal angezeigt und anschließend werden diese Datensätze gezählt.
	*	
	*Die Struktur des SQL Befehls:	
	* SELECT Count(DISTINCT Spaltenname) FROM Tabellenname;
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-countColumn-> Enhält die zu zählende Spalte
	*
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/
	

	void selectCountDistinct(std::string tableName,std::string countColumn){

		std::string sqlCommand = "SELECT COUNT(DISTINCT " + countColumn + ") FROM " + tableName + ";";
		check_error();
		connection_feedback(sqlCommand.c_str());
	}
	/*
	* Die "selectAverageSum" Methode berechnet den Durchschnittswert aller Werte, 
	* die in einer Spalte mittels einer Select-Abfrage ermitteln wurden.
	*	
	*Die Struktur des SQL Befehl:	
	* SELECT AVG(Spaltenname) FROM Tabellennamen
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-columnName-> Enhält den Spaltennamen von der, der Durchschnitt berechnet werden soll
	*
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

	void selectAverageSum(std::string tableName, std::string columnName){

		std::string sqlCommand = "SELECT AVG(" + columnName + ") FROM " + tableName;
		check_error();
		connection_feedback(sqlCommand.c_str());

	}
	/*
	* Die "selectSum" Methode summiert die Werte einer Tabellenspalte und liefert sie zurück. 
	* Zudem wird die zurück gegebene Spalte mit einem vom Nutzer bestimmten Aliasnamen versehen.
	* 
	*	
	*Die Struktur des SQL Befehl:	
	* SELECT SUM(Spaltenname) AS Alias-Spaltennamen FROM Tabellennamen
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-columnName-> Enhält den Spaltennamen von der, die Summe berechnet werden soll
	*	-aliasColumnName-> Enhält den Aliasnamen
	*
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

	void selectSum(std::string tableName, std::string columnName, std::string aliasColumnName){

		std::string sqlCommand = "SELECT SUM(" + columnName + ") AS " + aliasColumnName+ " FROM " + tableName;
		check_error();
		connection_feedbackAll(sqlCommand.c_str());

	}
	/*
	* Die "unionSelect" Methode vereinigt die Ergebnisse zweier Abfragen. 
	* 
	* 
	*	
	*Die Struktur des SQL Befehl:	
	* SELECT Spaltenname(n) FROM Tabellenname(n) UNION...
	*
	*@param 
	*	-tableName-> Enhält die Liste der Tabellennamen
	*	-columnName-> Enhält die Liste der Spaltennamen
	*
	*
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

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
		/*
	* Die "selectIn" Methode kann mehrere Abfrageergebnisse in einer SQL-Anweisung zu bündeln. 
	* Damit kann der IN Operator leicht mehrere OR Operatoren ersetzen und vereinfacht damit die Struktur von komplexen OR-Bedingungen.
	* 
	* 
	*	
	*Die Struktur des SQL Befehl:	
	* SELECT Spaltenname(n) FROM Tabellenname WHERE Spaltenname IN ('Wert1','Wert2')
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-columns-> Enhält die Liste der angezeigten Spalten
	*	-searchInColumn-> Enhält den Spaltennamen in der die Werte vergleicht werden
	-	-Enhält eine Liste der zu vergleichenden Werten
	*
	*
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

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
	/*
	* Die "selectBetween" Methode behinhlatet die SQL-Where Bedingungen mit einem eingeschränkten bestimmten Bereich eines Abfrageergebnisses.
	* 
	* 
	*	
	*Die Struktur des SQL Befehl:	
	* SELECT Spaltenname FROM Tabellenname WHERE Spaltenname BETWEEN 'DATUM1' AND 'DATUM2'
	*
	*@param 
	*	conditionString->
	*	conditionStringTwo->
	*	tablenName->Enhält die ausgewählte Tabelle
	*	conditionColumn->
	*	conditionColumn2->
	*	contition->
	*	condition2->
	*
	*
	*		
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

	void selectBetween(std::string conditionString, std::string conditionStringTwo, std::string tableName, std::string conditionColumn, std::string conditionColumnTwo, std::string condition, std::string conditionTwo){

		std::string first = "SELECT * ";
		std::string sqlCommand = first + " FROM " + tableName + " WHERE " + conditionColumn + " " + conditionString + " " + condition
                                             + " AND " + conditionColumnTwo + " " + conditionString + " " + conditionTwo;
		check_error();
		connection_feedbackAll(sqlCommand.c_str());

	}
	/*
	* Die "selectColumnsAlias" Methode kann für übergebene Spalte(n) einen ausgwählten Alias-Spaltenname(n) hinzufügen
	*	Zuordnung: Spaltenname(i) = Alias-Spaltennamen(i)
	* 
	* 
	*	
	*Die Struktur des SQL Befehl:	
	* SELECT Spaltennamen AS AliasSpaltennamen FROM Tabellennamen;
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-columns-> Enhält die Liste der zu anzeigenen & zu unbennenen Spalten
	*	-aliases-> Enhält die Liste mit den Aliasnamen 
	*	
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

	void selectColumnsAlias(std::string tableName,std::vector<std::string>columns,std::vector<std::string>aliases){
		
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
	/*
	* Die "selectTableAlias" Methode kann der übergebnenen Tabelle einen Alias-Tabellennamen zuweisen.
	* 
	* 
	*	
	*Die Struktur des SQL Befehl:	
	* SELECT Spaltennamen AS AliasSpaltennamen FROM Tabellennamen AS Alias-Tabellennamen;
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-columns-> Enhält die Liste der zu anzeigenen Spalten
	*	-aliasTabellennamen-> Enhält den Alias-Tabellennamen 
	*	
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

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

	 /*
	* Mithilfe der "selectGroupBy" Methode ist es möglich eine Ergebnismenge zu gruppieren
	* 
	* 
	*	
	*Die Struktur des SQL Befehl:	
	* SELECT Spaltenname(n) FROM Tabellenname [WHERE Bedingung] GROUP BY Spaltenname;
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-columns-> Enhält die Liste der zu anzeigenen & zu unbennenen Spalten
	*	-conditionColumn->Enhält den Namen der Bedingungsspalte
	*	-conditionValue->Enhält den Bedingungswert
	*	-groupByColumns-> Enhält die Liste der zu gruppierenden Spaltennamen
	*	
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/
	

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
	 /*
	* Mithilfe der "selectGroupByOrderBy" Methode ist es möglich eine Ergebnismenge zu gruppieren und diese auf- bzw. Absteigend zu sotieren.
	* 
	* 
	*	
	*Die Struktur der beiden SQL Befehle:	
	* SELECT Spaltenname(n) FROM Tabellenname [WHERE Bedingung] GROUP BY Spaltenname ORDER BY ASC;
	* SELECT Spaltenname(n) FROM Tabellenname [WHERE Bedingung] GROUP BY Spaltenname ORDER BY DESC;
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-columns-> Enhält die Liste der zu anzeigenen & zu unbennenen Spalten
	*	-conditionColumn->Enhält den Namen der Bedingungsspalte
	*	-conditionValue->Enhält den Bedingungswert
	*	-groupByColumns-> Enhält die Liste der zu gruppierenden Spaltennamen
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
	 /*
	* Mithilfe der "selectCountGroupByOrderBy" Methode ist es möglich die Ergebnismenge zu gruppieren. 
	* Das Count zählt die Anzahl der gruppierten Ergebnismengen. Es werden alle Datensätze gezählt, deren Wert nicht NULL ist
	* Zudem kann der Datensatz anschließend auf- bzw. Absteigend zu sotieren werden
	* 
	*	
	*Die Struktur der beiden SQL Befehle:	
	* SELECT COUNT(zu zählende Spalte) Spaltenname(n) FROM Tabellenname [WHERE Bedingung] GROUP BY Spaltenname ORDER BY ASC;
	* SELECT COUNT(zu zählende Spalte) Spaltenname(n) FROM Tabellenname [WHERE Bedingung] GROUP BY Spaltenname ORDER BY DESC;
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-countColumn-> Enhält die zu zählende Spalte
	*	-columns-> Enhält die Liste der zu anzeigenen & zu unbennenen Spalten
	*	-conditionColumn->Enhält den Namen der Bedingungsspalte
	*	-conditionValue->Enhält den Bedingungswert
	*	-groupByColumns-> Enhält die Liste der zu gruppierenden Spaltennamen
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
		 /*
	* Die selectNull Methode prüft eine Spalte auf den Wert NULL
	* 
	*	
	* Die Struktur des SQL Befehl:	
	* SELECT * FROM Tabellennamen WHERE Spaltenname IS NULL OR ' ';
	* 
	*
	*@param 
	*	-tableName-> Enhält den Tabellennamen
	*	-ColumnName->Enhält den Namen der Bedingungsspalte
	*	
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

	void selectNull(std::string tableName, std::string columnName){

		std::string first = "SELECT * ";
		std::string sqlCommand = first + " FROM " + tableName + " WHERE " + columnName + " IS NULL" + " OR ' '; ";
		check_error();
		connection_feedbackAll(sqlCommand.c_str());

	}
	/*Mithilfe der "selectInnerJoin" Methode wird eine neue Ergebnistabelle erstellt
	* durch Kombinieren von Spaltenwerten von zwei Tabellen (firstTable und secondTable) basierend auf dem Join-Prädikat. 
	* Die Abfrage vergleicht jede Zeile von table1 mit jeder Zeile von table2, um alle Zeilenpaare zu finden, die das Verknüpfungsprädikat erfüllen. 
	* Wenn das Join-Prädikat erfüllt ist, werden Spaltenwerte für jedes übereinstimmende Paar von Zeilen von A und B in einer Ergebniszeile zusammengefasst.
	* Das Schlüsselwort INNER JOIN wählt Datensätze mit übereinstimmenden Werten in beiden Tabellen aus.
	*	
	* Die Struktur des SQL Befehl:	
	* select <Auswahl> FROM TabelleA INNER JOIN TabelleB B ON A.ID = B.ID	 
	*
	*@param 
	*	-fristTableName-> Enhält den Tabellennamen der ersten Tabelle
	*	-columnIDTableOne-> enhält die zu vergleichene Spalte der ersten Tabelle
	*	-columnsTableOne-> enhält die Liste der Spalten die aus der ersten Tabelle angezeigt werden sollen
	*	-secondTableName-> Enhält den Tabellennamen der zweiten Tabelle
	*	-columnsTableTwo-> enhält die Liste der Spalten die aus der zweiten Tabelle angezeigt werden sollen
	*	
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

	void selectInnerJoin(std::string firstTableName, std::string columnIDTableOne,std:: vector <std::string> columnsTableOne,std::string secondTableName,std::vector <std::string> columnsTableTwo){
		int i=0;
		std::string allColumns;

		while(i<columnsTableOne.size()){
			allColumns +=  firstTableName + "." + columnsTableOne.at(i) + ", ";
			i++;
			}
		
		i=0;

		while(i<columnsTableTwo.size()){
			if(columnsTableTwo.size()==1){
				allColumns +=  columnsTableTwo.at(i) + " ";
			}
			else{
				if (i != columnsTableTwo.size()-1){
					allColumns += secondTableName + "." + columnsTableOne.at(i) + ", ";
				}
				else{
					allColumns +=  secondTableName + "." + columnsTableTwo.at(i) + " ";
				}
			}
			i++;
		}

		std::string sqlCommand = "SELECT " + allColumns + " FROM " + firstTableName + " INNER JOIN " + secondTableName + " ON " + secondTableName + "."  + columnIDTableOne + "=" + firstTableName + "." + columnIDTableOne + ";"; 	 
		std::cout << sqlCommand << std::endl;
		check_error();
		connection_feedbackAll(sqlCommand.c_str());
	}
	/*Mithilfe der "selectLeftJoin" Methode wird eine neue Ergebnistabelle erstellt
	* durch Kombinieren von Spaltenwerten von zwei Tabellen (firstTable und secondTable) basierend auf dem Join-Prädikat. 
	* Die Abfrage vergleicht jede Zeile von table1 mit jeder Zeile von table2, um alle Zeilenpaare zu finden, die das Verknüpfungsprädikat erfüllen. 
	* Wenn das Join-Prädikat erfüllt ist, werden Spaltenwerte für jedes übereinstimmende Paar von Zeilen von A und B in einer Ergebniszeile zusammengefasst.
	* Das Schlüsselwort LEFT JOIN gibt alle Datensätze der linken Tabelle (firstTable) und die übereinstimmenden Datensätze der rechten Tabelle (secondTable) zurück. 
	* Das Ergebnis ist NULL von rechts, wenn keine Übereinstimmung vorliegt.
	*	
	* Die Struktur des SQL Befehl:	
	* select <Auswahl> FROM TabelleA LEFT JOIN TabelleB B ON A.ID = B.ID	 
	*
	*@param 
	*	-fristTableName-> Enhält den Tabellennamen der ersten Tabelle
	*	-columnIDTableOne-> enhält die zu vergleichene Spalte der ersten Tabelle
	*	-columnsTableOne-> enhält die Liste der Spalten die aus der ersten Tabelle angezeigt werden sollen
	*	-secondTableName-> Enhält den Tabellennamen der zweiten Tabelle
	*	-columnsTableTwo-> enhält die Liste der Spalten die aus der zweiten Tabelle angezeigt werden sollen
	*	
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/
	void selectLeftJoin(std::string firstTableName, std::string columnIDTableOne,std:: vector <std::string> columnsTableOne,std::string secondTableName,std::vector <std::string> columnsTableTwo){
		int i=0;
		std::string allColumns;

		while(i<columnsTableOne.size()){
			allColumns +=  firstTableName + "." + columnsTableOne.at(i) + ", ";
			i++;
			}
		
		i=0;

		while(i<columnsTableTwo.size()){
			if(columnsTableTwo.size()==1){
				allColumns +=  columnsTableTwo.at(i) + " ";
			}
			else{
				if (i != columnsTableTwo.size()-1){
					allColumns += secondTableName + "." + columnsTableOne.at(i) + ", ";
				}
				else{
					allColumns +=  secondTableName + "." + columnsTableTwo.at(i) + " ";
				}
			}
			i++;
		}

		std::string sqlCommand = "SELECT " + allColumns + " FROM " + firstTableName + " LEFT JOIN " + secondTableName + " ON " + firstTableName + "."  + columnIDTableOne + "=" + secondTableName + "." + columnIDTableOne + ";"; 	 
		std::cout << sqlCommand << std::endl;
		check_error();
		connection_feedbackAll(sqlCommand.c_str());
	}

	/*Mithilfe der "selectRightJoin" Methode wird eine neue Ergebnistabelle erstellt
	* durch Kombinieren von Spaltenwerten von zwei Tabellen (firstTable und secondTable) basierend auf dem Join-Prädikat. 
	* Die Abfrage vergleicht jede Zeile von table1 mit jeder Zeile von table2, um alle Zeilenpaare zu finden, die das Verknüpfungsprädikat erfüllen. 
	* Wenn das Join-Prädikat erfüllt ist, werden Spaltenwerte für jedes übereinstimmende Paar von Zeilen von A und B in einer Ergebniszeile zusammengefasst.
	* Das Schlüsselwort RIGHT JOIN gibt alle Datensätze der rechten Tabelle (secondTable) und die übereinstimmenden Datensätze der linken Tabelle (firstTable) zurück. 
	* Das Ergebnis ist NULL von links, wenn keine Übereinstimmung vorliegt.
	*	
	* Die Struktur des SQL Befehl:	
	* select <Auswahl> FROM TabelleA LEFT JOIN TabelleB B ON A.ID = B.ID	 
	*
	*@param 
	*	-fristTableName-> Enhält den Tabellennamen der ersten Tabelle
	*	-columnIDTableOne-> enhält die zu vergleichene Spalte der ersten Tabelle
	*	-columnsTableOne-> enhält die Liste der Spalten die aus der ersten Tabelle angezeigt werden sollen
	*	-secondTableName-> Enhält den Tabellennamen der zweiten Tabelle
	*	-columnsTableTwo-> enhält die Liste der Spalten die aus der zweiten Tabelle angezeigt werden sollen
	*	
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/

	void selectRightJoin(std::string firstTableName, std::string columnIDTableOne,std:: vector <std::string> columnsTableOne,std::string secondTableName,std::vector <std::string> columnsTableTwo){
		int i=0;
		std::string allColumns;

		while(i<columnsTableOne.size()){
			allColumns +=  firstTableName + "." + columnsTableOne.at(i) + ", ";
			i++;
			}
		
		i=0;

		while(i<columnsTableTwo.size()){
			if(columnsTableTwo.size()==1){
				allColumns +=  columnsTableTwo.at(i) + " ";
			}
			else{
				if (i != columnsTableTwo.size()-1){
					allColumns += secondTableName + "." + columnsTableOne.at(i) + ", ";
				}
				else{
					allColumns +=  secondTableName + "." + columnsTableTwo.at(i) + " ";
				}
			}
			i++;
		}

		std::string sqlCommand = "SELECT " + allColumns + " FROM " + secondTableName + " RIGHT JOIN " + secondTableName + " ON " + firstTableName + "."  + columnIDTableOne + "=" + secondTableName + "." + columnIDTableOne + ";"; 	 
		std::cout << sqlCommand << std::endl;
		check_error();
		connection_feedbackAll(sqlCommand.c_str());
	}	
	/*Mithilfe der "selectFullJoin" Methode wird eine neue Ergebnistabelle erstellt
	* durch Kombinieren von Spaltenwerten von zwei Tabellen (firstTable und secondTable) basierend auf dem Join-Prädikat. 
	* Die Abfrage vergleicht jede Zeile von table1 mit jeder Zeile von table2, um alle Zeilenpaare zu finden, die das Verknüpfungsprädikat erfüllen. 
	* Wenn das Join-Prädikat erfüllt ist, werden Spaltenwerte für jedes übereinstimmende Paar von Zeilen von A und B in einer Ergebniszeile zusammengefasst.
	* Das Schlüsselwort FULL OUTER JOIN gibt alle Datensätze zurück, 
	* wenn eine Übereinstimmung in den Datensätzen der linken (firstTable) oder der rechten (secondTable) Tabelle vorliegt.
	*	
	* Die Struktur des SQL Befehl:	
	* select <Auswahl> FROM TabelleA FULL OUTER JOIN TabelleB B ON A.ID = B.ID	 
	*
	*@param 
	*	-fristTableName-> Enhält den Tabellennamen der ersten Tabelle
	*	-columnIDTableOne-> enhält die zu vergleichene Spalte der ersten Tabelle
	*	-columnsTableOne-> enhält die Liste der Spalten die aus der ersten Tabelle angezeigt werden sollen
	*	-secondTableName-> Enhält den Tabellennamen der zweiten Tabelle
	*	-columnsTableTwo-> enhält die Liste der Spalten die aus der zweiten Tabelle angezeigt werden sollen
	*	
	*@return 
	*	-Die Funktion gibt ein void zurück -> to Do sollte einen Boolean zurückgeben, ob der Befehl erfolgreich bearbeitet wurde.
	*
	* @author Martin Meyer
	*
	* @version 1.0
	*/
	
	void selectFullJoin(std::string firstTableName, std::string columnIDTableOne,std:: vector <std::string> columnsTableOne,std::string secondTableName,std::vector <std::string> columnsTableTwo){
		int i=0;
		std::string allColumns;

		while(i<columnsTableOne.size()){
			allColumns +=  firstTableName + "." + columnsTableOne.at(i) + ", ";
			i++;
			}
		
		i=0;

		while(i<columnsTableTwo.size()){
			if(columnsTableTwo.size()==1){
				allColumns +=  columnsTableTwo.at(i) + " ";
			}
			else{
				if (i != columnsTableTwo.size()-1){
					allColumns += secondTableName + "." + columnsTableOne.at(i) + ", ";
				}
				else{
					allColumns +=  secondTableName + "." + columnsTableTwo.at(i) + " ";
				}
			}
			i++;
		}

		std::string sqlCommand = "SELECT " + allColumns + " FROM " + firstTableName + " FULL OUTER JOIN " + secondTableName + " ON " + firstTableName + "."  + columnIDTableOne + "=" + secondTableName + "." + columnIDTableOne + ";"; 	 
		std::cout << sqlCommand << std::endl;
		check_error();
		connection_feedbackAll(sqlCommand.c_str());
	}



