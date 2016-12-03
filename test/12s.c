#include<stdlib.h>
#include<stdio.h>
int n,m,j,i;
int all[10][10],max[10][10],need[10][10],req[10],work[10],avail[10];

struct process
{
  int flag;
}p[10];

void input()
{
  printf("enter the number of processes \n");
  scanf("%d",&n);
  printf("enter the number of resources \n");
  scanf("%d",&m);
  printf("enter the allocation matrix \n");
  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      scanf("%d",&all[i][j]);
  printf("enter the max matrix \n");
  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      scanf("%d",&max[i][j]);
  printf("need matrix \n");
  for(i=0;i<n;i++)
  {
      for(j=0;j<m;j++)
      {
          need[i][j]=max[i][j]-all[i][j];
          printf("%d",need[i][j]);
      }
      printf("\n");
  }

  printf("enter available\n");
  for(j=0;j<m;j++)
    scanf("%d",&avail[j]);
}

void safseq()
{
  int ss=0,chk=0,chki=0,sseq[10],count=0;
  for(j=0;j<m;j++)
    work[j]=avail[j];
  for(i=0;i<n;i++)
    p[i].flag=0;
  printf("work sequence \n");
  while(count!=n)
  {
	  for(i=0;i<n;i++)
	  {
	    chk=0;
			for(j=0;j<m;j++)
			{
	        if(p[i].flag==0)
           		if(need[i][j]<=work[j])
			           chk++;
 			    if(chk==m)
			    {
			          for(j=0;j<m;j++)
			          {
                  work[j]=work[j]+all[i][j];
                  printf("%d",work[j]);
                  p[i].flag=1;
                }
                printf("\n");
                sseq[ss]=i;
                ss++;
                count++;
          }
      }
    }
  }

  for(i=0;i<n;i++)
    if(p[i].flag==1);
      chki++;
  if(chki==n)
  {
    printf("safe state \n");
    for(i=0;i<n;i++)
      printf("sequence is %d",sseq[i]);
  }
  else
    printf("not safe \n");
}

void request()
{
  int pro;
  printf("enter the process number \n");
  scanf("%d",&pro);

  printf("enter the request \n ");
  for(j=0;j<m;j++)
    scanf("%d",&req[j]);

  for(j=0;j<m;j++)
  {
      if(req[j]<=need[pro][j])
      {
          if(req[j]<=avail[j])
          {
            avail[j]=avail[j]-req[j];
            all[pro][j]=all[pro][j]+req[j];
            need[pro][j]=need[pro][j]-req[j];
            printf("%d",avail[j]);
          }
          printf("%d",need[pro][j]);
      }
      else
      {
          printf("error \n");
          exit(0);
      }
  }
}

void print()
{
	printf("Max matrix \n");
	for(i=0;i<n;i++)
  {
		for(j=0;j<m;j++)
			printf("%d ",max[i][j]);
		printf("\n");
	}
	printf("Allocation matrix\n");
	for(i=0;i<n;i++)
  {
		for(j=0;j<m;j++)
			printf("%d ",all[i][j]);
		printf("\n");
	}
	printf("Need matrix \n");
	for(i=0;i<n;i++)
  {
		for(j=0;j<m;j++)
			printf("%d ",need[i][j]);
		printf("\n");
	}
	printf("Available : ");
	for(j=0;j<m;j++)
		printf("%d ",avail[j]);
}

int main()
{
	int ch;
	while(1)
  {
		printf("\n\nMenu\n1.Input\n2.Safe seq\n3.Request\n4.Print\n5.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
    {
			case 1: input(); break;
			case 2: safseq(); break;
			case 3: request(); break;
			case 4: print(); break;
			case 5: exit(0);
			default: printf("Invalid choice \n"); continue;
		}
	}
	return 0;
}
