#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define my_buf_size 1024
char tmp_buf[my_buf_size] = {0};

int main ()
{
    int fd = open("./input.txt", O_RDONLY, 0777);
    int a = read(fd, tmp_buf, my_buf_size);
    int fd2 = open("./output.txt", O_WRONLY|O_CREAT|O_APPEND, 0777);
    int b = write(fd2, tmp_buf, a+1);
    printf("%d, %d", a, b);
}