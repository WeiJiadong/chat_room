#ifndef EPOLLEXC_H
#define EPOLLEXC_H

#include <exception.h>
#include <epoll.h>

class EpollExc : public Epoll
{
public:
    EpollExc();
    void create(int size = EPOLL_DEAUFULT_SIZE);
    void add(int fd, int eventsOption);
    void del(const int eventIndex);
    void modify(const int eventIndex, int eventsOption);
    int  wait(int timeout = EPOLL_NEVER_TIMEOUT);
    int  getFd(const int eventIndex);
    int  getEvents(const int eventIndex);
    virtual ~EpollExc();
};

#endif/*EPOLLEXC_H*/
