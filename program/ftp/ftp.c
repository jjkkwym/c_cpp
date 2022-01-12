#include "list.h"
#include "log.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

typedef enum
{
    FTP_EVT_UNKNOWN,
    FTP_EVT_ABOR,
    FTP_EVT_CWD,
    FTP_EVT_DELE,
    FTP_EVT_LIST,
    FTP_EVT_MDTM,
    FTP_EVT_MKD,
    FTP_EVT_NLST,
    FTP_EVT_PASS,
    FTP_EVT_PASV,
    FTP_EVT_PORT,
    FTP_EVT_PWD,
    FTP_EVT_QUIT,
    FTP_EVT_RETR,
    FTP_EVT_RMD,
    FTP_EVT_RNFR,
    FTP_EVT_RNTO,
    FTP_EVT_SITE,
    FTP_EVT_SIZE,
    FTP_EVT_STOR,
    FTP_EVT_TYPE,
    FTP_EVT_USER,
    FTP_EVT_NOOP
} ftp_evt_t;

void (*ftp_evt_handler)(ftp_evt_t ftp_evt);

typedef struct
{
    ftp_evt_t evt;
    const char *cmdlist_str;
} evt_table_t;

evt_table_t evt_table[] = {
    {FTP_EVT_ABOR, "ABOR"}, {FTP_EVT_CWD, "CWD"},   {FTP_EVT_DELE, "DELE"}, {FTP_EVT_LIST, "LIST"},
    {FTP_EVT_MDTM, "MDTM"}, {FTP_EVT_MKD, "MKD"},   {FTP_EVT_NLST, "NLST"},  {FTP_EVT_PASS, "PASS"},
    {FTP_EVT_PASV, "PASV"}, {FTP_EVT_PORT, "PORT"}, {FTP_EVT_PWD, "PWD"},   {FTP_EVT_QUIT, "QUIT"},
    {FTP_EVT_RETR, "RETR"}, {FTP_EVT_RMD, "RMD"},   {FTP_EVT_RNFR, "RNFR"}, {FTP_EVT_RNTO, "RNTO"},
    {FTP_EVT_SITE, "SITE"}, {FTP_EVT_SIZE, "SIZE"}, {FTP_EVT_STOR, "STOR"}, {FTP_EVT_TYPE, "TYPE"},
    {FTP_EVT_USER, "USER"}, {FTP_EVT_NOOP, "NOOP"}};

typedef struct
{
    ftp_evt_t type;
    bool has_msg;
    char evt[5];
    char param[1024];
}ftp_evt_data_t;

typedef struct
{
    int listen_sock;
    int conn_sock;
    ftp_evt_data_t evt_data;
} sock_port_t;

typedef struct
{
    sock_port_t ctrl_port;
    sock_port_t data_port;
} ftp_t;

void (*evt_handler)();
typedef struct
{
    ftp_evt_t evt_type;

} cmd_parse_data;

ftp_t g_ftp;

