#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include <iostream>
#include <vector>
#include "CyberTool.h"
#include "Password.h"

using namespace std;
class PasswordManager : public CyberTool
{
	private:
		vector<Password> passwords;
		int encryptionKey;
	public:
    	PasswordManager(int key);
		void addPassword();
		void viewPasswords();
		void searchPassword();
		void updatePassword();
		void deletePassword();
    	void saveToFile() override;
		void loadFromFile();
	    void displayMenu() override;
		void generatePassword();
		void passwordStrength();

};

#endif