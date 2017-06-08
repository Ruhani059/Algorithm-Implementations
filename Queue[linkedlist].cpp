#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};

class linklist : public node
{
private:
    node *head;
    void insert (int key,node *link);
    void delete_by_value (int key,node *link);
    void delete_by_link (node *link);
    node* search (int key,node *link);
    void destroy_linklist(node *link);
    void show (node *link);
public:
    linklist();
    ~linklist();
    void insert (int key);
    void delete_by_value (int key);
    void delete_by_link ();
    node* search (int key);
    void show ();
    void destroy_linklist();
    bool isEmpty();
};

linklist::linklist()
{
    head = NULL;
}

linklist::~linklist()
{
    destroy_linklist();
}

void linklist::destroy_linklist(node *link)
{
    if(link!=NULL)
    {
        destroy_linklist(link->next);
        delete link;
    }
}

void linklist::destroy_linklist()
{
    destroy_linklist(head);
}

void linklist::insert(int key , node *link)
{
    if(link->next!=NULL)
    {
        insert(key,link->next);
    }
    else
    {
        link->next = new node;
        link->next->data = key;
        link->next->next = NULL;
    }
}

void linklist::insert(int key)
{
    if (head == NULL)
    {
        head = new node;
        head->data = key;
        head->next = NULL;
    }
    else
    {
        insert(key,head);
    }
}

void linklist::delete_by_value(int key,node *link)
{
    node *prev_link = link;
    node *link_delete;
    link_delete = search(key,link);
    if(link_delete)
    {
        while(prev_link->next != link_delete)
            prev_link = prev_link->next;

        prev_link->next = link_delete->next;
        delete link_delete;
        cout<<"deleted\n";
    }
    else
    {
        cout<<"not found\n";
    }
}

void linklist::delete_by_value(int key)
{
    if(isEmpty())
    {
        node *cur;
        if(head->data == key)
        {
            cur = head;
            head = head->next;
            delete cur;
            cout<<"deleted\n";
        }
        else
        {
            delete_by_value(key,head);
        }
    }
}

node* linklist::search(int key,node *link)
{
    if (link!=NULL)
    {
        if(key!=link->data)
        {
            return search(key,link->next);
        }
        else
        {
            cout<<"search hit\n";
            return link;
        }
    }
    else
    {
        cout<<"search miss\n";
        return NULL;
    }
}

node* linklist::search(int key)
{
    if (isEmpty())
    {
        return search(key,head);
    }
}

void linklist::show(node *link)
{
    if(link!=NULL)
    {
        cout<<link->data<<" ";
        show(link->next);
    }
}

void linklist::show()
{
    if(head == NULL)
    {
        cout<<"list empty\n";
    }
    else
    {
        show(head);
    }
}

bool linklist::isEmpty()
{
    if(head == NULL)
    {
        cout<<"list is empty\n";
        return false;
    }
    else
    {
        //cout<<"list is not empty\n";
        return true;
    }
}

void linklist::delete_by_link(node *link)
{
}

void linklist::delete_by_link()
{
    node *cur = head;
    head = head->next;
    delete cur;
    cout<<"deleted\n";
}

class Queue : public linklist
{
public:
    void enqueue(int key);
    void dequeue();
};

void Queue::enqueue(int key)
{
    insert(key);
}

void Queue::dequeue()
{
    if(isEmpty())
    {
        delete_by_link();
    }
    else
    {
        cout<<"list is empty.\n";
    }
}

int main()
{
    int N;
    Queue queue;
    int choice = -1;
    cout<<"1.enque\n2.dequeue\n3.Show Queue\n";
    cin>>choice;
    while(choice != 0)
    {
        switch (choice)
        {
            case 1:
            {
                int num;
                cin>>num;
                queue.enqueue(num);
                queue.show();
                break;
            }
            case 2:
            {
                queue.dequeue();
                queue.show();
                break;
            }
            case 3:
            {
                cout<<"\nshowing\n";
                queue.show();
                cout<<"\n";
                break;
            }
        }
        cout<<"\n1.enque\n2.dequeue\n3.Show Queue\n";
        cin>>choice;
    }
    return 0;
}
