#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<queue>
#define SIZE 13
using namespace std;

struct node;

struct LinkList
{
    int element;
    LinkList *next;
};

struct node
{
    LinkList *list;
};

class Hashing
{
public:
    node nodeArray[SIZE];
    Hashing();
    LinkList *search(int  value);
    void insert(int  value);
    void Delete (int  value);
    void show();
    int hashCode(int x);
};

Hashing::Hashing()
{
    for(int i=0;i<SIZE;i++)
    {
        nodeArray[i].list = new LinkList;
        nodeArray[i].list = NULL;
    }
}

LinkList* Hashing::search(int  value)
{
    cout<<"searching...\n";
    int key = hashCode(value);
    LinkList *temp = nodeArray[key].list;
    cout<<temp<<endl;
    cout<<temp->element<<endl;
    while(temp!=NULL)
    {
        if(temp->element == value)
        {
            cout<<"searched successful\n";
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void Hashing::insert(int value)
{
    cout<<"inserting...\n";
    LinkList *newLinkList = new LinkList;
    newLinkList->element = value;
    newLinkList->next = NULL;
    int key = hashCode(value);
    if(nodeArray[key].list==NULL)
    {
        nodeArray[key].list = newLinkList;
    }

    else
    {
        LinkList *temp = nodeArray[key].list;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        //temp->next = new LinkList;
        temp->next = newLinkList;
    }
}

void Hashing::Delete(int value)
{
    cout<<"deleting...\n";
    LinkList* current = search(value);
    cout<<"current "<<current->element<<endl;
    if(current->element == value)
    {
        int key = hashCode(value);
        LinkList* tempList = nodeArray[key].list;
        if(tempList->element == value)
        {
            nodeArray[key].list = tempList->next;
            delete tempList;
        }
        else
        {
            while(tempList->next != current)
            {
                tempList = tempList->next;
            }
            tempList->next = current->next;
            delete current;
        }
    }
    else
        cout<<"value was not found.\n";
}

void Hashing::show()
{
    int i=0;
    while(i<SIZE)
    {
        cout<<i<<":\t";
        LinkList *tempList = nodeArray[i++].list;
        if(tempList!=NULL)
        {
            while(tempList!=NULL)
            {
                cout<<tempList->element<<"\t";
                tempList = tempList->next;
            }
        }
        cout<<endl;
    }
}

int Hashing::hashCode(int x)
{
    return x%SIZE;
}

class operationHashing
{
public:
    static void inputHashing();
    static void readFromFile(Hashing &H);
};

void operationHashing::inputHashing()
{
        ofstream fout ("HashingOffline.txt");

        if(!fout)
        {
            cout<<"Can't open.\n";
            exit(-1);
        }

        int value = 0;
        cin>>value;

        while(value != -1)
        {
            fout<<value<<endl;
            cin>>value;
        }

        fout.close();
}

void operationHashing::readFromFile(Hashing &H)
{
    ifstream fin ("HashingOffline.txt");
    if(!fin)
    {
        cout<<"cannot open HashingOffline.txt\n";
        exit(-1);
    }

    int value;

    while(!fin.eof())
    {
        fin>>value;
        H.insert(value);
    }

    fin.close();
}

int main()
{
    Hashing H;
    //operationHashing::inputHashing();
    operationHashing::readFromFile(H);
    H.show();
    cout<<"1.insert\n2.seach\n3.delete\n";
    cout<<"Enter your Choice.\t";
    int choose = 0;
    int value;
    cin>>choose;
    while(choose != -1)
    {
        cout<<"insert a value to perform the action.\t";
        cin>>value;
        if(choose == 1)
        {
            H.insert(value);
            H.show();
        }
        if(choose == 2)
        {
            if(H.search(value))
            {
                cout<<"search hit.\n";
            }
            else
                cout<<"search miss\n";
        }
        if(choose == 3)
        {
            H.Delete(value);
            cout<<"main";
            H.show();
        }
        cout<<"Enter your Choice.\t";
        cin>>choose;
    }
    return 0;
}
