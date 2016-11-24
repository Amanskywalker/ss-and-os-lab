#include <iostream>

using namespace std;

class proc
{
public:
  int id;
  int arrival;
  int brust;
  int rem;
  int wait;
  int finish;
  int turnaround;
  float ratio;

  void display()
  {
    turnaround = wait + brust;
    ratio = (float) turnaround/ (float) brust;
    cout << id << arrival << brust << wait << finish
      << turnaround << ratio << endl;
  }

}process[10],temp;

int no;

int chkprocess(int s) // function to check process remaining time is zero or not
{
  for(int i = 1; i <= s; i++)
  {
    if(process[i].rem != 0)
      return 1;
  }
  return 0;
}

int nextprocess()
{
  int min = 32000, l;
  for (int i = 1; i <= no; ++i)
  {
    if (process[i].rem != 0 && process[i].rem < min )
    {
       min = process[i].rem;
       l = i;
    }
  }
  return l;
}

void srtf(int n)
{
  int time=0,k;
  float tavg, wavg;
  for (int i = 1; i <= n; i++)
  {
    process[i].id = i;
    cout << "Enter the arrival time for process" << i << endl;
    cin >> process[i].arrival;
    cout << "Enter the brust time for process " << i << endl;
    cin >> process[i].brust;
    process[i].rem = process[i].brust;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = i+1; j <= n; j++)
    {
      if (process[i].arrival > process[j].arrival)
      {
        temp = process[i];
        process[i] = process[j];
        process[j] = temp;
      }
    }
  }
  no = 0;
  int j=0;
  while ( chkprocess(n) == 1)
  {
    if (process[no+1].arrival == time)
    {
      ++no;
      if (process[j].rem == 0)
        process[j].finish = time;
      j = nextprocess();
    }
    if (process[j].rem != 0)
    {
      process[j].rem--;
      for (int i = 1; i <= n; i++)
      {
        if (i != j && process[i].rem != 0 )
          process[i].wait++;
      }
    }
    else
    {
      process[j].finish = time;
      j=nextprocess();
      time--;
      k = j;
    }
    time++;
  }
  process[k].finish = time;
  cout << "---SHORTEST REMAINING TIME FIRST---" << endl;
  for (int i = 1; i <= n; i++)
  {
    process[i].display();
    tavg = tavg + process[i].turnaround;
    wavg = wavg + process[i].wait;
  }
  tavg = tavg/n;
  wavg = wavg/n;
  std::cout << "tavg = " << tavg << "shortest remaining time scheduling = " << wavg << endl;
}

void rr(int n, int tq, int st[], int bt[])
{
  int time = 0;
  int tat[10],wt[10],cq=0,swt=0,stat=0,temp1,sq=0,k;
  float awt=0,atat=0;
  while(true)
  {
    for(int i=0;i<n;i++)
    {
      temp1=tq;
      if(st[i]==0)
      {
        cq++;
        continue;
      }
      if(st[i]>tq)
        st[i]=st[i]-tq;
      if(st[i]>=0)
      {
        temp1=st[i];
        st[i]=0;
      }
      sq=sq+temp1;
      tat[i]=sq;
    }
    if(n == cq)
    break;
  }
  for (int i = 0; i < n; i++)
  {
    wt[i]=tat[i]-bt[i];
    swt=swt+wt[i];
    stat=stat+tat[i];
  }
  awt=(float)swt/n;
  atat=(float)stat/n;
  cout << "process no Brust time wait time turnaround time" << endl;
  for (int i = 0; i < n; i++)
    cout <<n+1<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
  cout << "awt = "<< awt << "\natat = " << atat << endl;
}

int main(int argc, char const *argv[])
{
  int n,tq,choice;
  int bt[10],st[10],i,j,k;
  while(true)
  {
    cout << "Enter teh choice \n 1. RR 2.SRT 3.exit" << endl;
    cin >> choice;
    switch (choice)
    {
      case 1:cout << "Round Robin" << "\nEnter the number of Process" << endl;
              cin >> n;
              cout << "Enter the brust Sequences:";
              for (int i = 0; i < n; i++)
              {
                cin >> bt[i];
                st[i]=bt[i];
              }
              cout << "Enter time quantum:" << endl;
              cin >> tq;
              rr(n,tq,st,bt);
              break;
      case 2:cout << "Shortest remaining time" << "\n Enter teh number of Process" << endl;
              cin >> n;
              srtf(n);
      case 3: return 0;
    }
  }
  return 0;
}
