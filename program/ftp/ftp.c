#include "log.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
typedef struct
{
    int listen_sock;
    int conn_sock;
} sock_port_t;

typedef struct
{
    sock_port_t ctrl_port;
    sock_port_t data_port;
} ftp_server_t;

/**@brief   this is a socket create
 * @param[in]    port init port
 * @retval    the socket desript 
**/

ftp_server_t g_ftp_sever;

int create_socket(int port)
{
    int listen_sock;
    int reuse = 1;

    /* Server addess */
    struct sockaddr_in server_address = (struct sockaddr_in){
        AF_INET,
        htons(port),
        (struct in_addr){INADDR_ANY}};

    if ((listen_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        LOG_ERROR("Cannot open socket");
        return -1;
    }

    /* Address can be reused instantly after program exits */
    setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    /* Bind socket to server address */
    if (bind(listen_sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        LOG_ERROR("Cannot bind socket to address");
        return -1;
    }

    listen(listen_sock, 10);
    return listen_sock;
}

void ftp_server_init(ftp_server_t *ftp_sever)
{
    //init the control port listen_sock
    ftp_sever->ctrl_port.listen_sock = create_socket(10021);
}


int main(int argc, char const *argv[])
{
    struct sockaddr_in cliaddr;
    int len = sizeof(cliaddr);
    char buf[1024];
    int bytes_read;
    ftp_server_init(&g_ftp_sever);

    LOG_INFO("this is a ftp program");

    while (1)
    {
        g_ftp_sever.ctrl_port.conn_sock = accept(g_ftp_sever.ctrl_port.listen_sock, (struct sockaddr *)&cliaddr, &len);
        LOG_INFO("accept client addr: %s:%d", inet_ntoa(cliaddr.sin_addr), cliaddr.sin_port);
        
        while (bytes_read = read(g_ftp_sever.ctrl_port.conn_sock, buf, sizeof(buf)))
        {
            if (bytes_read > 0)
            {
                printf("read bytes %d\n",bytes_read);
                buf[bytes_read] = '\0';
                printf("%s", buf);
            }
        }
    }

    return 0;
}