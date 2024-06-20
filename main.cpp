#include"struct.h"
#include"manage.h"
#include"student.h"
#include"class.h"
#include"menu.h"
#include "log.h"

int main()
{
    SchoolYear* ListSchoolYear = NULL;
    User* ListStaff = NULL;
    User* ListStudent = NULL;
    //System lay thong tin
    int mode = 1;
    Menu1();
    cout << "Enter your selection: ";
    cin >> mode;
    while (mode < 0 && mode > 3) {

        cout << "Wrong selection!\n";
        cout << "Enter your selection: ";
        cin >> mode; 
    }
    if (mode == 1) {
        //Staff login
        string password;
        string user;
        User* Staff;
        Menu2();
        //login
        Input_Username_Password(user, password);
        Staff = findUser(ListStaff, user);
        //Login thanh cong
        Menu3();
        int chose;
        cout << "Enter your selection: ";
        cin >> chose;
        while (chose != 8) {
            while (chose < 1 && chose > 8) {
                Menu3();
                cout << "Wrong selection!\n";
                cout << "Enter your selection: ";
                cin >> chose;
            }
            if (chose == 1) {
                system("cls");
                viewProfile(Staff);
            }
            if (chose == 2) {
                system("cls");
                changePassword(Staff);
            }
            if (chose == 3) {
                cout << "Menu creating.\n\n";
                Menu3p3();
                int chose3;
                cout << "Enter your selection: ";
                cin >> chose3;
                while (chose3 != 3) {
                    while (chose3 < 1 && chose3 > 3) {
                        Menu3p3();
                        cout << "Wrong selection!\n";
                        cout << "Enter your selection: ";
                        cin >> chose3;
                    }
                    if (chose3 == 1) {
                        system("cls");
                        cout << "Create Year. \n\n";
                        cout << "Press school year: ";
                        string year;
                        cin >> year;
                        createSchoolYear(year);
                        if (addSchoolYearToListYear) {
                            cout << "Creating school year " << year << " successfully.\n";
                        }
                        else cout << "Failed create new year.\n";
                    }
                    if (chose3 == 2) {
                        system("cls");
                        cout << "Create couse.\n\n";
                        cout << "Press the year contains the course: ";
                        string year;
                        cin >> year;
                        while (!findSchoolYearInList(ListSchoolYear, year)) {
                            cout << "Cannot find school year.\n";
                        }
                        cout << "Press semester order: ";
                        int numSemester;
                        cin >> numSemester;
                        //Tim hoc ky chua khoa hoc
                        Semester* curSemester = findSemester(findSchoolYearInList(ListSchoolYear, year), numSemester);
                        while (!curSemester) {
                            cout << "Cannot find semester.\n";
                            cout << "Press the year contains the course again: ";
                            cin >> year;
                            cout << "Press semester order: ";
                            cin >> numSemester;
                            Semester* curSemester = findSemester(findSchoolYearInList(ListSchoolYear, year), numSemester);
                        }
                        cout << "Press CourseID: ";
                        string courseid;
                        cin >> courseid;
                        cout << "Press course name: ";
                        string coursename;
                        getline(cin, coursename);
                        string classname, teachername, dayofweek, session;
                        int credits, maxstudent;
                        cout << "Press class name: ";
                        cin >> classname;
                        cout << "Press teachername: ";
                        cin >> teachername;
                        cout << "Press number of credis: ";
                        cin >> credits;
                        cout << "Press school day of week: ";
                        cin >> dayofweek;
                        //Kiem tra nhap dayofweek
                        cout << "Press session: ";
                        cin >> session;
                        Course* newCourse = createCourse(courseid, coursename, classname, teachername, credits, maxstudent, dayofweek, session);
                        addCourseToSemester(curSemester, newCourse);
                    }
                    char check3;
                    while (check3 != ' ') {
                        cout << "Press Space to go back!";
                        cin >> check3;
                    }
                    Menu3p3();
                    int chose3;
                    cout << "Enter your selection: ";
                    cin >> chose3;
                }
                //turn back
            }
            if (chose == 4) {

            }
            if (chose == 5) {

            }
            if (chose == 6) {

            }
            if (chose == 7) {

            }
            char check;
            while (check != ' ') {
                cout << "Press Space to go back!";
                cin >> check;
            }
            //Menu3();
            int chose;
            cout << "Enter your selection: ";
            cin >> chose;
        }
        //logout
        
    }
    if (mode == 2) {
        //Student login
        string password;
        string user;
        User* student;
        Menu2();
        //Login
        // ...
        //Login thanh cong
        Menu4();
        int chose;
        cout << "Enter your selection: ";
        cin >> chose;
        while (chose != 4) {
            while (chose < 1 && mode > 4) {
                Menu3();
                cout << "Wrong selection!\n";
                cout << "Enter your selection: ";
                cin >> chose;
            }
            if (chose == 1) {

            }
            if (chose == 2) {
                changePassword(student);
            }
            if (chose == 3) {

            }
        }
        //logout
    }
    Menu2();
    return 0;
}