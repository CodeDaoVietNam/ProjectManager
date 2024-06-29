#ifndef _LOG_H_
#define _LOG__H_
#include"lib.h"
#include"struct.h"
User* createUser(string userID, string password, string firstName, string lastName, string studentID, int userType);
void Input_Username_Password (User* userHead,string &username ,string &password);
bool Confirm (User* head,const string & username ,const string & password);
User *findUser (User*head ,const string &username);
void viewProfile(User*& user);
void changePassword(User*& user);
bool checkStrongPassword (const string &password);
void addUser(User*& head, string userID, string password, string firstName, string lastName, string StudentID, int userType);
void logout();
void importUsersFromCSV(User*& userList, const std::string& filePath);
#endif