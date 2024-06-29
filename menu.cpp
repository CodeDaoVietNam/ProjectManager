#include "menu.h"

void setConsoleColor(int background, int text) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, background * 16 + text);
}

void clearConsole() {
	system("cls");
}

void displayMainMenu() {
	clearConsole();
	setConsoleColor(0, 15); // Black background, white text
	cout << "========================================" << endl;
	cout << "          Course Management System      " << endl;
	cout << "========================================" << endl;
	cout << "1. Login" << endl;
	cout << "2. Exit" << endl;
	cout << "Enter your choice: ";
}

void displayStaffMenu() {
	clearConsole();
	setConsoleColor(0, 15); // Black background, white text
	std::cout << "========================================" << std::endl;
	std::cout << "               Staff Menu               " << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "1. Create School Year" << std::endl;
	std::cout << "2. Create Class" << std::endl;
	std::cout << "3. Add Student to Class" << std::endl;
	std::cout << "4. Import Students from CSV" << std::endl;
	std::cout << "5. Create Semester" << std::endl;
	std::cout << "6. Add Course to Semester" << std::endl;
	std::cout << "7. Import Course Students from CSV" << std::endl;
	std::cout << "8. View Class Scoreboard" << std::endl;
	std::cout << "9. View Course Scoreboard" << std::endl;
	std::cout << "10. Publish Scoreboard" << std::endl;
	std::cout << "11. Logout" << std::endl;
	std::cout << "Enter your choice: ";
}

void displayStudentMenu() {
	clearConsole();
	setConsoleColor(0, 15); // Black background, white text
	cout << "========================================" << endl;
	cout << "              Student Menu              " << endl;
	cout << "========================================" << endl;
	cout << "1. View Profile" << endl;
	cout << "2. View Scoreboard" << endl;
	cout << "3. Logout" << endl;
	cout << "Enter your choice: ";
}
void handleStaffChoice(int choice, SchoolYear*& schoolYearList) {
    switch (choice) {
    case 1: {
        std::string year;
        std::cout << "Enter school year: ";
        std::cin >> year;
        SchoolYear* newYear = createSchoolYear(year);
        addSchoolYearToListYear(newYear, schoolYearList);
        break;
    }
    case 2: {
        std::string className;
        std::cout << "Enter class name: ";
        std::cin >> className;
        Class* newClass = CreateClass(className);
        addClassToSchoolYear(schoolYearList, newClass);
        break;
    }
    case 3: {
        std::string className, studentID, firstName, lastName, gender, dob, socialID;
        int no;
        std::cout << "Enter class name: ";
        std::cin >> className;
        Class* cls = findClass(schoolYearList, className); // You need to implement findClass function
        std::cout << "Enter student details (no, ID, first name, last name, gender, dob, social ID): ";
        std::cin >> no >> studentID >> firstName >> lastName >> gender >> dob >> socialID;
        Student* student = createStudent(no, studentID, firstName, lastName, gender, dob, socialID, className);
        addStudentToClass(cls, student);
        break;
    }
    case 4: {
        std::string className, filePath;
        std::cout << "Enter class name: ";
        std::cin >> className;
        Class* cls = findClass(schoolYearList, className); // You need to implement findClass function
        std::cout << "Enter CSV file path: ";
        std::cin >> filePath;
        importStudentsFromCSV(cls, filePath);
        break;
    }
    case 5: {
        int semesterNumber;
        std::string schoolYear, startDate, endDate;
        std::cout << "Enter semester details (number, school year, start date, end date): ";
        std::cin >> semesterNumber >> schoolYear >> startDate >> endDate;
        Semester* newSemester = createSemester(semesterNumber, schoolYear, startDate, endDate);
        addSemesterToSchoolYear(schoolYearList, newSemester);
        break;
    }
    case 6: {
        std::string courseID, courseName, className, teacherName, dayOfWeek, session;
        int credits, maxStudents;
        std::cout << "Enter course details (ID, name, class, teacher, credits, max students, day of week, session): ";
        std::cin >> courseID >> courseName >> className >> teacherName >> credits >> maxStudents >> dayOfWeek >> session;
        Course* newCourse = createCourse(courseID, courseName, className, teacherName, credits, maxStudents, dayOfWeek, session);
        Semester* semester = findSemester(schoolYearList, className); // You need to implement findSemester function
        if (semester) {
            addCourseToSemester(semester, newCourse);
            std::cout << "Course added successfully." << std::endl;
        }
        else {
            std::cerr << "Semester not found for the given class." << std::endl;
        }
        break;
    }
    case 7: {
        std::string courseID, filePath;
        std::cout << "Enter course ID: ";
        std::cin >> courseID;
        Course* course = findCourse(schoolYearList, courseID); // You need to implement findCourse function
        std::cout << "Enter CSV file path: ";
        std::cin >> filePath;
        importCourseStudentsFromCSV(course, filePath);
        break;
    }
    case 8: {
        std::string className;
        std::cout << "Enter class name: ";
        std::cin >> className;
        Class* cls = findClass(schoolYearList, className); // You need to implement findClass function
        viewClassScoreBoard(cls, nullptr, className); // Assuming nullptr for courseList
        break;
    }
    case 9: {
        std::string courseID;
        std::cout << "Enter course ID: ";
        std::cin >> courseID;
        Course* course = findCourse(schoolYearList, courseID); // You need to implement findCourse function
        viewScoreBoard(course);
        break;
    }
    case 10: {
        std::string courseID, filePath;
        std::cout << "Enter course ID: ";
        std::cin >> courseID;
        Course* course = findCourse(schoolYearList, courseID); // You need to implement findCourse function
        std::cout << "Enter CSV file path to export: ";
        std::cin >> filePath;
        exportStudentListInCourseToCSV(course, filePath);
        break;
    }
    case 11: {
        saveData("data.bin", schoolYearList);
        std::cout << "Logged out and data saved." << std::endl;
        break;
    }
    default:
        std::cerr << "Invalid choice!" << std::endl;
    }
}
Semester* findSemester(SchoolYear* schoolYearList, const std::string& className) {
    while (schoolYearList) {
        Semester* semester = schoolYearList->semesterList;
        while (semester) {
            Course* course = semester->courseList;
            while (course) {
                if (course->className == className) {
                    return semester;
                }
                course = course->next;
            }
            semester = semester->next;
        }
        schoolYearList = schoolYearList->next;
    }
    return nullptr;
}
Course* findCourse(SchoolYear* schoolYearList, const std::string& courseID) {
    while (schoolYearList) {
        Semester* semester = schoolYearList->semesterList;
        while (semester) {
            Course* course = semester->courseList;
            while (course) {
                if (course->courseID == courseID) {
                    return course;
                }
                course = course->next;
            }
            semester = semester->next;
        }
        schoolYearList = schoolYearList->next;
    }
    return nullptr;
}
Class* findClass(SchoolYear* schoolYearList, const std::string& className) {
    while (schoolYearList) {
        Class* cls = schoolYearList->classList;
        while (cls) {
            if (cls->className == className) {
                return cls;
            }
            cls = cls->next;
        }
        schoolYearList = schoolYearList->next;
    }
    return nullptr;
}
void handleStudentChoice(int choice, User* currentUser, SchoolYear* schoolYearList) {
    switch (choice) {
    case 1: {
        // View Profile
        viewProfile(currentUser);
        break;
    }
    case 2: {
        // View Scoreboard
        std::cout << "Scoreboard: " << std::endl;
        Student* student = findStudentInSchoolYear(schoolYearList, currentUser->studentID);
        if (student) {
            printStudent01(student);
        }
        else {
            std::cerr << "Student not found in school year!" << std::endl;
        }
        break;
    }
    case 3: {
        // Logout
        saveData("data.bin", schoolYearList);
        std::cout << "Logged out and data saved." << std::endl;
        break;
    }
    default:
        std::cerr << "Invalid choice!" << std::endl;
    }
}

