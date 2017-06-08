#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

struct node
{
    int data;
    node *next;
};

class linklist
{
private:
    node *head;
    void insert (int key,node *link);
    void delete_by_value (int key,node *link);
    void search (int key,node *link);
    void destroy_linklist(node *link);
    void show (node *link);
public:
    linklist();
    ~linklist();
    void insert (int key);
    void delete_by_value (int key);
    void search (int key);
    void show ();
    void destroy_linklist();
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
    static node *prev_link;
    if (link!=NULL)
    {
        if(key!=link->data)
        {
            prev_link = link;
            delete_by_value(key,link->next);
        }
        else
        {
            prev_link->next = link->next;
            delete link;
            cout<<"deleted\n";
        }
    }
}

void linklist::delete_by_value(int key)
{
    if (key == head->data)
    {
        node *link;
        link = head;
        head = head->next;
        delete link;
    }
    else
    {
        delete_by_value(key,head);
    }
}

void linklist::search(int key,node *link)
{
    if (link!=NULL)
    {
        if(key!=link->data)
        {
            search(key,link->next);
        }
        else
        {
            cout<<"search hit\n";
        }
    }
}

void linklist::search(int key)
{
    search(key,head);
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
    show(head);
}

int main()
{
    int N,key;
    cin>>N;
    linklist a;
    for(int i=0;i<N;i++)
    {
        cin>>key;
        a.insert(key);
    }
    a.show();
    cout<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<"wanna seach...\n";
        cin>>key;
        a.search(key);
        cout<<"wanna delete...\n";
        cin>>key;
        a.delete_by_value(key);
        a.show();
        cout<<endl;
    }
    return 0;
}
