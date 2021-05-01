#include<stdio.h>

void split_time(int n, int *hr, int *min, int *sec)
{
  int x=0;
  int y=0;
  while(n>=3600)
  {
   x++;
   n=n-3600;
  }
  while(n>=60)
  {
   y++;
   n=n-60;
  }
  *hr=x;
  *min=y;
  *sec=n;
}

int main()
{
 int n,hr,min,sec;
 hr=0;
 printf("Enter seconds:");
 scanf("%d", &n);

 split_time(n, &hr, &min, &sec);

 printf("Converted format: %d hour %d mins %d secs", hr, min, sec);
 return 0;
}
