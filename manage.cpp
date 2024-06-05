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
    if (semester == NULL)
    {
        return;
    }
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
    if(course->studentList == NULL)
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
void viewClassesInYear(SchoolYear* schoolYear)
{
    if(!schoolYear->classList) return;
    Class* tem = schoolYear->classList;
    int count = 1;
    cout << "No  |" << " Class Name " << endl;
    while(tem) {
        cout << setw(6) << count << tem->className << endl;
        count++;
        tem = tem->next;
    }
}

void viewStudentsInClass(Class* cls)
{
    Student* student = cls->StudentList;
    if(student == NULL)
    {
        cout<<"There aren't any student in this class \n";
        return;
    }
    while(student != NULL)
    {
        PrintStudent(student,printStudent01);
        student = student ->next;
    }
}

void viewStudentsInCourse(Course* course)
{
    Student* student = course->studentList;
    if(student == NULL)
    {
        cout<<"There aren't any student in this course \n";
        return;
    }
    while(student != NULL)
    {
        PrintStudent(student,printStudent01);
        student = student ->next;
    }
}

int printCourse01(Course* course){
    if(!course) return 0;
    cout << course->courseID << string(11 - course->courseID.size(), ' ');
    cout << course->courseName << string(31 - course->courseName.size(), ' ');
    cout << course->className << string(12 - course->className.size(), ' ');
    cout << course->teacherName << string(31 - course->teacherName.size(), ' ');
    cout << course->dayOfWeek << string(15 - course->dayOfWeek.size(), ' ');
    return 1;
}

int printCourse02(Course* course){
    if(!course) return 0;
    cout << "CourseID: " << course->courseID << endl;
    cout << "Course name: " << course->courseName << endl;
    cout << "Class: " << course->className << endl;;
    cout << "Teacher Name: " << course->teacherName << endl;;
    cout << "Day of weak: " << course->dayOfWeek << endl;
    return 2;
}
 int printCourse03(Course* course){
    if(!course) return 0;
    cout << course->courseID << ", ";
    return 3;
 }

void viewCoursesInSemester(Semester* semester, PrintCourse printNumber)
{
    if(!semester->courseList) return;
    Course* tem = semester->courseList;
    if(printNumber(tem) == 1){
        int count = 1;
        cout << "                          " << "ALL COURSE IN SEMESTER " << semester->semesterNumber << " IN " << semester->schoolYear << endl;
        cout << "|No   |CourseID  |Course Name                   |Class name |Teacher Name                  |Day of weak     |" << endl;
        cout << "------------------------------------------------------------------------------------------------------------" << endl;
        while(tem){
            cout << " " << setw(5) << count;
            printCourse01(tem);
            cout << endl;
            tem = tem->next;
            count++;
        }
    }
    else {
        cout << "                          " << "ALL COURSE IN SEMESTER " << semester->semesterNumber << " IN " << semester->schoolYear << endl;
        while(tem){
            printCourse01(tem);
            cout << endl;
            tem = tem->next;
        }
    }
    
}

void exportStudentListInCourseToCSV(Course* course, const string& filename){
    if(!course) return;
    ofstream file;
    file.open(filename);
    if(!file.is_open()){
        cout << "Failed to open file.\n";
        return;
    }
    Student* tem = course->studentList;
    file << "No,StudentID,FullName,totalMark,finalMark,midtermMark,otherMark\n";
    while(tem){
        string fullname = tem->LastName + " " + tem->FirstName;
        file << tem->No << ",";
        file << tem->StudentID << ",";
        file << fullname << ",,,," << endl;
        tem = tem->next;
    }  
    file.close();
    cout << "Export sucessful.\n";
}

void ImportScoreBoard (Course *course , const string & filePath)
{
    ifstream file(filePath);
    if(file.is_open() == false)
    {
        cout<<"Failed to open file to read data .\n";
        return ;
    }
    string tmp ;
    Student * student = course->studentList;
    getline(file, tmp);
    while(!file.eof() && student)
    {
        getline(file, tmp);
        stringstream ss (tmp);
        string studentId , FullName;
        string no ;
        double TotalMark , FinalMark , MidtermMark , OtherMark;
        string tmp;
        getline(ss,no,',');
        int NO = stoi (no);
        getline(ss,studentId,',');
        getline(ss,FullName,',');
        getline(ss,tmp,',');
        TotalMark = stod(tmp);
        getline(ss,tmp,',');
        FinalMark = stod (tmp);
        getline(ss,tmp,',');
        MidtermMark = stod(tmp);
        getline(ss,tmp,',');
        OtherMark = stod(tmp);
        
        if(student->StudentID == studentId /*&& FullName == student->LastName + " " + student->FirstName*/)
            {
            student->totalMark = TotalMark;
            student->finalMark = FinalMark;
            student->midtermMark = MidtermMark;
            student->otherMark = OtherMark;
            }
        student = student->next;
    } 
    file.close();
}
 void viewStudentCourseResult(const string& studentID, Course* course)
 {
    if(!course->studentList) return;
    Student* tem = course->studentList;
    while(tem){
        if(tem->StudentID == studentID){
            cout << "-------- " << course->courseName << " course result " << " --------" << endl;
            cout << "Midterm Mark: " << tem->midtermMark << endl;
            cout << "Final Mark: " << tem->finalMark << endl;
            cout << "Other Mark: " << tem->otherMark << endl;
            cout << "TOTAL MARK: " << tem->totalMark << endl;
            break;
        }
        tem = tem->next;
    }
    if(!tem) cout << "This student was not found in this course.\n";
 }
 void printStudentScore(Student* student) {
     cout << student->StudentID << string(10 - student->StudentID.size(), ' ') << "|";
     string fullname = student->LastName + " " + student->FirstName;
     cout << fullname << string(30 - fullname.size(), ' ') << "|";
     cout << setw(6) << student->midtermMark << "      |";
     cout << setw(6) << student->finalMark << "      |";
     cout << setw(6) << student->otherMark << "      |";
     cout << setw(6) << student->totalMark << "      |" << endl;;
 }
 void viewScoreBoard(Course* course) {
     if (!course->studentList) return;
     Student* tem = course->studentList;
     int no = 1;
     cout << "+---------------------------------------------------------------------------------------------------+\n";
     cout << "|No   |StudentID |Full name                     |MidtermMark |FinalMark   |OtherMark   |TotalMark   |\n";
     cout << "+-----+----------+------------------------------+------------+------------+------------+------------+\n";
     while (tem) {
         cout << "|" << setw(4) << no << " |";
         no++;
         printStudentScore(tem);
         tem = tem->next;
     }
     cout << "+-----+----------+------------------------------+------------+------------+------------+------------+\n";
 }