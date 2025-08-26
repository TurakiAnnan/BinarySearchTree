// Author Turaki Annan 
// Binary Search Tree 

#include "student_record_system_HEADER.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;
Node::Node(int matriculation_number, string name, string programme)
    : matriculation_number(matriculation_number), name(name), programme(programme), left(nullptr), right(nullptr) {}

 
//Constructor for the StudentRecordSystem (already implemented for you)
StudentRecordSystem::StudentRecordSystem() : root(nullptr) {}


StudentRecordSystem::~StudentRecordSystem() 
{
    delete_tree(root);
}


void StudentRecordSystem::delete_tree(Node *node) 
{
    //write your code to delete all nodes in the tree,
	//freeing the memory, here
}

// The structure for addidng a student
void StudentRecordSystem::add_student(int matriculation_number, string name, string programme) 
{
    add_student_recursive(&root, matriculation_number, name, programme);
}

//Adding students with the key of matriculation number
void StudentRecordSystem::add_student_recursive(Node **node, int matriculation_number, string name, string programme) 
{
	// Checks if the first node (root is empty if so it will inserr itself as the root)
    if (*node == nullptr) {
        *node = new Node(matriculation_number,name,programme);
        (*node)->left = nullptr;
        (*node)->right = nullptr;
    } else {
        if (matriculation_number < (*node)->matriculation_number){
            add_student_recursive(&((*node)->left),matriculation_number, name ,programme);
        } 
        else{
            add_student_recursive(&((*node)->right),matriculation_number, name ,programme);
        }
    }
}
    

bool StudentRecordSystem::find_student_by_matriculation(int matriculation_number) 
{
    return find_student_by_matriculation_recursive(root, matriculation_number);
}

//Uses the matriculation number to find if a student is in the tree returning a boolean value 
bool StudentRecordSystem::find_student_by_matriculation_recursive(Node *node, int matriculation_number) 
{
    //Creating the logic that if node is found we set the flag to TRUE
   if (node == nullptr){
        return false;
   }


    // Once the tempory node contatining the pre determenend 
    //matriculation number it will se the flag to true
    if (node->matriculation_number == matriculation_number){
        return true;
    }



    if (matriculation_number < node->matriculation_number) {
            return find_student_by_matriculation_recursive(node->left, matriculation_number);
    } else {
        return find_student_by_matriculation_recursive(node->right, matriculation_number);
    }
}

int StudentRecordSystem::lookup_matriculation_by_name(string name) 
{
    return lookup_matriculation_by_name_recursive(root, name);
}

/*Recursivley searches the binary trees left branches first then right to get the name from every node
which is then compared against node->name to check which is a pre determined name*/
int StudentRecordSystem::lookup_matriculation_by_name_recursive(Node *node, string name) 
{
   if (node == nullptr) {
    return -1;
   }

    // Repeadtly calls on itself unitil it encourters nulptr 
   int result = lookup_matriculation_by_name_recursive(node->left, name);
   if (result != -1) {
    return result;
   }

   if(node->name == name){
    return node->matriculation_number;
   }
    return lookup_matriculation_by_name_recursive(node->right, name);
}
   

int StudentRecordSystem::number_enrolled_students() 
{
    return number_enrolled_students_recursive(root);
}

//Recursivly goes through the whole trees left branches then right branches and then add 1 to account for root node
int StudentRecordSystem::number_enrolled_students_recursive(Node *node) 
{
    if (node == nullptr) {
        return 0;
    }

    int left_counter = number_enrolled_students_recursive(node->left);
    int right_counter = number_enrolled_students_recursive(node->right);

    return left_counter + right_counter + 1;
}

void StudentRecordSystem::remove_student(int matriculation_number) 
{
    remove_student_recursive(&root, matriculation_number);
}

//Goes through left side first and deletes each node and then does the same on the right using matriculation for traveral
void StudentRecordSystem::remove_student_recursive(Node **node, int matriculation_number) 
{
    if (node == nullptr) {
        return;
    }

    if (matriculation_number < (*node)->matriculation_number) {
        delete node;
            return delete_tree((*node)->left);
    } else {
        delete node;
        return delete_tree((*node)->right);
    }
    root = nullptr;
}


string StudentRecordSystem::print_student_details() 
{
    return print_student_details_recursive(root);
  
}

string StudentRecordSystem::print_student_details_recursive(Node *node) 
{
    string result;
    if (node == nullptr) 
	{
        return result;
    }

    result += print_student_details_recursive(node->left);
    result += std::to_string(node->matriculation_number) + "," + node->name + 
									"," + node->programme + "\n";
    result += print_student_details_recursive(node->right);

    return result;
}


void StudentRecordSystem::save_to_file(string filename) 
{
    //write your code to save to file,
	//calling the save_to_file recursive method below to visit
	//the nodes using a preorder traversal
}

void StudentRecordSystem::save_to_file_recursive(Node *node, ofstream& file) 
{
    //write your code here to visit the nodes using a preorder traversal
	//and write them to file
}

void StudentRecordSystem::load_from_file(string filename) 
{
    //write your code to load from a file,
	//calling the load_to_file recursive method below to add
	//each line of the file as a node
}

 