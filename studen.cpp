#include "student.h"
Date stringToDate(string date) {
	Date tem;
	string day = date.substr(0, date.find_first_of("/"));
	tem.Day = stoi(day);
	string month = date.substr(day.size() + 1, date.find_last_of("/") - date.find_first_of("/") - 1);
	tem.Month = stoi(month);
	string year = date.substr(date.find_last_of('/') + 1, date.size() - date.find_last_of('/') - 1);
	tem.Year = stoi(year);
	return tem;
}
Student* createStudent(int no,string studentID,string firstName,string lastName,string gender ,string dob ,string socialID,string className)
{
    Student* newStudent = new Student ;
    newStudent->No = no;
    newStudent->StudentID = studentID;
    newStudent->FirstName = firstName;
    newStudent->LastName = lastName;
    newStudent->Gender = gender;
    newStudent->dob = dob;
    newStudent->SocialID = socialID;
    newStudent->className = className;
    newStudent->next = nullptr;
    return newStudent;
}
void importStudentsFromCSV(Class* cls, const string& filePath)
{
    ifstream file(filePath);
    if(file.is_open()==false)
    {
        cout<<"Failed to open file.\n";
        return ;
    }
    string tmp ;
    getline(file,tmp);
    while(getline(file,tmp))
    {
        stringstream ss (tmp);
        string no ,studentID ,firstName ,lastName,gender ,dob,socialID;
        getline(ss,no,',');
        getline(ss,studentID,',');
        getline(ss,firstName,',');
        getline(ss,lastName,',');
        getline(ss,gender,',');
        getline(ss,dob,',');
        getline(ss,socialID,',');
        int No = stoi(no);
        Student* student = createStudent(No,studentID,firstName,lastName,gender,dob,socialID,cls->className);
        addStudentToClass(cls,student);
    }
}
void deleteStudentList(Student* pHead){
    Student* tem = pHead;
    Student* next = nullptr;
    if(!tem) return;
    while(tem){
        next = tem->next;
        delete tem;
        tem = next;
    }
    pHead = nullptr;
}
typedef int(*PrintOneStudent)(Student* student);
int printStudent02(Student* student){
    cout << "StudentID: " << student->StudentID << endl;
    cout << "Name: " << student->LastName << " " << student->FirstName << endl;
    cout << "Class: " << student->className << endl;
    cout << "Gender: " << student->Gender << endl;
    cout << "Date of birth: " << student->dob << endl;
    cout << "SocialID: " << student->SocialID << endl << endl;
    return 2;
}
int printStudent01(Student* student) {
    cout << "|" << setw(4) << student->No << " |";
    cout << student->StudentID << string(10 - student->StudentID.size(), ' ') << "|";
    string fullname = student->LastName + " " + student->FirstName;
    cout << fullname << string(30 - fullname.size(), ' ') << "|";
    cout << student->Gender << string(8 - student->Gender.size(), ' ') << "|";
    cout << student->dob << string(13 - student->dob.size(), ' ') << "|";
    cout << student->SocialID << string(15 - student->SocialID.size(), ' ') << "|";
    cout << setw(6) << student->credits << " |";
//    cout << setw(4) << student->gpa << "  |\n";
    return 1;
}
void importCourseStudentsFromCSV(Course* course, const string& filePath)
{
    ifstream file;
    file.open(filePath);
    if(file.is_open()==false)
    {
        cout<<"Failed to open file.\n";
        return ;
    }
    string tmp ;
    getline(file,tmp);
    while(getline(file,tmp,'\n'))
    {
        stringstream ss (tmp);
        string no ,studentID ,firstName ,lastName,gender ,dob,socialID;
        getline(ss,no,',');
        getline(ss,studentID,',');
        getline(ss,firstName,',');
        getline(ss,lastName,',');
        getline(ss,gender,',');
        getline(ss,dob,',');
        getline(ss,socialID,',');
        int No = stoi(no);
        Student* student = createStudent(No,studentID,firstName,lastName,gender,dob,socialID,course->className);
        addStudentToCourse(course, student);
    }
}
void calculateSemesterGPA(Student* student, Course* courseList, int semesterNumber)
{
    double TotalGpa = 0;
    int  totalCredits = 0;
    Course* course = courseList;
    while (course != NULL)
    {
        Student* tmp = findStudentInCourse(course, student->StudentID);
        if (tmp != NULL)
        {
            TotalGpa += tmp->totalMark * course->credits;
            totalCredits += course->credits;
        }
        course = course->next;
    }
    student->semesterGPA[semesterNumber - 1] = (double)TotalGpa / totalCredits;
    student->credits[semesterNumber - 1] = totalCredits;

}
void  calculateYearGpa(Student* student)
{
    int ToTalCredits = 0;
    double ToTal = 0;
    for (int i = 0; i < 3; i++)
    {
        ToTalCredits += student->credits[i];
        if (student->semesterGPA[i] != -1)
        {
            ToTal += 1.00*student->semesterGPA[i] * student->credits[i];
        }
    }
    student->yearGpa = ToTal / (1.00*ToTalCredits);
}

Student* findStudentInClass(Class* cls, const string& studentID) {
    if (!cls->StudentList) return NULL;
    Student* tem = cls->StudentList;
    while (tem) {
        if (tem->StudentID == studentID) {
            return tem;
        }
    }
    return NULL;
}
Student* findStudentInCourse(Course* course, const string& studentID) {
    if (!course->studentList) return NULL;
    Student* tem = course->studentList;
    while (tem) {
        if (tem->StudentID == studentID) {
            return tem;
        }
    }
    return NULL;
}
void ViewClassScoreBoard(Class* cls);