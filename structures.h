struct symboltable
{
   int no;
   char type[20];
   char name[20];
}symboltable[200];

struct lit
{
   int no;
   char name[20];
}literal_table[1000];

struct id
{
  int no;
  char name[20];
}numbertable[1000];

FILE *fp1,*fp2;

char buff[8000];

int literalcount=0,id_cnt=0,u_cnt=0;
