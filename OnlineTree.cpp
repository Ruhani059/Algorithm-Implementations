#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
using namespace std;
int countCost =  0;
char arr[100];
int size = 0;
int N;

struct node
{
    char element;
    int cost;
    node *parentNode;
    node *leftChild;
    node *rightChild;
    node *next;
};

class tree
{
    node *root;
    node *listNode;
    node* findRoot(node *root);

public:
    tree();
    ~tree();
    void insertNode(char p,int cost);
    node *searchNode (char p);
    void construct(char p, char l, char r);
    void preOrder();
    int depth(char v);
    node* getRoot();
    node* getNodeList();
    void preOrder(node *root);
};

tree::tree()
{
    root = NULL;
    listNode = NULL;
}

tree::~tree()
{
    delete root;
    delete listNode;
}

node* tree::searchNode(char p)
{
    if(listNode==NULL)
        return NULL;

    node* temp;

    if(listNode->element==p)
    {
        return listNode;
    }

    else
    {
        temp = listNode->next;

        while(temp!=NULL)
        {
            if(temp->element == p)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
}

void tree::insertNode(char p,int cost)
{
    node *temp;
    node *newNode = new node;

    newNode->element = p;
    newNode->cost = cost;
    newNode->parentNode = NULL;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->next = NULL;

    if(listNode == NULL)
    {
        listNode = newNode;
    }
    else
    {
        if(!searchNode(p) && p!='#')
        {
            temp = listNode;

            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

node* tree::findRoot(node *findroot)
{
    while(findroot!=NULL)
    {
        if(findroot->parentNode==NULL)
        {
            return findroot;
            break;
        }

        findroot = findroot->next;
    }
}

node* tree::getRoot()
{
    return root;
}

void tree::construct(char p, char l, char r)
{
    node* tempP = searchNode(p);
    node* tempL = searchNode(l);
    node* tempR = searchNode(r);

    if(tempL==NULL && tempR!=NULL)
    {
        tempP->leftChild = NULL;
        tempP->rightChild = tempR;
        tempR->parentNode = tempP;
    }

    else if(tempR==NULL && tempL!=NULL)
    {
        tempP->leftChild = tempL;
        tempP->rightChild = NULL;
        tempL->parentNode = tempP;
    }

    else if(tempR==NULL && tempL==NULL)
    {
        tempP->leftChild = NULL;
        tempP->rightChild = NULL;
    }

    else if(tempL!=NULL && tempR!=NULL)
    {
        tempP->leftChild = tempL;
        tempP->rightChild = tempR;
        tempL->parentNode = tempP;
        tempR->parentNode = tempP;
    }
    root = findRoot(listNode);
}

void tree::preOrder(node *root)
{
    if(root==NULL)
        return;

    else
    {
        cout<<root->element<<"\t";
        arr[size++]=root->element;

        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}

int tree::depth(char v)
{
    node *temp=searchNode(v);

    if(temp == root)
    {
        return countCost+=root->cost;
    }
    else
    {
        countCost+=temp->cost;
        return depth(temp->parentNode->element);
    }
}

node* tree::getNodeList()
{
        return listNode;
}

class operationTree
{
public:
    static void readFromFile(tree &T);
};

void operationTree::readFromFile(tree &T)
{
    ifstream fin ("treeInput.txt");

    if(!fin)
    {
        cout<<"cannot open treeInput.txt\n";
        exit(-1);
    }

    string str;
    int cost;
    fin>>N; //number of nodes.
    //cout<<N<<endl;

    for(int i=0;i<N;i++)
    {
        fin>>str;
        fin>>cost;
        char v;
        v=str[0];
        //cout<<str<<"\n";
        T.insertNode(v,cost);
    }

    while(!fin.eof())
    {
        fin>>str;

        char p,l,r;
        p = str[0];
        l = str[2];

        if(str.size()==5) r = str[4];

        else r='\0';

        //cout<<p<<"."<<l<<"."<<r<<"\n";

        T.construct(p,l,r);
    }

    fin.close();
}

int main()
{
    tree T;
    operationTree::readFromFile(T);

    T.preOrder(T.getRoot());
    cout<<endl;

    for(int i=0;i<N;i++)
    {
        cout<<T.depth(arr[i])<<"\t";
        countCost = 0;
    }
    return 0;
}
