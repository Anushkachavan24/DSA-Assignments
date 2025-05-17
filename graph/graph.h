#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "stack.h"
#include "Queue.h"


typedef struct graph{
     int v;
     struct node **A;
}graph;

typedef struct edge{
     int start, dest, weight;
}edge;

edge *prims(graph , int );

void dijktra(graph, int);

void printedge(graph, edge*);

void init_graph(graph *, char*);

void displaygraph(graph *);

void BFS(graph *, int);

void DFS(graph *, int);

void Outdegree(graph);

void InDegree(graph);

#endif //GRAPH_H_INCLUDED
