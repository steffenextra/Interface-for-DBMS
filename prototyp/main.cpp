#include "sqllib.hpp"


int main (int argc, char *argv[]) {


        const char* host ="localhost";
        const char* user ="root";
        const char* passwort ="";
        const char* db = "DatabaseNumberOne1";
        unsigned int port=3306;
        unsigned int client_flag=0;
	connectionless(host, user, passwort, db, port,pathto, client_flag);


        //method-tests


        std::vector<std::string> columns; // jede gerade Index der Spaltennamen, Ungerade der Datentyp
        columns.push_back("Name");
        columns.push_back("char(50)");
        columns.push_back ("Nachname");
        columns.push_back("char(50)");
        columns.push_back("PLZ");
        columns.push_back("int");
	columns.push_back("Adresse");
	columns.push_back("char(50)");
	columns.push_back("Zwischenname");
	columns.push_back("char(50)");

	std::vector<std::string> row; // jede gerade Index der Spaltennamen, Ungerade der Datensatz

                                    //string mit '' versehen
        row.push_back("Name");
        row.push_back("'Dieter'");
        row.push_back("Nachname");
        row.push_back("'GanzLaaaaaaaaaangerNachname'");
        row.push_back("PLZ");
        row.push_back("'26817'");
        row.push_back("Adresse");
        row.push_back("'Straße 1'");
        row.push_back("Zwischennamen");
        row.push_back("'Heinrich'");


		std::vector <std::string> tableName;

		tableName.push_back("tabelle2");
		tableName.push_back("tabelle3");
		tableName.push_back("Lohn");


		std::vector <std::string> columnName;

		columnName.push_back("Nachname");
		columnName.push_back("Name");
		columnName.push_back("Lohn");

	/*	for (int i =0; i<columnName.size(); i++){

		std::cout << columnName.at(i) << std::endl;
		}
        */
//	unionSelect(tableName, columnName);
//	setSecondaryKey("tabelle3", "ID", "tabelle2", "ID", "Person_ID");
//      deleteSecondaryKey("tabelle3", "Person_ID");
//	setPrimaryKey("tabelle3", "ID");
//	setColumnWithPrimary("tabelle2", "ID", "int", true);
//	deletePrimaryKey("tabelle3");
//	averageSum("tabelle2", "ID");
//	sum("Lohn", "Lohn", "Gesamt");
//      selectWhere("tableNumberOne","Name","Markus",columnsss);
//      std::string myCommand="SELECT * FROM tableNumberOne";
//      sqlCommand(myCommand,"feedbackAll");
//      renameDatabase("DatabaseNumberOne1","DatabaseNumberOne");
//      selectWhereWithSort("tableNumberOne","Name","Dieter",columnsss,"Name","ASC");
//      selectLimitWhere("tableNumberOne","2","Name","Dieter",columnsss,"Name","DESC");
//      selectMinOrMax("tableNumberOne","MIN","Name","MAXIMALE");
//      selectMinOrMaxWithWhere("tableNumberOne","MIN","Name","MAXIMALE","Name","Dieter");
//	selectBetween (">=", "<=", "Lohn", "Lohn", "Lohn", "500", "1000");
//	selectNull("tabelle2", "Name");
//      selectCountDistinct("tableNumberOne","Name");
//      selectCount("tableNumberOne","Name","Namensanzahl");
//       selectAlias("tableNumberOne",columnsss,aliasss);
    
std::vector<std::string> columnsss;
std::vector<std::string> aliasss;

        columnsss.push_back("Name");
        aliasss.push_back("Vornamen");
        columnsss.push_back("Nachname");
        aliasss.push_back("Nachname2");
        columnsss.push_back("PLZ");
        aliasss.push_back("Postleitzahl");
        columnsss.push_back("Adresse");
        aliasss.push_back("Adresse2");
        columnsss.push_back("Zwischennamen");
        aliasss.push_back("Zwischennamen2");

//        selectTableAlias("tableNumberOne","tableNumberTwo", columnsss);


	disconnect();
}

