#ifndef _STUDENT_H_
#define _STUDENT_H_
#include"class.h"
#include "struct.h"
#include"manage.h"
#include"lib.h"
void importStudentsFromCSV(Class* cls, const string& filePath);
void deleteStudentList(Student* pHead);
Student* createStudent(int no , string studentID, string firstName, string lastName , string gender ,string dob , string socialID, string className);
typedef int(*PrintOneStudent)(Student* student);
int printStudent01(Student* student);
int printStudent02(Student* student);
void importCourseStudentsFromCSV(Course* course, const string& filePath);
// hàm xem điểm của một lớp bất kỳ có tên lớp
void viewClassScoreBoard(Class* classList, Course* courseList, const string& className);
Student* findStudentInCourse(Course* course, const string& studentID);
void  calculateYearGpa(Student* student);
void calculateSemesterGPA(Student* student, Course* courseList, int semesterNumber);
#endif