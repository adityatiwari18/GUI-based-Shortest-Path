#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Edge{ //This structure create an edge

int u;
int v;
int w;
};

struct graph{ // This structure create a graph
int V;
int E;
struct Edge *edge;
};
void bellman(struct graph *g,int source);
void display(int arr[],int t);


int main(void)
{
 struct graph *g = (struct graph*)malloc(sizeof(struct graph));
printf("Enter the number of verticse");
scanf("%d",&g->V);
printf("Enter the number of edges");
scanf("%d",&g->E);
 
 g->edge = (struct Edge*)malloc(g->E * sizeof(struct Edge));
printf("Enter the source,destination and weight");
for(int i=0;i<g->E;i++)
{
 scanf("%d",&g->edge[i].u);
  scanf("%d",&g->edge[i].v);
 scanf("%d",&g->edge[i].w);
       }

   bellman(g,0);
return 0;}

void bellman(struct graph *g,int source)// Implements bellmanford algorithm
{int i,j,u,v,w;
 int totalV=g->V;
 int totalE=g->E;

 int d[totalV];

 for(i=0;i<totalV;i++)
{
 d[i]=INT_MAX;
 }
d[source]=0;
for(i=0;i<totalV-1;i++)
{
 for(j=0;j<totalE;j++)
{
 u=g->edge[j].u;
 v=g->edge[j].v;
 w=g->edge[j].w;
 
if(d[u]!=INT_MAX && d[u]+w<d[v])
{
 d[v]=d[u]+w;
}
}
}
for(j=0;j<totalE;j++)
{
 u=g->edge[j].u;
 v=g->edge[j].v;
 w=g->edge[j].w;
 
if(d[u]!=INT_MAX && d[u]+w<d[v]){
printf("Negative weight cycle");
return;
}
}

printf("shortest distance from single source\n");
display(d,totalV);
}
void display(int arr[],int t)
{
 for(int i =0;i<t;i++)
{
 printf("%d ",arr[i]);
}}


