#include <stdio.h>
#include <string.h>

void swap(char *str1, char *str2)
{
 int i = 0;
 while(str1[i] != '\0')
 {
  if(((str1[i] >= '0' && str1[i] <= '9') && (str2[i]>= 'A' && str2[i]<='z')) ||     ((str2[i] >= '0' && str2[i] <= '9') && (str1[i]>= 'A' && str1[i]<='z')))
  {
   str1[i] = str1[i] + str2[i];
   str2[i] = str1[i] - str2[i];
   str1[i] = str1[i] - str2[i];
  }
  else
  {
  str1[i] = ' ';
  str2[i] = ' ';
  }
  i++;
 }
}

int main()
{
 char str1[20];
 char str2[20];

 printf("Enter a string: ");
 scanf("%s", str1); 
 printf("Enter a second string of same length: ");
 scanf("%s", str2);
 if(strlen(str1) != strlen(str2))
 {
  printf("Not same length\n");
  return 0;
 }
 printf("Before swap:\n%s\n%s\n", str1, str2);
 swap(str1, str2);
 printf("After swap:\n%s\n%s\n", str1, str2);
 return 0;
}
