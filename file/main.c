#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "file.h"

int main(){
    student S1;
    int N, remove, choice;
    float c;
    char name[40] = {'\0'};
    char stream[40] = {'\0'};
    while(1)
	{
		printf("1. Insert Record\n");
		printf("2. Search the record by MIS\n");
		printf("3. Search the record by Name\n");
		printf("4. Search the record by Stream\n");
		printf("5. Search the record by CGPA\n");
		printf("6. Delete Record\n");
		printf("7. Display all record\n");
		printf("8. Display count of student from each stream\n");
		printf("9. Exit\n");

		printf("\n");
		printf("Enter your choice : ");

		scanf("%d",&choice);
		switch(choice)
		{
		      case 1:
		          printf("MIS No:");
                          scanf("%d", &S1.MIS);
                          printf("Name:");
                          scanf("%s", S1.Name);
                          while(getchar()!='\n');
                          printf("Stream:");
                          scanf("%s", S1.Stream);
                          while(getchar()!='\n');
                          printf("CGPA:");
                          scanf("%f", &S1.CGPA);
                          insertFile("Student_Record.dat", S1);
                          printf("\n");
			  break;
		      case 2:
                          printf("Enter the MIS No:");
                          scanf("%d", &N);
                          SearchByMIS("Student_Record.dat", N);
		          printf("\n");
		          break;
	              case 3:
	                  printf("Enter the name:");
	                  scanf("%s", name);
	                  while(getchar()!='\n');
	                  SearchByName("Student_Record.dat", name);
	                  printf("\n");
	                  break;
	              case 4:
	                  printf("Enter the stream:");
	                  scanf("%s", stream);
	                  while(getchar()!='\n');
	                  SearchByStream("Student_Record.dat", stream);
	                  printf("\n");
	                  break;
	              case 5:
	                  printf("Enter the CGPA:");
                          scanf("%f", &c);
                          SearchByCGPA("Student_Record.dat", c);
		          printf("\n");
		          break;
	              case 6:
			  printf("Enter the MIS No:");
			  scanf("%d", &remove);
			  deleterecordByMIS("Student_Record.dat", remove);
			  printf("\n");
			  break;
		      case 7:
		          Display("Student_Record.dat");
		          printf("\n");
		          break;
		      case 8:
			  CountByStream("Student_Record.dat");
                          printf("\n");
			  break;
                      case 9:
                          exit(1);
                          break;
		      default:
			  printf("Wrong choice\n");
		}
	}
    return 0;
}
