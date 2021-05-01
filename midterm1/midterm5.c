#include <stdio.h>
int toDecimal(int x);
int toDecimal(int x)
{
 int y=0;
 int count=1;
 while(x>0)
 {
  int check = x%10;
  y += count*check;
  x /= 10;
  count *=2;
 }
 return y;
}

int main(void)
{
 int x, i;
 unsigned long long factorial=1;
 printf("Enter an integer: ");
 scanf("%d", &x);
 for(i = 1; i <= x; ++i)
 {
   factorial *= i;
 }
 
 int binary=0;
 int binaryA[x+1];
 int count = 0;
 int complement = 0;
 while(x > 0)
 {
  binaryA[count]=x%2;
  x=x/2;
  count++;
 }
 int y;
 for( y = count-1; y >=0; y--)
 {
  binary *= 10;
  complement *= 10;
  binary += binaryA[y];
  if(binaryA[y] == 0)
	complement +=1;
 }
 binary *= 1000;
 int new = toDecimal(binary)+toDecimal(complement);

 printf("The Factorial is %llu \n", factorial);
 printf("The value after bit-shifting left then adding its complement is %d\n", new);
 return 0;
 
}

