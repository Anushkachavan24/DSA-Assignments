#include<stdio.h>
#include<stdlib.h>
#include "matrix.h"

void LoadSparse(char *fname, sparse*S){
      FILE *fp;
      //node *p, *q, 
      node *nn;
      node *p = NULL;
      node *q = NULL;
      
      int r, c, n;
      fp = fopen(fname, "r");
      if(!fp){
            printf("Unable to open the file");
            return;
      }
      fscanf(fp, "%d", &r);
      fscanf(fp, "%d", &c);
      initsparse(S, r, c);
      for(int i = 0; i<r;i++){
            for(int j = 0; j<c;j++){
                fscanf(fp, "%d", &n);
                if(n != 0){
                    nn = (node *)malloc(sizeof(node));
                    nn->r = i;
                    nn->c = j;
                    nn->right = NULL;
                    nn->down = NULL;
                    nn->value = n;
                    if( S->row[i]== NULL){
                       S->row[i] = nn;
                    }
                    else{
                       p = S->row[i];
                       p->right = nn;
                       p = p->right;
                    }
                    if(S->column[j] == NULL){
                       S->column[j] = nn;
                    }
                    else{
                       q = S->column[j];
                       while(q->down != NULL){
                          q = q->down;
                       }
                       q->down = nn;
                    }
               }
            }
      }
      return;
}
void initsparse(sparse *S, int i, int j){
      S->nr = i;
      S->nc = j;
      S->row = (node **)malloc(sizeof(node *)*S->nr);
      for(int p = 0; p<S->nr;p++){
           S->row[p] = NULL;
      }
      S->column = (node **)malloc(sizeof(node *)*S->nc);
      for(int q = 0; q<S->nr;q++){
           S->column[q] = NULL;
      }
      return;
}

void display(sparse *s){
      node *q;
      /*for(int i =0; i<s->nr;i++){
          q = s->row[i];
          while(q){
              printf("(%d, %d, %d),\n", q->r, q->c, q->value);
              q = q->right;
          }
          
      }*/
      for(int i =0; i<s->nc;i++){
          q = s->column[i];
          while(q){
              printf("(%d, %d, %d),\n", q->c, q->r, q->value);
              q = q->down;
          }
          
      }
}

//void addition(sparse)


