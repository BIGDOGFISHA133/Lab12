#include<stdio.h>

int main()
{
 char str[20];                	// I will use a max of 20 chars for passwd
 int i;				// "i" will be the counter for length of string
 int lower = 20;		// default penalty for lowercase
 int upper = 20;		// check for uppercase
 int digit = 20;		// check for digits
 int consecutive = 0;		// check for consecutive chars
 printf("Please enter a password: ");
 scanf("%s", str);
 for(i = 0; str[i] != '\0'; i++)
 {
  if (str[i] >= 'a' && str[i] <= 'z')	// If lowercase exists, then I 'remove'
	lower = 0;			// the penalty by setting lower from
  if (str[i] >= 'A' && str[i] <= 'Z')	// 20 to 0, and I do the same for
	upper = 0;			// upper and digit.
  if (isdigit(str[i]))
	digit = 0;
 }
 
 for(i = 2; str[i] != '\0'; i++)	// Since we are checking FOR
 {					// consecutives rather than the lack
  if (str[i] - str[i-1] == 1)		// of, we have it initially set to 0,
  {					// then set it to 20 if 3 of the
   if (str[i-1] - str[i-2] == 1)	// characters are consecutive.
	consecutive = 20;
  }
 }

 if (i < 10)			// "i" currently is the length of string,
	i = 5*(10-i);		// if less than 10 then i have it be 5 points
				// per missing char
 int points = i + lower + upper + digit + consecutive;
				// Grand tally of all the points
 if (points > 30)		// If points >30, it is unsafe
	printf("Password is unsafe \n");
 else
	printf("Password is safe \n ");
 return 0;
}
