#include "log.h"
void Input_Username_Password (string &username ,string &password)
{
    cout<<"Please enter your username : ";
    cin>>username;
    cout<<endl;
    cout<<"Please enter your password : ";
    cin>>password;
    if(Confirm(userHead,username,password )== true)
    {
        cout<<"Login successful.\n";
        return ;
    }
    cout<<"You entered wrong password or username.\n";
    Input_Username_Password(username,password);
}
void addUser(User* &head, string userID, string password, string firstName, string lastName, int userType)
{
    User* newUser = createUser(userID, password, firstName, lastName, userType);
    newUser->next = head;
    head = newUser;
}
// hàm tìm user có trong danh sách liên kết hay không
User *findUser (User*head ,const string &username)
{
    User* tmp = head;
    while(tmp != NULL)
    {
        // nếu username đã nhập trước đó giống với username của một node trong dslk thì trả về node đó
        if(tmp->userName == username )
        {
            return tmp;
        }
        tmp = tmp ->next;
    }
    // nếu không thì trả về NULL cho trường hợp không có trường hợp nào đúng 
    return NULL;
}
// hàm xác minh tài khoản 
bool Confirm (User* head,const string & username ,const string & password)
{
    User* user = findUser(head,username);
    if(user == NULL) return false;
    // xác minh mật khẩu 
    else
    {
        return user->password == password ;
    }
}
//hàm xem profile của user 
void viewProfile(User*& user)
{
    cout<<"Profile Infomation : \n";
    cout<<"UserName : "<<user->userName<<"\n";
    cout<<"First Name : "<<user->firstName<<"\n";
    cout<<"Last Name : "<<user->lastName<<"\n";
}
// hàm thay đổi Password của user
bool checkStrongPassword (const string &password)
{
    if(password.size()<8) return false;
    int Lower = 0 , Upper =0 , Special  =0 , Digit =0;
    int Space =0;
    for(int i = 0;  i< password.size(); i++)
    {
        if(islower(password[i])) ++Lower;
        else if(isupper(password[i])) ++Upper;
        else if(password[i]>='0' && password[i]<='9') ++Digit;
        else if(isspace(password[i])) return false;
        else ++Special;
    }
    if(Lower == 0 || Upper == 0 || Special == 0 || Digit ==0) return false;
    return true;
}
void changePassword(User*& user)
{
    // newPassword là password mới cần thay đổi
    string newPassword;
    // current password là password hiện tại đang sử dụng 
    cout<<"Please enter your current password : ";
    string currentPassword;
    cin>>currentPassword;
    //bước này dùng để kiểm tra password hiện tại có đúng hay không 
    while(currentPassword != user->password)
    {
        cout<<"\nCurrent Password is wrong !\nEnter again pls : ";
        cin>>currentPassword;
    }
    // nếu đúng thì bắt đầu đổi mật khẩu
    if(currentPassword == user->password)
    {
        // nhap mat khau moi 
        cout<<"\nPlease enter your new password : ";
        cin>>newPassword;
        while(checkStrongPassword(newPassword)== false)
        {
            cout<<"Password is weak, pls enter it again : ";
            cin>>newPassword;
        }
        // new2Password là nhập lại mật khẩu mới để xác nhận
        string new2Password;
        cout<<"\nPlease enter your new password again : ";
        cin>>new2Password;
        while(new2Password != newPassword)
        {
            cout<<"\n Your new password is wrong \npls enter again : ";
            cin>>new2Password;
        }
        cout<<"Password changed successful. \n";
    }
}
// hàm tạo user
User* createUser(string userID, string password, string firstName, string lastName, int userType)
{
    User* user = new User;
    user->userName = userID;
    user->firstName = firstName;
    user->lastName = lastName;
    user->userType = userType;
    user->next = NULL;
    return user;
}

// ham đăng xuất 
void logout()
{
    
}