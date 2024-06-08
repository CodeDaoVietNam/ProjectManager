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


void calculateStudentGPA (Student *student , Course* courseList)
{
    // tính tổng điểm của của các học sinh đó học bằng tổng của điểm tổng kết nhân với số tín chỉ 
    double TotalMarkInSemester = 0;
    int ToTalCredits = 0;
    // Tạo một danh sách tạm để lưu danh sách các khoa học
    Course * courseTemp = courseList;
    while(courseTemp!= NULL)
    {
        // Tạo một danh  sách lưu tạm danh sách học sinh có trong khoa học đó
        Student * courseStudent = courseTemp->studentList;
        while(courseStudent!= NULL)
        {
            // so sánh từng sinh viên trong khóa học với mssv của sinh viên cần tính GPA
            if(courseStudent->StudentID == student->StudentID)
            {
                // cộng dồn theo tín chỉ nè
                TotalMarkInSemester += courseStudent->totalMark*courseStudent->credits;
                ToTalCredits += courseStudent->credits;
                break;
            }
            courseStudent = courseStudent->next;
        }
        // nếu đã tính được điểm học sinh của môn học này rồi chuyển sang check xem môn học khác học sinh ấy có học hay không
        courseTemp = courseTemp->next;
    }
    if(ToTalCredits >0)
    {
    //    student->gpa = TotalMarkInSemester/ToTalCredits;
    }
}


void viewClassScoreBoard (Semester * semester , const string & className)
{
    // tạo một Danh sách liên kết courseList tạm để lưu danh sách khoa học của học kỳ này 
    Course * courseList = semester->courseList;
    while(courseList != NULL){
        if(courseList->className == className)
        {
            cout<<"Course : "<<courseList->courseName<<endl;
            // trong khóa học đó sẽ có danh sách sinh viên đăng ký khóa học đó 
            Student *student = courseList->studentList;
            while(student != NULL)
            {
                calculateStudentGPA(student,courseList);
                cout<<"NO : "<<student->No<<endl;
                cout<<"StudentID : "<<student->StudentID<<endl;
                cout<<"Student ToTalMark : "<<student->totalMark<<endl;
                // in ra các kiểu thuôc tính của một học sinh trong lớp (có ham sẵn ) chỉ cần in thêm và tính toán gpa 
            }
            student =student->next;
        }
        // tiep tuc kiem tra trong cac khoa hoc khac co ten lop can in khong
        courseList = courseList->next;
    }
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