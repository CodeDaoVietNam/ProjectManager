#include "system.h"
#include"lib.h"
#include"class.h"
#include"manage.h"
#include"student.h"

void saveStudent(std::ofstream& ofs, Student* student) {
    while (student) {
        ofs.write((char*)&student->No, sizeof(student->No));
        size_t length = student->StudentID.length();
        ofs.write((char*)&length, sizeof(length));
        ofs.write(student->StudentID.c_str(), length);
        length = student->FirstName.length();
        ofs.write((char*)&length, sizeof(length));
        ofs.write(student->FirstName.c_str(), length);
        length = student->LastName.length();
        ofs.write((char*)&length, sizeof(length));
        ofs.write(student->LastName.c_str(), length);
        ofs.write((char*)&student->totalMark, sizeof(student->totalMark));
        ofs.write((char*)&student->finalMark, sizeof(student->finalMark));
        ofs.write((char*)&student->midtermMark, sizeof(student->midtermMark));
        ofs.write((char*)&student->otherMark, sizeof(student->otherMark));
        ofs.write((char*)student->semesterGPA, sizeof(student->semesterGPA));
        ofs.write((char*)&student->yearGpa, sizeof(student->yearGpa));
        student = student->next;
    }
}

void saveCourse(std::ofstream& ofs, Course* course) {
    while (course) {
        size_t length = course->courseID.length();
        ofs.write((char*)&length, sizeof(length));
        ofs.write(course->courseID.c_str(), length);
        length = course->courseName.length();
        ofs.write((char*)&length, sizeof(length));
        ofs.write(course->courseName.c_str(), length);
        length = course->teacherName.length();
        ofs.write((char*)&length, sizeof(length));
        ofs.write(course->teacherName.c_str(), length);
        ofs.write((char*)&course->credits, sizeof(course->credits));
        ofs.write((char*)&course->maxStudents, sizeof(course->maxStudents));
        length = course->dayOfWeek.length();
        ofs.write((char*)&length, sizeof(length));
        ofs.write(course->dayOfWeek.c_str(), length);
        length = course->session.length();
        ofs.write((char*)&length, sizeof(length));
        ofs.write(course->session.c_str(), length);
        length = course->className.length();
        ofs.write((char*)&length, sizeof(length));
        ofs.write(course->className.c_str(), length);
        saveStudent(ofs, course->studentList);
        course = course->next;
    }
}

void saveSemester(std::ofstream& ofs, Semester* semester) {
    while (semester) {
        ofs.write((char*)&semester->semesterNumber, sizeof(semester->semesterNumber));
        saveCourse(ofs, semester->courseList);
        semester = semester->next;
    }
}

void saveClass(std::ofstream& ofs, Class* classPtr) {
    while (classPtr) {
        size_t length = classPtr->className.length();
        ofs.write((char*)&length, sizeof(length));
        ofs.write(classPtr->className.c_str(), length);
        saveStudent(ofs, classPtr->StudentList);
        classPtr = classPtr->next;
    }
}

void saveSchoolYear(std::ofstream& ofs, SchoolYear* schoolYear) {
    while (schoolYear) {
        size_t length = schoolYear->year.length();
        ofs.write((char*)&length, sizeof(length));
        ofs.write(schoolYear->year.c_str(), length);
        saveClass(ofs, schoolYear->classList);
        saveSemester(ofs, schoolYear->semesterList);
        schoolYear = schoolYear->next;
    }
}

void saveData(const std::string& filename, SchoolYear* schoolYear) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }
    saveSchoolYear(ofs, schoolYear);
    ofs.close();
}


