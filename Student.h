#pragma once
#include <stdint.h>

typedef struct Student* student_pt;

student_pt student_create_student(char first_name[45], char last_name[45], int student_id, char nationality[45]);
void student_print_info(student_pt self);

