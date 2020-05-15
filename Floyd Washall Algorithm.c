#include<stdio.h>
#include<stdlib.h>

#define INFINITY 99999
int vertices;
int **distance;

void Floyd_Warshall(int **a)
{
distance=(int**)malloc(vertices*sizeof(int*));
for(int i=0;i<vertices;i++)
{
 distance[i]=(int*)malloc(vertices*sizeof(int));
}

for(int i=0;i<vertices;i++)
{
 for(int j=0;j<vertices;j++)
 {
  distance[i][j]=a[i][j];
 }
}

for(int k=0;k<vertices;k++)
{
 for(int i=0;i<vertices;i++)
 {
  for(int j=0;j<vertices;j++)
  {
   if(distance[i][j] > distance[i][k] + distance[k][j])
   {
    distance[i][j] = distance[i][k] + distance[k][j];
   }
   
  }
 }
}


}

void Display_Tabular_Form()
{
for(int i=0;i<vertices;i++)
{
 for(int j=0;j<vertices;j++)
 {
  printf("%d\t",distance[i][j]);
 }
 printf("\n");
}
}

void Display_All_Possible_Paths()
{
for(int i=0;i<vertices;i++)
{
 for(int j=0;j<vertices;j++)
 {
  printf("\nSource= %d Destination= %d ----> Cost= %d",i,j,distance[i][j]);
  printf("\n");
 }
}

}

void Display_Source_Destination()
{
printf("\nEnter Source Vertex : ");
int source_vertex;
scanf("%d",&source_vertex);

printf("\nEnter Destination Vertex :");
int destination_vertex;
scanf("%d",&destination_vertex);

for(int i=0;i<vertices;i++)
{
 for(int j=0;j<vertices;j++)
 {
  if(i==source_vertex && j==destination_vertex)
  {
   printf("\nSource= %d Destination= %d ----> Cost= %d",i,j,distance[i][j]);
   printf("\n"); 
  }
 }
}

}

int main()
{ 
printf("\nEnter The Number Of Vertices : ");
scanf("%d",&vertices);

int **a=(int**)malloc(vertices*sizeof(int*));
int value;

for(int i=0;i<vertices;i++)
{
 a[i]=(int*)malloc(vertices*sizeof(int));
}
printf("\n-----------Enter -1 For Infinity Values---------------------\n");

for(int i=0;i<vertices;i++)
{
 for(int j=0;j<vertices;j++)
 {
  printf("\nEnter The Data For Row %d & Column %d: ",i+1,j+1);
  scanf("%d",&value);
 
  if(value!=-1)
   a[i][j]=value;
  else
   a[i][j]=INFINITY;
 }
}
Floyd_Warshall(a);
Display_Tabular_Form();
Display_All_Possible_Paths();
Display_Source_Destination();
return 0; 
}