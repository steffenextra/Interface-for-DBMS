#include "catWindow.hpp"

	


	void catWindow(){

		Fl_Window *window = new Fl_Window(700,500);
	    Fl_Choice *choise = new Fl_Choice(150,20,100,30, "Auswahl");
		
		window->end();
		window->show();
		Fl::run();
	}