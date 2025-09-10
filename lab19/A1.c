#include <stdio.h>
#include <stdlib.h>
#define max 100
// Write a program to create a graph & implement the adjacency list
// representation of the graph  Apply DFS and BFS on the given graph.

struct Node
{
    int vertex;
    struct Node *link;
};
struct Graph
{
    int numvertices;
    struct Node **adjlists;
    int *visited;
};

struct Node *CreateNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->link = NULL;
    return newNode;
}

struct Graph *CreateGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numvertex = vertices;
    graph->adjlists = (struct Node *)malloc(sizeof(struct Node));
    graph->visited = (int *)malloc(sizeof(int));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
void addEdge(struct Graph*graph,int src,int dest){
    struct Node* newnode = createNode(dest);
    newnode->link=graph->adjLists[src];
    graph->adjLists[src]=newnode;

    newnode=createNode(src);
    newnode->link=graph->adjLists[dest];
    graph->adjLists[dest]=newnode;
}
void DFS(struct Graph* graph,int vertex){
    struct Node* adjlists = graph->adjlists[vertex];
    struct Node* temp=adjlists;

    graph->visited[vertex]=1;
    printf("%d",vertex);

    while(temp!=NULL){
        int connected= temp->vertex;
        if(graph->visited[connected]==0){
            DFS(graph,connected);
        }
        temp= temp->link;
    }

}
void BFS(struct Graph* graph ,int start){
    int queue[max],front=0,rear=0;

    for(int i=0;i<graph->numvertices;i++){
        graph->visited[i]=0;
    }
    graph->visited[start]=1;
    queue[rear++]=start;

    while(front<rear){
        int current=queue[front++];
        printf("%d ",current);

        struct Node* temp=graph->adjLists[current];

        while(temp!=NULL){
            int adjVertex=temp->vertex;
            if(graph->visited[adjVertex]==0){
                graph->visited[adjVertex]=1;
                queue[rear++]=adjVertex;
            }
            temp=temp->link;
        }
    }
}

void main()
{
    
}
