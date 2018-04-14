struct Point
{
	int x;
	int y;
};


struct employee
{
	char name[10];
	int age;
	char phone[20];
	struct Point p;
};

// typedef struct employee Some;

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	struct employee zhang;
	 // = {"zhang", 10, "585957", {19, 20}};
	struct employee huang;
	

	// zhang.name = "zhang";
	strcpy( zhang.name, "zhang");

	zhang.age = 10;

	// zhang.phone = "342";
	strcpy( zhang.phone, "5234325");

	struct Point my_p = {19, 20};
	zhang.p = my_p;
	// zhang.p = {19, 20};

	huang = zhang;
	printf("%d\n", huang.p.x);
	return 0;
}
