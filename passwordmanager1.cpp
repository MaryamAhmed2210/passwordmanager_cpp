#include "passwordmanager1.h"
#include "Encryption.h"
#include "Logger.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

PasswordManager::PasswordManager(int key)
{
    encryptionKey = key;
}
void PasswordManager::saveToFile()
{
    ofstream file("passwords.txt");
    if(!file)
    {
        cout<<endl<<"Error Opening File."<<endl;
        return;
    }
    for(const Password &p : passwords)
    {
        file<<p.getWebsite() << endl;
        file<<p.getUsername() << endl;
        file<<Encryption::encrypt(p.getPassword(), encryptionKey) << endl;
    }
    file.close();
}

void PasswordManager::displayMenu()
{
    cout <<endl<<"-------------------------"<<endl;
    cout << "   PASSWORD MANAGER  "<<endl;
    cout <<endl<<"-------------------------"<<endl;
    cout << "1. Add Password"<<endl;
    cout << "2. View Passwords"<<endl;
    cout << "3. Search Password"<<endl;
    cout << "4. Update Password"<<endl;
    cout << "5. Delete Password"<<endl;
    cout << "6. Generate Password"<<endl;
    cout << "7. Password Strength"<<endl;
    cout << "8. Logout"<<endl;
}
void PasswordManager::addPassword()
{
    Password p;
    p.setData();
    passwords.push_back(p);
    saveToFile();
    Logger::writeLog("Password Added");
    cout<<endl<<"Password Saved Successfully."<<endl;
}
void PasswordManager::viewPasswords()
{
    if(passwords.empty())
    {
        cout<<endl<<"No Passwords Saved."<<endl;
        return;
    }
    cout<<"------SAVED PASSWORDS-------"<<endl;
    for(size_t i=0; i<passwords.size(); i++)
    {
        cout<<endl<<"Record "<<i+1<<endl;
        passwords[i].display();
    }
}
void PasswordManager::searchPassword()
{
    if(passwords.empty())
    {
        cout<<endl<<"No Passwords Available."<<endl;
        return;
    }
    string website;
    cout<<endl<<"Enter Website : ";
    cin>>website;
    bool found = false;
    for(Password &p : passwords)
    {
        if(p.getWebsite() == website)
        {
            cout<<endl<<"Password Found"<<endl;
            p.display();
            found = true;
            break;
        }
    }
    if(!found)
    {
       cout<<endl<<"nWebsite Not Found."<<endl;
    }
}
void PasswordManager::updatePassword()
{
    if(passwords.empty())
    {
        cout<<endl<<"No Passwords Available."<<endl;
        return;
    }
    string website;
    cout<<endl<<"Enter Website : ";
    cin >> website;
    bool found = false;
    for(Password &p : passwords)
    {
        if(p.getWebsite() == website)
        {
            string username;
            string password;
            cout<<"Enter New Username : ";
            cin>>username;
            cout<<"Enter New Password : ";
            cin>>password;
            p.setUsername(username);
            p.setPassword(password);
            saveToFile();
            Logger::writeLog("Password Updated");
            cout<<endl<<"Password Updated Successfully."<<endl;
            found = true;
            break;
        }
    }
    if(!found)
    {
        cout<<endl<<"Website Not Found."<<endl;
    }
}
void PasswordManager::deletePassword()
{
    if(passwords.empty())
    {
        cout<<endl<<"No Passwords Available."<<endl;
        return;
    }
    string website;
    cout<<endl<<"Enter Website : ";
    cin >> website;
    for(auto it = passwords.begin(); it != passwords.end(); it++)
    {
        if(it->getWebsite() == website)
        {
            passwords.erase(it);
            saveToFile();
            Logger::writeLog("Password Deleted");
            cout<<endl<<"Password Deleted Successfully."<<endl;
            return;
        }
    }
    cout<<endl<<"Website Not Found."<<endl;
}
void PasswordManager::loadFromFile()
{
    ifstream file("passwords.txt");
    if(!file)
    {
        return;
    }
    passwords.clear();
    string website;
    string username;
    string password;
    while(getline(file, website))
    {
        if(!getline(file, username)) break;
        if(!getline(file, password)) break;
        password = Encryption::decrypt(password, encryptionKey);
        Password p;
        p.loadData(website, username, password);
        passwords.push_back(p);
    }
    file.close();
}
void PasswordManager::generatePassword()
{
    int length;
    cout<<endl<<"Enter Password Length : ";
    cin>>length;
    string password = Encryption::generatePassword(length);
    cout<<endl<<"Generated Password : "<<password<<endl;
}
void PasswordManager::passwordStrength()
{
    string password;
    cout<<endl<<"Enter Password : ";
    cin>>password;
    cout<<endl<<"Password Strength : ";
    cout<<Encryption::checkStrength(password)<<endl;
}







