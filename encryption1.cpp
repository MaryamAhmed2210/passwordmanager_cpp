#include "encryption1.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;
string Encryption::encrypt(string text, int key)
{
	for(char&ch:text)
	{
		ch=static_cast<char>(static_cast<unsigned char>(ch)+key);
	}
	return text;
}
string Encryption::decrypt(string text, int key)
{
	for(char&ch:text)
	{
		ch=static_cast<char>(static_cast<unsigned char>(ch)-key);
	}
	return text;
}
string Encryption::generatePassword(int length)
{
    string characters =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "!@#$%^&*";

    string password = "";
    for(int i = 0; i < length; i++)
    {
        password += characters[rand() % characters.length()];
    }
    return password;
}
string Encryption::checkStrength(string password)
{
    bool upper = false;
    bool lower = false;
    bool digit = false;
    bool special = false;

    for(char ch : password)
    {
        if(isupper(static_cast<unsigned char>(ch))) 
		{
			 upper = true;
		}
        else if(islower(static_cast<unsigned char>(ch)))
        {
            lower = true;
        }
        else if(isdigit(static_cast<unsigned char>(ch)))
        { 
			digit = true;
	    } 

        else
        {
            special = true;
        }
    }
    if(password.length() >= 8 && upper && lower && digit && special)
    {
        return "Strong";
    }
    if(password.length() >= 6)
    {
        return "Medium";
    }

    return "Weak";
}