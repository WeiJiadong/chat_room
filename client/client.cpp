#include <iostream>
#include <tools.h>
#include <sockexc.h>
#include <epollexc.h>
#include <cstring>
#include <unistd.h>

#define MAX_SIZE     (2048)
#define EXIT         ("EXIT")
using namespace std;

int main(void)
{
    pid_t pid = NG;
    int res   = OK;
    SockExc  client;
    EpollExc epoll;
    string recv_mesg;
    int mesg_fd[2];
    char send_mesg[MAX_SIZE];

    if (NG == pipe(mesg_fd)) {
        return NG;
    }/*end if*/

    try {
        client.connect();
        epoll.create();
        epoll.add(client.getFd(), EPOLLIN | EPOLLET | EPOLLOUT);
        epoll.add(mesg_fd[0], EPOLLIN | EPOLLET | EPOLLOUT);
        setnonblocking(client.getFd());
    }catch (Exception e) {
        cout << getReason() << endl;
    }/*end catch*/

    pid = fork();
    if (!IsOK(pid)) {
        res = NG;
    }/*end if*/

    if (0 == pid) {    /*如果是子进程*/
        close(mesg_fd[0]);
        while (true) {
            memset(send_mesg, 0x0, MAX_SIZE);
            fgets(send_mesg, MAX_SIZE, stdin);
            if (strncasecmp(send_mesg, EXIT, strlen(EXIT))) {
                cout << "Bye!" << endl;
                res = NG;
                break;
            }/*end if*/
            if (NG == write(mesg_fd[1], send_mesg, strlen(mesg))) {
                cerr << "消息发送错误!" << endl;
                res = NG;
                break;
            }/*end if*/
        }/*end while*/
    }else {            /*如果是父进程*/
        close (mesg_fd[1]);

        while(true) {
           try {
               try {
                   count = epoll.wait();
               }catch(Exception e) {
                   cout << getReason() << endl;
               }/*end catch*/
               for (i = 0; i < count; ++i) {
                   memset(send_mesg, 0x0, MAX_SIZE);
                   if (client == epoll.getFd()) {
                       try {
                           recv_mesg.clear();
                           len = client.recvMesg(recv_mesg);
                           if (NG == len) {
                               res = NG;
                               break;
                           }/*end if*/

                           if (0 == len) {
                               cout << "服务端关闭连接！\n" << endl;
                               res = NG;
                               break;
                           }else {
                           }/*end else*/
                       }catch {
                           cout << getReason() << endl;
                       }/*end catch*/
                   }else {
                       len = read(epoll.getFd(), send_mesg, MAX_SIZE);
                       if (0 == len) {
                           res = NG;
                           break;
                       }else {
                           client.sendMesg(send_mesg);
                       }/*end else*/
                   }/*end else*/
               }/*end for*/
           }/*end try*/
        }/*end while*/
    }/*end else*/

    if (pid > 0) {
        close(mesg_fd[0]);
    }else {
        close(mesg_fd[1]);
    }/*end if*/

    return res;
}
