// Cerrar archivo

// Librer�a
#include <stdio.h>
#include <conio.h>
// Funci�n principal
int main() {
	// Archivo *variable
	FILE *archivo;
	// Variable = abrir archivo
	archivo = fopen("archivo.txt","rt");
	// Comprobar si se abre
	if(archivo == NULL) {
		printf("No se ha podido abrir el archivo.\n\n");
	}
	
	// Cerrar archivo
	fclose(archivo);
	
	// Cierre
	printf("Cerramos el archivo Pulsa una tecla para finalizar...");
	fflush(stdin);
	getch();
	return 0;
}
