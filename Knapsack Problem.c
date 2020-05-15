#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void valuetoIndex(int weight[],int no_of_elements,int j);

void Combination(int weight[],int no_of_elements,int r, int index, int subset[], int i,int Maximum_Permissible_Weight)
{
int sum=0;

      if (index == r) 
{ 
 for (int j = 0; j < r; j++) 
 {
  sum+=subset[j];
               
 }
 if(sum<=Maximum_Permissible_Weight)
 {
  for (int j = 0; j < r; j++) 
  {  
   valuetoIndex(weight,no_of_elements,subset[j]);
  }
  
 }
 sum=0;

 free(chr);
 printf("\n"); 
          return; 
     } 
   
     if (i >= no_of_elements) 
          return; 
 
subset[index] = weight[i]; 
Combination(weight, no_of_elements, r, index + 1, subset, i + 1,Maximum_Permissible_Weight); 
Combination(weight, no_of_elements, r, index, subset, i + 1,Maximum_Permissible_Weight); 

}
void valuetoIndex(int weight[],int no_of_elements,int j)
{
for(int i=0;i<no_of_elements;i++)
{
 if(j==weight[i])
  printf("%d ",i+1);
}

}
void Knapsack(int weight[],int no_of_elements, int r,int Maximum_Permissible_Weight)
{
int *subset;
subset=(int*)malloc(r*sizeof(int));

Combination(weight,no_of_elements,r,0,subset,0,Maximum_Permissible_Weight);
}

int main()
{
printf("\nEnter The Number Of Elements: ");
int no_of_elements;
scanf("%d",&no_of_elements);

int *element;
element=(int*)malloc(no_of_elements*sizeof(int));

printf("\nEnter The Maximum Permissible Weight i.e. W: ");
int Maximum_Permissible_Weight;
scanf("%d",&Maximum_Permissible_Weight);

int *weight;
weight=(int*)malloc(no_of_elements*sizeof(int));

printf("\nEnter The Weights Accordingly:\n");
for(int i=0;i<no_of_elements;i++)
{
 printf("\nEnter Weight Of Element %d : ",i+1);
 scanf("%d",&weight[i]);
}
for(int i=1;i<=no_of_elements;i++)
 Knapsack(weight,no_of_elements,i,Maximum_Permissible_Weight);

return 0;
}