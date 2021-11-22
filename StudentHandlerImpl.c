#include "StudentHandler.h"
#include "Student.h"
#include "StudentList.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct StudentHandler
{
	student_list_t student_list;
} StudentHandler;

student_handler_pt student_handler_create()
{
	student_handler_pt student_handler = (student_handler_pt)malloc(sizeof(StudentHandler));
	student_handler->student_list = student_list_create();
}

void student_handler_print_studentInfo(student_pt student)
{
	student_print_info(student);
}

void student_handler_print_AllStudentsInfo(student_handler_pt self)
{
	//should be for loop with size of the list
	for (int i = 0; i < 2; i++)
	{
		student_pt* t = (student_pt)malloc(sizeof(student_pt));
		linked_list_peekItemByIndex(t, i);
		student_handler_print_studentInfo(*t);
		free(t);
	}
}

//student_pt student_handler_search_StudentById(int id)
//{
//
//}
//
//student_pt student_handler_search_StudentByLastName(char lastName[45])
//{
//
//}
//
void student_handler_add_student(student_handler_pt self, student_pt student)
{
	student_list_add_student(self -> student_list, student);
}