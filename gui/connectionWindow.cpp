#include "connectionWindow.hpp"

	void whenPushed(Fl_Widget* w, void*){

		if ( ((Fl_Button*) w)->value()){
		}else{
			printf("Ahhh!\n");
		}
	}




	void window(){

		Fl_Window *window = new Fl_Window(400,300);
		Fl_Box *box = new Fl_Box(20,40,300,100,"");

		Fl_Input *host = new Fl_Input(150,20,100,30,"Host");

		Fl_Input *name = new Fl_Input(150,60,100,30,"Benutzer");

		Fl_Input *pwd = new Fl_Input (150,100,100,30, "Passwort"); 

		Fl_Input *database = new Fl_Input (150,140,100,30, "Datenbank");

		Fl_Input *port = new Fl_Input (150,180,100,30, "Port");

		Fl_Button *connect = new Fl_Button(150,220,100,30, "Connect");
		connect->callback((Fl_Callback*) whenPushed);



		window->end();
		window->show();
		Fl::run();
	}