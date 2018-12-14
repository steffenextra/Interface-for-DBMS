#include "GUI.hpp"

Fl_Box *box1;
Fl_Input *host;
Fl_Input *name;
Fl_Input *pwd;
Fl_Input *database;
Fl_Input *port;
Fl_Button *connect;
ConnectionWindow *connectionWindow;
CategoryWindow *cw;

     void whenPushedConnect(Fl_Widget* w, void*){

		if ( ((Fl_Button*) w)->value()){
		} 
		else {
			int port1 = atoi(port->value());
			if(!(port==0)){
				connectionless(host->value(),name->value(),pwd->value(),database->value(),port1,pathto,0);
				connectionWindow->end();
				cw = new CategoryWindow();
			}
			else{
				//Exception
			}
		}
		
	}

	GUI::GUI(){
		 connectionWindow = new ConnectionWindow();
	}

  ConnectionWindow::ConnectionWindow() :
    Fl_Window(600,400,350,350,"SQL-Interface"){
        color(FL_WHITE);
        begin();

	 	box1 = new Fl_Box(20,40,300,100,"");
		host = new Fl_Input(150,20,100,30,"Host");
		name = new Fl_Input(150,60,100,30,"Benutzer");
		pwd = new Fl_Input (150,100,100,30, "Passwort"); 
		database = new Fl_Input (150,140,100,30, "Datenbank");
		port = new Fl_Input (150,180,100,30, "Port");
		connect = new Fl_Button(150,220,100,30, "Connect");
		connect->callback((Fl_Callback*) whenPushedConnect);
        end();
        show();
    }
ConnectionWindow::~ConnectionWindow() {
		
    }
  CategoryWindow::CategoryWindow() :
    Fl_Window(600,400,350,350,"SQL-Interface"){
        color(FL_WHITE);
        begin();

	 	box1 = new Fl_Box(20,40,300,100,"");
		connect->callback((Fl_Callback*) whenPushedConnect);
        end();
        show();
        Fl::run();
    }
