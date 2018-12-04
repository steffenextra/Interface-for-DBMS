#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include "/Users/steffenextra/projekt/projektarbeit/prototyp/sqllib.hpp"
#include <stdio.h>

	void whenPushed(Fl_Widget* w, void*){

		if ( ((Fl_Button*) w)->value()){
			disconnect();
			std::cout << "test" << std::endl;
		}else{
			printf("Ahhh!\n");
		}
	}




	int main(int argc, char **argv) {

		Fl_Window *window = new Fl_Window(700,400);
		Fl_Box *box = new Fl_Box(20,40,300,100,"");

		Fl_Input *host = new Fl_Input(70,20,100,30,"Host");

		Fl_Input *name = new Fl_Input(70,60,100,30,"Benutzer");

		Fl_Input *pwd = new Fl_Input (70,100,100,30, "Passwort"); 

		Fl_Input *database = new Fl_Input (70,140,100,30, "Datenbank");

		Fl_Input *port = new Fl_Input (70,180,100,30, "Port");

		Fl_Button *connect = new Fl_Button(70,220,100,30, "Connect");
		connect->callback((Fl_Callback*) whenPushed);



		window->end();
		window->show(argc, argv);
		return Fl::run();

	}
