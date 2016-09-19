#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include  <unistd.h>

int main(int argc, char const *argv[])
{
     pid_t  pid,child_id;
     pid = fork();
     if (pid<0)
     {
       printf("ERROR forking \n");
       return 0;
     }
     else if(pid==0)
     {
        printf("This is Chils process\n");
        printf("\nChild process i'd : %d",getpid());
        printf("\nParent process i'd : %d",getppid());
     }
     else
     {
       wait(1);
       printf("\n\nThis is Parent process\n");
       printf("\nParent process i'd : %d",getpid());
       printf("\nChild process i'd : %d\n",pid);
     }
     return 0;
}
