#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void insertion_sort (int i)
{
    printf("\nYour Entry is Procesing...\n");
    list *new_list, *current, *previous;
    new_list = ( list* ) malloc ( sizeof ( list ) );
    new_list->left=NULL;
    new_list->data=i;
    new_list->right=NULL;
    current=head;
    previous=NULL;
    if(head==NULL)
    {
        head=new_list;
        head->right=NULL;
        printf("\n%d is Successfully added at first.\n",new_list->data);
    }
    else
    {
        if (head->data >= i)
        {
            new_list->right=current;
            current->left=new_list;
            head=new_list;
            head->left=NULL;
            printf("\n%d is Successfully added at first.\n",head->data);
        }
        else
        {
            while(current!= NULL)
            {
                if(current->data >= i)
                    break;
                previous=current;
                current=current->right;
            }
            if(current==NULL)
            {
                previous->right=new_list;
                new_list->left=previous;
                printf("\n%d is Successfully added at last.\n",previous->right->data);
            }
            else
            {
                new_list->left=previous;
                new_list->right=current;
                previous->right=new_list;
                current->left=new_list;
                printf("\n%d is Successfully added in the middle.\n",current->left->data);
                printf("\n%d is Successfully added in the middle.\n",previous->right->data);
            }
        }
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

void rev_display ( list *current)
{
    if(current==NULL)
        return;
    else
    {
        rev_display(current->right);
        printf("%d ",current->data);
    }
}

void search_by_value (int i)
{
    printf("\nSearching...\n");
    list *current;
    current=head;
    if(head==NULL)
    {
        printf("\nSorry. List is not Created or Empty...\nTry again...\n");
        return;
    }
    if(current->data==i)
    {
        printf("\nYes! Paisi!!! You are searching for %d.\n",current->data);
        return;
    }
    else if(current->data!=i && current->right==NULL)
    {
        printf("\nSorry. The value you are searching is not in the list...\nTry again...\n\n");
        return;
    }
    else
    {
        while(current!=NULL)
        {
            if(current->data == i)
                break;
            current=current->right;
        }
        if(current==NULL)
        {
            printf("\nSorry. The value you are searching is not in the list...\nTry again...\n\n");
        }
        else
        {
            printf("\nYes! Paisi!!! You are searching for %d.\n",current->data);
        }
        return;
    }
    //return (current->next);
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

void sort ()
{
    printf("\nYour List is Sorting...\tPlease wait a while...\n");
    list *previous, *current, *temp, *head_protect;
    temp = ( list * ) malloc (sizeof ( list ) );
    if(head==NULL)
    {
        printf("\n\nLinked List is not Created or Empty...\n\n");
        return;
    }
    current=head->right;
    previous=head;
    while(previous->right!=NULL)
    {
        while(current!=NULL)
        {
            if(current->data < previous->data)
            {
                temp->left=current->left;
                temp->data=current->data;
                temp->right=current->right;
                temp->left=previous->left;
                temp->right=previous;
                previous->left=temp;
                previous->right=current->right;
                if(previous==head)
                {
                    head=temp;
                }
                printf("Mone hoi sort hoitese...\n");
                display();
                printf("\n\n");
            }
            current=current->right;
            display();
            printf("\n\n");
            printf("KIsuta Sort Hoise...\n");
        }
        previous=previous->right;
        current=previous->right;
        printf("Are baba, Hosse to, Dhoirjo dhoro...\n");
        display();
        printf("\n\n");
    }
    //printf("\n*\n");
}

int add ()
{
    list *current;
    int sum=0;
    current=head;
    if(head==NULL)
    {
        printf("\n\nLinked List is not Created or Empty...\n\n");
        return 0;
    }
    else
    {
        while(current!=NULL)
        {
            sum+=current->data;
            current=current->right;
        }
        return sum;
    }
}
int main()
{
    int i,j;
    printf("Linked List:\n\n");
    printf("1.Create or Add a value in Linklist.\n");
    printf("2.Create or Add values by insertion sort.\n");
    printf("3.Search a Value.\n");
    printf("4.Delete a value.\n");
    printf("5.Display the List.\n");
    printf("6.Print Reversively.\n");
    printf("7.Sort the List.\n");
    printf("8.Add.\n");
    printf("9.Exit...\n\n");
    while(scanf("%d",&j)==1)
    {
        switch(j)
        {
            case 1:
                printf("\nEnter a value to insert: \nPress  -1 to Finish Inserting...\n");
                scanf("%d",&i);
                while(i!=-1)
                {
                    insert_by_value(i);
                    scanf("%d",&i);
                }
                break;
            case 2:
                printf("\nEnter a value to insert using insertion sort: \nPress  -1 to Finish Inserting...\n");
                scanf("%d",&i);
                while(i!=-1)
                {
                    insertion_sort (i);
                    scanf("%d",&i);
                }
                break;
            case 3:
                printf("\nEnter a value to search: \nPress  -1 to Finish Searching...\n");
                scanf("%d",&i);
                while(i!=-1)
                {
                    search_by_value (i);
                    scanf("%d",&i);
                }
                break;
            case 4:
                printf("\nEnter a value to delete: \nPress  -1 to Finish Deleting...\n");
                scanf("%d",&i);
                while(i!=-1)
                {
                    delete_by_value(i);
                    scanf("%d",&i);
                }
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\nThe List is Printed Reversively...\n");
                rev_display(head);
                printf("\n\n");
                break;
            case 7:
                printf("\nThe List is being sorted...\n");
                sort();
                //printf("\n\n");
                display();
                printf("\n\n");
                break;
            case 8:
                printf("\nAdd the List...\n");
                int sum;
                sum=add();
                printf("The summation of the all value of thr Linked List is = %d.\n\n",sum);
                break;
            case 9:
                exit(0);
        }
        printf("\n\n1.Create or Add a value in Linklist.\n");
        printf("2.Create or Add values by insertion sort.\n");
        printf("3.Search a Value.\n");
        printf("4.Delete a value.\n");
        printf("5.Display the List.\n");
        printf("6.Print Reversively.\n");
        printf("7.Sort the List.\n");
        printf("8.Add.\n");
        printf("9.Exit...\n\n");
    }
    free(head);
    return 0;
}
