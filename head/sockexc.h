#ifndef SOCKEXC_H
#define SOCKEXC_H

#include <socklib.h>
#include <exception.h>

class SockExc : public Socket
{
public:
    SockExc();
    void create(int domain = AF_INET, int type = SOCK_STREAM,
                int protocol = 0);
    void bind(int port, string host = LOCAL);
    void listen(int connum = 10);
    void connect(int port, string host = LOCAL);
    void sendMesg(Socket &socket, string &send_buf);
    int  recvMesg(Socket &socket, string &recv_buf);
    virtual ~SockExc();
};

#endif/*SOCKEXC_H*/
