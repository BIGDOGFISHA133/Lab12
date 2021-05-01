#include<stdio.h>

struct dialing_code
{
  char name[50];
  int code;
};

int main()
{
 const struct dialing_code intcode[25] = 
 { {"Argentina", 54}, {"Bangladesh", 880}, {"Brazil", 55},
   {"China", 86}, {"Colombia", 57}, {"Congo, Demo. Rep. of", 243},
   {"Egypt", 20}, {"Ethiopia", 251}, {"France", 33}, {"Germany", 49},
   {"India", 91}, {"Indonesia", 62}, {"Iran", 98}, {"Italy", 39},
   {"Japan", 81}, {"Mexico", 52}, {"Nigeria", 234}, {"Pakistan", 92},
   {"Russia", 7}, {"South Africa", 27}, {"South Korea", 82}, 
   {"Spain", 34}, {"Sudan", 249}, {"Ukraine", 380}, {"Vietnam", 84} };
 // This is the list of countries
 int code;	// Code will be the user input
 int x=0;	// X will be used for going through the for loop
 int scan = 0;	// Scan is used to keep track of if a country is found
 printf("Enter code: ");
 scanf("%d", &code);
 
 for(x = 0; x<25; x++)
 {
  if(intcode[x].code == code)	// If the country's code is the same
  {				// as the input code, then scan is set to 1
    printf("Country: %s, Code: %d\n", intcode[x].name, intcode[x].code);
    scan = 1;		// Scan is set to 1 so it doesn't trigger the if
    break;  		// later, and the loop is broken
  }
 }
			// If the for loop finishes without setting scan to
 if(scan == 0)		// 1, then the code does not exist
	printf("Country not found\n");
 return 0;
} 
