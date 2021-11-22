// Ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

#include "Student.h"
#include "StudentList.h"
#include "StudentHandler.h"

int main()
{
    printf("Hello World!\n");

    student_list_t myList = student_list_create();
    student_handler_pt myHandler = student_handler_create();

    student_pt student1 = student_create_student("Justyna", "Janczy", 309958, "Poland");
    student_pt student2 = student_create_student("Sandra", "Grzelak", 309958, "Poland");

    student_handler_add_student(myHandler, student1);
    student_handler_add_student(myHandler, student2);

    student_handler_print_AllStudentsInfo(myHandler);

    //student_print_info(student1);
    //student_print_info(student2);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
