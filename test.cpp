/*
 *Author: Simon Powers
 *Test driver for the StudentRecordSystem class.
 *
 */ 

#include "student_record_system_HEADER.h"
#include <iostream>
#include <string>
using namespace std;

/* 
 * Function to display test result
 * Parameters: result - true if the test passed
 *			   message - string describing the test
 */
void display_result(bool result, const std::string &message) {
    if (result)
        cout << "[PASS] " << message << endl;
    else
        cout << "[FAIL] " << message << endl;
}

int main() {
    // Test Case 1: Adding students
    StudentRecordSystem system;
    system.add_student(300000, "Charlie", "Software Engineering");
    system.add_student(200000, "Bob", "Computing");
    system.add_student(100801, "David", "Games Development");
    system.add_student(200500, "Alice", "Computer Science");
    system.add_student(400000, "Eve", "Games Development");
    system.add_student(350000, "Frank", "Software Engineering");
	system.add_student(310000, "Claire", "Computing");
	system.add_student(500550, "Alex", "Computer Science");

    // Check if students are added correctly
    string expected_result =
        "100801,David,Games Development\n"
        "200000,Bob,Computing\n"
        "200500,Alice,Computer Science\n"
        "300000,Charlie,Software Engineering\n"
        "310000,Claire,Computing\n"
		"350000,Frank,Software Engineering\n"
		"400000,Eve,Games Development\n"
		"500550,Alex,Computer Science\n";
    string result = system.print_student_details();
    display_result(result == expected_result, "Test 1: Adding students");

    // Test Case 2a: Finding a student by matriculation number
    display_result(system.find_student_by_matriculation(310000) == true,
        "Test 2a: Finding an existing student by matriculation number");
		
	// Test Case 2a: Finding a student by matriculation number
    display_result(system.find_student_by_matriculation(100000) == false,
        "Test 2a: Finding a non-existing student by matriculation number");

    // Test Case 3: Lookup matriculation number by name
    display_result(system.lookup_matriculation_by_name("Alice") == 200500,
        "Test 3: Lookup matriculation number by name");

    // Test Case 4: Number of enrolled students
    display_result(system.number_enrolled_students() == 8,
        "Test 4: Number of enrolled students");

    //Checking for deletion
    

	// Test Case 5: Save and load student records
    system.save_to_file("student_records.txt");
    StudentRecordSystem loaded_system;
    loaded_system.load_from_file("student_records.txt");
    display_result(loaded_system.print_student_details() == 
		"100801,David,Games Development\n"
        "200000,Bob,Computing\n"
        "200500,Alice,Computer Science\n"
        "300000,Charlie,Software Engineering\n"
        "310000,Claire,Computing\n"
		"350000,Frank,Software Engineering\n"
		"400000,Eve,Games Development\n"
		"500550,Alex,Computer Science\n",
		"Test 5: Save and load student records");

    // Test Case 6a: Removing a student (Case 1: Node with no children)
    system.remove_student(100801);
    display_result(system.print_student_details() ==
        "200000,Bob,Computing\n"
        "200500,Alice,Computer Science\n"
        "300000,Charlie,Software Engineering\n"
        "310000,Claire,Computing\n"
		"350000,Frank,Software Engineering\n"
		"400000,Eve,Games Development\n"
		"500550,Alex,Computer Science\n",
		"Test 6a: Removing a student (Node with no children)");

    // Test Case 6b: Removing a student (Case 2: Node with one child)
    system.remove_student(350000);
    display_result(system.print_student_details() ==
        "200000,Bob,Computing\n"
        "200500,Alice,Computer Science\n"
        "300000,Charlie,Software Engineering\n"
        "310000,Claire,Computing\n"
		"400000,Eve,Games Development\n"
		"500550,Alex,Computer Science\n",
        "Test 6b: Removing a student (Node with one child)");

    // Test Case 6c: Removing a student (Case 3: Node with two children)
    system.remove_student(300000);
    display_result(system.print_student_details() ==
        "200000,Bob,Computing\n"
        "200500,Alice,Computer Science\n"
        "310000,Claire,Computing\n"
		"400000,Eve,Games Development\n"
		"500550,Alex,Computer Science\n",
        "Test 6c: Removing a student (Node with two children)");
    return 0;
}

