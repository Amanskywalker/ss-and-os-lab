%{
  #include <stdio.h>
  int flag=0;
%}
id [a-zA-Z0-9]*
%%
{id}" and|but|or|not|between "{id} {flag=0;}
. ;
\n {return 0;}
%%
int main()
{
  printf("\n Enter a Sentence:\n");
  yylex();
  if(flag)
    printf("\n Compound Sentence \n");
  else
    printf("\n Simple Sentence \n");
  return 0;
}
