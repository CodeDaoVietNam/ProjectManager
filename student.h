#ifndef _STUDENT_H_
#define _STUDENT_H_
#include"class.h"
#include "struct.h"
#include"manage.h"
void importStudentsFromCSV(Class* cls, const string& filePath);
void deleteStudentList(Student* pHead);
Student* createStudent(int no , string studentID, string firstName, string lastName , string gender ,string dob , string socialID, string className);
typedef int(*PrintOneStudent)(Student* student);
int printStudent01(Student* student);
int printStudent02(Student* student);
void importCourseStudentsFromCSV(Course* course, const string& filePath);
void calculateStudentGPA (Student *student , Course* courseList);
// hàm xem điểm của một lớp bất kỳ có tên lớp
void viewClassScoreBoard (Semester * semester , const string & className);
#endif