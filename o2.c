/*Write a program in C to create a linked list with 10 numbers and then display it*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elements are:%d \n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct Node *head = NULL;
    struct Node *newnode = NULL;
    struct Node *temp = NULL;

    for (int i = 1; i <= 10; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = i;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = head;
        }

        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
    }
    traverse(head);
    return 0;
}
