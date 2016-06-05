#include <epoll.h>

/*Epoll 构造函数*/
Epoll::Epoll()
{
    this->m_Epollfd    = NG;
    this->m_EventIndex = EPOLL_EVENT_BEGIN;
}

bool Epoll::createEpoll(int size)
{
    bool res = false;
    int flag = NG;

    flag = epoll_create(size);
    if (IsOK(this->m_Epollfd)) {
        res = true;
    }/*end if*/

    return res;
}

bool Epoll::addFd(int fd, int eventsOption)
{
    bool res = false;
    int flag = NG;

    if (IsOK(this->m_Epollfd)) {
        this->m_Events[m_EventIndex].events  = eventsOption;
        this->m_Events[m_EventIndex].data.fd = this->m_Epollfd;
        flag = epoll_ctl(this->m_Epollfd, EPOLL_CTL_ADD, fd,
                         &this->m_Events[m_EventIndex]);
        if (IsOK(flag)) {
            res = true;
            this->m_EventIndex++;
        }/*end if*/
    }/*end if*/

    return res;
}

bool Epoll::delFd(const int eventIndex)
{
    bool res = false;
    int flag = NG;

    if (IsOK(this->m_Epollfd)) {
        flag = epoll_ctl(this->m_Epollfd, EPOLL_CTL_DEL,
                         this->m_Events[eventIndex].data.fd,
                         &this->m_Events[eventIndex]);
        if (IsOK(flag)) {
            res = true;
            this->m_EventIndex--;
        }/*end if*/
    }/*end if*/

    return res;
}

bool Epoll::changeEvent(const int eventIndex, int eventsOption)
{
    bool res = false;
    int flag = NG;

    if (IsOK(this->m_Epollfd)) {
        this->m_Events[eventIndex].events = eventsOption; 
        flag = epoll_ctl(this->m_Epollfd, EPOLL_CTL_MOD,
                         this->m_Events[eventIndex].data.fd,
                         &this->m_Events[eventIndex]);
        if (IsOK(flag)) {
            res = false;
        }/*end if*/
    }/*end if*/

    return res;
}

/*等待函数*/
int Epoll::waitEvents(int timeout)
{
    bool res = false;
    int flag = NG;

    if (IsOK(this->m_Epollfd)) {
        flag = epoll_wait(this->m_Epollfd, this->m_Events,
                          this->m_EventIndex + 1, timeout);
        if (IsOK(flag)) {
            res = true;
        }/*end if*/
    }/*end if*/

    return res;
}

/*获取变化的文件描述符*/
int Epoll::getEventOccurfd(const int eventIndex) const
{
    int fd = NG;

    if (IsOK(this->m_Epollfd) && this->m_EventIndex >= eventIndex) {
        fd = this->m_Events[eventIndex].data.fd;
    }/*end if*/

    return fd;
}

/*Epoll 析构函数*/
Epoll::~Epoll()
{
    close(this->m_Epollfd);
}
