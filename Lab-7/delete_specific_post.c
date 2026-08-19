#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* deleteBeforePosition(struct node *head, int position)
{
    struct node *temp, *prev, *del;

    if(head == NULL)
    {
        printf("Linked List is empty.\n");
        return head;
    }

    /* No node exists before position 1 or 2 */
    if(position <= 1)
    {
        printf("No node exists before this position.\n");
        return head;
    }

    /* Position 2 means delete first node */
    if(position == 2)
    {
        del = head;
        head = head->next;

        free(del);

        return head;
    }

    temp = head;
    prev = NULL;

    /*
       Move temp to the node
       before the node to be deleted
    */
    int i;
    for( i = 1; i < position - 2 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL)
    {
        printf("Invalid position.\n");
        return head;
    }

    del = temp->next;
    temp->next = del->next;

    free(del);

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
    int n, value, position, i;

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

    printf("Original Linked List: ");
    display(head);

    printf("Enter position: ");
    scanf("%d", &position);

    head = deleteBeforePosition(head, position);

    printf("After deletion: ");
    display(head);

    return 0;
}
