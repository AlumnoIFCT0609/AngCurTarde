#include <stdio.h>
int main() 
{
    int num1, num2;
    int *ptr1, *ptr2;

    ptr1 = &num1;
    ptr2 = &num2;

    num1 = 10;
    num2 = 20;

    ptr1 = ptr2;
    ptr2 = NULL;

    return 0;



    
}