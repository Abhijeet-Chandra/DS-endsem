#include<stdio.h>
#include<stdlib.h>

int main(){
    int vertices,edges,u,v,weight;

    //undirected:
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d",&vertices,&edges);
    int adjMat[vertices][vertices];
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


    printf("Undirected:\n");
    for(int i=0; i<vertices; i++){
        for(int j =0; j<vertices; j++){
            printf("%d\t",adjMat[i][j]);
        }
        printf("\n");
    }


    //directed:
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d",&vertices,&edges);
    int adjMat2[vertices][vertices];
    //initializing adjmat to 0;
    for(int i=0; i<vertices; i++){
        for(int j =0; j<vertices; j++){
            adjMat2[i][j] = 0;
        }
    }
    for(int i=0; i<edges; i++){
        printf("Enter value of u and v for Edge U->V and its weight: ");
        scanf("%d %d %d",&u,&v,&weight);
        adjMat2[u][v] = weight;
    }

    printf("Directed:\n");
    for(int i=0; i<vertices; i++){
        for(int j =0; j<vertices; j++){
            printf("%d\t",adjMat2[i][j]);
        }
        printf("\n");
    }
}