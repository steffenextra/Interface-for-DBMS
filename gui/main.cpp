#include "connectionWindow.hpp"


int main (int argc, char *argv[]) {
    connectionWindow *c1 = new connectionWindow();
    c1->end();
    c1->show();
    Fl::run;

    delete c1;


}
