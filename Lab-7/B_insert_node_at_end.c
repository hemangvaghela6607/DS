#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* insertEnd(struct node *head, int value)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return head;
    }

    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

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
    int value, n, i;

    printf("How many nodes : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        head = insertEnd(head, value);
    }

    printf("Linked List: ");
    display(head);

    return 0;
}
