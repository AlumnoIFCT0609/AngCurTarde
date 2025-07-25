// Paso de par�metro por referencia

// Librer�a
#include <stdio.h>
#include <conio.h>
// Otras funciones
void cambiar(int *num);

// Funci�n principal
int main() {
	// Variables
	int x, *h;
	h=&x;
	// Pedir valor para x
	printf("Introduce un valor para la variable x: ");
	fflush(stdin);
	scanf("%d",h);
	printf("\n");
	
	// Mostrar valor de x
	printf("Has introducido el valor %d.\n\n",*h);
	
	// Llamada a funci�n cambiar
	cambiar(h);
	
	// Volver a mostrar valor de x + 1
	printf("Ahora x tiene como valor %d.\n\n",x);
	
	// Cierre
	printf("Pulse una tecla para terminar...");
	fflush(stdin);
	getch();
	return 0;
}
void cambiar(int *num) {
	// Sumamos 1 a x
	*num = *num + 1;
}
