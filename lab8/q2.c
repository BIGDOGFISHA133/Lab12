#include <stdio.h>

int main()
{
 int letters, words;
 char character;

 printf("Enter a Sentence: ");
 while((character=getchar()) != \n)
 {
  if(character != ' ')
  {
   if(!space)
   {
    words++;
    space=1;
   }
  letters++
  }
  else
	space = 0;
 }
 printf("Average word length : %.lf", letters/words);
return 0;
}
