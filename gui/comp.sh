#!/bin/bash

	if [ -d /usr/local/mysql/include ];
	then
			clang++ -std=c++11 -w  -L/usr/local/lib -lfltk_images -lfltk_png -lz -lfltk_jpeg -lfltk -lpthread -framework Cocoa -I/usr/local/mysql/include -L/usr/local/opt/openssl/lib -I/usr/local/opt/openssl/include -L/usr/local/mysql/lib -lmysqlclient -lssl -lcrypto  *.cpp 
			rm -rf *.hpp.gch

	elif [ -d /usr/include/openssl ];
	then
			clang++ -std=c++11 -w -I -L/usr/include/openssl  -I -L/usr/include/mysql  -lmysqlclient -lssl -lcrypto -L/usr/local/lib -lfltk -lXext -lX11 -lm *.cpp
			rm -rf *.hpp.gch
	fi
