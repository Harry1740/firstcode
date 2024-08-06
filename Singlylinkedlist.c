#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct person
{
        int data;
        struct person *next;
}PERSON;
void display(PERSON*);
void insert_begin(PERSON **head)
{
        PERSON *ptr;
        int item;
        ptr=(PERSON*)malloc(sizeof(PERSON));
        if(ptr==NULL)
        {
                printf("List is empty\n");
                return;
        }
        else
        {
            printf("Enter the data to insert\n");
            scanf("%d",&item);
            ptr->data=item;
            if((*head)==NULL)
            {
                (*head)=ptr;
                ptr->next=NULL;
            }
            else
            {
                ptr->next=(*head);
                (*head)=ptr;
                printf("Node inserted at begining\n");
                
            }
        }
}
void insert_random(PERSON **head)
{
        PERSON *ptr;
        PERSON *temp;
        PERSON *prev;
        ptr=(PERSON*)malloc(sizeof(PERSON));
        int pos;
        int item;
        printf("Enter the data to item\n");
        scanf("%d",&item);
        ptr->data=item;
         temp=(*head);
        if(temp==NULL)
        {
            (*head)=ptr;
            ptr->next=NULL;
            printf("Node inserted at first position\n");
            return;
        }
        else
        {
            printf("Enter the position you want to insert\n");
            scanf("%d",&pos);
            if(pos==0)
            {
                ptr->next=(*head);
                (*head)=ptr;
                printf("Node inserted at %d position\n",pos);
                return;
            }
        }
        int index;
        for(index=0;index<pos;index++)
        {
                prev=temp;
                temp=temp->next;
                if(temp==NULL && index<pos-1)
                {
                    printf("You can't insert because there are %d less than elements\n",pos);
                    free(ptr);
                    return;
                }

        }
        prev->next=ptr;
        ptr->next=temp;
        printf("Node inserted at pos of %d\n",index);
        return;
}
void insert_last(PERSON **head)
{
        PERSON *ptr;
        PERSON *temp;
        ptr=(PERSON*)malloc(sizeof(PERSON));
        int item;
        printf("Enter the item\n");
         scanf("%d",&item);
        ptr->data=item;
        if((*head)==NULL)
        {
                ptr->next=NULL;
                (*head)=ptr;
                printf("Node inserted at end\n");
                return;
        }
        else
        {
                temp=(*head);
                while(temp->next!=NULL)
                {
                        temp=temp->next;
                }
                temp->next=ptr;
                ptr->next=NULL;
                printf("Node inserted at end\n");
        }
}
void search_list(PERSON **head)
{
        PERSON *temp=(*head);
        int key;
        if((*head)==NULL)
        {
                printf("List is empty you can't be search\n");
                return;
        }
        printf("Enter the key you want to search\n");
        scanf("%d",&key);
        int index=0;
        int flag=1;
        while(temp!=NULL)
        {
                if(temp->data==key)
                {
                        printf("Key found at the position of index : %d\n",index);
                         flag=1;
                        return;
                }
                else
                {
                        flag=0;
                }
                temp=temp->next;
                index++;
        }
        if(flag==0)
        {
                printf("Key not found in the list\n");
                return;
        }

}
void sort_list(PERSON **head)
{
        PERSON *temp=(*head);
        PERSON *ptr;
        int index;
        if((*head)==NULL)
        {
                printf("List is empty you can't be sort\n");
                return;
        }
        while(temp->next!=NULL)
        {
                ptr=temp->next;
                while(ptr!=NULL)
                {
                        if(temp->data>ptr->data)
                        {
                                index=temp->data;
                                temp->data=ptr->data;
                                ptr->data=index;
                        }
                        ptr=ptr->next;
                }
                temp=temp->next;
        }
        display(*head);
}
void delete_begin(PERSON **head)
{
        PERSON *ptr;
        if((*head)==NULL)
        {
                printf("List is empty Deletion is not possible\n");
                return;
        }
        ptr=(*head);
       (*head)=(*head)->next;
        free(ptr);
        printf("Node deleted at begining\n");
}
void delete_random(PERSON **head)
{
        PERSON *ptr=(*head);
        PERSON *prev;
        if((*head)==NULL)
        {
                printf("List is empty Deletion at random not possible\n");
                return;
        }
        int index;
        int pos;
         printf("Enter the position u want\n");
        scanf("%d",&pos);
        if(pos==0)
        {
                ptr=(*head);
                (*head)=(*head)->next;
                free(ptr);
                printf("Node deleted at position as : %d\n",pos);
                return;
        }
        for(index=0;index<pos;index++)
        {
                prev=ptr;
                ptr=ptr->next;
                if(ptr==NULL)
                {
                    printf("Index out of bounds\n");
                    return;
                }

        }
/*      if(ptr->next == NULL)
        {
                printf("%d", ptr->data);
                prev->next = NULL;
                free(ptr);
                return;
        }*/
        printf("%d", ptr->data);
        prev->next=ptr->next;
        free(ptr);
        printf("\nDeletion at position of index : %d\n", index);
}
void delete_last(PERSON **head)
{
        PERSON *ptr=(*head);
        PERSON *temp;
        if((*head)==NULL)
        {
                printf("List is empty Deletion at last not possible\n");
                 return;
        }
        else if(ptr->next==NULL)
        {
                (*head)=NULL;
                free((*head));
                printf("Only one node present in list it can be deleted\n");
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
                printf("Deletion can be done in the end\n");
        }
        display(*head);
}

