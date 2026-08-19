#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int Que[MAX], front=-1, rear=-1;
int value;
int isFull(){
    if(rear==MAX-1)
        return 1;
    else

    return 0;
}
void insert(){
    if(isFull()==1)
        printf("Queue is Overflow.");
    else{
        printf("Enter a Value:");
        scanf("%d",&value);

        if(front==-1)
                front++;
        rear++;
        Que[rear]=value;
        printf("Insertion Done.");
    }
}
int isEmpty(){
    if(front==-1)
        return 1;
    else
        return 0;
}
void del(){
    if(isEmpty()==1)
        printf("Queue is underflow.");
    else{
        //value=Que[front];
        //printf("%d is deleted.",value);
        printf("%d is deleted.",Que[front]);
        if(front==rear)
                front=rear=-1;
        else
            front++;
    }
}
void peek(){
    if(isEmpty()==1)
        printf("Queue is Empty.");
    else
        printf("Last inserted Value is %d.",Que[rear]);
}
void change(){
    int index, newvalue;
    if(isEmpty()==1)
    printf("Queue is Empty.");
	else{
        printf("Enter an index:");
        scanf("%d",&index);

        if(index >(rear-front+1) || index<=0)
            printf("Invalid Index..");
        else{
            printf("Enter a new value:");
            scanf("%d",&newvalue);
            Que[index+front-1]=newvalue;
            printf("value updated.");
    	}
	}
}
void display(){
    int i;
    if(isEmpty()==1)
        printf("Queue is Empty.");
    else{
        printf("\nQueue is:");
        for(i=front;i<=rear;i++)
            printf("%d ",Que[i]);
    }
}
void main(){
    int ch;
    while(1){
        printf("\n\nQueue Operation:");
        printf("\n1. Insert\n2. Delete\n3. Peek\n4. Change \n5. Display\n6. isEmpty\n7. isFull \n8. Exit");
        printf("\nEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: insert();
                    break;
            case 2: del();
                    break;
            case 3: peek();
                    break;
            case 4: change();
                    break;
            case 5: display();
                    break;
            case 6: if(isEmpty()==1)
                        printf("Yes, Queue is Empty.");
                    else
                        printf("No,Queue is not Empty.");
                    break;
            case 7: if(isFull()==1)
                        printf("Yes,Queue is Full.");
                    else
                        printf("No, Queue is Not Full.");
                    break;
            case 8: exit(0);
            default: printf("Invalid CHoice; Try Again!");
        }
    }
}
