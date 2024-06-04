#ifndef _MANAGE_H_
#define _MANAGE_H_
#include"struct.h"
#include"lib.h"
#include "student.h"
Course* createCourse(string courseID, string courseName, string className, string teacherName, int credits, int maxStudents, string dayOfWeek, string session) ;

Semester* createSemester(int semesterNumber, string schoolYear, string startDate, string endDate) ;

SchoolYear* createSchoolYear(string year) ;

// hàm thêm học sinh vào khoa học 
void addStudentToCourse(Course* course, Student* student);

// hàm thêm khoa học vào học kỳ 
void addCourseToSemester(Semester* semester, Course* course) ;

// hàm thêm học kỳ vào năm học 
void addSemesterToSchoolYear(SchoolYear* schoolYear, Semester* semester) ;

// hàm thêm lóp học vào năm học 
void addClassToSchoolYear(SchoolYear* schoolYear, Class* cls) ;

// hàm cập nhật khoa học
void updateCourse(Course* course, const string& newCourseName, const string& newTeacherName, int newCredits, int newMaxStudents, const string& newDayOfWeek, const string& newSession);

// hàm xóa sinh viên ra khỏi khoa học 
void removeStudentFromCourse(Course* course, const string& studentID);

// hàm xóa khoa học ra khỏi học kỳ
void deleteCourse(Semester* semester, const string& courseID);

// hàm xuất các lớp học trong năm học
void viewClassesInYear(SchoolYear* schoolYear);

//hàm xuất course ra màn hình 
void printCourse(Course* course);

// hàm xuất course trong học kỳ
void viewCoursesInSemester(Semester* semester);

// hàm xuat hoc sinh trong lop hoc
void viewStudentsInClass(Class* cls);

//hàm update student result
void updateStudentResult ();

#endif