%{
#include <stdio.h>
int id=0,op=0,a=0,s=0,d=0,m=0,ob=0,cb=0,flag=1;
%}
%%
[a-zA-Z][a-zA-Z0-9]* {id++;printf("\n %s an idetifier",yytext);}
"+" {op++;a++;printf("\n %s an operator",yytext);}
"*" {op++;m++;printf("\n %s an operator",yytext);}
"-" {op++;s++;printf("\n %s an operator",yytext);}
"/" {op++;d++;printf("\n %s an operator",yytext);}
"(" {ob++;}
")" {if(ob>cb) cb++;
else flag=0;}
\n ext();
%%
int ext()
{
    return 0;
}
int main(int argc,char* argv[])
{
  printf("Enter the airthmetic expressions :");
  if(yylex()==0);
  int b=ob+cb;
  if((id==op+1) && (b%2==0) && (ob==cb) && (flag==1))
  {
    printf("\nThe expressions is valild");
    printf("\n No of \n addop=%d \n subop=%d \n mulop=%d \n divop=%d \n open bracket=%d \n close bracket=%d \n identifiers=%d \n",a,s,m,d,ob,cb,id);
  }
  else
  {
    printf("\n invalid expressions");
  }
  return 0;
}
