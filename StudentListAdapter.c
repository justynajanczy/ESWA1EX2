#include "StudentList.h"
#include "LinkedList.h"

#include "stdlib.h"

typedef struct StudentList
{
	linkedlist_t list;
}StudentList;

student_list_t student_list_create(void)
{
	student_list_t student_list = (student_list_t)malloc(sizeof(StudentList));
	student_list->list = linked_list_create();
}

list_returnCode_t student_list_add_student(student_list_t self, student_pt student)
{
	linked_list_add_item(self->list, student);
}

list_returnCode_t student_list_get_student(student_list_t self, student_pt* student, int index)
{
	student_pt temp = malloc(sizeof(StudentList));
	temp = (student_pt)linked_list_peekItemByIndex(self->list, index);
	*student = temp;
}

list_returnCode_t student_list_remove_student(student_list_t self, student_pt student)
{
	linked_list_remove_item(self->list, student);
}

int student_list__no_of_students(student_list_t self)
{
	return linked_list_no_of_items(self->list);
}