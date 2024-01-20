#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define _GNU_SOURCE
extern char * program_invocation_short_name;
extern char * program_invocation_name;

int main(int argc, char * argv[])
{
    if (strcmp(argv[0],"./argv_ex") == 0)
    {
        printf("This is comm1.\r\n");
        printf("%s\r\n",program_invocation_name);
    }
    else if (strcmp(argv[0],"./comm2") == 0)
    {
        printf("This is comm2");
    }
    else 
    {
        printf("%s\r\n",argv[0]);
    }

    return 0;
}