#include <stdlib.h>
#include <stdio.h>
#include<time.h>
int size;
void Display();
int *a;
int *b;
clock_t t;
int Partition_Random(int left, int right);

int Partition_Left(int left, int right)
{
         int pivot=a[left];
int counter =0;//Number of values which are smaller than the pivot,it takes count of that.... 

for(int i=left;i<=right;i++)
{
 if(a[i]<=pivot)
 counter++;
}
counter--;
int swap=a[left];
a[left] = a[left+counter];
a[left+counter]=swap;

int j= right;

for(int i=left; i<=right; i++)
{
 if(a[i]>pivot)
 {
  int temp=a[i];
  a[i]=a[j];
  a[j]=temp;
  right--;
  j--;
  i=left; 
 }
}
//printf("pivot index = %d\n",left+counter);
return (left+counter);
}

int Partition_Right(int left, int right)
{
int pivot =a[right];
int i=(left -1);

for(int j=left;j<right;j++)
{
 if(a[j] <= pivot)
 {
  i++;
  int swap=a[i];
  a[i]=a[j];
  a[j]=swap;
 }
}

int temp=a[i+1];
a[i+1]=a[right];
a[right]=temp;

return (i+1);
}

                             
int Partition_Middle(int beg, int end)
{
        int pivot, i, j, temp;

        pivot = beg + (end-beg)/2;
        do{
                for(i=beg; i<pivot; i++){
                        if(a[i] > a[pivot]){
                                break;
                        }
                }
                for(j=end; j>pivot; j--){
                        if(a[j] < a[pivot]){
                                break;
                        }
                }
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
        }while(i<j);
        return pivot;
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
 if(a[i] <= pivot)
 counter++;
}
counter--;
int swap=a[index];
a[index]=a[left+counter];
a[left+counter]=swap;

int j=right;

for(int i=left;i<=right;i++)
{
 if(a[i] > pivot)
 {
  int temp=a[i];
  a[i]=a[j];
  a[j]=temp;
  right--;
  j--;
  i=left;
 }
}
//Display();
return (left+counter);
}


                                                           
void Quicksort_Middle(int left, int right)
{
        int pivot;
        if(left<right)
{
 pivot = Partition_Middle(left,right);
 Quicksort_Middle(left, pivot-1);
 Quicksort_Middle(pivot+1,right);
}
}
void Quicksort_Left(int left, int right)
{
int pivot;
if(left < right)
{
 pivot = Partition_Left(left,right);
 Quicksort_Left(left, pivot-1);
 Quicksort_Left(pivot+1, right);
}
}


void Quicksort_Right(int left, int right)
{
int pivot;
if(left < right)
{
  pivot= Partition_Right(left,right);
  Quicksort_Right(left,pivot-1);
  Quicksort_Right(pivot+1,right);
}

}



void resetArray()
{
for(int i=0;i<size;i++)
{
 a[i]=b[i];
}
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
        

while(input!=5)
{
 printf("\nEnter 1 For Left Pivot QuickSort\nEnter 2 For Right Pivot\nEnter 3 For Middle Pivot\nEnter 4 For Random Pivot\nEnter 5 For Exit\n"); 
 scanf("%d",&input);
 printf("\n Before sorting array :  ");
 Display();

 switch(input)
 {
  case 1:
   t=clock();
   Quicksort_Left(0, size-1);
           Display();
   resetArray();
   break;
 
  case 2:
   t=clock();
   Quicksort_Right(0,size-1);
   Display();
   resetArray();
   
   break;

  case 3:
   t=clock(); 
   Quicksort_Middle(0, size-1);
           Display();
   resetArray();
   break;

  case 4:
   t=clock();
   Quicksort_Random(0,size-1);
   Display();
   resetArray();
   
   break;

  case 5:
   break;

  default:
   printf("\nEnter Correct Input\n");
   break;
 } 
}
        return 0;
}
