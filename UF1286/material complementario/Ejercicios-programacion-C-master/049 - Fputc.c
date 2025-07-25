// FputC
// Librer�a
#include <stdio.h>
#include <conio.h>
// Funci�n principal
int main() {
	// Archivo *variable
	FILE *archivo;
	// Variable = abrir archivo
	archivo = fopen("C:\Users\integ\Documents\Angel (Curso tarde)\uf1286\material complementario\Ejercicios-programacion-C-master\output\archivo.txt","rt");
	// Comprobar si se abre
	if(archivo == NULL) {
		printf("No se ha podido abrir el archivo.\n\n");
	}
	
	// Insertar car�cter
	fputc('160', archivo);
	
	// Cerrar archivo
	fclose(archivo);
	// Cierre
	printf("Pulsa una tecla para finalizar...");
	fflush(stdin);
	getch();
	return 0;
}
