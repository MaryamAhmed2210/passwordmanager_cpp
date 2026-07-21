#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
#include "CyberTool.h"

using namespace std;

class User : public CyberTool
{
	private:
    	string username;
    	string masterPassword;

public:

    User();
    void registerUser();
    bool login();
    string getMasterPassword() const;
    void displayMenu() override;
    void saveToFile() override;
};

#endif