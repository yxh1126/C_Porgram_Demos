#include <stdio.h>

int main(int argc, char const *argv[])
{
	char a_word1[] = "Hello world!";
	char* a_word2 = "Hello world!";
	char a[] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\0'};

	int f[] = {1, 2, 3};

	printf("%s\n", a);
	printf("%s\n", a_word1);
	printf("%s\n", a_word2);

	printf("%d\n", f[1]);

	return 0;
}
