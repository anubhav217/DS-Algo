#include<stdio.h>
#include<stdlib.h>

void parenthesise(int *order, int **scalar,int **split,int chainsize)
{
int i,j,k,len,t;

for(i=0;i<chainsize;i++)
 scalar[i][i]=0;

for(len=2;len<=chainsize;len++)
{
 for(i=0;i<=chainsize-len;i++)
 {
  j=i+len-1;
  scalar[i][j]=99999;

  for(k=i;k<=j-1;k++)
  {
   t=scalar[i][k]+scalar[k+1][j]+(order[i]*order[k+1]*order[j+1]);
   if(t<scalar[i][j])
   {
    scalar[i][j]=t;
    split[i][j]=k;
   }
  }
 }
}

printf("\nThe Scalar Matrix : \n");
for(i=0;i<chainsize;i++)
{
 for(j=0;j<chainsize;j++)
 {
  printf("%d\t",scalar[i][j]);
 }
 printf("\n");
}
printf("\n"); 

printf("\nThe Split Matrix :: \n");
for(i=0;i<chainsize;i++)
{
 for(j=0;j<chainsize;j++)
 {
  printf("%d\t",split[i][j]);   
 }
 printf("\n");  
} 
}

void parenthesis(int **split,int i, int j)
{
if(i==j)
 printf("A%d ",i+1);
else
{
 printf("( ");
 parenthesis(split,i,split[i][j]);
 parenthesis(split,split[i][j]+1,j);
 printf(" )");   
} 
}

int main()
{
int a[100],b[100],**scal,**spl;
int i,k=1;

printf("\nEnter The Number Of Matrices :: ");
int n;
scanf("%d",&n);

scal=(int**)malloc(n*sizeof(int*));
for(i=0;i<n;i++)
 scal[i]=(int*)malloc(n*sizeof(int));

spl=(int**)malloc(n*sizeof(int*));
for(i=0;i<n;i++)
 spl[i]=(int*)malloc(n*sizeof(int));

printf("\nEnter The Number Of Rows And Columns Of %d Matrices: ",n);
for(i=0;i<2*n;i++)
{
 scanf("%d",&a[i]);
}
for(i=1;i<2*n-1;i+=2)
{
 b[k]=a[i];
 k++;  
}

b[0]=a[0];
b[n]=a[2*n-1];

printf("\nThe Order Matrix:\n");
for(i=0;i<=n;i++)
{
 printf("%d\t",b[i]);
}
printf("\n");

parenthesise(b,scal,spl,n);
parenthesis(spl,0,n-1);

return 0; 
}