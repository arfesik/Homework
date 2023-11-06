#include <stdio.h>
int main()
{
  int time_sec = 63274;
  int time_hours = time_sec / 3600;
  int time_min = (time_sec - time_hours * 3600) / 60;

  printf("%d:", time_hours);
  printf("%d", time_min);
  return 0;
}


