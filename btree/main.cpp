// Author: Michael C. Robinson
//   Date: December 29. 2016
// Implement a binary tree of numbers, this is the main program.

#include"btree.h"

int main(void)
{
	btree number_tree;
	int flag = 0;

	cout << "Insert 8 into a binary tree\n";
	number_tree.insert_number(8);
	cout << "Insert 4\n";
	number_tree.insert_number(4);
	cout << "Insert 10\n";
	number_tree.insert_number(10);
	cout << "Insert 2\n";
	number_tree.insert_number(2);
	cout << "Insert 6\n";
	number_tree.insert_number(6);
	cout << "Insert 9\n";
	number_tree.insert_number(9);
	cout << "Insert 12\n";
	number_tree.insert_number(12);
	cout << "Insert 1\n";
	number_tree.insert_number(1);
	cout << "Insert 3\n";
	number_tree.insert_number(3);
	cout << "Insert 5\n";
	number_tree.insert_number(5);
	cout << "Insert 7\n";
	number_tree.insert_number(7);
	cout << "Insert 11\n";
	number_tree.insert_number(11);
	cout << "Insert 13\n";
	number_tree.insert_number(13);

	cout << "Inserted the following numbers into the tree:\n"
	     << "8,4,10,2,6,9,12,1,3,5,7,11,13\n\n"
	     << "In the order shown to get reasonable balance.\n\n";

	cout << "Now I will do a search for 12.\n\n";

	flag = number_tree.search_number(12);

	if ( flag == 1 )
	{	
		cout << "12 was found!\n\n";
	}
	else
	{
		cout << "12 was not found\n\n";
	}

	for ( int counter = 1 ; counter < 14 ; ++counter )
	{
	      flag = number_tree.search_number(counter);
	      if ( flag == 1 )
	      {
		   cout << "Number " << counter << " was found!\n";
              }
	      else
              {
		   cout << "Number " << counter << " was not found!\n";
              }
	}

	return 0;
}

