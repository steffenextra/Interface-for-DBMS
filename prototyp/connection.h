//#include "/usr/include/mysql/mysql.h"
#include "/usr/local/mysql/include/mysql.h"

void check_error(void);
void connection_query(char* sqlcommand);
void connectionless(const char *host,const char *user,const char *passwort,unsigned int port,const char *unix_socket,unsigned int client_flag);
void disconnect();

