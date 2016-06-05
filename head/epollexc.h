#ifndef EPOLLEXC_H
#define EPOLLEXC_H

#include <exception.h>
#include <epoll.h>

class EpollExc : public Epoll
{
public:
    EpollExc();
    virtual EpollExc();
};

#endif/*EPOLLEXC_H*/
