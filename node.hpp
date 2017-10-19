/*
Function: Node
Constructor: defaults phone and name to predetermined value.
Make left and right NULL. 
Inputs: None
Outputs: None data is going to be zeroed
Return: N/A

Function: Node
Constructor: Takes in phone number and name.
Inputs: phne, nme
Outputs: None
Returns: None

Function: get_left
Description: Accessor function to get left.
Inputs: None
Output: None
Return: left

Function: get_right
Description: Accessor function to get right.
Inputs: None
Output: None
Return: right

Function: set_left
Description: Mutator function to set left ptr.
Input: *aleft
Output: None
Return: None

Function: set_right
Description: Mutator function to set right ptr.
Input: *aright
Output: None
Return: None

Function: get_phone
Description: Accessor function to get phone number.
Inputs: None
Outputs: None
Return: phone

Function: get_name
Description: Accessor function to get name.
Inputs: None
Outputs: None
Return: name

Function: set_phone
Description: Mutator function to set phone number.
Input: phne
Output: None
Return: None

Function: set_name
Description: Mutator function to set name.
Input: nme
Output: None
Return: None
*/
#include <string>
using namespace std;
// Node class

#ifndef __NODE__
#define __NODE__
class Node 
{
    long long phone;
    string name;
    Node* left;
    Node* right;
public:
    Node();
    Node(long long phne, string nme);
    void set_left(Node* aleft);
    void set_right(Node* aright);
    void set_phone(long long phne);
    void set_name(string nme);
    long long get_phone();
    string get_name();
    Node* get_left();
    Node* get_right();
};
#endif
