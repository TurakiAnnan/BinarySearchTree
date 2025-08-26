#pragma once
#include <string>
#include <fstream>

//Header for student_record_system.cpp
//Author Turaki Annan

// As name suggest this is the structure of a node 
struct Node 
{
public:
    // inititialising what a node is made up of
    int matriculation_number;
    std::string name;
    std::string programme;
    //Creating the branches for a node (the binary tree structure)
    Node* left;
    Node* right;
    //Node contrustuctor means the data will be stored in order of matriculation_numner,name.programme
    Node(int matriculation_number, std::string name, std::string programme);
};

class StudentRecordSystem {


public:
    StudentRecordSystem();
    ~StudentRecordSystem();

    //Providing the data that will create a student 
    void add_student(int matriculation_number, std::string name, std::string programme);
    //Matriculation number is used as the unique identifier of a student and a boolean value true if found and false if not
    bool find_student_by_matriculation(int matriculation_number);
    //Name is now used as the identifier for each student with a integer value (matriculation number) being returned
    int lookup_matriculation_by_name(std::string name);
    //A integer value represent the amount of student in the tree will be returned
    int number_enrolled_students();
    //Matriculation number will be used to search through each student when deleting them
    void remove_student(int matriculation_number);
    std::string print_student_details();
    void save_to_file(std::string filename);
    void load_from_file(std::string filename);
	
private:
    Node* root;

	std::string print_student_details_recursive(Node *node);
    // **node means that the tree itself will be added to and not a copy of the tree and the rest is used to create what will be inside a node
    void add_student_recursive(Node **node, int matriculation_number, std::string name, std::string programme);
    // Node *node sets up a node that will allow for a recrusive search through the tree using the matriculatio number
    bool find_student_by_matriculation_recursive(Node *node, int matriculation_number);
    // Node *node sets up a node that will allow for a recrusive search through the tree using the name
    int lookup_matriculation_by_name_recursive(Node *node, std::string name);
    // Node *node is used to search through the tree recursivly
    int number_enrolled_students_recursive(Node *node);
    // Node **node sets it so that the actuall tree itself will be edited and the matriculation as the key for traversal
    void remove_student_recursive(Node **node, int matriculation_number);
    void delete_tree(Node *node);
    void save_to_file_recursive(Node *node, std::ofstream &file);
 
};
