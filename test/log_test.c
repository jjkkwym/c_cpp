#include "log.h"
#include "cJSON.h"

int main()
{
    LOG_INFO("%s",cJSON_Version());
}