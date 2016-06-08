#include <sockexc.h>

/*构造函数*/
SockExc::SockExc()
{
}

/*创建函数*/
void SockExc::create(int domain, int type, int protocol)
{
    if (!Socket::create(domain, type, protocol)) {
        throw Exception("创建失败！\n");
    }/*end if*/
}

/*绑定函数*/
void SockExc::bind(int port, string host)
{
    if (!IsOK(Socket::getFd()) || !Socket::bind(port, host)) {
        throw Exception("绑定失败！\n");
    }/*end if*/
}

/*监听函数*/
void SockExc::listen(int connum)
{
    if (!IsOK(Socket::getFd()) || !Socket::listen(connum)) {
        throw Exception("监听失败！\n");
    }/*end if*/
}

/*连接函数*/
void SockExc::connect(int port, string host)
{
    if (!IsOK(Socket::getFd()) || !Socket::connect(port, host)) {
        throw Exception("连接失败！\n");
    }/*end if*/
}

/*发送消息*/
void SockExc::sendMesg(string &send_buf, SockExc &socket)
{
    if (!IsOK(Socket::getFd()) || !Socket::sendMesg(socket, send_buf)) {
        throw Exception("消息接收失败！\n");
    }/*end if*/
}

/*接收消息*/
int SockExc::recvMesg(string &recv_buf, SockExc &socket)
{
    int flag = NG;

    if (!IsOK(Socket::getFd()) || !(flag = Socket::recvMesg(socket, recv_buf))) {
        throw Exception("消息接收失败！\n");
    }/*end if*/

    return flag;
}

/*析构函数*/
SockExc::~SockExc()
{
}
