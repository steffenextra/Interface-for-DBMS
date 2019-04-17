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
	std::vector<char> val (s.begin(), s.end());
	f.open(name, std::ios::in);
	int count =0;

	while(!f.eof()){
		getline(f,s);
		val.push_back(s.c_str());
		count++;
	}
	connectionless(val.at(0), val.at(1), val.at(2),val.at(3),val.at(4), pathto, 0);


}



