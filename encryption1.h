#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <iostream>
#include <string>
using namespace std;

class Encryption
{
	public:
    	static string encrypt(string text, int key);
    	static string decrypt(string text, int key);
    	static string generatePassword(int length);
    	static string checkStrength(string password);
};

#endif