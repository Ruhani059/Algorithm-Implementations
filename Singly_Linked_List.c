#include <stdio.h>
#include <stdlib.h>

#define true 1

struct node
{
    int data;
    struct node *next;
};

void insert_data();
void delete_data();
void search_data();
void display_data();

struct node *head=NULL;

int main()
{
    int option;

    printf("---------------------------This is Singly Linked List---------------------------\n");

    while(true)
    {
        printf("Choose any of the options below\n");
        printf("1. Insert data\n");
        printf("2. Delete data\n");
        printf("3. Search data\n");
        printf("4. Display data\n");
        printf("5. Exit\n\n");

        scanf("%d", &option);

        if(option==1) insert_data();
        else if(option==2) delete_data();
        else if(option==3) search_data();
        else if(option==4) display_data();
        else exit(0);
    }

    free(head);

    return 0;
}

// Insertion of data by indexing

void insert_data()
{
    static int count_element=0; // it counts how many elements are in the list
    int index,count_index=0;

    printf("Enter index: ");
    scanf("%d", &index);

    // if index is out of range, shows error

    if(index>count_element)
    {
        printf("\nIndex Allocation Error\n\n");
        return;
    }

    struct node *temp=NULL,*copy_head=head,*prev=NULL;

    temp=(struct node *) malloc(sizeof(struct node));

    int data;
    printf("\nEnter data: ");  // input of data
    scanf("%d",&temp->data);

    temp->next=NULL;

    // Initialization of list

    if(index==0 && head==NULL)
    {
        head=temp;
        ++count_element;
    }

    // Insertion at begining of the list

    else if(index==0 && head!=NULL)
    {
        temp->next=head;
        head=temp;
        ++count_element;
    }

    // Insertion in the middle of the list

    else if(index>0 && index<count_element)
    {
        count_index=0;

        while(count_index!=index)
        {
            prev=copy_head;
            copy_head=copy_head->next;
            ++count_index;
        }

        temp->next=copy_head;
        prev->next=temp;

        ++count_element;
    }

    // Insertion at the end of the list

    else if(index==count_element)
    {
        count_index=0;

        while(count_index!=index)
        {
            prev=copy_head;
            copy_head=copy_head->next;
            ++count_index;
        }

        temp->next=NULL;
        prev->next=temp;

        ++count_element;
    }

    printf("\n\n");
}

// Deletion of data by indexing

void delete_data()
{
    if(head==NULL)
    {
        printf("\n\nThe List is empty.\n\n");
        return;
    }

    struct node *cur=head,*prev=NULL;
    int index,count_element=0;

    printf("\nEnter index: ");
    scanf("%d",&index);

    // if the very first element is to be deleted

    if(index==0)
    {
        cur=cur->next;
        head=cur;
    }

    // deletion of elements other than the very first one

    else
    {
        while(count_element!=index)
        {
            prev=cur;
            cur=cur->next;
            ++count_element;

            // if input index is greater than the list index

            if(cur==NULL)
            {
                printf("\nIndex Out of Range!!\n\n");

                return;
            }
        }

        prev->next=cur->next;
    }

    printf("\nData successfully deleted.\n\n");
}

// searching data by indexing and value

void search_data()
{
    if(head==NULL)
    {
        printf("\n\nThe List is empty.\n\n");
        return;
    }

    int option,index,value,count_element=0;
    struct node *temp=head;

    printf("\nChoose any of the options below\n");
    printf("1. Search by index\n");
    printf("2. Search by value\n\n");

    scanf("%d",&option);

    // searching by index

    if(option==1)
    {
        printf("Enter index: ");
        scanf("%d",&index);

        while(count_element!=index)
        {
            temp=temp->next;
            ++count_element;

            if(temp==NULL)
            {
                printf("\nIndex Out of Range!!\n\n");
                return;
            }
        }

        printf("Data: %d\n\n", temp->data);
    }

    // searching by value

    else if(option==2)
    {
        printf("Enter value: ");
        scanf("%d",&value);

        while(temp->data!=value)
        {
            temp=temp->next;
            ++count_element;

            // if such data does not exist

            if(temp==NULL)
            {
                printf("\nNo such data exists!!\n\n");
                return;
            }
        }

        printf("Index: %d\n\n", count_element);
    }
}

void display_data()
{
    if(head==NULL)
    {
        printf("\n\nThe List is empty.\n\n");
        return;
    }

    struct node *temp=head;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);

        temp=temp->next;
    }

    printf("\n\n");
}