void reverse_list(PERSON **head)
{
    if((*head)==NULL || (*head)->next==NULL)
    {
        printf("No possible to reverse the list\n");
        return;
    }
    PERSON *curr=(*head);
    PERSON *prev=NULL;
    PERSON *last=NULL;
    
    while(curr!=NULL)
    {
        last=curr->next;
        curr->next=prev;
        prev=curr;
        curr=last;
    }
    (*head)=prev;
    return;
        
}
void middle_element(PERSON **head)
{
    PERSON *slow=(*head);
    PERSON *fast=(*head);
    
    PERSON *temp=(*head);
    if(temp==NULL)
    {
        printf("No middle_element in the list\n");
        
    }
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("Middle element in the list : %d\n",slow->data);
    
}
void duplicate_removal(PERSON **head)
{
    PERSON *ptr;
    PERSON *ptr2;
    PERSON *temp;
    ptr=(*head);
    if((*head)==NULL)
    {
        printf("No possible to duplicates\n");
        return;
    }
    else
    {
        while(ptr!=NULL)
        {
            ptr2=ptr;
            temp=ptr2->next;
            while(temp!=NULL)
            {
                if(ptr->data==temp->data)
                {
                    ptr2->next=temp->next;
                }
                else
                {
                    ptr2=temp;
                }
                temp=temp->next;
            }
            ptr=ptr->next;
        }
    }
    
   
}
int counter(PERSON *head)
{
    PERSON *ptr=head;
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    return count;
}
void check_palindrome(PERSON *head)
{
    PERSON *front;
    PERSON *rear;
    int i=0;
    int j;
    bool flag=true;
    if(head==NULL||head->next==NULL)
    {
        printf("List is empty OR Only one element present in list so palidrome is not possible\n");
        return;
    }
    
    int size= counter(head);
    while(i!=size/2)
    {
        front=rear=head;
        for(j=0;j<i;j++)
        {
            front=front->next;
        }
        for(j=0;j<size-(i+1);j++)
        {
            rear=rear->next;
        }
        if(front->data!=rear->data)
        {
            flag=false;
            display(head);
            printf("\nList is not palindrome\n");
            return;
        }
        else
        {
            i++;
        }
    }
    if(flag==true)
    {
        display(head);
        printf("\nList is a palindrome\n");
    }
    
}
void create_loop(PERSON **head,int pos)
{
    PERSON *temp=(*head);
    PERSON *loop_node=NULL;
    int i=1;
    while(temp->next!=NULL)
    {
        if(i==pos)
        {
            loop_node=temp;
        }
        temp=temp->next;
        i++;
    }
    temp->next=loop_node;
}
void loop_list(PERSON **head)
{
    PERSON *slow=(*head);
    PERSON *fast=(*head);
    PERSON *ptr;
    if((*head)==NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    int flag=0;
    int choice;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            flag=1;
            break;
        }
    }
    printf("1.Check the loop or not \n2.Loop is present get the starting node of loop\n3.loop is present delete node of loop started\n");
    printf("Enter the choice you want\n");
    scanf("%d",&choice);
    //do{
    if(choice>=1 && choice<=3)
    {
        switch(choice)
        {
            case 1:
                if(flag==1)
                {
                    printf("Loop node is detected\n");
                }
                else
                {
                    printf("Loop node not detected\n");
                }
                break;
            case 2:
                if(flag==1)
                {
                    slow=(*head);
                    while(slow!=fast)
                    {
                        slow=slow->next;
                        fast=fast->next;
                    }
                }
                printf("Loop detected at start node :%d\n",slow->data);
                break;
            case 3:
                if(flag==1)
                {
                    slow=(*head);
                    while(slow!=fast)
                    {
                        slow=slow->next;
                        fast=fast->next;
                    }
                    ptr=slow;
                    while(ptr->next!=slow)
                    {
                        ptr=ptr->next;
                    }
                    ptr->next=NULL;
                }
                printf("Loop node can be deleted\n");
                break;
                
               
                
        }
    }
    else
    {
        printf("Enter the choice b/w 1 to 3\n");
        //scanf("%d",&choice);
    }
    //}while(choice!=0);
    return;
}

