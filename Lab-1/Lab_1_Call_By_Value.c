#include<stdio.h>
void swap(int a, int b);
void main(){
    int x, y, a, b;
    printf("Enter two values:");
    scanf("%d %d",&x,&y);
        swap(x,y); //call by value
   //printf("\nAfter Swapping: x=%d y=%d",x,y);
}


void swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("\nAfter Swapping: x=%d y=%d",a,b);
}
