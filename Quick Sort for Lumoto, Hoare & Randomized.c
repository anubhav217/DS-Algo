#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int size;
void Display();
int *a;
int *b;
clock_t t;

int comparison=0;

void Swap(int *a, int *b)
{
int Swap=*a;
*a=*b;
*b=Swap;
}

int Generate_Random(int left, int right)
{
srand(time(NULL));  
int index_number = (rand() % (right -left + 1)) + left; 
printf("\nThe Random Index Is %d \n",index_number);
return index_number; 
}


int Partition_Random(int left, int right)
{
int index=Generate_Random(left,right);
int pivot=a[index];
int counter=0;

for(int i=left; i<=right;i++)
{
 comparison++;
 if(a[i] <= pivot)
 {
  counter++;
 }
}
counter--;
//int swap=a[index];
//a[index]=a[left+counter];
//a[left+counter]=swap;
Swap(&a[index],&a[left+counter]);

int j=right;

for(int i=left;i<=right;i++)
{
 comparison++;
 if(a[i] > pivot)
 {
  Swap(&a[i],&a[j]);
  right--;
  j--;
  i=left;
 }
}
//Display();
return (left+counter);
}


void Quicksort_Random(int left, int right)
{
int pivot;
if(left < right)
{  
  pivot= Partition_Random(left,right);
  Quicksort_Random(left,pivot-1);
  Quicksort_Random(pivot+1,right);
}
}

int Partition_Lumoto(int left, int right)
{
int pivot =a[right];
int i=(left -1);

for(int j=left;j<right;j++)
{
 comparison++;
 if(a[j] <= pivot)
 {
  i++;
  Swap(&a[i],&a[j]);
 }
}

Swap(&a[i+1],&a[right]);
return (i+1);
}

void Quicksort_Lumoto(int left, int right)
{
int pivot;
if(left < right)
{
  pivot= Partition_Lumoto(left,right);
  Quicksort_Lumoto(left,pivot-1);
  Quicksort_Lumoto(pivot+1,right);
}

}


int Partition_Hoare(int left, int right)
{
int l=left;
int r=right;
for( ; l<r-1; )
{
 comparison++;
 if(a[l] < a[l+1])
 {
  l++;
 }
 else
 {
  Swap(&a[l],&a[l+1]);
  l++;   
 }
 comparison++;
                              if(l!=r-1)
 {
  comparison++;
  if(a[r] > a[r-1])
  {
   
   Swap(&a[r],&a[r-1]);
   r--;
  }
  else
  {
   
   r--;
  }
 }
 comparison++;
                              if(l+1==r)
 {
  comparison++;
  if(a[l]<a[r])
  {
   
   Swap(&a[r],&a[right]);
  }
  else
  {
   
   Swap(&a[l],&a[right]);
  }
  Partition_Hoare(left,right-1);
 }
}
comparison++;
if(a[left]>a[left+1])
{
 Swap(&a[left],&a[left+1]);
}
}



void Quicksort_Hoare(int left,int right)
{

               if(left<right)
{ 
 Partition_Hoare(left,right);
 
}
}
void resetArray()
{
for(int i=0;i<size;i++)
{
 a[i]=b[i];
}

comparison=0;

t=clock()-t;
double time_taken= ((double)t)/CLOCKS_PER_SEC;
printf("\nTime taken by Quicksort = %f\n\n",time_taken);
}

void Display()
{
for(int i=0;i<size;i++)
{
 printf("%d\t",a[i]);
}
printf("\n");
printf("Total Comparisons = %d\n",comparison);
//resetArray();
}



int main()
{

int input=0;


printf("\nEnter Size Of The Array: ");
scanf("%d",&size);

a=(int*)malloc(size*sizeof(int));
b=(int*)malloc(size*sizeof(int));

for(int i=0;i<size;i++)
{
 printf("\nEnter Term %d: ",i+1);
 scanf("%d",&a[i]);
 b[i]=a[i];
}

while(input!=4)
{
 printf("\nEnter 1 For Lumoto Partition\nEnter 2 For Hoare Partition\nEnter 3 For Randomized Quick Sort\nEnter 4 For Exit\n"); 
 scanf("%d",&input);
 printf("\n Before sorting array :  ");
 Display();

 switch(input)
 {
  case 1: 
   Quicksort_Lumoto(0, size-1);
           Display();
   resetArray();
   break;
 
  case 2:
   Quicksort_Hoare(0,size-1);
   Display();
   resetArray();
   break;
  
  case 3:
   Quicksort_Random(0,size-1);
   Display();
   resetArray();
   break;

  case 4:
   break;

  default:
   printf("\nEnter The Correct Input\n");
   break;
 }
}
return 0; 
}