#ifndef _SYSTEM_H_
#define _SYSTEM_H_
#include "lib.h"
#include "struct.h"
#include"class.h"
#include"manage.h"
#include"student.h"
void saveStudent(std::ofstream& ofs, Student* student);
void saveCourse(std::ofstream& ofs, Course* course);
void saveSemester(std::ofstream& ofs, Semester* semester);
void saveClass(std::ofstream& ofs, Class* classPtr);
void saveSchoolYear(std::ofstream& ofs, SchoolYear* schoolYear);
void saveData(const std::string& filename, SchoolYear* schoolYear);
void loadStudent(std::ifstream& ifs, Student*& studentList);
void loadCourse(std::ifstream& ifs, Course*& courseList);
void loadSemester(std::ifstream& ifs, Semester*& semesterList);
void loadClass(std::ifstream& ifs, Class*& classList);
void loadSchoolYear(std::ifstream& ifs, SchoolYear*& schoolYearList);
void loadData(const std::string& filename, SchoolYear*& schoolYearList);
#endif