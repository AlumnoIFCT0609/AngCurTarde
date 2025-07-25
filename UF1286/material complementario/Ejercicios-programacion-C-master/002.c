#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i = 0, j = 4, h = 2;
    char a[] = "abcde";
    float f = 3.56;

    // Imprimir float, enteros y un carácter específico de la cadena
    printf("%f, %d, %d, %c\n", f, i, h, a[3]);

    return 0;
}