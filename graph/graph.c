#include<stdio.h>
#include<stdlib.h>
#include "limits.h"
#include "graph.h"

typedef struct node{
     int vertex;
     int value;
     struct node *next;
}node;

int checkSymmetric(graph);

int minvalue(int A[], int, int v[]);

void printarray(int Array[], int n);




void init_graph(graph *g, char *ptr){
      int x, n;
      FILE *fp;
      int i, j;
      fp = fopen(ptr, "r");
      if(fp == NULL){
          printf("Unable to open the file");
          return;
      }
      fscanf(fp, "%d", &x);
      g->v = x;
      g->A = (node**)malloc(sizeof(node*)*g->v);
      for(i = 0; i<x; i++){
          g->A[i] = NULL;
          for(j = 0;j<x; j++){
               node *p = (node *)malloc(sizeof(node));
               fscanf(fp, "%d", &n);
               if(n != 0){
                   p->value = n;
                   p->vertex = j;
                   if(g->A[i] == NULL){
                      p->next = NULL;
                   }
                   else{
                      p->next = g->A[i];
                      
                   }
                   g->A[i] = p;
               }
          }
      }
      return;
 
}


void displaygraph(graph *g){
    int i, j, k;
    node *p;
    for(i = 0;i<g->v;i++){
        p = g->A[i];
        for(j = 0; j<g->v;j++){
            while(p != NULL){
               if(p->vertex == j){
                   k = 1;
                   printf("%d ", p->value);
               }
               p = p->next;
            }
            if(k != 1)
               printf("0 ");
            k = 0;
            p = g->A[i];
            
        }
        printf("\n");
    }
    return;
}


void BFS(graph *g, int d){
    queue Q1;
    int v;
    node *p;
    int *visited = calloc(g->v, sizeof(int));
    initQueue(&Q1, g->v);
    enque(&Q1, d);
    visited[d] = 1;
    printf("%d ", d);
    while(!isEmptyQue(Q1)){
         v = deque(&Q1);
         p = g->A[v];
         while(p != NULL){
             if(visited[p->vertex] != 1){
                  printf("%d ", p->vertex);
                  enque(&Q1, p->vertex);
                  visited[p->vertex] = 1;
                 // break;
             }
             p = p->next;
         }
    }
    return;
    
}



void DFS(graph *g, int d){
     stack S1;
     int v;
     node *p;
     int *visited = calloc(g->v, sizeof(int));
     init_stack(&S1, g->v);
     push(&S1, d);
     visited[d] = 1;
     printf("%d ", d);
     while(!isEmpty_stack(S1)){
         v = pop(&S1);
         p = g->A[v];
         while(p != NULL){
             if(visited[p->vertex] != 1){
                  push(&S1, p->vertex);
                  printf("%d ", p->vertex);
                  visited[p->vertex] = 1;
             }
             p = p->next;
         }
     }
     return;
}


int checkSymmetric(graph g){
    int v, S;
    node *p, *q;
    for(int i = 0;i<g.v;i++){
        p = g.A[i];
        while(p != NULL){
            int n = p->vertex;
            q = g.A[n];
            while(q != NULL){
                if(q->vertex == i){
                     S = 1;
                }
                q = q->next;
            }
            if(S != 1)
               return 0;
            S = 0;
            p = p->next;
        }
    }
    return 1;
}


void Outdegree(graph g){
    node *p;
    int count;
    if(checkSymmetric(g)){
        printf("Graph is undirected\n");
    }
    else
       printf("Graph is directed\n");
    for(int i = 0;i<g.v;i++){
        count = 0;
        p = g.A[i];
        while(p != NULL){
            count++;
            p = p->next;
        }
        printf("Outdegree of %d: %d\n",i,count);   
    }
    return; 
}




void InDegree(graph g){
    node *p, *q;
    int c = 0;
    int *indeg = calloc(g.v, sizeof(int));
    if(checkSymmetric(g)){
        printf("Graph is undirected\n");
    }
    else
        printf("Graph is directed\n");
    for(int i = 0;i<g.v;i++){
        p = g.A[i];
        for(int j = 0;j<g.v;j++){
            while(p != NULL){
               indeg[p->vertex]++;
               p = p->next;
            }
        }
    }
    for(c = 0;c<g.v;c++){
        printf("Indegree of %d: %d\n", c, indeg[c]);
    }
    
    return;
}


edge *prims(graph g, int s){
    int *visited = (int *)calloc(sizeof(int),g.v);
    edge *edges = (edge *)malloc(sizeof(edge)*g.v-1);
    int n, m;
    if(!edges){
        printf("\nNULL");
        return NULL;
    }
    edge minedge;
    int minweight = INT_MAX, j;
    visited[s] = 1;
    node *p;
    for(int i = 0; i<g.v-1; i++){
        minweight = INT_MAX;
        for(j = 0; j<g.v;j++){
            if(visited[j] == 1){
                p = g.A[j];
                while(p != NULL){
                    if(p->value < minweight && !visited[p->vertex]){
                         minweight = p->value;
                         m = j;
                         n = p->vertex;
                    }
                    p = p->next;
                }
            }
       }
       visited[n] = 1;
       minedge.start = m;
       minedge.dest = n;
       minedge.weight = minweight;
       edges[i] = minedge; 
    }
   
    return edges;
}

void printedge(graph g, edge *edges){
    for(int i = 0; i<g.v-1; i++){
        printf("(%d, %d, %d), ",edges[i].start,edges[i].dest,edges[i].weight);
    }
    return;
}

int minvalue(int A[], int n, int v[]){
    int min = INT_MAX, c;
    for(int i = 0; i<n;i++){
        if(A[i] < min && !v[i]){
           min = A[i];
           c = i;
        }
    }
    return c;
}

void dijktra(graph g, int d){
    int *visited = (int*)calloc(sizeof(int), g.v);
    int dist[g.v];
    for(int i = 0; i<g.v; i++){
        dist[i] = INT_MAX;
    }
    dist[d] = 0;
    node *p;
    int cost;
    for(int k = 0; k<g.v; k++){
        d = minvalue(dist, g.v, visited);
        p = g.A[d];
        visited[d] = 1;
        while(p != NULL){
            if(!visited[p->vertex]){
                cost = dist[d] + p->value;
                if(cost < dist[p->vertex]){
                    dist[p->vertex] = cost;
                }
            }
            p = p->next;
        }
    }
    printarray(dist, g.v);
    return;
}

void printarray(int Array[], int n){
    printf("Vertex\tDistance\n");
    for(int i = 0; i<n;i++){
        printf("%d\t%d\n", i, Array[i]);
    }
    return;
}




