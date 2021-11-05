#include "log.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct
{
    int sock;
    int conn_sock;
}ctrl_port_t;

typedef struct
{
    ctrl_port_t ctrl_port;
}ftp_server_t;

/**@brief   this is a socket create
 * @param[in]    port init port
 * @retval    the socket desript 
**/

int create_socket(int port)
{
    int sock;
    int reuse = 1;

    /* Server addess */
    struct sockaddr_in server_address = (struct sockaddr_in){  
        AF_INET,
        htons(port),
        (struct in_addr){INADDR_ANY}
    };

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        LOG_ERROR("Cannot open socket");
        return -1;
    }

    /* Address can be reused instantly after program exits */
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    /* Bind socket to server address */
    if(bind(sock,(struct sockaddr*) &server_address, sizeof(server_address)) < 0)
    {
        LOG_ERROR("Cannot bind socket to address");
        return -1;
    }

    listen(sock,10);
    return sock;
}

void ftp_server_init(ftp_server_t *ftp_sever)
{
    //init the control port sock
    ftp_sever->ctrl_port.sock = create_socket(10021);
}

int main(int argc, char const *argv[])
{
    ftp_server_t ftp_sever;
    struct sockaddr_in cliaddr;
    int len = sizeof(cliaddr);

    ftp_server_init(&ftp_sever);

    LOG_INFO("this is a ftp program");
    
    while (1)
    {
        ftp_sever.ctrl_port.conn_sock = accept(ftp_sever.ctrl_port.conn_sock, (struct sockaddr*) &cliaddr,&len);
        LOG_INFO("accept client addr: %s:%d",inet_ntoa(cliaddr.sin_addr),cliaddr.sin_port);

    }
    
    return 0;
}