#include"struct.h"
#include"manage.h"
#include"student.h"
#include"class.h"
int main()
{
    SchoolYear* schoolYear = createSchoolYear("2023-2024");
    Semester* semester = nullptr;
    addSemesterToSchoolYear(schoolYear, semester);
    Class* CTT5 = CreateClass("23CTT5");
    importStudentsFromCSV(CTT5, "CTT5.csv");
    viewStudentsInClass(CTT5);
    addClassToSchoolYear(schoolYear, CTT5);
    createSemester(1, "2023-2024", "07.07/2023", "07/07/2024");
    Course* course = createCourse("23120368","VTP","23CTT5","Pham Le Thanh Tu",3,50,"Mon","S1");
    addCourseToSemester(semester,course);
    importCourseStudentsFromCSV(course,"VTP.csv");
    viewStudentsInCourse(course);
    ImportScoreBoard(course, "ScoreBoard.csv");
    viewStudentCourseResult("23120368", course);

    return 0;
}