#ifndef MAIN_CPP_LOGIN_H
#define MAIN_CPP_LOGIN_H

#endif //MAIN_CPP_LOGIN_H

#include <iostream>
#include <windows.h>

using namespace std;

class LogIn{
    static LogIn* ptr;
    string userName;
    string password;
    string matchUser;
    string matchPass;
    LogIn(){
        userName = "";
        password = "";
        matchUser = "WAH";
        matchPass = "WAH";
    }
public:
    static LogIn* getInstance();

    static void releaseInstance();

    string getUserName();
    void setUserName();

    string getPassword();
    void setPassword();

    string getMatchUser();
    string getMatchPass();


};

int userLogIn();

