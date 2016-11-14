%{
#include <stdio.h>
#include <stdlib.h>
%}

% token ALPHA DIGIT

%%
S:ALPHA S1;
S1:DIGIT S1|ALPHA S1|;
%%
yyerror()
{
  printf("Invalid string\n");
  exit(0);
}
int main()
{
  printf("Enter the string\n");
  yyparse();
  printf("Valid string\n");
  return 0;
}
