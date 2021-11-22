#include "Student.h"

typedef struct StudentHandler* student_handler_pt;

student_handler_pt student_handler_create();
void student_handler_print_studentInfo(student_pt student);
void student_handler_print_AllStudentsInfo(student_handler_pt self);
student_pt student_handler_search_StudentById(int id);
student_pt student_handler_search_StudentByLastName(char lastName[45]);
void student_handler_add_student(student_handler_pt self, student_pt student);