#include <stdio.h>

int main(int argc, char *argv[]) {
	long inta[10];

	long *punt[10];
	
	for(int i=0; i<(sizeof(inta) / sizeof(inta[0]));i++)
	{
		inta[i]= (i*5)+3;
		punt[i]=&inta[i];
		printf(" %i ----> %i \n", i,*punt[i]);
		
	}
	printf("%i   ", sizeof(inta)); 
	
	//printf("%i \n", *punt[0]); //puntero para mostrar el dato
	//printf("%i \n", punt[0]); //puntero para mostrar la direccion del dato
	//printf("%i \n", punt[1]); //puntero para mostrar la direccion del dato
	//printf("%i \n", punt[2]); //puntero para mostrar la direccion del dato
	//printf("%i \n", &punt[0]); //puntero para mostrar la direccion del puntero
	return 0;
}

