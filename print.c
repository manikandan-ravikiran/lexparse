
void universaltable()
{ int i;

  printf("\n\n UNIVERSAL SYMB TABLE");
  printf("\nTERMINAL\tTYPE\tNO");
  for(i=0;i<u_cnt;i++)
  {
	printf("\n%s\t\t%s\t%d",symboltable[i].name,symboltable[i].type,symboltable[i].no);
	  
  }
}
void literaltable()
{
	int i;

  printf("\n\n litral table");
  printf("\nlitral\tNO");
  for(i=0;i<literalcount;i++)
  {
	printf("\n%s\t%d",literal_table[i].name,literal_table[i].no);
	 
  }
}
