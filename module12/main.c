// lexer in c

// library headers
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <sys/types.h>

// user definde functions
#include "vector.h"
#include "adv.h"

int main(int argc, char const *argv[]) {
  //a infinte while loop is called to rade the input from the users

  char Command[100]; // a string to hold the command

  int ContinueWhile = 1; // true by default

  while (ContinueWhile)
  {
    vector_init(v);
    printf("$ -> ");
    scanf("%s",Command);


  }
  return 0;
}
