#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE head,int no)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;

    if(*head==NULL)
    {
        *head=newn;
    }
    else
    {
        newn->next=*head;
        *head=newn;
    }
}

void InsertLast(PPNODE head,int no)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;

    if(*head==NULL)
    {
        *head=newn;
    }
    else
    {
        PNODE temp=NULL;
        temp=*head;

        while(temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
}
void DeleteFirst(PPNODE head)
{

    if(*head==NULL)
    {
        return ;
    }
    else if((*head)->next==NULL)
    {
       free(*head);
       *head=NULL;

    }
    else
    {
        PNODE temp=NULL;
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }

}
void DeleteLast(PPNODE head)
{   
    PNODE temp=NULL;

    if(*head==NULL)
    {
        return ;
    }
    else if((*head)->next==NULL)
    {
       free(*head);
       *head=NULL;

    }
    else
    {
      
        temp=*head;
        while(temp -> next -> next !=NULL)
        temp=temp->next;

    }
    free(temp -> next);
    temp->next=NULL;

}
// void DeleteLast(PPNODE head)
// {
//     PNODE temp = NULL;

//     if(*head == NULL)
//     {
//         return;
//     }
//     if((*head) -> next == NULL)
//     {
//         free(*head);
//         *head = NULL;
//     }
//     else
//     {
//         temp = *head;
        
//         while(temp -> next->next != NULL)
//         {
//             temp = temp -> next;
//         }
//         free(temp->next);
//         temp->next = NULL;
//     }
//}
int  Count(PNODE head)
{
    int iCount=0;
    while(head !=NULL)
    {
        head=head->next;
        iCount++;
    }
    return iCount;
}

void InsertAtPos(PPNODE head,int no,int iPos)
{
    int iCount=0;
    PNODE newn=NULL;
    PNODE temp=NULL;
 
    int i=0;


    iCount = Count(*head);
    if(iPos<1 || iPos>iCount+1)
    {
        printf("invalid position \n ");
        return;
    }
    if(iPos==1)
    {
        InsertFirst(head,no);
    }
    else if(iPos==iCount+1)
    {
        InsertLast(head,no);
    }
    else
    {
           
        newn=(PNODE)malloc(sizeof(NODE));
                newn->data=no;
                newn->next=NULL;
                temp=*head;
                for(i=0;i<iPos-1;i++)
                {
                    temp=temp->next;
                }
                newn->next=temp->next;
                temp->next=newn;
        }
    
}

void DeleteAtPos(PPNODE head,int iPos)
{
    int iCount=0;
    
    PNODE temp=NULL;
    PNODE target=NULL;
 
    int i=0;


    iCount = Count(*head);
    if(iPos<1 || iPos>iCount)
    {
        printf("invalid position \n ");
        return;
    }
    if(iPos==1)
    {
        DeleteFirst(head);
    }
    else if(iPos==iCount)
    {
        DeleteLast(head);
    }
    else
    {
        temp=*head;

        for(i=0;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        target=temp->next;
        temp->next=target->next;
        free(target);

           
       
    }
    
}


void Display(PNODE head)
{
    while(head !=NULL)
    {
        printf("|%d|->",head->data);
        head=head->next;
    }
    printf("|NULL|\n");
}

int main()
{
    PNODE first=NULL;
    int iRet=0;
    InsertFirst(&first,51);
    InsertFirst(&first,21);
    InsertFirst(&first,11);
    InsertLast(&first,101);
    InsertLast(&first,111);
    InsertLast(&first,121);

    Display(first);
    iRet=Count(first);
    printf("The no of nodes are: %d\n ",iRet);

    DeleteFirst(&first);

  
   
    DeleteLast(&first);
    Display(first);
    iRet=Count(first);
    printf("The no of nodes are: %d\n ",iRet);
    
    InsertAtPos(&first,75,4);
        Display(first);
    iRet=Count(first);
    printf("The no of nodes are: %d\n ",iRet);

    DeleteAtPos(&first,4);
     Display(first);
    iRet=Count(first);
    printf("The no of nodes are: %d\n ",iRet);




    return 0;
}