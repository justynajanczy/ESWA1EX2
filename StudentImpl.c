#define _CRT_SECURE_NO_DEPRECATE

#include "Student.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
	char first_name[45];
	char last_name[45];
	int student_id;
	char nationality[45];
} Student;

student_pt student_create_student(char firstName[45], char lastName[45], int studentId, char nationality[45])
{
	student_pt self = (student_pt)malloc(sizeof(Student));

	strcpy(self->first_name, firstName);
	strcpy(self->last_name, lastName);
	self->student_id = studentId;
	strcpy(self->nationality, nationality);

	return self;
}

void student_print_info(student_pt self)
{
	printf("Student info: %s %s %d %s \n", self->first_name, self->last_name, self->student_id, self-> nationality);
}



