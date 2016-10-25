// Author: Michael C. Robinson
// program: llinkedlist.cpp, a simple linear linked list of names.

#include "llinkedlist.h"

llinkedlist::llinkedlist()
{
     head = NULL;
     tail = NULL;
     len_of_list = 0;
}

llinkedlist::~llinkedlist()
{
     while ( head )
     {
             tail = head -> next;
             delete [] head -> first_name;
             delete [] head -> last_name;
             delete head;
             head = tail;
     }
}

int llinkedlist::add_name(const char * FIRST_NAME, const char * LAST_NAME)
{
       node * newnode = NULL; 
       node * current = NULL;
       node * previous = NULL; 

       //----------------------------------------------------------------------
       // Case 1 is empty list, handle that first...
       if ( ! head ) 
       {
            head = new node();
            if ( ! head )
            {
                 return -1; // Uh-oh, no memory available for new head.
            }
            else
            { head -> next = NULL; }

            head -> first_name = new char[strlen(FIRST_NAME)+1];
            head -> last_name = new char[strlen(LAST_NAME)+1];

            if ( head -> first_name && head -> last_name )
            {
                 strcpy(head -> first_name,FIRST_NAME);
                 strcpy(head -> last_name,LAST_NAME);
            }
            else
            { 
                 delete head;
                 head = NULL;
                 tail = NULL;
 
                 return -2; // Not enough memory for first and last name. 
            }


            tail = head;
            tail -> next = NULL;

            return ++len_of_list;
       }
       //----------------------------------------------------------------------
       else // Non empty list, search first for new name.
       {
           if ( search_name(FIRST_NAME,LAST_NAME) == 0 )
           { 
                return -3; // Already in the list... 
           }

           //------------------------------------------------------------------
           // Okay, set up a new node before installing to the list.
           newnode = new node;
           if ( ! newnode ) 
           {  
                return -4; // Not enough memory to add this name.
           }

           newnode -> first_name = new char[strlen(FIRST_NAME)+1];
           newnode -> last_name = new char[strlen(LAST_NAME)+1];

           if ( newnode -> first_name && newnode -> last_name )
           {
                strcpy ( newnode -> first_name, FIRST_NAME );
                strcpy ( newnode -> last_name, LAST_NAME );
           }
           else
           {
                delete newnode;
                return -2;
           } // New node is ready...
           //------------------------------------------------------------------



           //------------------------------------------------------------------
           if ( strcmp ( head -> last_name, LAST_NAME ) < 0 )
           { // Does this name go before the first name in the list???

                newnode -> next = head;

                head = newnode;

                return ++len_of_list;

           } // Inserted before head of the list...
           //------------------------------------------------------------------



           //------------------------------------------------------------------
           if ( strcmp ( tail -> last_name, LAST_NAME ) > 0 )
           { // Should the new name be tacked onto the end of the list???

                tail -> next = newnode;
 
                tail = newnode;

                tail -> next = NULL; 

                return ++len_of_list;

           } // New name went onto end of the list...
           //------------------------------------------------------------------

             
           //------------------------------------------------------------------
           // Goes somewhere in the middle of the list...
           
           current = head -> next;
           previous = head;
           while ( current ) 
           {
                   if ( strcmp ( current -> last_name, LAST_NAME ) < 0 )
                   {
                        previous -> next = newnode;
                        newnode -> next = current;
                   }

                   previous = current;
                   current = current -> next;
           }

           return ++len_of_list;
           //------------------------------------------------------------------
        }
           
} // End of add_name...

int llinkedlist::search_name(const char * FIRST_NAME, const char * LAST_NAME)
{
       node * newnode = head;

       while ( newnode ) // If there is a list, there may be a match.
       {
            if (strcmp(FIRST_NAME, newnode -> first_name)==0 && 
                strcmp(LAST_NAME, newnode -> last_name)==0
               )
            {
                return 0;
            }
            
            newnode = newnode -> next;
       }

       return -1;
}

void llinkedlist::print_names()
{
     using std::cout;
     using std::endl;

     node * current = head;
     while ( current )
     {
             cout << current -> first_name << ' '
                  << current -> last_name << endl;

             current = current -> next;
     }
}
