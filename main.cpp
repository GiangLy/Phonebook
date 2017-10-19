/*
Author: Giang Ly
Student ID: C427R468
Program Number: 6

Description of Problem:
For this program, you will develop a C++ program that will implement 
a binary search tree.  The data structure for the tree will contain a 
phone number and a name.  The phone number will be used for the key into 
the search tree.  
*/

#include "node.hpp"
#include "bst.hpp"
#include <iostream>
#include <string>

using namespace std;
void print_menu();


int main(void)
{
	long long phne;
	int choice;
	string nme;
	
	BST tree;  //Create Binary search tree
   	do
	{
		//get user choice from menu.
		print_menu();
		cout << "Enter Choice: ";
	    cin >> choice;
	    cin.ignore(25, '\n');
		switch (choice)
		{
		//add telephone entry
		case 1:
			cout << "Name: ";
	        getline(cin, nme);
			cout << "Telephone number: ";
		    cin >> phne;
			tree.insert(phne,nme);
			break;
		//delete telephone entry
		case 2:
		    cout << "Telephone number: ";
	        cin >> phne;
	        tree.delete_node(phne);
			break;
		//Search for telephone number
		case 3:
		    cout << "Telephone number: ";
	        cin >> phne;
	        if (tree.search(phne) == NULL)
	        {
				cout << "Number does not exist in tree." << endl;
			}
			else
			{
				cout << phne << " was found in the tree." << endl;
			}
			break;
		//Traverse and list tree pre order
		case 4:
		    tree.pre_order();
			break;
		//Traverse and list tree post order
		case 5:
		    tree.post_order();
		    break;
		//Traverse and list tree in order
		case 6:
			tree.in_order();
			break;
		//Exit program and save entries to Tree.dat
		case 7:
			cout << "saving to file..." << endl;
			tree.save_tree();
			break;
		default:cout << "Not a valid choice" << endl;
		}
	} while (choice != 7);
	return 0;
}

//This is the menu that is displayed for user to select a choice from.
void print_menu()
{

	cout << "1. Add a Telephone number" << endl;
	cout << "2. Delete a Telephone number" << endl;
	cout << "3. Locate a Telephone number" << endl;
	cout << "4. Pre-order" << endl;
	cout << "5. Post-order" << endl;
	cout << "6. In-order" << endl;
	cout << "7. Exit" << endl;
}


