// Paso de par�metros por valor

// Librer�a
#include <stdio.h>
#include <conio.h>
// Otra funci�n
void funcion(int x);

// Funci�n principal
int main() {
	int x;
	
	//Solicitamos valor para pasarlo a otra funci�n
	printf("Introduce un valor: ");
	fflush(stdin);
	scanf("%d",&x);
	printf("\n");
	
	// Llamamos a la funci�n siguiente
	funcion(x);
	
	// Cierre
	printf("Pulsa una tecla para terminar...");
	fflush(stdin);
	getch();
	return 0;
}
// Pasamos por par�metro el valor solicitado
void funcion(int x) {
	printf("El valor introducido es %d.\n\n",x);
}
