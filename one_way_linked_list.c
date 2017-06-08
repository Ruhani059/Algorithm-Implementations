#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct database
{
    int data;
    struct database *next;
};

typedef struct database node;

node *head=NULL,  *current=NULL, *previous=NULL;

void insert (int i)
{
    printf("\nYour Entry is Procesing...\n");
    if(current==NULL)
    {
        current = ( node* ) malloc ( sizeof ( node ) );
        current->data = i;
        current->next = NULL;
        head = current;
        printf("\n%d is Successfully added.\n",current->data);
    }
    else
    {
        node *new_node;
        new_node = ( node* ) malloc ( sizeof ( node ) );
        new_node->data=i;
        new_node->next=NULL;
        current=head;
        if( current->data >= i) // inserted in the first.
        {
            new_node->next=current;
            head=new_node;
            printf("\n%d is Successfully added.\n",head->data);
        }
        else
        {
            if(current->next==NULL)
            {
                current->next=new_node;
                printf("\n%d is Successfully added.\n",new_node->data);
            }
            else
            {
                while(current->next->data <= i)
                {
                    current=current->next;
                    if (current->next==NULL)
                        break;
                }
                if(current->next==NULL)
                {
                    current->next=new_node;
                    printf("\n%d is Successfully added.\n",new_node->data);
                }
                else
                {
                    new_node->next=current->next;
                    current->next=new_node;
                    printf("\n%d is Successfully added.\n",new_node->data);
                }
            }
        }
    }
}

void display ()
{
    printf("\nDisplaying The List...\n");
    current=head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}

void search (int i)
{
    current=head;
    while(current->next!=NULL)
    {
        if(current->next->data == i)
            break;
        current=current->next;
    }
    if(current->next==NULL)
    {
        printf("\nDhur Bal. Hudai Khujalam...\n");
    }
    else
    {
        printf("\nYes! Paisi!!! Are you searching %d...\n",current->next->data);
    }
    //return (current->next);
}

void delete_ (int i)
{
    printf("\nIn Delete Function:\n");
    current=head;
    previous=head->next;
    if(current->data==i)
    {
        printf("\n%d is being deleted within a second...\n",current->data);
        head=current->next;
        free(current);
        printf("\nDeletion Successful.\n");
    }
    else
    {
        if(previous->data==i)
        {
            printf("\n%d is being deleted within a second.\n",previous->data);
            current->next=NULL;
            free(previous);
            printf("\nDeletion Successful\n");
        }
        else
        {
            while(previous->next!=NULL)
            {
                if(previous->next->data==i)
                    break;
                previous=previous->next;
            }
            if(previous->next==NULL)
            {
                printf("\nSorry. Deletion can't be done.\nYour Entry %d isn't in the List...\n",i);
            }
            else
            {
                printf("\n%d is being deleted within a second.\n",previous->next->data);
                current=previous->next;
                previous->next=previous->next->next;
                free(current);
                printf("\nDeletion Successful\n");
            }
        }
    }
}

int main()
{
    char ch;
    int i;
    printf("Linklist:\n1.Create a Linklist.\n2.Search a Value.\n3.Delete a value.\n4.Display the List.\n5.Exit...\n\n");
    while((ch=getch())!=EOF)
    {
        switch(ch)
        {
            case '1':
                printf("\nEnter a value to insert:\n");
                scanf("%d",&i);
                insert(i);
                break;
            case '2':
                printf("\nEnter a value to search:\n");
                scanf("%d",&i);
                search(i);
                break;
            case '3':
                printf("\nEnter a value to delete:\n");
                scanf("%d",&i);
                delete_(i);
                break;
            case '4':
                display();
                break;
            case '5':
                exit(0);
        }
        printf("\nLinklist:\n1.Create a Linklist.\n2.Search a Value.\n3.Delete a value.\n4.Display the List.\n5.Exit...\n\n");
    }
    free(head);
    return 0;
}

