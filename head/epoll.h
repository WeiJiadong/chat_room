#ifndef EPOLL_H
#define EPOLL_H

#include <unistd.h>
#include <sys/epoll.h>
#include <tools.h>

/*EPOLL 参数值定义*/
#define EPOLL_DEAUFULT_SIZE   (1024)
#define EPOLL_MAX_SIZE        (10240)
#define EPOLL_EVENT_BEGIN     (0)
#define EPOLL_NEVER_TIMEOUT   (-1)

class Epoll
{
public:
    Epoll();
    bool createEpoll(int size = EPOLL_DEAUFULT_SIZE);
    bool addFd(int fd, int eventsOption);
    bool delFd(const int eventIndex);
    bool changeEvent(const int eventIndex, int eventsOption);
    int  waitEvents(int timeout = EPOLL_NEVER_TIMEOUT);
    int  getEventOccurfd(const int eventIndex) const;
    int  getEvents(const int eventIndex) const;
    virtual ~Epoll();

private:
    int m_Epollfd;
    int m_EventIndex;
    int m_EventCount;
    struct epoll_event m_Events[EPOLL_MAX_SIZE];
};

#endif
/*EPOLL_H*/
