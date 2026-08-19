#include<stdio.h>
#include<stdlib.h>
struct stud{
    int num, marks;
    char name[30];
};
void main(){
    int i, n;
    struct stud *p;
    printf("How many number of students:");
    scanf("%d",&n);
    p = (struct stud*) malloc (n*sizeof(struct stud));
    
    if(p==NULL){
        printf("\nMemory not available..");
    }

    printf("Enter Student Details:");
    for(i=0;i<n;i++)
    {
        printf("\nEnter Number:");
        scanf("%d",&p[i].num);
        printf("Enter Name:");
        scanf("%s",&p[i].name);
        printf("Enter Marks:");
        scanf("%d",&p[i].marks);
    }
    printf("\nStudent Details\n Number\t Name\t Marks");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%s\t%d",p[i].num,p[i].name,p[i].marks);
    }

     free(p);
}
