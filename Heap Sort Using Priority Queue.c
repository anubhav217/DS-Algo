#include<stdio.h>
#include<stdlib.h>
#define size 100

int front=-1;
int rear=-1;

struct node
{
int data;
int priority;
};

struct node* Queue[size];
int data_counter=0;//To count the datas available in the queue
int arr[size];

void EnQueue(struct node *p)
{

Queue[++rear]=p; 
}

void Display()
{
for(int i=0;i<=rear;i++)
{
 printf("%d\t",Queue[i]->data);
}
}

void rearrange()
{
  for(int i=0;i<rear;i++)
{
 for(int j=i+1;j<=rear;j++)
 {
  if(Queue[i]->priority < Queue[j]->priority)
  {
   struct node *swap;
   swap=Queue[i];
   Queue[i]=Queue[j];
   Queue[j]=swap;
  }   
 }
}
   
}

void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        //swap(arr[i], arr[largest]); 
         int temp;
         temp=arr[largest];
         arr[largest]=arr[i];
         arr[i]=temp;
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
// Build heap (rearrange array) 
for (int i = n / 2 - 1; i >= 0; i--) 
heapify(arr, n, i); 

// One by one extract an element from heap 
for (int i=n-1; i>=0; i--) 
{ 
// Move current root to end  
 int temp;
 temp=arr[0];
 arr[0]=arr[i];
 arr[i]=temp;
 // call max heapify on the reduced heap 
 heapify(arr, i, 0); 
} 
} 

void printArray(int arr[], int n) 
{ 
     for (int i=0; i<n; ++i) 
         printf("%d\t",arr[i]);  
} 

int main()
{
int input=0;
printf("\nPress 1 For EnQueue\nPress 2 For Exit\n");  
scanf("%d",&input);

while(input!=2)
{  

 struct node *p=(struct node*)malloc(sizeof(struct node));
 printf("\nEnter Data\n");
 scanf("%d",&p->data);

 printf("\nEnter Priority of that data\n");
 scanf("%d",&p->priority);
 arr[data_counter]=p->data;
 data_counter++;
 EnQueue(p);

 printf("\nPress 1 For EnQueue\nPress 2 For Exit\n");  
 scanf("%d",&input);  
}
rearrange();
Display();
heapSort(arr, data_counter); 
               printf("\nSorted array is \n"); 
     printArray(arr, data_counter); 

return 0;
}