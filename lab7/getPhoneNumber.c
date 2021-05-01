#include <stdio.h>

void printNum(char *x)
{
 char new[12];
 new[0] = x[1];
 new[1] = x[2];
 new[2] = x[3];
 new[3] = '-';
 new[4] = x[5];
 new[5] = x[6];
 new[6] = x[7];
 new[7] = '-';
 new[8] = x[9];
 new[9] = x[10];
 new[10] = x[11];
 new[11] = x[12];
 printf("You entered: %s\n", new);
}

int main(void)
{
 char num[13];
 printf("Enter phone number [(999)999-9999]: ");
 scanf("%s", num);
 printNum(num);
 return 0;
}
