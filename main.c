#include <stdio.h>
#include <stdlib.h>


 typedef struct{
   char lastname[25];
   int assignment, exam, finalgrade;
   int *quizzes;
 }student;


student *readData(FILE *in, int *noOFRecords, int *noofquiz){
 
  int s,q;

  fscanf(in, "%d %d", noOFRecords, noofquiz);
  student *students=(student*)malloc(*noOFRecords*sizeof(student));
  for(s=0;s<*noOFRecords;s++){

    students[s].quizzes=(int*)malloc(*noofquiz*sizeof(int));
    students[s].finalgrade=0;

  }

  fscanf(in, "%s, %d", students[s].lastname, &students[s].assignment);
  for(q=0;q<*noofquiz;++q){
    fscanf(in,"%d", &students[s].quizzes[q]);
    students[s].finalgrade += students[s].quizzes[q];
  }
  fscanf(in,"%d",&students[s].exam);
  students[s].finalgrade+=students[s].assignment+students[s].exam;
 
 return students;

 }




int main(void) {

  student *students;
  FILE *inFile, *outFile;
  int s, j, numstudents, numquizzes;

  inFile=fopen("input.txt","r");
  if(inFile!=NULL){
    printf("Reading data from input.txt\n");
    students=readData(inFile, &numstudents, &numquizzes);
  }
  else{
    printf("Please provide correct input file\n");
    exit(-1);
  }

  printf("Reading complete. Showing the summary.\n");
  printf("(lastname, finalgrade)\n");
  for(s=0;s<numstudents;s++){
    printf("(%s,%d)\n", (students+s)->lastname, students[s].finalgrade);
  }
    fclose(inFile);

  printf("\nStudent with the hightest finalgrade score\n");
  int max_finalgrade=0;
  int max_finalgrade_index=0;
  for(s=0;s<numstudents;s++){
    if(students[s].finalgrade>max_finalgrade){
      max_finalgrade=students[s].finalgrade;
      max_finalgrade_index=s;
    }

  }
  printf("(%s %d)",students[max_finalgrade_index].lastname, students[max_finalgrade_index].finalgrade);

  outFile=fopen("output.txt","w");
  fprintf(outFile,"(%s %d)\n",students[max_finalgrade_index].lastname, students[max_finalgrade_index].finalgrade);
  printf("Output.txt generated.\n");
  fclose(outFile);


  for(s=0;s<numstudents;s++)
    free(students[s].quizzes);
  free(students);
  return 0;
}

