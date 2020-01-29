#include <stdio.h>
#include <stdlib.h>
struct ListNode{
  int endNode;
  int weight;
  struct ListNode* next;
};
struct List{
  struct ListNode* head;
};
struct Graph{
  int v;
  struct List* A; 
};

int minVertex(struct Graph* g, int visited[], int mdist[]){       //This function will always return the Minimum Vertex everytime it is been called.
  int mvertex = -1;
  for(int i=0;i<g->v;i++){
    if(!visited[i] && (mvertex==-1 || mdist[i]<mdist[mvertex])){
      mvertex = i;
    }
  }
  return mvertex;
}

void dijkastra(struct Graph* g, int visited[], int mdist[]){      //This function will perform Dijkastra Algorithm
  int smallest = 99999, MinIndex;
  mdist[0] = 0;
  for(int i=0;i < g->v - 1;i++){
     int minvertex = minVertex(g, visited, mdist);
     visited[minvertex] = 1;
     struct ListNode* temp = g->A[minvertex].head;
     while(temp){
       if(!visited[temp->endNode]){
         int d = mdist[minvertex] + temp->weight;
         if(d< mdist[temp->endNode])
           mdist[temp->endNode] = d;
       }
       temp = temp->next;         
     }
  }
}

struct Graph* createGraph(int ver){                            //This function will create and return a graph of vertex v
  struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
  g->v = ver;
  g->A = (struct List*)malloc(ver*sizeof(struct List));
  
  return g;
}

void addEdge(struct Graph* g, int start, int end, int wei){    //This function will add an undirected edge 
  struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode)); 
  t->endNode = end;
  t->weight = wei;
  t->next = g->A[start].head;
  g->A[start].head = t;

  struct ListNode* t2 = (struct ListNode*)malloc(sizeof(struct ListNode)); 
  t2->endNode = start;
  t2->weight = wei;
  t2->next = g->A[end].head;
  g->A[end].head = t2;
}

void printGraph(struct Graph* g){
  for(int i=0;i<g->v;i++){
        struct ListNode* temp = g->A[i].head;
	while(temp){
	  printf("%d weight = %d ",temp->endNode,temp->weight);
	  temp = temp->next;
        }
	printf("\n");
  }
}

int printDijkastra(struct Graph* g, int mdist[]){
  printf("Vertex   Distance\n");
  for(int i=0;i<g->v;i++){
    printf("%d\t  %d\n", i, mdist[i]);
  }
}

int main(){
  int v;
  printf("Enter no of vertices");
  scanf("%d",&v);
  int mdist[v], visited[v];
  for(int i=0;i<v;i++){
    mdist[i] = 99999;
    visited[i] = 0;
  }
  struct Graph* graph = createGraph(v);
  struct Graph* g2 = graph;
  addEdge(graph, 0, 1, 3);
  addEdge(graph, 0, 2, 1);
  addEdge(graph, 1, 2, 7);
  addEdge(graph, 1, 4, 1);
  addEdge(graph, 1, 3, 5);
  addEdge(graph, 2, 3, 2);
  addEdge(graph, 3, 4, 7);
  dijkastra(graph, visited, mdist);
  printGraph(graph);
  printf("\n\n");
  printDijkastra(graph, mdist);

}

