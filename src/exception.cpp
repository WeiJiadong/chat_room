#include <exception.h>

/*获得异常原因*/
string &Exception::getReason()
{
    return this->m_str;
}

/*析构函数*/
Exception::~Exception()
{
}
