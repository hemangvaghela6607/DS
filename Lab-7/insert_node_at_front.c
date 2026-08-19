#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* insertFront(struct node *head, int value)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = head;

    head = newNode;

    return head;
}

void display(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;
    int value;

    printf("Enter value: ");
    scanf("%d", &value);

    head = insertFront(head, value);

    printf("Linked List: ");
    display(head);

    return 0;
}
