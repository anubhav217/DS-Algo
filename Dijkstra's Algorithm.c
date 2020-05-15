#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

int vertices;
int *distance;
int *visited;
int *predecessor;
int *a[100];

int Minimum_Distance(int distance[],int visited[])
{
int Max_Value =MAX;
int Minimum_Node_Value; 
   
for (int i= 0;  i< vertices; i++) 
if (visited[i] == 0 && distance[i] <= Max_Value)
{
 Max_Value = distance[i]; 
 Minimum_Node_Value = i;
} 
return Minimum_Node_Value;  
}


int Display(int dist[], int vertices) 
{ 
printf("Vertex   Distance from Source\n"); 
for (int i = 0; i < vertices; i++) 
printf("%d -----> %d\n", i, dist[i]); 
} 

void Dijkstra(int start_node)/// source_vertex & start_node are same
{
predecessor=(int*)malloc(vertices*sizeof(int)); 
distance=(int*)malloc(vertices*sizeof(int));
visited=(int*)malloc(vertices*sizeof(int));

for(int i=0;i<vertices;i++)
{
 distance[i]=MAX;
 visited[i]=0;
 predecessor[i]=start_node;//0 is the starting node.
}

distance[start_node]=0;

for(int i=0;i<vertices-1;i++)
{
 int u= Minimum_Distance(distance,visited);//'u' is the next node
 visited[u] =1;

 for(int v=0;v<vertices;v++)
 {
  if(!visited[v] && a[u][v] && distance[u]!=MAX && distance[u]+ a[u][v] < distance[v])
  {
   distance[v]= distance[u] + a[u][v];
   predecessor[v]=u;
  }
 } 
}
Display(distance,vertices);

for(int i=0;i<vertices;i++)
{
 if(i!=start_node)
 {
  printf("\nDistance of node %d= %d",i,distance[i]);
  printf("\nPath= %d",i);
  int j;
  j=i;
  do
  {
   j=predecessor[j];
   printf("<-%d",j);
  }while(j!=start_node);
 }
} 
}

int main()
{
printf("Enter The Number Of Vertices::");
scanf("%d",&vertices);
//int *a[vertices]; 
     for (int i=0; i<vertices; i++) 
          a[i] = (int *)malloc(vertices * sizeof(int)); 
//int **a;
//a=(int**)malloc(vertices*vertices*sizeof(int*));

printf("\nEnter The Starting Node:: ");
int start_node;
scanf("%d",&start_node);

printf("\n\nEnter The Adjacency Matrix:: ");

for(int i=0;i<vertices;i++)
{
 for(int j=0;j<vertices;j++)
 {
  //int input;
  scanf("%d",&a[i][j]);
  //scanf("%d",&input);
  //*(a + i*vertices + j)=input;
 }
}
Dijkstra(start_node);
return 0;
}