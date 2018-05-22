#include<time.h>
#include <stdlib.h>
#include<stdio.h>

int main()
{
  time_t rawtime;
  time_t now;
  struct tm * timeinfo;
  long before=time ( &rawtime );
  long now_time=time(&now);
  while(1)
  {
    timeinfo = localtime ( &now );
now_time=time(&now);
    if( (now_time-before) >=1 )
{
     before=time(&now);
     system("cls");
     printf ( "The current date/time is: %s", asctime (timeinfo) );
  }
  }
} 
