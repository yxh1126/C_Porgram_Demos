#include "stdio.h"
#include "stdlib.h"

typedef enum
{
	Mon,
	Tue,
	Wed,
	Thu,
	Fri,
	Sat,
	Sun
} Week;


int main(int argc, char* argv[])
{
	int day = atoi(argv[1]);
	Week one_day;
	
	switch(day)
	{
		case(1):
			one_day = Mon;
			break;
		case(2):
			one_day = Tue;
			break;
		default:
			one_day = Sun;
			break;
	}
	
	switch(one_day)
	{
		case(Mon):
			printf("Weeday!\n");
			break;
		case(Tue):
			printf("Come on!\n");
			break;
		default:
			printf("Payer day!\n");;
			break;
	}
	
	return 0;
}