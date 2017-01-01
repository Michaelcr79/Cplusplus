// Author: Michael C. Robinson
//   Date: December 29, 2016
// Implement a binary tree.

#include"btree.h"

btree::btree()
{
	root=NULL;
	search=NULL;
}

btree::~btree()
{
	clear_node(root);
}

void btree::clear_node(node * curr)
{
	if ( curr && curr -> left != NULL )
		clear_node(curr -> left);

	if ( curr && curr -> right != NULL )
		clear_node(curr -> right);

	delete curr;

	curr = NULL;
}



int btree::check_empty()
{
	if ( root = NULL )
	{ return 1; }

	if ( root )
	{ return 0; }
}



void btree::insert_node(node * node_to_add)
{
	if ( check_empty() == 1 )
	{
		root = node_to_add;

		return; // Node added at root.
	}

	while ( node_to_add -> number < search -> number )
	{
		if ( search -> left != NULL )
		{
	 	     search = search -> left;
		}
		else
	        {
		     search -> left = node_to_add;
		     return; // Node added at left leaf.
		}
	}

	while ( node_to_add -> number > search -> number )
	{
		if ( search -> right != NULL )
                {
		     search = search -> right;
		}
		else
		{
	             search -> right = node_to_add; 
		     return; // Node added at right leaf.
		}
	}

	insert_node(node_to_add);
}



int btree::insert_number(const int number)
{
	node * node_to_add = new node;
	if (NULL ==  node_to_add)
        {	
	     return -1;
	}

	node_to_add -> number = number;
	node_to_add -> left = NULL;
	node_to_add -> right = NULL;

	// Want to add the first number...
	if ( check_empty() == 1 )
	{
		insert_node(node_to_add);
		return 0;
	}

	// Don't want to add the same number twice...
	if ( search_number(number) == 1 )
	{	
		delete node_to_add;
		node_to_add = NULL;
		return -2;     
	}

	insert_node(node_to_add);

	return 0;
}



int btree::search_number(const int number)
{
	if ( check_empty() == 1 )
	{
	     return 1; // Number is not here.
	}

	search=root;

	while ( search && search -> number != number )
	{
		if ( search -> number > number )
		{
			search = search -> left;
			search_node ( number );
		}

		if ( search -> number < number )
		{
			search = search -> right;
			search_node ( number );
		}
	}

        if ( search == NULL )
	{
	     return 1; // Number is not here.
	}

	return 0; // Number was found!!!
}



void btree::search_node(const int number)
{
	if ( search == NULL )
	{
    	     return; // Number is not in the tree.
	}

	if ( number < search -> number )
	{
	     search = search -> left;
	     search_node ( number );
	}

	if ( number > search -> number )
	{
	     search = search -> right;
	     search_node ( number );
        }

	if ( number == search -> number )
	{
		return; // Found the number!!!
	}
}
