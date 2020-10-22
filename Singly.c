#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

int Count(PNODE head)
{
    int iCnt = 0;

    while(head != NULL)
    {
        iCnt++;
        head = head->next;
    }

    return iCnt;

}

void InsertFirst(int value, PPNODE head)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = value;
    newn->next = NULL;


    if(head == NULL)
    {
        *head = newn;
    }
    else
    {
       newn->next = *head;
       *head = newn;
    }
    

}

void Display(PNODE head)
{
    while(head != NULL)
    {
        printf("|%d|->", head->data);
        head = head->next;
    }
}
void InsertLast(PPNODE head,int value)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = value;
    newn->next= NULL;

    PNODE temp = NULL;
    temp = *head;

    while((temp->next) != NULL)
    {
        temp=temp->next;
    }

    temp->next = newn;

}

void InsertAtPos(int value, int pos, PPNODE head)
{
    int llsize = Count(*head);
    printf("Size of the LL is :%d\n", llsize);

    if((pos < 1) || (pos > llsize+1))  //if pos is less than 0 or greater than size of LL
    {
        printf("Invalid position:\n");
        return ;
    }
    else if(pos == 1)            //if pos is 1
    {
        InsertFirst(value,head);
    }
    else if(pos == llsize)  //if pos is end of LL
    {
        InsertLast(head,value);

    }
    else                //if pos is between the LL
    {
        PNODE newn = NULL;
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = value;
        newn->next = NULL;

        PNODE temp = NULL;
        temp = *head;

        for(int i = 1 ; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
    

}


void DeleteFirst(PPNODE head)
{
    PNODE temp = NULL;

    temp = *head;       //take the address of first node in temp

    if(*head != NULL)   //if LL is not empty
    {
        *head = (*head)->next;    //move the head to second node
        free(temp);             //delete first node
    }


}

void DeleteLast(PPNODE head)
{
    PNODE temp = NULL;
    temp = *head;

    if(*head == NULL)   //if LL is empty
    {
        return;
    }
    else if(((*head)->next) == NULL)  //if LL has only one element
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        while((temp->next->next) != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;

    }

}

void DeleteAtPos(int pos, PPNODE head)
{
    PNODE temp = NULL;
    PNODE temp2 = NULL;
    temp = *head;


    int llsize = Count(*head);
    printf("Size of the LL is %d\n",llsize);

    if((pos < 1)||(pos > llsize))
    {
        printf("Invalid Position\n");
        return;
    }
    else if(pos == 1)
    {
        DeleteFirst(head);
    }
    else if(pos == llsize)
    {
        DeleteLast(head);
    }
    else
    {
        for(int i = 1 ; i < pos-1 ; i++)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
    


}
int main()
{
    PNODE first = NULL;

    printf("Welcome to the application of Singly Linked List\n");
    printf("Choice to be selected from below\n");
    printf("------------------------------------------------------------\n");
    printf("1.InsertFirst\n");
    printf("2.InsertLast\n");
    printf("3.InsertAtPos\n");
    printf("4.DeleteFirst\n");
    printf("5.DeleteLast\n");
    printf("6.DeleteAtPos\n");
    printf("7.Display Linked list\n");
    printf("8.Count of elements in linked list\n");
    
    printf("0.Exit application\n");
     printf("------------------------------------------------------------\n");


    
    int choice = 1;
    int no;
    int iCnt = 0;
    int pos = 0;

    while(choice != 0)
    {
        printf("Enter your choice : \n");
        scanf("%d",&choice);

        if((choice < 1) || (choice > 8))
        {
            printf("Invalid Choice\n");
            printf("Please Enter valid choice from range 1 to 8\n");
            
        }
        switch (choice)
        {
        case 1: 
            
            printf("Enter element to be Inserted at first position\n");
            scanf("%d",&no);
            InsertFirst(no,&first);
            break;

        case 2:
            printf("Enter element to be Inserted at last position\n");
            scanf("%d",&no);
            InsertLast(&first,no);
            break;

        case 3:
            printf("Enter the position where  you wish to inert the element:\n");
            scanf("%d", &pos);

            printf("Enter the element to be Inserted at the given position :\n");
            scanf("%d", &no);

            InsertAtPos(no,pos,&first);
            break;
        

        case 4:
            DeleteFirst(&first);
            printf("First node deleted successfully\n");
            break;


        case 5:
            DeleteLast(&first);
             printf("Last node deleted successfully\n");
            break;


        case 6:
            printf("Enter the position you want to delete:\n");
            scanf("%d",&pos);
            DeleteAtPos(pos,&first);
            printf("Node of position %d deleted successfully\n",pos);
            break;

        case 7:
            Display(first);
            break;

        case 8:
            iCnt = Count(first);
            printf("Count of element in LL is %d\n", iCnt); 
            break;



       

        
        default:
            break;
        }

    }


    
    return 0;
}