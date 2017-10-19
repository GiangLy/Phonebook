#include "bst.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Constructor
BST::BST() 
{
   root = NULL;
   
}

// Destructor
BST::~BST()
{
   destroy_tree(root);
}

// Add a telephone number
void BST::insert(long long phne, string nme) 
{
     // No elements. Add the root
   if (root == NULL) 
   {
      cout << "add root node ... " << endl;
      Node* n = new Node(phne, nme);
      root = n;
   }
   else 
   {
      cout << "add other node ... " << phne << endl << nme << endl;
      insert(phne, nme, root);
   }
}

// Add a telephone number (private)
void BST::insert(long long phne, string nme, Node* leaf)
{
	//checks to see if phone number exists in tree.
	if ( phne == leaf->get_phone())
	{
		cout << "duplicate phone number cannot add..." << endl;
	}
	else
	{
		if ( phne <= leaf->get_phone() ) 
		{
			if ( leaf->get_left() != NULL )
			insert(phne , nme, leaf->get_left());
		else 
		{
			Node* n = new Node(phne, nme);
			leaf->set_left(n);
		}
		}
		else 
		{
		if ( leaf->get_right() != NULL )
			insert(phne, nme, leaf->get_right());
		else 
		{
			Node* n = new Node(phne, nme);
			leaf->set_right(n);
		}
		}
	}
}

Node* BST::search (Node* root, long long phne)
{
	// base case
    if (root == NULL) return root;
 
    // If the number to be found is smaller than the root's number,
    // then it lies in left subtree
    if (phne < root->get_phone())
        root->set_left(search(root->get_left(), phne));
 
    // If the key to be found is greater than the root's number,
    // then it lies in right subtree
    else if (phne > root->get_phone())
        root->set_right(search(root->get_right(), phne));
 
    // if number is same as root's number, then number exists in tree.
    return root;
}
	
//Delete node (public)
void BST::delete_node(long long phne)
{
   root = delete_node (root, phne);
}

//Search node (public)
Node* BST::search(long long phne)
{
	root = search (root,phne);
	return root;
}

/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
Node* BST::min_value_node(Node* node)
{
    Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->get_left() != NULL)
        current = current->get_left();
 
    return current;
}

/* Given a binary search tree and a number, this function deletes the
 number and returns the new root */
Node* BST::delete_node(Node* root, long long phne)
{
    // base case if number is not found
    if (root == NULL)
    {
		cout << "Phone number was not found." << endl;
		return root;
	}
 
    // If the number to be deleted is smaller than the root's number,
    // then it lies in left subtree
    if (phne < root->get_phone())
        root->set_left(delete_node(root->get_left(), phne));
 
    // If the number to be deleted is greater than the root's number,
    // then it lies in right subtree
    else if (phne > root->get_phone())
        root->set_right(delete_node(root->get_right(), phne));
 
    // if number is same as root's number, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->get_left() == NULL)
        {
            Node* temp = root->get_right();
            destroy_tree(root);
            return temp;
        }
        else if (root->get_right() == NULL)
        {
            Node *temp = root->get_left();
            destroy_tree(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node* temp = min_value_node(root->get_right());
 
        // Copy the inorder successor's content to this node
        root->set_phone (temp->get_phone());
        root->set_name (temp->get_name());
 
        // Delete the inorder successor
        root->set_right(delete_node(root->get_right(), temp->get_phone()));
    }
    return root;
}

// Free the node
void BST::destroy_tree(Node* leaf)
{
    if ( leaf != NULL )
    {
       destroy_tree(leaf->get_left());
       destroy_tree(leaf->get_right());
       cout << leaf->get_name() << " deleted." << endl;
       delete leaf;
    }
}

//Traverse and list in order (private)
void BST::in_order(Node* root)
{
	if ( root != NULL )// (Otherwise, there's nothing to print.)
    {  
		post_order(root->get_left());    // Print items in left subtree.
		// Print the root item.
        cout << root->get_name() << " " << root->get_phone() << endl;
        post_order(root->get_right());   // Print items in right subtree.
    }
}

//Traverse and list pre order (private)
void BST::pre_order(Node* root)
{
    if ( root != NULL )// (Otherwise, there's nothing to print.)
    {  
		// Print the root item.
		cout << root->get_name() << " " << root->get_phone() << endl;       
        post_order(root->get_left());    // Print items in left subtree.
        post_order(root->get_right());   // Print items in right subtree.
    }
}

//Traverse and list post order (private)
void BST::post_order(Node* root)
{
    if ( root != NULL )// (Otherwise, there's nothing to print.)
    {  
        post_order(root->get_left());    // Print items in left subtree.
        post_order(root->get_right());   // Print items in right subtree.
        // Print the root item.
		cout << root->get_name() << " " << root->get_phone() << endl;       
    }
}

// Save's tree to tree.dat in pre order.
void BST::save_tree(Node* root)
{
	ofile.open("tree.dat", ios::app);
	if ( root != NULL )// (Otherwise, there's nothing to print.)
    {  
		//Save the root item to file.
		ofile << root->get_name() << "\t" << root->get_phone() << endl;       
        save_tree(root->get_left());    // Save items in left subtree.
        save_tree(root->get_right());   // Save items in right subtree.
    }
    ofile.close();
}

//Traverse and list in order (public)
void BST::in_order()
{
	in_order(root);
}

//Traverse and list pre order (public)
void BST::pre_order()
{
	pre_order(root);
}

//Traverse and list post order (public)
void BST::post_order()
{
	post_order(root);
}

//Destroy tree (public)
void BST::destroy_tree()
{
   destroy_tree(root);
}

//Saves tree to file (public)
void BST::save_tree()
{
	save_tree(root);
}
