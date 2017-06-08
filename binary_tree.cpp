#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
using namespace std;

struct node
{
    char element;
    node *parentNode;
    node *leftChild;
    node *rightChild;
    node *next;
};

class tree
{
    node *root;
    node *listNode;
    void inOrder(node *root);
    void inOrder(char v);
    void preOrder(node *root);
    void postOrder(node *root);
    node* findRoot(node *root);

public:
    tree();
    ~tree();
    void insertNode(char p);
    node *searchNode (char p);
    void construct(char p, char l, char r);
    void nodeInformation(char p);
    bool isInternal(char v);
    bool isExternal(char v);
    bool isInternal(node *temp);
    bool isExternal(node *temp);
    node *LeftChild(char v);
    node *RightChild(char v);
    node *LeftChild(node *temp);
    node *RightChild(node *temp);
    void inOrder();
    void preOrder();
    void postOrder();
    int depth(char v);
    int height2(node *root);
    int height2(char v);
    node* getRoot();
    node* getNodeList();
    void constructTreeManually(tree &T);
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

void tree::insertNode(char p)
{
    node *temp;
    node *newNode = new node;

    newNode->element = p;
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

void tree::nodeInformation(char p)
{
    node* temp = searchNode(p);

    cout<<"\n\nnode :"<<temp->element<<endl;

    if(temp->parentNode!=NULL)
    {
        cout<<"parent :"<<temp->parentNode->element<<endl;
    }

    if(temp->leftChild!=NULL)
    {
        cout<<"leftChild :"<<temp->leftChild->element<<endl;
    }

    if(temp->rightChild!=NULL)
    {
        cout<<"righttChild :"<<temp->rightChild->element<<endl;
    }
}

bool tree::isInternal(char v)
{
    node *temp = searchNode(v);

    if(temp)
    {
        if(temp->leftChild!=NULL || temp->rightChild!=NULL)
            return true;

        return false;
    }
    return false;
}

bool tree::isExternal(char v)
{
    node *temp = searchNode(v);

    if(temp)
    {
        if(temp->leftChild==NULL && temp->rightChild==NULL)
            return true;

        return false;
    }
    return false;
}

bool tree::isInternal(node *temp)
{
    if(temp->leftChild!=NULL || temp->rightChild!=NULL)
        return true;

    return false;
}

bool tree::isExternal(node *temp)
{
    if(temp->leftChild==NULL && temp->rightChild==NULL)
        return true;

    return false;
}

node* tree::LeftChild(char v)
{
    node *temp = searchNode(v);

    if(temp)
    {
        return temp->leftChild;
    }
    return NULL;
}

node* tree::RightChild(char v)
{
    node *temp = searchNode(v);

    if(temp)
    {
        return temp->rightChild;
    }
    return NULL;
}

node* tree::LeftChild(node *temp)
{
    return temp->leftChild;
}

node* tree::RightChild(node *temp)
{
    return temp->rightChild;
}

void tree::preOrder(node *root)
{
    if(root==NULL)
        return;

    else
    {
        cout<<root->element<<"  ";
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}

void tree::preOrder()
{
    preOrder(root);
}

void tree::inOrder(node *root)
{
    if(root==NULL)
        return;

    else
    {
        inOrder(root->leftChild);
        cout<<root->element<<"  ";
        inOrder(root->rightChild);
    }
}

void tree::inOrder(char v)
{
    if(isInternal(v))
        inOrder(LeftChild(v));

    cout<<v<<"  ";

    if(isInternal(v))
        inOrder(RightChild(v));
}

void tree::inOrder()
{
    inOrder(root);
}

void tree::postOrder(node *root)
{
    if(root==NULL)
        return;

    else
    {
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        cout<<root->element<<"  ";
    }
}

void tree::postOrder()
{
    postOrder(root);
}

int tree::height2(char v)
{
    node *temp;
    temp = searchNode(v);
    height2(temp);
}

int tree::height2(node *Node)
{
    if(Node == NULL)
        return 0;

    if(isExternal(Node))
        return 0;

    else
    {
        int h;
        h = 0;
        h = max(h,height2(LeftChild(Node)));
        h = max(h,height2(RightChild(Node)));
        return 1+h;
    }
}

node* tree::getNodeList()
{
        return listNode;
}

int tree::depth(char v)
{
    node *temp=searchNode(v);

    if(temp == root)
        return 0;
    else
    {
        return 1+depth(temp->parentNode->element);
    }
}

void tree::constructTreeManually(tree &T)
{
        char p,l,r;
        cout<<"insert parentNode :\t";
        cin>>p;
        T.insertNode(p);
        cout<<"insert leftChild\t";
        cin>>l;
        T.insertNode(l);
        cout<<"insert rightChild\t";
        cin>>r;
        T.insertNode(r);
        T.construct(p,l,r);
}

class operationTree
{
public:
    static void inputTree(tree &T);
    static void readFromFile(tree &T);
};

void operationTree::inputTree(tree &T)
{
        ofstream fout ("treeInput.txt");

        if(!fout)
        {
            cout<<"Can't open.\n";
            exit(-1);
        }

        int N;
        cin>>N;
        fout<<N;
        string str;
        cin>>str;

        while(str!="end")
        {
            fout<<str;
            fout<<"\n";
            cin>>str;
        }

        fout.close();
}

void operationTree::readFromFile(tree &T)
{
    ifstream fin ("treeInput.txt");

    if(!fin)
    {
        cout<<"cannot open treeInput.txt\n";
        exit(-1);
    }

    string str;

    int N;
    fin>>N;
    //cout<<N<<endl;

    for(int i=0;i<N;i++)
    {
        fin>>str;
        char v;
        v=str[0];
        //cout<<str<<"\n";
        T.insertNode(v);
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
    int a=0;
    cout<<"Do you want to run the program again? if yes enter 1. else 0\n\n";
    cin>>a;
    while(a)
    {
        tree T;
        int input = 0;
        cout<<"\nTo build a new tree, press 1. Otherwise press 0.\n\n";
        cin>>input;

        if(input)
        {
            operationTree::inputTree(T);
        }

        operationTree::readFromFile(T);

        ifstream fin ("treeInput.txt");

        if(!fin)
        {
            cout<<"cannot open treeInput.txt\n";
            return -1;
        }

        int N;
        fin>>N;
        //cout<<N<<endl;

        cout<<"\nInorder :\n";
        T.inOrder();

        cout<<"\npreorder :\n";
        T.preOrder();

        cout<<"\nPostOrder :\n";
        T.postOrder();
        cout<<endl;
/*
        for(char i='a';i<'a'+N;i++)
        {
            cout<<"depth of node "<<i<<" is "<<T.depth(i)<<endl;
        }

        for(char i='a';i<'a'+N;i++)
        {
            cout<<"height of node "<<i<<" is "<<T.height2(i)<<endl;
        }
*/
        cout<<"\nheight of the Tree is = "<<T.height2(T.getRoot())<<endl<<endl;

        cout<<"\nTo insert a new node and children manually, press 1. otherwise 0.\n";
        int checkInsetNode = 0;
        cin>>checkInsetNode;
        while(checkInsetNode)
        {
            T.constructTreeManually(T);
            cout<<"\nTo insert a new node and children manually, press 1. otherwise 0.\n";
            cin>>checkInsetNode;
        }

        cout<<"\nInorder :\n";
        T.inOrder();

        cout<<"\npreorder :\n";
        T.preOrder();

        cout<<"\nPostOrder :\n";
        T.postOrder();
        cout<<endl;
/*
        for(char i='a';i<'a'+N;i++)
        {
            cout<<"depth of node "<<i<<" is "<<T.depth(i)<<endl;
        }
*/
        cout<<"\nDo you want to run the program again? if yes enter 1. else 0\n\n";
        cin>>a;
    }
    return 0;
}
