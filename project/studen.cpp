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
void PrintStudent (Student *student,Print function)
{
    function(student);
}
void printStudent01(Student* student){
    cout << "StudentID: " << student->StudentID << endl;
    cout << "Name: " << student->LastName << " " << student->FirstName << endl;
    cout << "Class: " << student->className;
    cout << "Gender: " << student->Gender << endl;
    cout << "Date of birth: " << student->dob << endl;
    cout << "SocialID: " << student->SocialID << endl;
}