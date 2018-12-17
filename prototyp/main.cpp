#include "sqllib.hpp"
#include "GUI.hpp"


int main (int argc, char *argv[]) {


        const char* host ="localhost";
        const char* user ="root";
        const char* passwort ="root";
        const char* db = "DatabaseNumberOne1";
        unsigned int port=3306;
        unsigned int client_flag=0;
	connectionless(host, user, passwort, db, port,pathto, client_flag);
        showTable("tabelle2");

/*        GUI *gui1 =  new GUI();
                Fl::run();
	//disconnect();*/
}

