#pragma once

#include "LinkedList.h"
#include "Student.h"

typedef struct StudentList* student_list_t;

student_list_t student_list_create(void);
list_returnCode_t student_list_add_student(student_list_t self, student_pt student);
list_returnCode_t student_list_get_student(student_list_t self, student_pt* student, int index);
list_returnCode_t student_list_remove_student(student_list_t self, student_pt student);
int student_list__no_of_students(student_list_t self);
void linked_list_print_elements(student_list_t self);