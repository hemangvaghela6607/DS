#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* deleteLast(struct node *head)
{
    struct node *temp, *prev;

    if(head == NULL)
    {
        printf("Linked List is empty.\n");
        return head;
    }

    /* Only one node */
    if(head->next == NULL)
    {
        free(head);
        head = NULL;

        return head;
    }

    temp = head;
    prev = NULL;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

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
    struct node *newNode, *temp;
    int n, value, i;

    printf("How many nodes : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newNode = (struct node*)malloc(sizeof(struct node));

        printf("Enter value: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    printf("Before deletion: ");
    display(head);

    head = deleteLast(head);

    printf("After deletion: ");
    display(head);

    return 0;
}
