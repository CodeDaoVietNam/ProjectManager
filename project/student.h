#ifndef _STUDENT_H_
#define _STUDENT_H_
#include"class.h"
#include "struct.h"
void importStudentsFromCSV(Class* cls, const string& filePath);
void deleteStudentList(Student* pHead);
Student* createStudent(int no , string studentID, string firstName, string lastName , string gender ,string dob , string socialID, string className);
#endif