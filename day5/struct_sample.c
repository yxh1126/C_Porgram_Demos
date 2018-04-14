struct string 
{
    int length;
    // char data[10];
    char* data;
};

// typedef struct string Zhang;

typedef struct 
{
	int length;
	char* data;
} Zhang;

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    // struct string s;
    Zhang s;

    s.length = 4;

    // s.data[0] = 'a';
    // s.data[1] = 'b';
    // s.data[2] = 'c';
    // strcpy( s.data, "C Programming");

    //s.data[] = '{'a', 'b', 'c'}; // "abc"or

    
    // "this string is a lot longer than you think";
    s.data = "this string is a lot longer than you think";

    // puts(s.data);
    printf("%s\n", s.data);

    return 0;
}