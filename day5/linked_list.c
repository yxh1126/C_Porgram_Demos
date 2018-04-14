#define NULL 0

struct node_t
{
    int data;
    struct node_t* next;
};

typedef struct node_t Node;

#include "stdio.h"
#include "stdlib.h"

Node* build_list(Node* top_node, int num);
void push_data(Node*);

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        int data = atoi(argv[1]);
        printf("The data is: %d\n", data);

        Node* top = NULL;

        int i = 0;
        for (i = 1; i <= data; ++i)
        {
            top = build_list(top, i);
        }

        push_data(top);
    }
    else
    {
        printf("Give more inputs!\n");
    }

    return 0;
}

Node* build_list(Node* top_node, int num)
{
    if (top_node == NULL)
    {
        top_node = (Node*)malloc(sizeof(Node));
        top_node->data = num;
        top_node->next = NULL;
    }
    else
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = num;
        new_node->next = top_node;

        top_node = new_node;
    }

    return top_node;
}

void push_data(Node* a_node)
{
    while(a_node != NULL)
    {
        // int d = a_node->data;
        // printf("%x -> %d\n", a_node, d);

        Node* temp = a_node;
        a_node = a_node->next;

        free(temp);
    }
}
