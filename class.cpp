#include"class.h"
// hàm tạo lớp học
Class *CreateClass(string className)
{
    Class * newClass = new Class;
    newClass->className = className;
    newClass->StudentList = nullptr;
    newClass->next = nullptr;
    return newClass;
}
// add ma khong dung pTail , đỡ rối
void addStudentToClass (Class*cls , Student *student)
{
    if(cls->StudentList == NULL)
    {
        cls->StudentList = student;
        return;
    }
    Student * tmp = cls->StudentList;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = student;
}

