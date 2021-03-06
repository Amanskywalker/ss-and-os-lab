#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,m,i,j;    //n=no. of processes, m= recources
int all[10][10],max[10][10],need[10][10],avail[10],work[10],req[10];
int count=0;
struct process
{
  char process[10]; // to name the process like process=0 implies process 0 = P0
  int flag; //used to check safe sequence
}p[10];

void input()
{
  printf("\n Enter total num of processes:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("\nprocess:-");
    scanf("%s",p[i].process);
  }
  printf("\n Enter the number of resources:");
  scanf("%d",&m);
  printf("\n Enter allocation matrix:");
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      scanf("%d",&all[i][j]);
    }
  }
  printf("\n Enter max matrix:");
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      scanf("%d",&max[i][j]);
    }
  }
  printf("\n  need matrix:");
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      need[i][j]=max[i][j]-all[i][j];
      printf("%d",need[i][j]);
    }
    printf("\n");
  }
  printf("\n Enter Available");
  for(i=0;i<m;i++)
  {
    scanf("%d",&avail[i]);
  }
}

void safeseq()
{
  int sseq[10],ss=0,chk=0,chki=0;
  for(j=0;j<m;j++)
    work[j]=avail[j];//initialise work=available
  for(i=0;i<n;i++)
    p[i].flag=0;//initialise finish[i]=false for i=0,1,2...
  while(count!=n)
  {
    for(i=0;i<n;i++)
    {
      chk=0;
      for(j=0;j<m;j++)
      {
        if(p[i].flag==0)
        {
          if(need[i][j]<=work[j])
            chk++;
        }
        if(chk==m)
        {
          for(j=0;j<m;j++)
          {
            work[j]=work[j]+all[i][j];
            p[i].flag=1;
          }
          sseq[ss]=i;
          ss++;
          count++;
        }
      }
    }
  }
  for(i=0;i<n;i++)
  {
    if(p[i].flag==1)
      chki++;
  }
  if(chki>=n)
  {
    printf("\n System is in safe state");
    for(i=0;i<n;i++)
      printf("%d",sseq[i]);
  }
  else
    printf("\nsystem is not safe");
}

void request()
{
  int processreq;
  printf("\n Enter the process process that is requesting:");
  scanf("%d",&processreq);
  printf("\n enter the reqested array:");
  for(i=0;i<m;i++)
    scanf("%d",&req[i]);
  for(j=0;j<m;j++)
  {
    if(req[j]<=need[processreq][j])
    {
      if(req[j]<=avail[j])
      {
        avail[j]=avail[j]-req[j];
        all[processreq][j]=all[processreq][j]+req[j];
        need[processreq][j]=need[processreq][j]-req[j];
        printf("avail:%d",avail[j]);
      }
      printf("\tneed: %d\n",need[processreq][j]);
    }
    else
    {
      printf("\n Process is not in safe state and hence request cannot be granted");
      //exit(0);
    }
  }
  printf("\nrequest can be granted");
}

void print()
{
   printf("no. of processes=%d",n);
   printf("no. of resources=%d",m);
   printf("\npid\t max \t allocated \t need");
   for(i=0;i<n;i++)
   {
     printf("\n%d\t",i);
     for(j=0;j<m;j++) printf(" %d ",max[i][j]); printf("\t");
     for(j=0;j<m;j++) printf(" %d ",all[i][j]); printf("\t");
     for(j=0;j<m;j++) printf(" %d ",need[i][j]); printf("\t");
   }
   printf("\n Available");
   for(i=0;i<m;i++)
      printf("%d ",avail[i]);
}

int main(int argc, char const *argv[])
{
  int ch;
  do
  {
    printf("\n menu:");
    printf("\n 1.Input:");
    printf("\n 2.Safe Seq:");
    printf("\n 3.Request:");
    printf("\n 4.Print:");
    printf("\n 5.exit:");
    printf("\n Ent choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: input();
              break;
      case 2: safeseq();
              break;
      case 3: request();
              break;
      case 4: print();
              break;
      case 5: return 0;
    }
  }while(1);
  return 0;
}

/*
Output:



$ cc 12.c
$ ./a.out

menu:
1.Input:
2.Safe Seq:
3.Request:
4.Print:
5.exit:
Ent choice1


Enter total num of processes:5
process:-0
process:-1
process:-2
process:-3
process:-4

Enter the number of resources:3
Enter allocation matrix:0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter max matrix:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
 need matrix:743
122
600
011
431
Enter Available3 3 2
menu:
1.Input:
2.Safe Seq:
3.Request:
4.Print:
5.exit:
Ent choice4
no. of processes=5no. of resources=3
pid  max     allocated   need
0    7  5  3     0  1  0     7  4  3
1    3  2  2     2  0  0     1  2  2
2    9  0  2     3  0  2     6  0  0
3    2  2  2     2  1  1     0  1  1
4    4  3  3     0  0  2     4  3  1
Available3 3 2
menu:
1.Input:
2.Safe Seq:
3.Request:
4.Print:
5.exit:
Ent choice2
System is in safe state13402
menu:
1.Input:
2.Safe Seq:
3.Request:
4.Print:
5.exit:
Ent choice3
Enter the process process that is requesting:1
enter the reqested array:1 0 2
avail:2 need: 0
avail:3 need: 2
avail:0 need: 0
request can be granted
menu:
1.Input:
2.Safe Seq:
3.Request:
4.Print:
5.exit:
Ent choice3
Enter the process process that is requesting:2
enter the reqested array:2 2 3
avail:0 need: 4
Process is not in safe state and hence request cannot be granted
*/
