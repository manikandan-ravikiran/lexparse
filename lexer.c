#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structures.h"
#include"func.c"
#include"print.c"



int main()
{
  char source[200];
  printf("\n\n enter source file name::");
  scanf("%s",source);
  lex(source);
   universaltable();
   literaltable();
	return 0;

	 
}
