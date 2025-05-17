#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "file.h"

void Display(char *fname){
     FILE *fp;
     student s;
     fp = fopen(fname, "r");
     if (!fp)
        return;
     while(fread(&s, sizeof(s), 1, fp))
         printf("MIS = %d\nName = %s\nStream = %s\nCGPA = %f\n\n", s.MIS, s.Name, s.Stream, s.CGPA);
     fclose(fp);
     return;
}

void insertFile(char *fname, student S){
     FILE *fp;
     fp = fopen(fname, "a");
     if (!fp)
        return;
     fwrite(&S, sizeof(S), 1, fp);
     printf("Record has been added successfully\n");
     fclose(fp);
     return;
}

void SearchByMIS(char *fname, int n){
     FILE *fp;
     student s;
     int found;
     fp = fopen(fname, "r");
     if (!fp)
        return;
     while(fread(&s, sizeof(s), 1, fp)){
          if(n == s.MIS){
               found = 1;
               printf("Found\n");
               printf("MIS No: %d\n", s.MIS);
               printf("MIS No: %s\n", s.Name);
               printf("MIS No: %s\n", s.Stream);
               printf("MIS No: %f\n", s.CGPA);
          }
     }
     if(found != 1){
         printf("No such record\n");
     }
     return;
}

void SearchByName(char *fname, char *str){
     FILE *fp;
     student s;
     int found;
     fp = fopen(fname, "r");
     if (!fp)
        return;
     while(fread(&s, sizeof(s), 1, fp)){
          if(strcmp(str, s.Name) == 0){
               found = 1;
               printf("Found\n");
               printf("MIS No: %d\n", s.MIS);
               printf("MIS No: %s\n", s.Name);
               printf("MIS No: %s\n", s.Stream);
               printf("MIS No: %f\n", s.CGPA);
          }
     }
     if(found != 1){
         printf("No such record\n");
     }
     return;
}

void SearchByCGPA(char *fname, float n){
     FILE *fp;
     student s;
     int found;
     fp = fopen(fname, "r");
     if (!fp)
        return;
     while(fread(&s, sizeof(s), 1, fp)){
          if(n == s.CGPA){
               found = 1;
               printf("Found\n");
               printf("MIS No: %d\n", s.MIS);
               printf("MIS No: %s\n", s.Name);
               printf("MIS No: %s\n", s.Stream);
               printf("MIS No: %f\n", s.CGPA);
          }
     }
     if(found != 1){
         printf("No such record\n");
     }
     return;
}

void SearchByStream(char *fname,char *str){
     FILE *fp;
     student s;
     int found;
     fp = fopen(fname, "r");
     while(fread(&s, sizeof(s), 1, fp)){
          if(strcmp(str, s.Stream) == 0){
               found = 1;
               printf("Found\n");
               printf("MIS No: %d\n", s.MIS);
               printf("MIS No: %s\n", s.Name);
               printf("MIS No: %s\n", s.Stream);
               printf("MIS No: %f\n", s.CGPA);
          }
     }
     if(found != 1){
         printf("No such record\n");
     }
     return;
}


void deleterecordByMIS(char *fname, int n){
    FILE *fp, *fp_temp;
    student s;
    int found;
    fp = fopen(fname, "r");
    if(!fp){
        printf("Unable to open student record file\n");
    }
    fp_temp = fopen("file_Temp.dat", "w");
    if(!fp_temp){
        printf("Unable to open the file_Temp file\n");
    }
    while(fread(&s, sizeof(s), 1, fp)){
        if(s.MIS == n){
            printf("Record deleted successfully\n");
            found = 1;
        }
        else{
            fwrite(&s, sizeof(s), 1, fp_temp);
        }
    }
    if(found != 1){
        printf("No such record exist\n");
    }
    fclose(fp);
    fclose(fp_temp);
    remove(fname);
    rename("file_Temp.dat", fname);
    return;
}


void CountByStream(char *fname){
    FILE *fp;
    int compC = 0; 
    int instruC = 0;
    int mechC = 0;
    int eleC = 0; 
    int entcC = 0;
    int prodC = 0;
    int metaC = 0;
    student s;
    fp = fopen(fname, "r");
    if (!fp)
        return;
    while(fread(&s, sizeof(s), 1, fp)){
        if (feof(fp))
            break;
        if(strcmp(s.Stream, "Computer") == 0)
            compC++;
        else if(strcmp(s.Stream, "Instrumentation") == 0)
            instruC++;
        else if(strcmp(s.Stream, "Mechanical") == 0)
            mechC++;
        else if(strcmp(s.Stream, "Electrical") == 0)
            eleC++;
        else if(strcmp(s.Stream, "ENTC") == 0)
            entcC++;
        else if(strcmp(s.Stream, "Production") == 0)
            prodC++;
        else if(strcmp(s.Stream, "Metallurgy") == 0)
            metaC++;
    }
    printf("Students of Computer:%d\n", compC);
    printf("Students of Instrumentation:%d\n", instruC);
    printf("Students of Mechanical:%d\n", mechC);
    printf("Students of Electrical:%d\n", eleC);
    printf("Students of Electronics:%d\n", entcC);
    printf("Students of Production:%d\n", prodC);
    printf("Students of Metallurgy:%d\n", metaC);
    
    return;
}
