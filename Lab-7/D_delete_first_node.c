#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* deleteFirst(struct node *head)
{
    struct node *temp;

    if(head == NULL)
    {
        printf("Linked List is empty.\n");
        return head;
    }

    temp = head;
    head = head->next;

    free(temp);

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
    struct node *newNode;
    int n, value, i;

    printf("How many nodes : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newNode = (struct node*)malloc(sizeof(struct node));

        printf("Enter value: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    printf("Before deletion: ");
    display(head);

    head = deleteFirst(head);

    printf("After deletion: ");
    display(head);

    return 0;
}
