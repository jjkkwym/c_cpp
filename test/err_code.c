#include "log.h"

typedef enum
{
    ERROR,
    ERROR1,
    ERROR2,
    ERROR3
} err_code_t;

const char *map_error_code(err_code_t err_code)
{
#define ERR_CODE(x) \
    case (x):       \
        return #x;
    switch (err_code)
    {
        ERR_CODE(ERROR);
    }
#undef ERR_CODE
    return "UNKNOWN ERROR CODE";
}

typedef struct
{
    err_code_t err_code;
    const char *err_code_desc;
} err_code_sum_t;


//err_code_sum_t err_code_sum;

void test1(char *desc,err_code_sum_t *err_code_sum)
{
    err_code_sum->err_code = ERROR;
    printf("desc:%p\n",desc);
    err_code_sum->err_code_desc = desc;
    printf("%s \n", err_code_sum->err_code_desc);
    printf("point:%p\n",err_code_sum->err_code_desc);
}

void test2(err_code_sum_t *err_code_sum)
{
    printf("test2:%s \n", err_code_sum->err_code_desc);
    printf("point:%p\n",err_code_sum->err_code_desc);

}

const char *tt = "123456";
const char *aa = "32";

void test(err_code_sum_t *t1,err_code_sum_t *t2)
{
    LOG_INFO("%s", map_error_code(ERROR));
    const char *buf;
    strcpy(buf,"321");

    printf("point:%p\n",buf);

    test1((const char *)buf,t1);
    strcpy(buf,"44444");

    test1((const char *)buf,t2);
    test2(t1);
    test2(t2);
}
int main(int argc, char const *argv[])
{
    err_code_sum_t t1;
    err_code_sum_t t2;
    test(&t1,&t2);
    printf("end point:%p\n",t1.err_code_desc);
    printf("end point:%p\n",t2.err_code_desc);
    printf("t1:%s\n",t1.err_code_desc);
    printf("t2:%s\n",t2.err_code_desc);
    
    
    // err_code_sum.err_code_desc = "error_desc1";
    // printf("%s \n", err_code_sum.err_code_desc);    
    // err_code_sum.err_code_desc = "error_desc2";
}