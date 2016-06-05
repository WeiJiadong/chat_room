#include <epollexc.h>
#include <exception.h>

/*构造函数*/
EpollExc::EpollExc()
{
}

/*创建函数*/
void EpollExc::create(int size)
{
    if (!Epoll::createEpoll(size)) {
        throw Exception("事件表创建失败！\n");
    }/*end if*/
}

/*添加文件描述符*/
void EpollExc::add(int fd, int eventsOption)
{
    if (!Epoll::addFd(fd, eventsOption)) {
        throw Exception("描述符添加失败！\n");
    }/*end if*/
}

/*删除文件描述符*/
void EpollExc::del(const int eventIndex)
{
    if (!Epoll::delFd(eventIndex)) {
        throw Exception("描述符删除失败！\n");
    }/*end if*/
}

/*修改事件*/
void EpollExc::modify(const int eventIndex, int eventsOption)
{
    if (!Epoll::changeEvent(eventIndex, eventsOption)) {
        throw Exception("事件修改失败！\n");
    }/*end if*/
}

/*等待函数*/
int EpollExc::wait(int timeout)
{
    int index = NG;

    index = Epoll::waitEvents(timeout);
    if (!IsOK(index)) {
        throw Exception("等待失败！\n");
    }/*end if*/

    return index;
}

/*获得对应的fd*/
int EpollExc::getFd(const int eventIndex)
{
    int fd = NG;

    fd = Epoll::getEventOccurfd(eventIndex);
    if (!IsOK(fd)) {
        throw Exception("获取文件描述符失败\n");
    }/*end if*/

    return fd;
}

/*获取对应的事件*/
int EpollExc::getEvents(const int eventIndex)
{
    int events = NG;

    events = Epoll::getEvents(eventIndex);
    if (!IsOK(events)) {
        throw Exception("获取事件失败！\n");
    }/*end if*/

    return events;
}

/*析构函数*/
EpollExc::~EpollExc()
{
}
