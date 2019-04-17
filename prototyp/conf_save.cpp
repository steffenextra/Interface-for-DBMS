#include "sqllib.hpp"
#include <fstream>

void conf( const char host [], const char user [], const char password [], const char database [], int port, bool safeconf){

	std::ifstream FileTest("config.txt");

	if(safeconf == true){
		if (!FileTest){
			std::cout << "File not Found" << std::endl;
		}else {	
			std::fstream in; 
			in.open("config.txt", std::ios::out);
			in << host << std::endl;
			in << user << std::endl;
			in << password << std::endl;
			in << database << std::endl;
			in << port << std::endl;
			in.close();
		}
	
	}

}

void loadConf(char *name){

	std::ifstream f;
	std::string s;
	f.open(name, std::ios::in);
	while(!f.eof()){
		getline(f,s);
		//strcpy(puffer,s.c_str());	
		std::cout << s << std::endl;
	}

}



