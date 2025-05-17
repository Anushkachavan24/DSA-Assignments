#include <stdio.h>
#include <stdlib.h>
#define MAX 50


int main() {
   FILE *fp;

   fp = fopen("integer.txt", "w+");
   if(!fp) return 0;
   int i;
   for (i = 0; i <MAX; i++)
   {
       fprintf(fp,"%d ", rand());
   }

   fclose(fp);
   return 0;
}


