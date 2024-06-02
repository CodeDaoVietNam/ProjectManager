#include "manage.h"
Course* createCourse(string courseID, string courseName, string className, string teacherName, int credits, int maxStudents, string dayOfWeek, string session) {
    Course* course = new Course;
    course->courseID = courseID;
    course->courseName = courseName;
    course->className = className;
    course->teacherName = teacherName;
    course->credits = credits;
    course->maxStudents = maxStudents;
    course->dayOfWeek = dayOfWeek;
    course->session = session;
    course->studentList = nullptr;
    course->next = nullptr;
    return course;
}

Semester* createSemester(int semesterNumber, string schoolYear, string startDate, string endDate) {
    Semester* semester = new Semester;
    semester->semesterNumber = semesterNumber;
    semester->schoolYear = schoolYear;
    semester->startDate = startDate;
    semester->endDate = endDate;
    semester->courseList = nullptr;
    semester->next = nullptr;
    return semester;
}

SchoolYear* createSchoolYear(string year) {
    SchoolYear* schoolYear = new SchoolYear;
    schoolYear->year = year;
    schoolYear->classList = nullptr;
    schoolYear->semesterList = nullptr;
    schoolYear->next = nullptr;
    return schoolYear;
}

void addCourseToSemester(Semester* semester, Course* course) {
    if(semester->courseList == NULL)
    {
        semester->courseList = course;
        return;
    }
    Course * tmp = semester->courseList;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = course;
}
void addSemesterToSchoolYear(SchoolYear* schoolYear, Semester* semester) {
    if(schoolYear->semesterList == NULL)
    {
        schoolYear->semesterList = semester;
        return;
    }
    Semester * tmp = schoolYear->semesterList;
    while(tmp ->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = semester;
}

void addClassToSchoolYear(SchoolYear* schoolYear, Class* cls) {
    if(schoolYear->classList == NULL)
    {
        schoolYear->classList = cls;
        return;
    }
    Class* tmp = schoolYear->classList;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = cls;
}

void addStudentToCourse(Course* course, Student* student)
{
    if(course->studentList != NULL)
    {
        course->studentList = student;
        return;
    }
    Student * tmp = course->studentList ;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = student;
}

void updateCourse(Course* course, const string& newCourseName, const string& newTeacherName, int newCredits, int newMaxStudents, const string& newDayOfWeek, const string& newSession)
{
    course->courseName = newCourseName;
    course->teacherName = newTeacherName;
    course->credits = newCredits;
    course->maxStudents = newMaxStudents;
    course->dayOfWeek = newDayOfWeek;
    course->session = newSession;
}
void removeStudentFromCourse(Course* course, const string& studentID)
{
    if(!course->studentList) 
    {
        return;
    }
    Student* tem = course->studentList;
    while(tem)
    {
        if(tem->next->StudentID == studentID)
        {
            break;
        }
        tem = tem->next;
    }
    if(tem && tem->next) {
        Student* rmStudent = tem->next;
        tem->next = rmStudent->next;
        delete rmStudent;
        cout << "Student removed from course.\n";
    }
    else {
        cout << "This student has not registered for the course yet.\n";
    }
}
void deleteCourse(Semester* semester, const string& courseID)
{
    if(!semester->courseList) {
        return;
    }
    Course* tem = semester->courseList;
    while(tem) {
        if(tem->next->courseID == courseID)
        {
            break;
        }
        tem = tem->next;
    }
    if(tem && tem->next) {
        Course* rmCourse = tem->next;
        tem->next = rmCourse->next;
        deleteStudentList(tem->studentList);
        delete tem;
        cout << "Course is deleted.\n";
    }
    else {
        cout << "Cannot find this course.\n";
    }
}
void viewClasses(SchoolYear* schoolYear){
    if(!schoolYear->classList) return;
    Class* tem = schoolYear->classList;
    int count = 0;
    cout << "No  |" << " Class Name " << endl;
    while(tem) {
        cout << setw(6) << count << tem->className << endl;
        count++;
        tem=tem->next;
    }
}
void viewStudentsInClass(Class* cls)
{
}