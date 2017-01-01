// Author: Michael C. Robinson
//   Date: December 29, 2016
// Prototype a binary tree.

#include <iostream>
using namespace std;

struct node
{
	int number;
	node * left;
	node * right;
};

class btree
{
		void clear_node(node * curr);
		// Call by default destructor to delete the leaves.
		
		int check_empty();
		// 1 means empty.
		// 0 means not empty.
		
		void insert_node(node * node_to_add);
		// node_to_add is the node to add to the tree.

		void search_node(const int number);
		// Recurse through tree to see if number is in it.
		
		node * root; 
		// Points to the root of the tree.
		
		node * search;
		// Points to the place you searched to for insertion.

	public:
		btree();
		// Default constructor.
	
		~btree();
		// Default destructor.

		int insert_number(const int number);
		// -1 means I couldn't create a new node.
		// -2 means The number is already in the list.
		//  0 means the number was added to the list.

		int search_number(const int number);
		// 0 means yes it is, 1 means not found.
};
