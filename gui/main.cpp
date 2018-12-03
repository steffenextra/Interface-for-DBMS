#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Output.H>



	int main(int argc, char **argv) {

		Fl_Window *window = new Fl_Window(700,400);
		Fl_Box *box = new Fl_Box(20,40,300,100,"");

		Fl_Output *output = new Fl_Output(40,40,150,40,"");
		output->value("Verbindung erfolgreich");

/* box->box(FL_UP_BOX);
box->labelfont(FL_BOLD+FL_ITALIC);
box->labelsize(36);
box->labeltype(FL_SHADOW_LABEL);*/


		window->end();
		window->show(argc, argv);
		return Fl::run();

	}
