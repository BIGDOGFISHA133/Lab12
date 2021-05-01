#include <stdio.h>
#include <stdlib.h>

void sort_numeric(float array[], int length, char type)
{
 if(type == 'a' || type == 'A')             // I am going to use bubble sort to sort these floats
 {                          
  int x,y;                                  // X and Y are just integers to keep count traversing the array
  float z;                                  // Z is a temporary variable that will let us swap X and Y
  for (x = 0; x<length; x++) 
  {
   for (y = x+1; y<length; y++)
   {
    if (*(array + y) < *(array + x))        // If X is bigger than Y, then X will swap with Y, sending
    {                                       // the biggest variable to the right
     z = *(array + x);
     *(array + x) = *(array + y);
     *(array + y) = z;
    }
   }
  }
 }
 else 
 {
  int x, y;                                 // Essentially the exact same as the if-statement, but
  float z;                                  // now we check if X is less than Y
  for (x = 0; x < length; x++)        
  {
   for (y = x+1; y < length; y++) 
   {
    if (*(array + y) > *(array + x))
    {
     z = *(array + x);
     *(array + x) = *(array + y);
     *(array + y) = z;
    }
   }
  }
 }
}

int main()
{
int n;                                      // N will be used as the size of the float array
float * array;
array = (float*)malloc(n * sizeof(float));  // The array will be the size of the element we enter multiplied by the size of a float
printf("Enter size of the array: ");
scanf("%d", &n);
float userstring;                           // Userstring will be each string entered by the user
int i;                                      // I is a counter variable
char ch;                                    // Ch is to see if we sort by ascending or descending
printf("Enter floats one by one: ");
for(i = 0 ; i < n; i++)
{
 scanf("%f", &userstring );
 *(array + i) = userstring;
}
printf("\nSort by (A)scending or (D)escending:");
printf("\n");
scanf("%c", &ch);
scanf("%c", &ch);
printf("Array before sorting:\n");
for (i = 0; i < n; i++)
    printf("%f ", *(array + i));
sort_numeric(array, n, ch);
printf("\n");
printf("Array after sorting:\n");
for(i = 0 ; i < n; i++)
 printf("%f ", *(array + i));
printf("\n");
free(array);                                // Make sure to free malloc to stop memory leakage
return 0;
}
