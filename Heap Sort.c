#include<stdio.h>
#include<stdlib.h>

FILE *fp,*f1;
float sum=0,c1=0,c2=0;

void swap(int *a, int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}
void max_heapify(int a[],int n, int i)
{
int large=i;
int left=2*i+1;
int right=2*i+2;
c1++;

if(left<n && a[left]>a[large])
 large=left;

if(right<n && a[right]>a[large])
 large=right;

if(large!=i)
{
 swap(&a[i],&a[large]);
 max_heapify(a,n,large);
}

}

void heap_sort(int a[], int n)
{
int i;
for(i=(n/2)-1;i>=0;i--)
 max_heapify(a,n,i);

for(i=n-1;i>=1;i--)
{
 swap(&a[0],&a[i]);
 max_heapify(a,i,0);  
}
}



int main()
{
int n,i;
printf("\nEnter The Size Of Array: ");
scanf("%d",&n);
int a[n];

fp=fopen("input_heapsort.txt","r");
f1=fopen("output_heapsort.txt","a");

if(fp!=NULL)
{
 while(!feof(fp))
 {
  for(i=0;i<n;i++)
  {
   fscanf(fp,"%d ",&a[i]);    
  }
  c1=0;
  heap_sort(a,n);
  
  for(i=0;i<n;i++)
  {
   fprintf(f1,"%d ",a[i]);  
  }
  c2++;
  fprintf(f1,"No. Of Comparisons = %d",c1);
  sum+=c1;
  fprintf(f1,"\n");
 }  
}
float average=sum/c2;

printf("\nAverage Comparisons = %f\n",average);
return 0;
}