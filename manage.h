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

// hàm thêm year vào listschoolyear
bool addSchoolYearToListYear(SchoolYear* newYear, SchoolYear* listYear);

// hàm thêm học kỳ vào năm học 
void addSemesterToSchoolYear(SchoolYear* schoolYear, Semester* semester) ;

// hàm thêm lóp học vào năm học 
void addClassToSchoolYear(SchoolYear* schoolYear, Class* cls) ;

// hàm cập nhật khoa học
void updateCourse(Course* course, const string& newCourseName, const string& newTeacherName, int newCredits, int newMaxStudents, const string& newDayOfWeek, const string& newSession);

// hàm xóa sinh viên ra khỏi khoa học 
void removeStudentFromCourse(Course* course, const string& studentID);

// hàm xóa khóa học ra khỏi học kỳ
void deleteCourse(Semester* semester, const string& courseID);

// hàm xuất danh sách lớp học trong năm học
void viewClassesInYear(SchoolYear* schoolYear);

//hàm xuất course ra màn hình 
void printCourse(Course* course);

// hàm xuất course trong học kỳ
void viewCoursesInSemester(Semester* semester);

typedef int(*PrintOneStudent)(Student* student);
// hàm xuất danh sách học sinh trong lớp học
void viewStudentsInClass(Class* cls, PrintOneStudent print, int typePrint);

//hàm update student result
void updateStudentResult ();

// hàm xuất danh sách học sinh trong khóa học
void viewStudentsInCourse(Course* course);
typedef int(*PrintCourse)(Course* course);
// hàm xuất khóa học kiểu bảng, từng thông tin, chỉ xuất ID khóa học
int printCourse01(Course* course);
int printCourse02(Course* course);
int printCourse03(Course* course);

// hàm xuát danh sách khóa học trong một học kỳ
void viewCoursesInSemester(Semester* semester, PrintCourse printNumber, int typePrint);
 
//hàm xuất file học sinh trong môn học có các điểm số
void exportStudentListInCourseToCSV(Course* course, const string& filename);

// hàm đọc file
void ImportScoreBoard (Course *course , const string & filePath);

// hàm in kết quả khóa học của một sinh viên
void viewStudentCourseResult(const string& studentID, Course* course);

// hàm in điểm của sinh viên
void printStudentScore(Student* student);

// hàm in bảng điểm của tất cả học sinh trong lớp học
void viewScoreBoard(Course* course);

// hàm tìm năm học
SchoolYear* findSchoolYearInList(SchoolYear* list, const string& year);

// hàm tìm học kỳ trong năm học
Semester* findSemester(SchoolYear* year, int numSemester);

#endif