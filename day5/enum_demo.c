enum fruit 
{
    Apple,  //0
    Banana, //1
    Orange  //2
};

typedef enum fruit Zhang;
typedef enum fruit Wang;

typedef enum
{
    Apple1,
    Banana1,
    Orange1
}Super;


#include <stdio.h>

int main(int argc, char **argv)
{
    // enum fruit s;
    // enum fruit s;
    enum fruit b;
    enum fruit c;

    Zhang s;
    // Super s;
    s = Orange;
    
    printf("%d\n", s);

    return 0;
}