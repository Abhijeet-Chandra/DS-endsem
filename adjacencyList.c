#include<stdio.h>
#include<stdlib.h>


typedef struct graphNode{
    int vertex;
    int weight;
    struct graphNode* next;
}graphNode;


graphNode* createGraphNode(int vertex, int weight){
    graphNode* newNode = (graphNode*)malloc(sizeof(graphNode));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

int numVertex, isDirected;

void readGraph(graphNode* head[]){
    graphNode* newNode;
    int vertex, neighbour, k, weight;
    for(int i=0; i<numVertex; i++){
        graphNode* tail = NULL;
        printf("Enter vertex: \n");
        scanf("%d",&vertex);
        if(head[vertex]==NULL){
            head[vertex] = createGraphNode(vertex,-1);
        }
        tail = head[vertex];
        while(tail->next!=NULL){
            tail = tail->next;
        }
        printf("Enter number of neighbours of vertex %d: ", vertex);
        scanf("%d",&k);
        for(int j = 0; j<k; j++){
            printf("Enter vertex number: ");
            scanf("%d",&neighbour);
            printf("Enter weight: ");
            scanf("%d",&weight);
            newNode = createGraphNode(neighbour,weight);
            tail->next = newNode;
            tail = newNode;
            if(!isDirected){
                graphNode* revNode = createGraphNode(vertex,weight);
                if(head[neighbour]==NULL){
                    head[neighbour] = createGraphNode(neighbour,-1);
                    head[neighbour]->next = revNode;
                }
                else{
                    revNode->next = head[neighbour]->next;
                    head[neighbour]->next = revNode;
                }
            }
        }
    }

}

void printGraph(graphNode* head[]){
    for(int i=0; i<numVertex; i++){
        graphNode* temp = head[i];
        while(temp!=NULL){
            if(temp==head[i]){
                printf("Vertex %d->",temp->vertex);
            }
            else{
                printf("{%d,%d}, ",temp->vertex,temp->weight);
            }
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    printf("Enter the number of vertices and enter 1 if graph is directed else enter 0: ");
    scanf("%d %d",&numVertex,&isDirected);
    graphNode* head[numVertex];
    for(int i=0; i<numVertex; i++){
        head[i]=NULL;
    }
    readGraph(head);
    printGraph(head);
}