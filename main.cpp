#include"struct.h"
#include"manage.h"
#include"student.h"
#include"class.h"
int main()
{
    Semester* semester = nullptr;
    createSemester(1,"2023-2024","07.07/2023","07/07/2024");
    Course* course = createCourse("23120368","VTP","23CTT5","Pham Le Thanh Tu",3,50,"Mon","S1");
    addCourseToSemester(semester,course);
    importCourseStudentsFromCSV(course,"VTP.csv");
    viewStudentsInCourse(course);
    return 0;
}