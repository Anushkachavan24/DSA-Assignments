#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

typedef struct student{
    int MIS;
    char Name[40];
    char Stream[40];
    float CGPA; 
}student;

void deleterecordByMIS(char *, int );

void insertFile(char *, student );

void SearchByMIS(char *, int );

void SearchByName(char *, char *);

void SearchByCGPA(char *, float );

void SearchByStream(char *,char *);

void Display(char *);

void CountByStream(char *);


#endif //FILE_H_INCLUDED
