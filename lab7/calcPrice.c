#include <stdio.h>

int main(void)
{
 float price;
 int num, qty;
 char dat[10];
 printf("Enter item number:");
 scanf("%d", &num);
 printf("Enter unit price:");
 scanf("%f", &price);
 printf("Enter quantity:");
 scanf("%d", &qty);
 printf("Enter purchase date (mm/dd/yyyy) :");
 scanf("%s", &dat);
 printf("Item\tUnit\tPrice\tQTY\tPurchase Date\tTotal Amount\n");
 printf("%d\t$\t%.2f\t%d\t%s\t$%.2f\n", num, price, qty, dat, price*qty);
 return 0;
}
