#include "stdio.h"

int main(int argc, char* argv[])
{
printf("Argc is: %d\n", argc);

for(int i = 0; i < argc; i++)
{
  printf("The value is: %s\n", argv[i]);
}

int a = 0x77;
int b = 0x3;
printf("Result: %d\n", a^b);
printf("Result: %d\n", a|b);

int c = 4;
printf("Shift: %d\n", c>>2);
}