int create_socket(int port)
{
    int listen_sock;
    int reuse = 1;

    /* Server addess */
    struct sockaddr_in server_address = (struct sockaddr_in){AF_INET, htons(port), (struct in_addr){INADDR_ANY}};

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

void ftp_init(ftp_t *p_ftp)
{
    // init the control port listen_sock
    p_ftp->ctrl_port.listen_sock = create_socket(10021);
}

const char *cmd_user_resp = "331 User name okay, need password\n";
const char *cmd_pass_resp = "230 Login successful\n";
const char *cmd_unknown_command = "500 Unknown command\n";

int parse_ftp_evt(ftp_evt_data_t *evt_data,char *cmd_str)
{
    char evt_str[5];
    char evt_str_len;
    char *blank_separator = NULL;

    blank_separator = strchr(cmd_str,' ');
    //LOG_INFO("TEST");
    if(blank_separator)
    {
        LOG_INFO("blank:%s",blank_separator);
        evt_data->has_msg = true;
        strncpy(evt_data->param,blank_separator + 1,sizeof(evt_data->param));    
        evt_str_len = blank_separator - cmd_str;
        LOG_INFO("str_len:%d",evt_str_len); 
        if(evt_str_len > 4)
        {
            LOG_ERROR("ftp event len too long");
            return -1;
        }
        LOG_INFO("cmd_str:%s",cmd_str);
        strncpy(evt_str,cmd_str,evt_str_len);
        evt_str[evt_str_len] = '\0';
    }
    else
    {
        strncpy(evt_str,cmd_str,sizeof(evt_str));
        evt_data->has_msg = false;
        memset(evt_data->param,0,sizeof(evt_data->param));
    }
    LOG_INFO("evt_str:%s", evt_str);
    LOG_INFO("evt param:%s",evt_data->param);

    for (int i; i < sizeof(evt_table) / sizeof(evt_table[0]); i++)
    {
        if (!strcmp(evt_str, evt_table[i].cmdlist_str))
        {
            evt_data->type = evt_table[i].evt;
            return 0;
        }
    }
    
    evt_data->type = FTP_EVT_UNKNOWN;
    return 0;
}

void ftp_send_raw_msg(sock_port_t *p_port)
{
    write(p_port->listen_sock,p_port->evt_data->param);
}

void handle_ftp_evt(ftp_t *p_ftp)
{
    ftp_evt_data_t *evt_data = &p_ftp->ctrl_port.evt_data;

    switch(evt_data->type)
    {
        case FTP_EVT_UNKNOWN:
            break;
        case FTP_EVT_ABOR:
            
            break;
        case FTP_EVT_CWD:
            
            break;
        case FTP_EVT_DELE:
            
            break;
        case FTP_EVT_LIST:
            
            break;
        case FTP_EVT_MDTM:
            
            break;
        case FTP_EVT_MKD:
            
            break;
        case FTP_EVT_NLST:
            
            break;
        case FTP_EVT_PASS:
            
            break;
        case FTP_EVT_PASV:
            
            break;
        case FTP_EVT_PORT:
            
            break;
        case FTP_EVT_PWD:
            
            break;
        case FTP_EVT_QUIT:
            
            break;
        case FTP_EVT_RETR:
            
            break;
        case FTP_EVT_RMD:
            
            break;
        case FTP_EVT_RNFR:
            
            break;
        case FTP_EVT_RNTO:
            
            break;
        case FTP_EVT_SITE:
            
            break;
        case FTP_EVT_SIZE:
            
            break;
        case FTP_EVT_STOR:
            
            break;
        case FTP_EVT_TYPE:
            
            break;
        case FTP_EVT_USER:
            
            break;
        case FTP_EVT_NOOP:
            
            break;
    }
}

typedef enum
{
    FILE_DESCRIPTOR_READ,
    FILE_DESCRIPTOR_WRITE
} data_src_op_type_t;

typedef void (*data_src_evt_handler)();

typedef struct data_src_s
{
    int fd;
    data_src_op_type_t type;
    void (*evt_hander)(struct data_src_s *ds, data_src_op_type_t type);
} data_src_t;

void ftp_start(ftp_t *p_ftp)
{
    struct sockaddr_in cliaddr;
    int len = sizeof(cliaddr);
    char raw_data_buf[1024];
    int bytes_read;
    int conn_sock;
    ftp_evt_data_t ftp_evt_data;
    while (1)
    {
        p_ftp->ctrl_port.conn_sock = accept(p_ftp->ctrl_port.listen_sock, (struct sockaddr *)&cliaddr, &len);
        if (conn_sock < 0)
        {
            LOG_INFO("accept error");
        }

        LOG_INFO("accept client addr: %s:%d", inet_ntoa(cliaddr.sin_addr), cliaddr.sin_port);
        write(p_ftp->ctrl_port.conn_sock, "220 hello ftp\n", strlen("220 hello ftp\n") + 1);
        while (1)
        {
            bytes_read = read(p_ftp->ctrl_port.conn_sock, raw_data_buf, sizeof(raw_data_buf));
            LOG_INFO("read_byte:%d", bytes_read);
            if (bytes_read > 0)
            {
                raw_data_buf[bytes_read] = '\0';
                raw_data_buf[bytes_read -1] = '\0';
                LOG_HEXDUMP("packet:", raw_data_buf, bytes_read);
                ftp_evt_data_t ftp_evt_data;
                parse_ftp_evt(&ftp_evt_data,raw_data_buf);
                p_ftp->ctrl_port.evt_data = &ftp_evt_data;
                handle_ftp_evt(&p_ftp);
            }
            else if (bytes_read == 0)
            {
                LOG_INFO("connect close");
                break;
            }
            else
            {
                break;
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    ftp_init(&g_ftp);

    LOG_INFO("this is a ftp program");

    ftp_start(&g_ftp);
}