#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Date
{
  int day;
  int month;
  int year;
};

struct Potluckcontent{
    int id;
    char name[20];
    char food[30];
    bool confirmed;
    struct Date sign_up;
};

int main(void)
{
    struct Date  date1={12,12,2012};
   struct Potluckcontent plc1={1,"horst","bbq",true,date1};
  
    printf("ID: %d\n", plc1.id);
    printf("Name: %s\n", plc1.name);
    printf("Date: %d-%d-%d\n", plc1.sign_up.day, plc1.sign_up.month,plc1.sign_up.year);
  return 0;
}