// load Data
void loadStudent(std::ifstream& ifs, Student*& studentList) {
    Student* tail = nullptr;
    while (ifs) {
        Student* student = new Student;
        ifs.read((char*)&student->No, sizeof(student->No));
        size_t length;
        ifs.read((char*)&length, sizeof(length));
        student->StudentID.resize(length);
        ifs.read(&student->StudentID[0], length);
        ifs.read((char*)&length, sizeof(length));
        student->FirstName.resize(length);
        ifs.read(&student->FirstName[0], length);
        ifs.read((char*)&length, sizeof(length));
        student->LastName.resize(length);
        ifs.read(&student->LastName[0], length);
        ifs.read((char*)&student->totalMark, sizeof(student->totalMark));
        ifs.read((char*)&student->finalMark, sizeof(student->finalMark));
        ifs.read((char*)&student->midtermMark, sizeof(student->midtermMark));
        ifs.read((char*)&student->otherMark, sizeof(student->otherMark));
        ifs.read((char*)student->semesterGPA, sizeof(student->semesterGPA));
        ifs.read((char*)&student->yearGpa, sizeof(student->yearGpa));
        student->next = nullptr;
        if (!tail) {
            studentList = tail = student;
        }
        else {
            tail->next = student;
            tail = student;
        }
    }
}

void loadCourse(std::ifstream& ifs, Course*& courseList) {
    Course* tail = nullptr;
    while (ifs) {
        Course* course = new Course;
        size_t length;
        ifs.read((char*)&length, sizeof(length));
        course->courseID.resize(length);
        ifs.read(&course->courseID[0], length);
        ifs.read((char*)&length, sizeof(length));
        course->courseName.resize(length);
        ifs.read(&course->courseName[0], length);
        ifs.read((char*)&length, sizeof(length));
        course->teacherName.resize(length);
        ifs.read(&course->teacherName[0], length);
        ifs.read((char*)&course->credits, sizeof(course->credits));
        ifs.read((char*)&course->maxStudents, sizeof(course->maxStudents));
        ifs.read((char*)&length, sizeof(length));
        course->dayOfWeek.resize(length);
        ifs.read(&course->dayOfWeek[0], length);
        ifs.read((char*)&length, sizeof(length));
        course->session.resize(length);
        ifs.read(&course->session[0], length);
        ifs.read((char*)&length, sizeof(length));
        course->className.resize(length);
        ifs.read(&course->className[0], length);
        loadStudent(ifs, course->studentList);
        course->next = nullptr;
        if (!tail) {
            courseList = tail = course;
        }
        else {
            tail->next = course;
            tail = course;
        }
    }
}

void loadSemester(std::ifstream& ifs, Semester*& semesterList) {
    Semester* tail = nullptr;
    while (ifs) {
        Semester* semester = new Semester;
        ifs.read((char*)&semester->semesterNumber, sizeof(semester->semesterNumber));
        loadCourse(ifs, semester->courseList);
        semester->next = nullptr;
        if (!tail) {
            semesterList = tail = semester;
        }
        else {
            tail->next = semester;
            tail = semester;
        }
    }
}

void loadClass(std::ifstream& ifs, Class*& classList) {
    Class* tail = nullptr;
    while (ifs) {
        Class* classPtr = new Class;
        size_t length;
        ifs.read((char*)&length, sizeof(length));
        classPtr->className.resize(length);
        ifs.read(&classPtr->className[0], length);
        loadStudent(ifs, classPtr->StudentList);
        classPtr->next = nullptr;
        if (!tail) {
            classList = tail = classPtr;
        }
        else {
            tail->next = classPtr;
            tail = classPtr;
        }
    }
}

void loadSchoolYear(std::ifstream& ifs, SchoolYear*& schoolYearList) {
    SchoolYear* tail = nullptr;
    while (ifs) {
        SchoolYear* schoolYear = new SchoolYear;
        size_t length;
        ifs.read((char*)&length, sizeof(length));
        schoolYear->year.resize(length);
        ifs.read(&schoolYear->year[0], length);
        loadClass(ifs, schoolYear->classList);
        loadSemester(ifs, schoolYear->semesterList);
        schoolYear->next = nullptr;
        if (!tail) {
            schoolYearList = tail = schoolYear;
        }
        else {
            tail->next = schoolYear;
            tail = schoolYear;
        }
    }
}

void loadData(const std::string& filename, SchoolYear*& schoolYearList) {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        std::cerr << "Error opening file for reading." << std::endl;
        return;
    }
    loadSchoolYear(ifs, schoolYearList);
    ifs.close();
}
