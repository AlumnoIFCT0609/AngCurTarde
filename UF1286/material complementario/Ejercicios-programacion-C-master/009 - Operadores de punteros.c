// OPERADORES DE PUNTEROS

// Librerias
#include <stdio.h>
#include <stdlib.h>

// Funcion principal
int main(void) {
	// Dando valores a variables
	int lapices, *p_lapices, libros, *p_libros, calculadoras, *p_calculadoras;
	
	// A la variables de los punteros les asignamos la direcci�n de las variables
	p_lapices = &lapices;
	p_libros = &libros;
	p_calculadoras = &calculadoras;
	
	// A los punteros les damos el valor de las variables
	*p_lapices = 2;
	*p_libros = 8;
	*p_calculadoras = 1;
	
	// Valor de lapices
	printf("L%cpices = %i.\n",160,*p_lapices);
	
	// Direccion de libros
	printf("Libros = %i \n",*p_libros);
	
	// Referencia de calculadoras
	
	
	getchar();
	
	return 0;
}
