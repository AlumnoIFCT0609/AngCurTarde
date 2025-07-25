// Funci�n que devuelve un valor

// Librer�a
#include <stdio.h>
#include <conio.h>
// Funciones secundarias
int suma(int n1, int n2);

// Funci�n principal
int main() {
	// Variables
	int n1,n2,res;
	
	// Pedir n�meros
	printf("Introduce un n%cmero: ",163);
	fflush(stdin);
	scanf("%d",&n1);
	
	printf("Ahora introduce otro n%cmero: ",163);
	fflush(stdin);
	scanf("%d",&n2);
	printf("\n");
	
	res = suma(n1,n2);
	
	// Mostrar resultado
	printf("El resultado de la suma de %d + %d es %d.\n\n",n1,n2,res);
	
	// Cierre
	printf("Pulsa una tecla para terminar...");
	fflush(stdin);
	getch();
	return 0;
}
// Funciones secundarias
int suma(int n1, int n2) {
	int resultado = n1 + n2;
	
	return resultado;
}
