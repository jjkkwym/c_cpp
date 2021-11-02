#include "log.h"
#include "list.h"
#include <string.h>
#include "stdint.h"
#include "list.h"

typedef struct
{
    const char *name;
    size_t cmd_num;
}cmd_group_t;

typedef struct
{   
    cmd_group_t * const *cmd_group;

}cmd_group_desc_t;

cmd_group_t cmd_group_1 = {
    .name = "g1",
    .cmd_num = 1
};

cmd_group_t cmd_group_2 = {
    .name = "g2",
    .cmd_num = 2
};

cmd_group_t cmd_group[] = {
    &cmd_group_1,
    &cmd_group_2
};



char *cmd_prefix = "AT#"; 
typedef void (*cmd_event_handle_t)(char *para);
//example AT#START=1,2
typedef struct 
{
    char *cmd_prefix;
    uint8_t cmd_prefix_len;  
    char cmd_para_separator;
}cmd_format_cfg_t;

typedef struct
{
    const char *cmd;
    const char *cmd_desc;
    uint8_t is_with_para;
    char *para;
    uint8_t para_max_len;
}
cmd_info_t;


typedef struct
{
    cmd_format_cfg_t cmd_format_cfg;
    cmd_info_t *cmd_info;
}cmd_t;

cmd_format_cfg_t cmd_format_cfg_default = {
    .cmd_prefix = "AT#",
    .cmd_para_separator = '='
};

void cmd_init(cmd_format_cfg_t *cfg)
{
    // list_t *at_cmd_list = list_new(NULL);
    // cmd_info_t cmd_info = {
    //     .cmd = "START",
    // };
    // list_append(at_cmd_list,&cmd_info);
    


    *cfg = cmd_format_cfg_default; 
}

void cmd_recv(char *data,int size)
{
    size_t n;
    fgets(data,size,stdin);
    char *s = strrchr(data,'\n');
    *s = '\0';
    LOG_INFO("%s",data);
}


void cmd_parse(char *data,int size)
{
    cmd_format_cfg_t cmd;
}

void register_cmd(cmd_info_t *cmd_info)
{

}


int main(int argc, char const *argv[])
{
    cmd_format_cfg_t cmd_format_cfg;
    cmd_init(&cmd_format_cfg);
    LOG_INFO("%s",cmd_group[0]->name);
    
    
    LOG_INFO("size:%d",sizeof(size_t));
    LOG_INFO("%s",cmd_format_cfg.cmd_prefix);
    LOG_INFO("%c",cmd_format_cfg.cmd_para_separator);
    LOG_INFO("%x",512);    
    char cmd_buf[128];
    while(1)
    {
        cmd_recv(cmd_buf,sizeof(cmd_buf));
        cmd_parse(cmd_buf,sizeof(cmd_buf));       
    }
}