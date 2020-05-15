#include<stdio.h>
#include<stdlib.h>
int max= -99999;
int min= 99999;
int *a;

void FindMax(int left, int right)
{
if(a[left] > max)
{
 max=a[left];
}
if(a[right]>max)
{
 max=a[right];
}
if(left<right)
FindMax(left+1,right-1);
}

void FindMin(int left, int right)
{
if(a[left] < min)
{
 min=a[left];
}
if(a[right]< min)
{
 min=a[right];
}
if(left < right)
FindMin(left+1, right-1);
}


int main()
{
printf("Enter The Size Of Array");
int size;
scanf("%d",&size);

a=(int*)malloc(size*sizeof(int));

for(int i=0;i<size;i++)
{
 printf("Enter Number %d ",i+1);
 scanf("%d",&a[i]);
}
FindMax(0,size-1);
FindMin(0,size-1);
printf("\nThe Max Value Is:: %d \n",max);
printf("\nThe Min Value Is:: %d \n",min);
return 0;
}