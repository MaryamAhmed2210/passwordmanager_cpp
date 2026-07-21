#include <iostream>
#include <cstdlib>
#include <ctime>

#include "user1.h"
#include "passwordmanager1.h"

using namespace std;

int main()
{
    srand(time(0));
    User user;
    int choice;
    while(true)
    {
        user.displayMenu();

        cout<<endl<<"Enter Choice : ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            user.registerUser();
            break;

        case 2:
            if(user.login())
        {
            cout<<"Login Successful."<<endl;
            int key = 0;
            string master = user.getMasterPassword();
            for(char ch : master)
            {
                 key += ch;
            }
            key = (key % 20) + 1;
			PasswordManager manager(key);
            manager.loadFromFile();
			int option;
			bool loggedIn = true;
			while(loggedIn)
                {
                    manager.displayMenu();
					cout<<endl<<"Enter Choice : ";
                    cin>>option;
                    switch(option)
                    {
                        case 1:
                        manager.addPassword();
                        break;

                        case 2:
                        manager.viewPasswords();
                        break;

                        case 3:
                        manager.searchPassword();
                        break;

                        case 4:
                        manager.updatePassword();
                        break;

                        case 5:
                        manager.deletePassword();
                        break;

                        case 6:
                        manager.generatePassword();
                        break;

                    	case 7:
                        manager.passwordStrength();
                        break;

                        case 8:
                    	cout<<endl<<"Logging Out..."<<endl;
                        loggedIn = false; 
                        break;

                		default:
                        cout<<endl<<"Invalid Choice."<<endl;
                        }
                    }
                }
                else
                {
                    cout<<endl<<"Invalid Username or Password."<<endl;
                }
                break;

            case 3:
                cout<<endl<<"Thank You"<<endl;
                return 0;

            default:
                cout<<endl<<"Invalid Choice."<<endl;
        }
    }

    return 0;
}
