#include <stdio.h>
#include <stdlib.h>
typedef struct {
      char name[30];
      int age;
      char gender;//M male, F female
}assistent;
void asignacion(int);
void counterf(int);
void counterm(int);
int n=0;
assistent *asistentes=NULL;
assistent *female=NULL;
assistent *male=NULL;
int main(){
	int i=0,j=0;
	do{
		printf("How many assistants do you want to register: ");scanf("%i",&n);fflush(stdin);
		asistentes=(assistent *)malloc(n*sizeof(assistent));
		male=(assistent *)malloc(n*sizeof(assistent));
		female=(assistent *)malloc(n*sizeof(assistent));
	}while(n<0);
	
	for(i=0;i<n;i++){
		printf("Name: ");scanf("%s",asistentes[i].name);fflush(stdin);
		printf("Age: ");scanf("%i",&asistentes[i].age);fflush(stdin);
		printf("Gender (M/F)");scanf("%c",&asistentes[i].gender);fflush(stdin);
		printf("\n");
	}
	asignacion(i);
	counterf(i);
	counterm(i);
	printf("\ntotal of asistants registered : %i",i);
	free(asistentes);
	free(male);
	free(female);
	return 0; 	
}
void asignacion(int i){
	for(i=0;i<n;i++){
			if(asistentes[i].gender=='F'||asistentes[i].gender=='f'){
				female[i]=asistentes[i];
				printf("\nName: %s",female[i].name);
				printf("\nAge: %i",female[i].age);
				printf("\nGender: Female");
				printf("\n");
			}else if(asistentes[i].gender=='M'||asistentes[i].gender=='m'){
				male[i]=asistentes[i];
				printf("\nName: %s",male[i].name);
				printf("\nAge: %i",male[i].age);
				printf("\nGender: Male");
				printf("\n");	
			}
	}	
}
void counterf(int i){
	int j=0;
	for(i=0;i<n;i++){
		if(asistentes[i].gender=='F'||asistentes[i].gender=='f'){ 
			female[i]=asistentes[i];
			j+=female[i].gender;
			printf("\nTotal of females resgistered : %i",j);
		}
		female[i].gender++;
	}
}
void counterm(int i){
	int k=0;
	for(i=0;i<n;i++){
		if(asistentes[i].gender=='M'||asistentes[i].gender=='m'){
			male[i]=asistentes[i];
			k+=male[i].gender;
			printf("\nTotal of males registered: %i",k);
		}
		male[i].gender++;
	}
}
