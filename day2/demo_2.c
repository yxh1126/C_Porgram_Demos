#include "stdio.h"

typedef struct
{
    int* value;
    char name;
} SomeType;

int xyz = 100;
char kid = 'a';

typedef struct
{
    char* name;
    int* age;
} ABS;

int main(int argc, char const *argv[])
{
    SomeType sample;
    // sample = {&xyz, kid};
    sample.value = (int*)(&xyz);
    sample.name = kid;

    int one = 10;
    char two = 'm';
    SomeType perfect = {&xyz, kid};

    printf("Var_1 is: %d; and Var_2 is: %c\n", *(sample.value), sample.name);
    printf("Var_1 is: %d; and Var_2 is: %c\n", (perfect.value), perfect.name);

    ABS supername = {"hello", &one};
    printf("Var_1 is: %d; and Var_2 is: %d\n", (supername.name), supername.age);
    puts(supername.name);
    printf("%d\n", *(supername.age));

    return 0;
}