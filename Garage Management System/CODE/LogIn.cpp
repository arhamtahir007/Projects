#include "LogIn.h"

string LogIn::getUserName() {
    return userName;
}

void LogIn::setUserName() {
    cin>>userName;
}

string LogIn::getPassword() {
    return password;
}

void LogIn::setPassword() {
    cin>>password;
}

string LogIn::getMatchUser() {
    return matchUser;
}

string LogIn::getMatchPass() {
    return matchPass;
}

LogIn *LogIn::getInstance() {
    if (ptr == nullptr){
        ptr = new LogIn;
    }
    return ptr;
}

void LogIn::releaseInstance() {
    if (ptr != nullptr) {
        delete ptr;
        ptr = nullptr;
    }
}

int userLogIn() {
    LogIn* logIn = LogIn::getInstance();
    static int tryCounter = 3;
    reLog:
    system("clear");
    cout<<"\n\n\t\t\t\tLOGIN\n\nEnter User Name: ";
    logIn->setUserName();
    cout<<"\nEnter Password: ";
    logIn->setPassword();
    if (logIn->getUserName() != logIn->getMatchUser() || logIn->getPassword() != logIn->getMatchPass()){
        if (tryCounter != 0){
            --tryCounter;
            cout<<"\n\t\t\tInvalid User Name or Password!\n\n";
            cout<<tryCounter<<" more tries left";
            cin.ignore();
            cout<<"\n\nPress Enter Key to continue\n\n";
            cin.get();              //next line executes only when user presses enter key
            goto reLog;
        }
        else{
            while (tryCounter != 5) {
                char asking[] = "LOCKING SYSTEM........";
                for (int i = 0; asking[i] != '\0'; i++) {
                    cout << asking[i];
                    cout.flush();
                    if (asking[i] == '\n')
                        Sleep(500);
                    else
                        Sleep(5);
                }
                Sleep(1000);
                system("clear");
                tryCounter++;
            }
            LogIn::releaseInstance();
            return 0;
        }
    }
    else
        return 1;
}

LogIn* LogIn::ptr = nullptr;
