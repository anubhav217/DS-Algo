#include<stdio.h>
#include<stdlib.h>

int Matrix_Chain(int a[],int i, int j)
{
if(i==j) //when A x A occurs or B x B occurs then we shouls return
return 0;
int MIN=99999;
int count=0;

for(int k=i;k<j;k++)
{
 count= Matrix_Chain(a,i,k)+
 Matrix_Chain(a,k+1,j)+
 a[i-1]*a[k]*a[j];

 if(count<MIN)
 MIN=count;
}
return MIN;
}

int main()
{
printf("\nEnter The Number Of Matrices : ");
int Number_Of_Matrices;
scanf("%d",&Number_Of_Matrices);

int *a;
a=(int*)malloc( (Number_Of_Matrices+1)*sizeof(int));
int j=0;

for(int i=0;i<Number_Of_Matrices;i++)
{
 printf("\nEnter Row Of Matrix %d : ",i+1);
 int row;
 scanf("%d",&row);
 printf("Enter Column Of Matrix %d ",i+1);
 int column;
 scanf("%d",&column);

 if(i==0)
 {
  a[j++]=row;
  a[j++]=column;
 }
 else
 {
  if(a[j-1]!=row)
  {   
   printf("\n Invalid Input, Try again\n");
   i--;
  }
  else
  {
   a[j++]=column;
  }
 }
}

/*for(int i=0;i<=Number_Of_Matrices;i++)
{
 printf("\n%d\t",a[i]);
}*/
int t=Matrix_Chain(a,1,Number_Of_Matrices);
printf("\nThe Minimum Order Of Matrix Multiplication is %d",t);


return 0;
}