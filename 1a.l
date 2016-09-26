
%{
  int c=0,w=0,l=0,b=0;
%}
%%
[\t] {b++;w++;}
[" "] {b++;w++;}
[\n] {l++;w++;}
[^" "\n\t]+ {c+=yyleng;}
%%
int main (int argc, char* argv[])
{
  if(argc >= 2)
  {
    yyin = fopen(argv[1],"r");
    yylex();
    printf("\n character= %d \n lines=%d \n blanks=%d \n words=%d \n",c,l,b,w);
  }
}
