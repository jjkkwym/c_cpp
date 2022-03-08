#include "utils_vsprintf.h"
#include "stdio.h"
#include <string.h>
#include "log.h"
#include "cJSON.h"

int main(int argc,char *argv[])
{
    char dest[128];
    char src[] = "hello world!";
    char seial_setting_str_buf[1024];
    
    util_sprintf(dest,"the src:%s\n",src);
    printf("%s",dest);
    LOG_INFO("%s",dest);
    LOG_HEXDUMP("dest: ",dest,strlen(dest));        
    cJSON *root = cJSON_CreateObject();
    cJSON *serial_setting = cJSON_AddObjectToObject(root,"serial_setting");
    cJSON_AddStringToObject(serial_setting,"dev_name","/dev/ttyUSB1");
    cJSON_AddNumberToObject(serial_setting,"baudrate",115200);
    cJSON_AddNumberToObject(serial_setting,"data_bit",8);
    cJSON_AddNumberToObject(serial_setting,"stop_bit",1);
    cJSON_AddStringToObject(serial_setting,"pari_bit","none");
    cJSON_AddBoolToObject(serial_setting,"flow_control",cJSON_False);
    sprintf(seial_setting_str_buf,"%s",cJSON_Print(root));
    printf("%s",seial_setting_str_buf);
    cJSON_Delete(root);

    root = cJSON_Parse(seial_setting_str_buf);
    if(!root)
    {
        LOG_ERROR("parse ereer");
    }
    serial_setting = cJSON_GetObjectItem(root,"serial_setting");
    if(!serial_setting)
    {
        LOG_ERROR("parse eroor");        
    }
    cJSON *dev_name = cJSON_GetObjectItem(serial_setting,"dev_name");
    if(!dev_name)
    {
        LOG_ERROR("parse eroor");
    }
    printf("dev name:%s",dev_name->valuestring);
    cJSON_Delete(root);
}