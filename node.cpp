#include "node.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//Constructor
Node :: Node()
{
	phone = 0;
	name = " ";
	left = NULL;
	right = NULL;
}

//Constructor
Node :: Node(long long phne, string nme)
{
	phone = phne;
	name = nme;
	left = NULL;
	right = NULL;
}


//Mutator Function to get left ptr.
void Node :: set_left(Node* aleft)
{
	left = aleft;
}

//Mutator Function to get right ptr.
void Node :: set_right(Node *aright)
{
	right = aright;
}

//Mutator Function to set the phone number.
void Node :: set_phone(long long phne)
{
	phone = phne;
}

//Mutator Function to set the name.
void Node :: set_name(string nme)
{
	name = nme;
}

//Accessor function to get left pointer of current node.
Node* Node :: get_left()
{
	return left;
}

//Accessor function to get right pointer of current node.
Node* Node :: get_right()
{
	return right;
}

//Accessor Function to get name of current node.
string Node :: get_name()
{
	return name;
}

//Accessor Function to get phone number of current node.
long long Node :: get_phone()
{
	return phone;
}

