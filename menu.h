#ifndef _MENU_H
#define _MENU_H
#include"student.h"
#include"manage.h"
#include"struct.h"
#include"lib.h"
#include"log.h"
#include"system.h"
#include"class.h"
#include<Windows.h>
using namespace std;
void displayMainMenu();
void setConsoleColor(int background, int text);
void clearConsole();

void displayStaffMenu();

void displayStudentMenu();
Semester* findSemester(SchoolYear* schoolYearList, const std::string& className);
Course* findCourse(SchoolYear* schoolYearList, const std::string& courseID);
Class* findClass(SchoolYear* schoolYearList, const std::string& className);
void handleStaffChoice(int choice, SchoolYear*& schoolYearList);
void handleStudentChoice(int choice, User* currentUser, SchoolYear* schoolYearList);

Student* findStudentInSchoolYear(SchoolYear* schoolYearList, const std::string& studentID);

//void Menu1();
//void Menu2();
//void Menu3();
//void Menu4();
//void Menu3p3();
#endif