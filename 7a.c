#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include  <unistd.h>

#define   MAX_COUNT  200
#define   BUF_SIZE   100

void  main(void)
{
     pid_t  pid;
     int    i,count;
     char   buf[BUF_SIZE];

     printf("Enter the numbers of commands\n");
     scanf("%d",&count);

     pid = fork();

     if(!pid)
     {
        for (i = 0; i < count; i++)
        {
          printf("Enter the commands:");
          scanf("%s",buf);
          system(buf);
        }
     }
     else
     {
       wait(10);
       exit(1);
     }

     printf("Parent process completed\n");

     return 0;
}
