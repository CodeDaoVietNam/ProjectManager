#ifndef _LOG_H_
#define _LOG__H_
#include"lib.h"
#include"struct.h"
User* createUser(string userID, string password, string firstName, string lastName, int userType);
void Input_Username_Password (string &username ,string &password);
bool Confirm (User* head,const string & username ,const string & password);
User *findUser (User*head ,const string &username);
void viewProfile(User*& user);
void changePassword(User*& user);
bool checkStrongPassword (const string &password);
void logout();
User* userHead = nullptr;
#endif