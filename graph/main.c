#include<stdio.h>
#include<stdlib.h>
#include "graph.h"
#include "stack.h"
#include "Queue.h"

int main(int argc, char *argv[]){
   graph G1;
   init_graph(&G1,argv[1]);
   printgraph(&G1);
   displaygraph(&G1);
   BSF(&G1, 0);
   printf("\n");
   DSF(&G1, 0);
   printf("\n%d\n", checkSymmetric(G1));
   Outdegree(G1);
   Indegree(G1);
   return 0;
}
