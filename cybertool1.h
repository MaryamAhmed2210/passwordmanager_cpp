#ifndef CYBERTOOL_H
#define CYBERTOOL_H

class CyberTool
{
public:

    virtual void displayMenu() = 0;
    virtual void saveToFile() = 0;
    virtual ~CyberTool() {}

};
#endif