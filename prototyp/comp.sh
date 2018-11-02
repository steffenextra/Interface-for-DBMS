#!/bin/bash

	if [ -d /usr/local/mysql/include ];
	then
			clang++ -std=c++11 -I/usr/local/mysql/include -L/usr/local/opt/openssl/lib -I/usr/local/opt/openssl/include -L/usr/local/mysql/lib -lmysqlclient -lssl -lcrypto  *.cpp *.hpp
			rm -rf *.hpp.gch
	fi


