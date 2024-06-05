#ifndef _STUDENT_H_
#define _STUDENT_H_
#include"class.h"
#include "struct.h"
#include"manage.h"
void importStudentsFromCSV(Class* cls, const string& filePath);
void deleteStudentList(Student* pHead);
Student* createStudent(int no , string studentID, string firstName, string lastName , string gender ,string dob , string socialID, string className);
typedef void (*Print) (Student *);
void PrintStudent (Student *,Print function);
void printStudent01(Student* student);
void importCourseStudentsFromCSV(Course* course, const string& filePath);
#endif