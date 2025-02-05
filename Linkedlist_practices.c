#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
void display_list(NODE*);
void create_list(NODE **head,int size)
{
     NODE *ptr;
     ptr=(NODE*)malloc(sizeof(NODE));
    NODE *temp;
    int i;
    if(ptr==NULL)
    {
        printf("Memory not allocated\n");
        return;
    }
    int value;
    printf("Enter the value\n");
    scanf("%d",&value);
    ptr->data=value;
    ptr->next=NULL;
    (*head)=ptr;
    temp=(*head);
    for(i=2;i<=size;i++)
    {
        ptr=(NODE*)malloc(sizeof(NODE));
        if(ptr==NULL)
        {
            printf("Memory not allocated\n");
            return;
        }
        printf("Enter the value:\n");
        scanf("%d",&value);
        ptr->data=value;
        temp->next=ptr;
        temp=temp->next;
        ptr->next=NULL;
    }
    
}
void delete_begin(NODE **head)
{
    NODE *ptr;
    if((*head)==NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr=(*head);
    (*head)=(*head)->next;
    free(ptr);
    printf("Node deletion done at begin\n");
    display_list(*head);
    return;
    
}
void delete_end(NODE **head)
{
    NODE *ptr=(*head);
    NODE *temp;
    if((*head)==NULL)
    {
        printf("List is empty deletion not possible at end\n");
        return;
    }
    else if(ptr->next==NULL)
    {
        free(ptr);
        (*head)=NULL;
        printf("Only one present in list it can be deleted\n");
        return;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        free(ptr);
        printf("NODE deletion done at end\n");
    }
    display_list(*head);
    return;
    
}
void reverse_list(NODE **head)
{
    NODE *current=(*head);
    NODE *prev=NULL;
    NODE *last=NULL;
    if((*head)==NULL)
    {
        printf("Reverse not possible in list\n");
        return;
    }
 
    while(current!=NULL)
    {
        last=current->next;
        current->next=prev;
        prev=current;
        current=last;
    }
    (*head)=prev;
    printf("Reverse list :\n");
    display_list(*head);
    return;
}
void display_list(NODE *head)
{
    NODE *temp;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    NODE *head=NULL;
    int n;
    printf("Enter the node size you want\n");
    scanf("%d",&n);
    if(n>0)
    {
        create_list(&head,n);
        display_list(head);
        delete_begin(&head);
        delete_end(&head);
        reverse_list(&head);
    }
    else
    {
        printf("If you want to some operation node size will be greater than zero\n");
    }
    
}