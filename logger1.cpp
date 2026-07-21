#include "logger1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;
void Logger::writeLog(string message)
{
    ofstream file("activity.log", ios::app);
    if(!file)
    {
        cout << "Unable to Open Log File"<<endl;
        return;
    }
    time_t now = time(0);
    char* dateTime = ctime(&now);
    file << "----------------------------------"<<endl;
    file << "Timestamp: " << dateTime; 
    file << "Activity:  " << message <<endl;
    file.close();
}