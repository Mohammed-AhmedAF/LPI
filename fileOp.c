#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define O_CREATE O_CREAT
int main(void)
{
    int fd;
    fd = open("demo.c",O_RDONLY | O_CREATE);
    if (fd == -1)
    {
        printf("Error while opening file.");
    }
    else
    {
        printf("File opened successfully.");
    }

    return 0;
}