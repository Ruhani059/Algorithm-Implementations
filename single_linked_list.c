#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct database
{
    int data;
    struct database *next;
};

typedef struct database list;

list *head=NULL;

void insert_by_value (int i);
void search_by_value (int i);
void delete_by_value (int i);
void insert_by_index (int i, int value);
void search_by_index (int i);
void delete_by_index (int i);
void display ();
void rev_display ( list *current);
void sort_by_swapping_value ();
int add ();

void insert_by_value (int i)
{
    printf("\nYour Entry is Procesing...\n");
    list *new_list, *current;
    new_list = ( list* ) malloc ( sizeof ( list ) );
    new_list->data=i;
    new_list->next=NULL;
    if(head==NULL)
    {
        head=new_list;
        printf("%d is Successfully added.\n",head->data);
    }
    else
    {
        current=head;
        while(current->next != NULL)
        {
            current=current->next;
        }
        current->next=new_list;
        printf("%d is Successfully added.\n",current->next->data);
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
        current=current->next;
    }
    printf("\n");
}

void rev_display ( list *current)
{
    if(current==NULL)
        return;
    else
    {
        rev_display(current->next);
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
    else if(current->data!=i && current->next==NULL)
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
            current=current->next;
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
        head=current->next;
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
            current=current->next;
        }
        if(current==NULL)
        {
            printf("Sorry. Deletion can't be done.\nYour Entry %d isn't in the List...\n",i);
        }
        else
        {
            printf("%d is being deleted within a few second...\n",current->data);
            previous->next=current->next;
            free(current);
            printf("...Deletion Successful\n");
        }
    }
}

void insert_by_index (int i, int value)
{
    list *current, *previous, *new_list;
    new_list = (list *) malloc(sizeof(list));
    new_list->data=value;
    new_list->next=NULL;
    current=head;
    previous=NULL;
    if(i==1 && head==NULL)
    {
        head=new_list;
        head->next=NULL;
    }
    else if (i==1)
    {
        new_list->next=head;
        head=new_list;
    }
    else if (i!=1)
    {
        int check=i;
        while(check<=i && current->next!=NULL)
        {
            previous=current;
            current=current->next;
            check++;
        }
        if(check==i && current!=NULL)
        {
            previous->next=new_list;
            new_list->next=current;
        }
    }
}
void search_by_index (int i)
{

}

void delete_by_index (int i)
{

}

void sort_by_swapping_value ()
{
    printf("\nYour List is Sorting...\tPlease wait a while...\n");
    list *previous, *current;
    int temp;
    if(head==NULL)
    {
        printf("\n\nLinked List is not Created or Empty...\n\n");
        return;
    }
    current=head->next;
    previous=head;
    while(previous->next!=NULL)
    {
        while(current!=NULL)
        {
            if(current->data < previous->data)
            {
                //printf("Sort Hobe Ekhoni...\n");
                temp=current->data;
                current->data=previous->data;
                previous->data=temp;
                //printf("Sort Hoitese...\n");
            }
            current=current->next;
            //printf("KIsuta Sort Hoise...\n");
        }
        previous=previous->next;
        current=previous->next;
        //printf("Are baba, Hosse to, Dhoirjo dhoro...\n");
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
            current=current->next;
        }
        return sum;
    }
}
int main()
{
    int i,j,k;
    printf("Linked List:\n");
    printf("\n1.Create or Add a value in Linklist.\n2.Search a Value.\n3.Delete a value.\n4.Display the List.\n");
    printf("5.Print Reversively.\n6.Sort the List.\n7.Add.\n8.Exit...\n\n");
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
                printf("\nEnter a value to search: \nPress  -1 to Finish Searching...\n");
                scanf("%d",&i);
                while(i!=-1)
                {
                    search_by_value (i);
                    scanf("%d",&i);
                }
                break;
            case 3:
                printf("\nEnter a value to delete: \nPress  -1 to Finish Deleting...\n");
                scanf("%d",&i);
                while(i!=-1)
                {
                    delete_by_value(i);
                    scanf("%d",&i);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nThe List is Printed Reversively...\n");
                rev_display(head);
                printf("\n\n");
                break;
            case 6:
                printf("\nThe List is being sorted...\n");
                sort_by_swapping_value ();
                //printf("\n\n");
                display();
                printf("\n\n");
                break;
            case 7:
                printf("\nAdd the List...\n");
                int sum;
                sum=add();
                printf("The summation of the all value of thr Linked List is = %d.\n\n",sum);
                break;
            case 8:
                printf("\nEnter an index and a value to insert: \nPress  -1 to Finish Inserting...\n");
                scanf("%d %d",&i,&k);
                while(i!=-1)
                {
                    insert_by_index(i,k);
                    scanf("%d %d",&i,&k);
                }
                break;
            case 9:
                exit(0);
        }
        printf("\n\n1.Create or Add a value in Linklist.\n2.Search a Value.\n3.Delete a value.\n4.Display the List.\n");
        printf("5.Print Reversively.\n6.Sort the List.\n7.Add.\n8.Exit...\n\n");
    }
    free(head);
    return 0;
}
