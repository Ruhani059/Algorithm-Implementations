#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
int arr[size];
int n = 0;
struct database
{
    struct database *left;
    int data;
    struct database *right;
};

typedef struct database list;

list *head=NULL;

void insert_by_value (int i)
{
    printf("\nYour Entry is Procesing...\n");
    list *new_list, *current;
    new_list = ( list* ) malloc ( sizeof ( list ) );
    new_list->left=NULL;
    new_list->data=i;
    new_list->right=NULL;
    if(head==NULL)
    {
        head=new_list;
        //head->right=NULL;
        printf("%d is Successfully added.\n",head->data);
    }
    else
    {
        current=head;
        while(current->right != NULL)
        {
            current=current->right;
        }
        current->right=new_list;
        new_list->left=current->right;
        printf("%d is Successfully added.\n",current->right->data);
    }
}

void display ()
{
    if(head==NULL)
    {
        printf("\n\nLinked List is not Created or Empty...\n\n");
        return;
    }
    printf("\nYour List is Printing...\n");
    list *current;
    current = head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->right;
    }
    printf("\n");
}

void delete_by_value (int i)
{
    printf("\nIn Delete Function:\n");
    list *current, *previous;
    current=head;
    previous=NULL;
    if(head==NULL)
    {
        printf("\nSorry. List is not Created or Empty...\nTry again...\n");
        return;
    }
    if(current->data==i)
    {
        printf("%d is being deleted within a few second...\n",current->data);
        head=current->right;
        free(current);
        printf("...Deletion Successful...\n");
    }
    else
    {
        while(current!=NULL)
        {
            if(current->data==i)
                break;
            previous=current;
            current=current->right;
        }
        if(current==NULL)
        {
            printf("Sorry. Deletion can't be done.\nYour Entry %d isn't in the List...\n",i);
        }
        else if (current->right==NULL && current->data==i)
        {
            printf("%d is being deleted within a few second (This is the last element of the list)...\n",current->data);
            previous->right=NULL;
            free(current);
            printf("...Deletion Successful\n");
        }
        else
        {
            printf("%d is being deleted within a few second...\n",current->data);
            previous->right=current->right;
            //current->right->left=current->left;
            current->right->left=previous->right;
            free(current);
            printf("...Deletion Successful\n");
        }
    }
}

void array (void)
{
    int i,j,count=0;
    list *current;
    current = head;
    while(current!=NULL)
    {
        for(j=0;j<n;j++)
        {
            if(arr[j]==current->data)
            {
                count++;
                break;
            }
        }
        if(count==0)
        {
            delete_by_value(current->data);
        }
        count=0;
        current = current->right;
    }
}

int main()
{
    int i,j;
    printf("\nEnter a value to insert: \nPress  -1 to Finish Inserting...\n");
    scanf("%d",&i);
    while(i!=-1)
    {
        insert_by_value(i);
        scanf("%d",&i);
    }
    display();
    printf("Enter Array Size\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    array();
    printf("Displaying Linked List\n");
    display();
    free(head);
    return 0;
}