void display(PERSON *head)
{
        PERSON *temp;
        temp=head;
        if(temp==NULL)
        {
                printf("List is empty\n");
                return;
        }
        printf("Display the values\n");
        printf("%d",temp->data);
        temp=temp->next;
        while(temp!=NULL)
        {
                printf("->%d ",temp->data);
                 temp=temp->next;
        }
        return;
}


int main()
{
        int choice;
        PERSON *head=NULL;
        PERSON *temp=head;
        printf("_______Singly linked list Operation_______\n");
        do
        {
                printf("\n1.Insert at Begining\n2.Insert at random\n3.Insert at last\n4.Search\n5.Sort\n6.Delete at Begining\n7.Delete at random\n8.Delete at last\n9.Reverse the list\n10.Display\n11.middle_element in list\n12.Duplicate removal\n13.Check Palindrome\n14.Create a loop in list\n15.Find a loop in list\n16.Exit\n");
                printf("Enter ur choice\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                insert_begin(&head);
                                break;
                        case 2:
                                insert_random(&head);
                                break;
                        case 3:
                                insert_last(&head);
                                break;
                        case 4:
                                search_list(&head);
                                break;
                        case 5:
                                sort_list(&head);
                                break;
                        case 6:
                                delete_begin(&head);
                                break;
                        case 7:
                                delete_random(&head);
                                 break;
                        case 8:
                                delete_last(&head);
                                break;
                        case 9:
                                reverse_list(&head);
                                display(head);
                                break;
                        case 10:
                                display(head);
                                break;
                        case 11:
                                middle_element(&head);
                                break;
                        case 12:
                                duplicate_removal(&head);
                                display(head);
                                break;
                        case 13:
                                check_palindrome(head);
                                break;
                        case 14:
                                printf("enter the node to start the loop\n");
                                int pos;
                                scanf("%d",&pos);
                                create_loop(&head,pos);
                                break;
                        case 15:
                                loop_list(&head);
                                break;
                        case 16:
                                while(temp!=NULL)
                                {
                                    temp=temp->next;
                                    free(head);
                                    head=temp;
                                }
                                exit(0);
                        default:
                                printf("Enter the limits between 1 to 10\n");
                                break;
                }
        }while(choice!=0);
}



