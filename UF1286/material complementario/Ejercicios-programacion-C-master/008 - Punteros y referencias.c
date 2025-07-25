// PUNTEROS Y REFERENCIAS

// Librerias
#include <stdio.h>
#include <stdlib.h>

// Funcion principal
int main(void) {
	// Dando valores a variables
	int edad,anio_actual,anio_nacimiento;
	int *tata;
	// Solicitamos edad
	printf("Edad? ");
	fflush(stdin);
	tata= &edad;
	scanf("%i",&edad);
	printf("el valor de tata es: %d \n", *tata);
	// Solicitamos a�o actual
	printf("A%co actual? ",164);
	fflush(stdin);
	scanf("%i",&anio_actual);
	
	// Solicitamos año nacimiento
	printf("A%co nacimiento? ",164);
	fflush(stdin);
	scanf("%i",&anio_nacimiento);
	
	if ((anio_actual-anio_nacimiento)==edad) {

		printf("Edad %i, a%co actual %i, y a%co de nacimiento %i.\n",edad,164,anio_actual,164,anio_nacimiento);
	} else {

		printf("no tienes %i, a%cos ni de co%ca ", edad,164, 164 );
	}
	// Imprimiendo en pantalla los resultados
	
	
	getchar();
	
	return 0;
}
