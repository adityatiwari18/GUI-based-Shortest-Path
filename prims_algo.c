#include<stdio.h>
#include<stdlib.h>
 
#define infinity 9999
#define m 10
 
int graph[m][m],spanning[m][m],n;
int prims();
 
int main()
{
	int i,j,total_weight;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			scanf("%d",&graph[i][j]);
			}
		}
	total_weight=prims();
	printf("\nspanning tree matrix:\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d\t",spanning[i][j]);
	}
	
	printf("\n\nTotal weight of spanning tree= %d\n",total_weight;
	return 0;
}
 
int prims()
{
	int weight[m][m];
	int u,v,min_distance,distance[m],from[m];
	int visited[m],no_of_edges,i,min_weight,j;
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(graph[i][j]==0)
				weight[i][j]=infinity;
			else
				weight[i][j]=graph[i][j];
				spanning[i][j]=0;
		}
	
	distance[0]=0;
	visited[0]=1;
	
	for(i=1;i<n;i++)
	{
		distance[i]=weight[0][i];
		from[i]=0;
		visited[i]=0;
	}
	
	min_weight=0;		//weight of spanning tree
	no_of_edges=n-1;	//no. of edges to be added
	
	while(no_of_edges>0)
	{
		min_distance=infinity;
		for(i=1;i<n;i++)
			if(visited[i]==0&&distance[i]<min_distance)
			{
				v=i;
				min_distance=distance[i];
			}
			
		u=from[v];
		
		//insert the edge in spanning tree
		spanning[u][v]=distance[v];
		spanning[v][u]=distance[v];
		no_of_edges--;
		visited[v]=1;
		
		//updated the distance[] array
		for(i=1;i<n;i++)
			if(visited[i]==0&&weight[i][v]<distance[i])
			{
				distance[i]=weight[i][v];
				from[i]=v;
			}
		
		min_weight=min_weight+weight[u][v];
	}
	
	return(min_weight);
}
 
