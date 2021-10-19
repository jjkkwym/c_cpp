#include "log.h"
#include "list.h"

char *cmd_prefix = "AT#"; 
//example AT#START=1,2
typedef struct 
{
    char *cmd_prefix;
    char *cmd;
    char *cmd_para_separator;
    char *para;
    char *para_separator;
}cmd_format_cfg_t;

cmd_format_cfg_t cmd_format_cfg_default = {
    .cmd_prefix = "AT#",
    .cmd_para_separator = "=",
    .para_separator = ","
};

void cmd_init(cmd_t *self)
{
    *self = g_cmd_config; 
}

void cmd_parse()
{
}


int main(int argc, char const *argv[])
{
    cmd_t cmd;
    cmd_init(&cmd);
    LOG_INFO("%s",cmd.cmd_prefix);
    LOG_INFO("%s",cmd.cmd_para_separator);
    LOG_INFO("%s",cmd.para_separator);
}