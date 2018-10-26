clang++ -I/usr/local/mysql/include -L/usr/local/opt/openssl/lib -I/usr/local/opt/openssl/include -L/usr/local/mysql/lib -lmysqlclient -lssl -lcrypto  mainSQL.c buildconn.c buildconn.h
rm -rf buildconn.h.gch mainSQL.h.gch
