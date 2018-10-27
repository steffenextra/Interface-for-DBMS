#include "/usr/include/mysql/mysql.h"
//#include "/usr/local/mysql/include/mysql.h"

void connection_query(char* sqlcommand);
void load_defaults(const char *conf_file, const char **groups,int *argc, char ***argv);
void connectionless(const char *host,const char *user,const char *passwort,unsigned int port,const char *unix_socket,unsigned int client_flag);
void disconnect();
void check_error(void);
