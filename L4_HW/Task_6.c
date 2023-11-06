#include <stdio.h>
int main()
{
  int time_sec = 53423;
  int time_hours = time_sec / 3600;
  int time_min = (time_sec - time_hours * 3600) / 60;
  int time_r = (time_sec - time_hours * 3600);
  int time_seconds = (time_r - time_min * 60);
  
  printf("%d:", time_hours);
  printf("%d:", time_min);
  prinf("%d", time_seconds);
  
  return 0;
}


