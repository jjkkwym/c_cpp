#include "log.h"
#include <string.h>

typedef struct 
{
    char name[32];
    char link_key[128];
}pair_info_t;

typedef struct 
{
    int ram_id[8];
}pair_info_order_t;

int main(int argc, char const *argv[])
{
    pair_info_t pair_info;
    strcpy(pair_info.name,"1.1.1.1");
    LOG_INFO("get_pair dev name:%s",pair_info.name);
    pair_info_order_t order;
    order.ram_id;
    for(int i = 0;i < 8;i++)
    {
        if()
        order.ram_id        
    }
}