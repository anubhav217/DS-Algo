#include<stdio.h>
#include<stdlib.h>

int *a;
int size;
FILE *fp;

void Swap(int *a,int *b)
{
int Swap=*a;
*a=*b;
*b=Swap;
}


void permutation(int left, int right)
{
int i;
if(left==right)
{
 fp=fopen("input_heapsort.txt","a");
 if(fp!=NULL)
 {
  for(i=0;i<=right;i++)
  {
   fprintf(fp,"%d ",a[i]);
  }
  fprintf(fp,"\n");
  fclose(fp);
 }
}
else
{
 for(i=left;i<=right;i++)
 {
  Swap(&a[i],&a[left]);
  permutation(left+1,right);
  Swap(&a[i],&a[left]);
 } 
}
}



int main()
{
printf("\nEnter The Size Of Array: ");
scanf("%d",&size);

a=(int*)malloc(size*sizeof(int));

int i;

for(i=0;i<size;i++)
{
 a[i]=i+1;
}

permutation(0,size-1);
free(a);


return 0;
}