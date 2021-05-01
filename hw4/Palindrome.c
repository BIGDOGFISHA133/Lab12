#include<stdio.h>
#include<string.h>

void palindrome(char str[])
{
 int left = 0;			// This is the start of the string
 int right = strlen(str) - 1;	// This is the end of the string
 while (right > left)		// This program will run when the two
 {				// pointers meet at the middle
  if (tolower(str[left++]) != tolower(str[right--]))
  {				// I used tolower() to account for casing
   printf("Not a palindrome. \n");	// If not equal, prints then ends
   return;				// the method
  }
 }
 printf("The string is a palindrome. \n");	// If while loop is able
}					// to finish, means that string
					// is a palindrome
int main()
{
 char str[20];
 printf("Enter a string: ");
 scanf("%s", str);
 palindrome(str);
 return 0;
}
