#include <stdio.h>
int main( )
{
  int time1, time2, hours, mins;
  scanf("%d%d", &time1, &time2);

  if(time2%100<time1%100)
  {
    hours = time2/100-time1/100-1;
    mins = time2%100 - time1%100 + 60;
  }
  else
  {
    hours = time2/100-time1/100;
    mins = time2%100 - time1%100;
  }

  printf("The train journey time is %d hrs %d mins.\n", hours, mins);
}
