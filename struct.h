#ifndef _STRUCT_H_
#define _STRUCT_H_
#include "lib.h"
struct User{
    string userName;
    string password;
    string firstName;
    string lastName;
    string studentID;
    int userType;
    User *next;
};
struct Date
{
	int Day, Month, Year;
};
struct Time
{
	int Hour, Minute;
};
struct Student
{
    int No;
    string StudentID;
    string FirstName;
    string LastName;
    string Gender;
    string dob;
    string SocialID;
    string className;
    double totalMark = -1;
    double finalMark = -1;
    double midtermMark = -1;
    double otherMark = -1;
    double semesterGPA[3] = {-1, -1, -1};
    int credits[3] = { 0,0,0 };
    double yearGpa = 0;
    Student* next ;
};
struct Course
{
    string courseID;
    string courseName;
    string className;
    string teacherName;
    int credits; // tín chỉ 
    int maxStudents;
    string dayOfWeek;// ngày trong tuần
    string session;
    Student* studentList;
    Course *next ;
};
struct Class {
   string className;
   Student *StudentList;
   Class *next;
};
struct Semester
{
    int semesterNumber;
    string schoolYear;
    string startDate;
    string endDate;
    Course* courseList;
    Semester *next;
};
struct SchoolYear
{
   string year;
   Semester* semesterList;
   Class * classList;
   SchoolYear *next;
};
#endif