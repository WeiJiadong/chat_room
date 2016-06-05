#ifndef EXCEPTIOM_H
#define EXCEPTIOM_H

#include <iostream>
#include <string>

using namespace std;

class Exception
{
public:
    Exception(string str):m_str(str){}
    string &getReason();
    virtual ~Exception();

private:
    string m_str;
};
#endif/*EXCEPTIOM_H*/
