#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* insertAscending(struct node *head, int value)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = NULL;

    /* Insert at front */
    if(head == NULL || value < head->data)
    {
        newNode->next = head;
        head = newNode;

        return head;
    }

    temp = head;

    /* Find correct position */
    while(temp->next != NULL && temp->next->data < value)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
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

        head = insertAscending(head, value);
    }

    printf("Ascending Linked List: ");
    display(head);

    return 0;
}
