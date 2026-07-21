#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Logger
{
public:

    static void writeLog(string message);

};

#endif