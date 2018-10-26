clang++ -I/usr/local/mysql/include -L/usr/local/opt/openssl/lib -I/usr/local/opt/openssl/include -L/usr/local/mysql/lib -lmysqlclient -lssl -lcrypto  main.c connection.c connection.h createDatabase.c createDatabase.h
rm -rf connection.h.gch main.h.gch
