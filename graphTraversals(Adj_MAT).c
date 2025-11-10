#include<stdio.h>
#include<stdlib.h>


typedef struct queueNode{
    int data;
    struct queueNode* next;
}queueNode;

queueNode* front = NULL, *rear = NULL;

queueNode* createQueueNode(int data){
    queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(){
    return front == NULL;
}

void enqueue(int data){
    queueNode* newNode = createQueueNode(data);
    if(newNode==NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    if(isEmpty()){
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int dequeue(){
    if(isEmpty()){
        printf("Queue is empty.\n");
        return -1;
    }
    queueNode* t = front;
    int returnvalue = front->data;
    front = front->next;
    free(t);
    return returnvalue;
}

void bfs(int adjMat[][100], int vertices,int start){
    int visited[100] = {0};
    visited[start] = 1;
    enqueue(start);
    while(!isEmpty()){
        int node = dequeue();
        printf("%d ",node);
        for(int j=0; j<vertices; j++){
            if(adjMat[node][j]!=0&&visited[j]==0){
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
    printf("\n");
}


int visited[100] = {0};
void dfs(int adjMat[][100], int vertices, int start){
    visited[start] = 1;
    printf("%d ",start);
    for(int j=0; j<vertices; j++){
        if(adjMat[start][j]!=0&&visited[j]==0){
            dfs(adjMat,vertices,j);
        }
    }
}

int main(){
    int vertices,edges,u,v,weight;

    //undirected:
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d",&vertices,&edges);
    int adjMat[100][100];
    //initializing adjmat to 0;
    for(int i=0; i<vertices; i++){
        for(int j =0; j<vertices; j++){
            adjMat[i][j] = 0;
        }
    }
    for(int i=0; i<edges; i++){
        printf("Enter value of u and v for Edge U->V and its weight: ");
        scanf("%d %d %d",&u,&v,&weight);
        adjMat[u][v] = weight;
        adjMat[v][u] = weight;
    }
    bfs(adjMat,vertices,0);
    dfs(adjMat,vertices,0);
}