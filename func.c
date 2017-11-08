
int searchidentifytable(char temp[200])
{
  int i;

  for(i=0;i<id_cnt;i++)
  {
	if(strcmp(temp,numbertable[i].name)==0)
	 return(i);
  }
  return(-1);
}

int search_littab(char temp[200])
{
  int i;
  for(i=0;i<literalcount;i++)
  {
	if(strcmp(temp,literal_table[i].name)==0)
	 return(i);
  }
  return(-1);
}
void lex(char source[8000])
{
  int i,id,lit=0,term=0,l=0,terminal_no,res;

  char temp[2000],terminal[2000],str[8000];

  fp1=fopen(source,"r");
  if(fp1==NULL)
  {
	printf("\n\n source file not found::");
	 
	exit(0);
  }

  while(fgets(str,80,fp1)!=NULL)
  {

  for(i=0;str[i]!='\0';i++)
  {
	  id=lit=term=l=0;

	  strcpy(temp,"");

	  if(str[i]=='{'||str[i]=='}'||str[i]=='['||str[i]==']')
	  {
		temp[l]=str[i];
		l++;
		temp[l]='\0';
	  }

	  if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
	  {
		temp[l]=str[i];
		l++;
		temp[l]='\0';
	  }


	  if(str[i]==','||str[i]=='.'||str[i]==':'||str[i]=='"')
	  {
		temp[l]=str[i];
		l++;
		temp[l]='\0';
	  }

	  if(str[i]=='#'||str[i]=='%'||str[i]=='('||str[i]==')')
	  {
		temp[l]=str[i];
		l++;
		temp[l]='\0';
	  }

	  if(str[i]=='<')
	  {
		   temp[l]=str[i];
		   l++;
		   if(str[i+1]=='=')
		   {
			 temp[l]=str[i+1];
			 i++;
			 l++;
		  }
		  temp[l]='\0';
	  }
	  else if(str[i]=='=')
	  {
		 temp[l]=str[i];
		 l++;
		 if(str[i+1]=='='||str[i+1]=='>')
		 {
		   temp[l]=str[i+1];
		   l++;
		   i++;
		 }
		 temp[l]='\0';
	  }
	  else if(str[i]=='>')
	  {
		temp[l]='>';
		l++;
		temp[l]='\0';
	  }
	  else if(isalpha(str[i]))
	  {
		temp[l]=str[i];
		l++;
		i++;
	 while( isalpha(str[i]) || isdigit(str[i]) || str[i]=='_'||str[i]=='.')
	 {
			temp[l]=str[i];
			i++;
			l++;
		}
		i--;
		temp[l]='\0';
		id=1;
	 }
	 else if(isdigit(str[i]))
	 {
		temp[l]=str[i];
		l++;
		i++;
		while(isdigit(str[i]))
		{
		 temp[l]=str[i];
		 l++;
		 i++;
		}
		i--;
		temp[l]='\0';
		lit=1;
	 }
	fp2=fopen("hi2.txt","r");

	if(fp2==NULL)
	{
	 printf("\n\n terminal file not found::");
	  
	 exit(0);
	}
	while(fscanf(fp2,"%s%d",terminal,&terminal_no)!=EOF)
	{
	  if(strcmp(terminal,temp)==0)
	  {
		strcpy(symboltable[u_cnt].name,temp);
		strcpy(symboltable[u_cnt].type,"term");
		symboltable[u_cnt].no=terminal_no;
		term=1;
		u_cnt++;
		break;
	   }
	}
	fclose(fp2);
	if(term!=1&&id==1)
	{
		 res=searchidentifytable(temp);

		 if(res==-1)//not found
		 {
			strcpy(symboltable[u_cnt].name,temp);
			strcpy(symboltable[u_cnt].type,"ID");
			symboltable[u_cnt].no=id_cnt;

			strcpy(numbertable[id_cnt].name,temp);
			numbertable[id_cnt].no=id_cnt;

			id_cnt++;
			u_cnt++;
		 }
		 else
		 {
			strcpy(symboltable[u_cnt].name,temp);
			strcpy(symboltable[u_cnt].type,"ID");
			symboltable[u_cnt].no=res;
			u_cnt++;
		 }
	}

	if(term!=1&&lit==1)
	{
		  res=search_littab(temp);
		 if(res==-1)//not found
		 {
			strcpy(symboltable[u_cnt].name,temp);
			strcpy(symboltable[u_cnt].type,"lit");
			symboltable[u_cnt].no=literalcount;

			strcpy(literal_table[literalcount].name,temp);
			literal_table[literalcount].no=literalcount;

			literalcount++;
			u_cnt++;
		 }
		 else
		 {
			strcpy(symboltable[u_cnt].name,temp);
			strcpy(symboltable[u_cnt].type,"lit");
			symboltable[u_cnt].no=res;
			u_cnt++;
		 }
	}
  }
 }
}

