#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int i,j,m,n,a;
int c[50][50];// Value  Matrix

char x[20];
char y[20];
char b[50][50];//Arrow Matrix

void print_LCS(int i, int j)
{
if(i==0 || j==0)
return ;

if(b[i][j]=='C')
{
 print_LCS(i-1,j-1);
 printf("%c",x[i-1]);
}
else if(b[i][j]=='U')
 print_LCS(i-1,j);
else
 print_LCS(i,j-1);
}

void LCS_length()
{
m= strlen(x);
n=strlen(y);

for(i=0;i<=m;i++)// For 0
c[i][0]=0;

for(i=0;i<=n;i++) //For 0
c[0][i]=0;

for(i=1;i<=m;i++)
{
 for(j=1;j<=n;j++)
 {
  if(x[i-1]==y[j-1])
  {
   c[i][j]=c[i-1][j-1]+1;
   b[i][j]='C';
  }
  else if(c[i-1][j]>=c[i][j-1])
  {
   c[i][j]=c[i-1][j];
   b[i][j]='U';    
  }
  else
  {
   c[i][j]=c[i][j-1];
   b[i][j]='l';    
  }   
 }
} 
print_LCS(m,n);
}

int main()
{

printf("\nEnter The 1st String: ");
scanf("%s",x);

printf("\nEnter The 2nd String: ");
scanf("%s",y);

printf("\nThe LCS is : ");
LCS_length(m,n);
return 0;
}
