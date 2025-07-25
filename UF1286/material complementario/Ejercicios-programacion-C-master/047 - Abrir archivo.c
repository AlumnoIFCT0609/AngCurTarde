#include <stdio.h>

int main() {
    FILE *archivo = fopen("archivo.txt", "rt");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
    } else {
        // Aquí podrías leer el contenido si lo deseas
		printf("apertura correcta\n ");
        fclose(archivo);
    }

    printf("Pulsa una tecla para finalizar...");
    getchar();  // más portable que getch()
    return 0;
}