Student* findStudentInSchoolYear(SchoolYear* schoolYearList, const std::string& studentID) {
    while (schoolYearList) {
        Class* cls = schoolYearList->classList;
        while (cls) {
            Student* student = cls->StudentList;
            while (student) {
                if (student->StudentID == studentID) {
                    return student;
                }
                student = student->next;
            }
            cls = cls->next;
        }
        schoolYearList = schoolYearList->next;
    }
    return nullptr;
}
//void Menu1()
//{
//	system("cls");
//	cout << "WELCOME TO MANAGEMENT COURSE SYSTEM \n";
//	cout << "1.If you are a staff , please enter 1.\n";
//	cout << "2.If you are a student , please enter 2.\n";
//	cout << "3.If you want to exit , please enter 0.\n";
//}
//void Menu2() {
//	system("cls");
//	cout << "LOGIN\n";
//}
//void Menu3()
//{
//	system("cls");
//	cout << "YOU ARE A STAFF HEHE\n";
//	cout << "1.View Profile Information\n";
//	cout << "2.Change Password\n";
//	cout << "3.Create\n";
//	cout << "4.View\n";
//	cout << "5.Remove\n";
//	cout << "6.Import\n";
//	cout << "7.Export\n";
//	cout << "8.logout\n";
//}
//void Menu4()
//{
//	system("cls");
//	cout << "YOU ARE A STUDENT HEHE\n";
//	cout << "1.View Profile Information\n";
//	cout << "2.Change Password\n";
//	cout << "3.View ScoreBoard\n";
//	cout << "4.logout\n";
//}
//void Menu3p3() {
//	system("cls");
//	cout << "STAFF CREATING\n";
//	cout << "1. Create new school year.\n";
//	cout << "2. Create new course.\n";
//	cout << "3. Go back.\n";
//}
//void Menu3p4() {
//	system("cls");
//	cout << "STAFF VIEW\n";
//	cout << "1. View class list.\n";
//	cout << "1. View class information.\n";
//	cout << "3. View course List.\n";
//	cout << "2. View course information.\n";
//	cout << "5. View course result.\n";
//	cout << "6. View student GPA.\n";
//}