#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Beispielprogramm für den  Prototypen. Das Beispielprogramm  
enthält  eine Struktur mit den selben Attributen wie unsere Datenbank.
Es soll die Struktur uebergeben werden, sodass mit dieser 
ein neuer Datensatz in unserer Datenbank ensteht.
*/

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
    printf("Food: %s\n", plc1.food);
    printf("Confirmed: %d\n", plc1.confirmed);
    printf("Date: %d-%d-%d\n", plc1.sign_up.day, plc1.sign_up.month,plc1.sign_up.year);

    
  return 0;
}