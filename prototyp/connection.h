#include "/usr/local/mysql/include/mysql.h"
#include <string>


void load_defaults(const char *conf_file, const char **groups,int *argc, char ***argv);
MYSQL* connectionless(const char host [], const char user [], const char passwort [], unsigned int port,/*const char unix_socket*/const char macOS_socket [], unsigned int client_flag); 

void disconnect();
void check_error(void);
