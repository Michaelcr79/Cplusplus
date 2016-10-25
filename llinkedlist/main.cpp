// Author: Michael C. Robinson
// Program: main.cpp - a demo of llinkedlist.cpp implementing a linear linked
//                     list of names.

#include "llinkedlist.h"
using std::cout;
using std::endl;
using std::cin;

void return_name(char * name);

int main()
{
    llinkedlist list_names;

    int flag = 1;

    char  name[256];
    char namef[256];
    char namel[256];


    while ( flag )
    {
          return_name(name);

          if ( strcmp ( name, "quit" ) == 0 )
          {    
               flag = 0;    
               break;
          }

          strcpy ( namef, name );

          return_name(name);

          if ( strcmp ( name, "quit" ) == 0 )
          {    
               flag = 0;    
               break;
          }

          strcpy ( namel, name );

          cout << list_names.add_name(namef,namel) << endl; 
    }

    list_names.print_names();

    return 0;
}



void return_name(char * name)
{
        cout << "Type a name or quit to quit: ";
         cin >> name;
}
