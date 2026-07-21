#include "password1.h"
#include <iostream>
#include <string>
using namespace std;

Password::Password()
{
    website = "";
    username = "";
    password = "";
}

Password::Password(string website, string username, string password)
{
    this->website = website;
    this->username = username;
    this->password = password;
}

void Password::setData()
{
    cout << "Enter Website : ";
    cin >> website;
    cout << "Enter Username : ";
    cin >> username;
    cout << "Enter Password : ";
    cin >> password;
}

void Password::display() const
{
    cout <<endl<<"----------------------------"<<endl;
    cout << "Website : " << website << endl;
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout <<endl<<"----------------------------"<<endl;
}

string Password::getWebsite() const
{
    return website;
}
string Password::getUsername() const
{
    return username;
}
string Password::getPassword() const
{
    return password;
}

void Password::setWebsite(string website)
{
    this->website = website;
}

void Password::setUsername(string username)
{
    this->username = username;
}

void Password::setPassword(string password)
{
    this->password = password;
}

void Password::loadData(string website, string username, string password)
{
    this->website = website;
    this->username = username;
    this->password = password;
}