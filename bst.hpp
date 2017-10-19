/*
Function: BST
Constructor: defaults root to predetermined value.
Inputs: None
Outputs: None data is going to be zeroed
Return: N/A

Function: ~BST
Deconstructor: frees up memory by deleting tree
Inputs: None
Outputs: None
Returns: None

Function: insert
Description: Takes in value and creates new node and places it in the
appropriate place on tree.
Inputs: phne,nme
Output: None
Return: None

Function: search
Description: Gets user input and determines if the value is in the tree
Inputs: phne
Output: None
Return: Node

Function: delete_node
Description: Frees up memory by removing a node from the tree
Input: phne
Output: None
Return: None

Function: in_order
Description: Traverse the tree and lists nodes in order
Input: None
Output: None
Return: None

Function: pre_order
Description: Traverse the tree and list nodes in pre order
Inputs: None
Outputs: None
Return: None

Function: post_order
Description: Traverse the tree and list nodes in post order
Inputs: None
Outputs: None
Return: None

Function: destroy_tree
Description: Frees up memory by deleting all nodes in the tree
Input: None
Output: None
Return: None

Function: save_tree
Description: Saves all nodes into a file in pre order format.
Input: None
Output: None
Return: None
*/

#include "node.hpp"
#include <fstream>

#ifndef __TREE__
#define __TREE__
// Binary Search Tree class
class BST
{
   Node* root;
   void destroy_tree(Node* leaf);
   void in_order(Node* root);
   void pre_order(Node* root);
   void post_order(Node* root);
   void save_tree(Node* root);
   void insert(long long phne, string nme, Node* leaf);
   Node* delete_node(Node* root, long long phne);
   Node* search (Node* root, long long phne);
   Node* min_value_node(Node* node);
   ofstream ofile;
public:
   BST();
   ~BST();
   void insert(long long phne, string nme);
   Node* search (long long phne);
   void delete_node (long long phne);
   void in_order();
   void pre_order();
   void post_order();
   void destroy_tree();
   void save_tree();
};
#endif
