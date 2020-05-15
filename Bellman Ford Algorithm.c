#include<stdio.h>

#include<stdlib.h>

#define MAX 9999



struct Edge

{

int source, destination, weight;

};



struct Graph

{

int vertices,edges;

struct Edge* edge;

};



struct Graph* createGraph(int V, int E)

{

struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

graph->vertices=V;

graph->edges=E;

graph->edge=(struct Edge*)malloc(sizeof(struct Edge)*E);

return graph;

}



void Display(int V,int distance[])

{

printf("Vertex   Distance from Source\n");

     for (int i = 0; i < V; ++i)

printf("%d \t\t %d\n", i, distance[i]);

}





void Bellman_Ford(struct Graph* graph, int source)

{

int V = graph->vertices;

int E = graph->edges;



int *distance;

distance=(int*)malloc(V*sizeof(int));



for(int i=0;i<V;i++)

{

 distance[i]=MAX;

}

distance[source]=0;



for(int i=1;i<V;i++)

{

 for(int j=0;j<E;j++)

 {

  int u = graph->edge[j].source;

  int v = graph->edge[j].destination;

  int w = graph->edge[j].weight;



  if(distance[u] != MAX && distance[u] + w < distance[v])

  {

   distance[v] = distance[u] + w;

  }

 }

}



for(int i=1;i<V;i++)

{

 for(int j=0;j<E;j++)

 {

  int u = graph->edge[j].source;

  int v = graph->edge[j].destination;

  int w = graph->edge[j].weight;



  if(distance[u] != MAX && distance[u] + w < distance[v])

  {

   printf("\nGraph contains negative weight cycle\n");

  }

 }

}

Display(V,distance);

}



int main()

{

printf("\nEnter The Number Of Vertices: ");

int V;

scanf("%d",&V);



printf("\nEnter The Number Of Edges: ");

int E;

scanf("%d",&E);



printf("\nEnter The Source Vertex: ");

int source_vertex;

scanf("%d",&source_vertex);



struct Graph* graph = createGraph(V,E);

for(int i=0;i<E;i++)

{

 printf("\nEnter Source: ");

 scanf("%d",&graph->edge[i].source);

 printf("\nEnter Destination: ");

 scanf("%d",&graph->edge[i].destination);

 printf("\nEnter Weight: ");

 scanf("%d",&graph->edge[i].weight);

}



Bellman_Ford(graph,source_vertex);

return 0;

}
