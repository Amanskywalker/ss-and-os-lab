%{
  #include <stdio.h>
  int flag=0;
%}
%%
(""[aA][nN][dD]"")|(""[bB][uU][tT]"")|(""[oO][rR]"")|(""[nN][oO][tT]"") {flag=1;}
. {;}
%%
int main()
{
  printf("\n Enter a Sentence:\n");
  yylex();
  if(flag)
    printf("\n Compound Sentence");
  else
    printf("\n Simple Sentence");
  return 0;
}
