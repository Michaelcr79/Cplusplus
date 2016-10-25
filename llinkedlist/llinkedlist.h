// Author: Michael C. Robinson
// header: llinkedlist.h.

#include <iostream>
#include <cstring>
#include <cstdio>



struct node
{
	char * first_name;
        char * last_name;
        node * next;
};



class llinkedlist 
{
      private:
          node * head;         // Points to first name in list.
          node * tail;         // Points to last name in list.
          int len_of_list = 0; // Number of names in the list.

      public:
          llinkedlist();
          ~llinkedlist();

          int    add_name(const char * FIRST_NAME, const char * LAST_NAME);
          // Return value > 0 is length of the list, add successfull.
          // Return value -1 => No memory to allocate first node in list.
          // Return value -2 => Not enough memory for first and last name.
          // Return value -3 => Name already in the list.
          // Return value -4 => Not enough memory to add another node.


          int search_name(const char * FIRST_NAME, const char * LAST_NAME);
          // Return value  0 => name is in the list already.
          // Return value -1 => name is NOT in the list.
          
          void print_names();
          // Output to the screen the names in the list in order.
};
