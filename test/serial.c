#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    system("stty -F /dev/ttyUSB1 cs8 -parenb -cstopb -echo raw speed 115200");
    int uart_fd = open("/dev/ttyUSB1",O_RDWR | O_NOCTTY | O_NONBLOCK);
    char read_buf[1024];
    int read_len;
    int flag = 0;
    char byte;
    while(1)
    { 
        read_len = read(uart_fd,byte,sizeof(byte));
        if(read_len > 0)
        {
            // printf("%s",read_buf);
            if(byte == '\r')
            {
                byte = '\n';
            }
            printf("%c",byte);
        }
        else
        {
        }
        //usleep(20000); //recive 
    }
}