#include <stdio.h>
int main (void);
int calculate_bill (int, int, int);
int main()
{
int bill;
int fred = 25;
int frank = 32;
int franny = 27;
bill = calculate_bill (fred, frank, franny);
printf("The total bill comes to $%d.00.\n", bill);
//exit (0);
}
int calculate_bill (int diner1, int diner2, int diner3)
{
int total;
total = diner1 + diner2 + diner3;
return total;
}
