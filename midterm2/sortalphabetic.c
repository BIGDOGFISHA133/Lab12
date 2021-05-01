#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_alphabetic(char **array, char type)   // One main difference of this code to number one is that we use a double array,
{                                               // since a string is an array of characters, and we need an array of those arrays
 if(type == 'a' || type == 'A')         // The shell of this code was copied over from the first question
 {                                      // The only real differences there are is that we can use strcasecmp
  int x,y;                              // for the comparison between the first and second element.
  for (x = 0; x<7; x++)                 // X and Y are juse used as counter variables
  {
   for (y = x+1; y<8; y++)              // This program uses bubble sort just like number 1.
   {
    if (strcasecmp(array[x],array[y])>0) 
    {
     char* z = array[x];                // Make sure to set the temp variable as a pointer by using char*
     array[x] = array[y];
     array[y] = z;
    }
   }
  }
 }
 else 
 {
  int x,y; 
  for (x = 0; x<7; x++)                 // The exact same as the if-statement except we set strcasecmp to <0 rather than >0
  {
   for (y = x+1; y<8; y++)
   {
    if (strcasecmp(array[x], array[y])<0)
    {
     char* z = array[x];
     array[x] = array[y];
     array[y] = z;
    }
   }
  }
 }
}

int main()
{
 int n = 8;                 // The number of strings in the array
 int i;                     // Counter varible
 char* array[8] = { "Systems", "Programming", "Deep", "Learning", "Internet", "Things", "Robotics", "Course" };
 char sort;                 // Used for deciding which sort to use
 printf("Sort by (A)scending or (D)escending: \n");
 scanf("%c",&sort);
 printf("Before sorting:\n");
 for (i = 0; i < n; i++)
  printf("%s ", *(array + i));
 printf("\n");
 sort_alphabetic(array, sort);
 printf("After sorting:\n");
 for(i = 0 ; i < n; i++)
  printf("%s ", *(array + i));
 printf("\n");
 return 0;
}