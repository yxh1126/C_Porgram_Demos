#include <stdio.h>

// static char* get_message(void);
char* pass_a_pointer();

int main(int argc, char const *argv[])
{
	// char∗ string = get_message();
	// printf("%s\n", string);
	puts("Hello");

	char* msg = "Here is something very fun.";
	puts(msg);

	char* a_string = pass_a_pointer();
	puts(a_string);

	return 0;
}

char* pass_a_pointer()
{
	char* some = "Hello world";
	// a = some;
	return some;
}

// static char* get_message(void)
// {
// 	char msg[] = "Aren't pointers fun?";

// 	char *str = (char *) malloc(sizeof(msg));
// 	return str;
// }
