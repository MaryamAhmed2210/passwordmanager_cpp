#ifndef PASSWORD_H
#define PASSWORD_H

#include <iostream>
#include <string>
using namespace std;
class Password
{
	private:
    	string website;
    	string username;
    	string password;
	public:
    	Password();
    	Password(string website, string username, string password);
    	void setData();
    	void display() const;
    	string getWebsite() const;
    	string getUsername() const;
    	string getPassword() const;
		void setWebsite(string website);
    	void setUsername(string username);
    	void setPassword(string password);
    	void loadData(string website, string username, string password);
};

#endif