#include "user1.h"
#include "logger1.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

User::User()
{
    username = "";
    masterPassword = "";
}
void User::saveToFile()
{
    ofstream file("user.txt");
    if(!file)
    {
        cout<<"Error Opening File."<<endl;
        return;
    }
    file<<username<<endl;
    file<<masterPassword<<endl;
    file.close();
}
void User::registerUser()
{
    cout<<endl<<"Create Username: ";
    cin>>username;
    cout<<"Create Master Password: ";
    cin>> masterPassword;
    saveToFile();
    Logger::writeLog("New User Registered: " + username);
    cout<<endl<< "Registration Successful."<<endl;
}
bool User::login()
{
    ifstream file("user.txt");
    if(!file)
    {
        cout<<endl<<"No Registered User Found."<<endl;
        return false;
    }
    string enteredUser;
    string enteredPswd;
    string storedUser;
    string storedPswd;
    cout<<endl<<"Username: ";
    cin>>enteredUser;
    cout<<"Master Password: ";
    cin>>enteredPswd;
    file>>storedUser>>storedPswd;
    file.close();
    if(enteredUser==storedUser && enteredPswd== storedPswd)
    {
        username = storedUser;
        masterPassword = storedPswd;
        Logger::writeLog("User Logged In Successfully");
        return true;
    }
    return false;
}

string User::getMasterPassword() const
{
    return masterPassword;
}

void User::displayMenu()
{
    cout <<endl<<"-------------------------"<<endl;
    cout << "      PASSWORD MANAGER    "<<endl;
    cout <<endl<<"-------------------------"<<endl;
    cout << "1. Register"<<endl;
    cout << "2. Login"<<endl;
    cout << "3. Exit"<<endl;
}