#include<stdio.h>
#include<stdlib.h>
struct edge
{
int vertex;
int edge;
int weight;
};
struct graph
{ // This structure create a graph
int V;
int E;
struct Edge *edge;
};
int main()
{
 struct graph *g = (struct graph*)malloc(sizeof(struct graph));
int n,e;
printf("enter the number of vertices");
scanf("%d",&g->V);
printf("enter the number of edges");
scanf("%d",&g->E);
g->edge=(struct edge*)malloc(g->E * sizeof(struct edge));
int i;
printf("Enter the source,destination and weight");
for(int i=0;i<g->E;i++)
{
 scanf("%d",&g->edge[i].vertex);
  scanf("%d",&g->edge[i].edge);
 scanf("%d",&g->edge[i].weight);
 }

kruskals(g,n,e);
return 0;
}

int findparent(int v,int *parent)
{
if(parent[v]==v)
{
return v;
}
return findparent(parent[v],parent);   
}
void sort(struct graph *g,struct graph *g1)
{
struct graph *temp;
if(g->edge.weight<g1->edge.weight)
{
temp=g;
g=g1;
g1=temp;
}
}
void kruskals(struct graph *g,int n, int e)
{
sort(graph *g,graph *g+e);
struct graph *output[n-1];
int *parent[n];
for(int i=0;i<n;i++)
{
parent[i]=i;
}
int count=0;
int i=0;
while(count!=n-1)
{
struct graph *currentedge=inp[i];
//check if we can add the current edge in mst or not
int sourceparent=findparent(currentedge->V,parent);
int destparent=findparent(currentedge->E,parent);
if(sourceparent!=destparent)
{
output[count]=currentedge;
count++;
parent[sourceparent]=destparent;
}
i++;
}
for(int i=0;i<n-1;i++)
{
if(output[i]->V<output[i]->E)
{
printf("%d  %d  %d/n",output->edge[i].vertex,output->edge[i].edge,output->edge[i].weight);
else
{
printf("%d  %d  %d/n",output[i]->edge,output[i]->vertex,output[i]->weight);
}
}
}


