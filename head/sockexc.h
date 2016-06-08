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
    void bind(int port = PORT, string host = LOCAL);
    void listen(int connum = 10);
    void connect(int port = PORT, string host = LOCAL);
    void sendMesg(string &send_buf, SockExc &socket = *this);
    int  recvMesg(string &recv_buf, SockExc &socket = *this);
    virtual ~SockExc();
};

#endif/*SOCKEXC_H*/
