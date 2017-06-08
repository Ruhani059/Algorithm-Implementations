#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
using namespace std;
int nodeNumber;
struct node;
struct childrenNodes
{
    node *child;
    childrenNodes *nextChild;
};

struct node
{
    char element;
    node *parentNode;
    childrenNodes *childrenList;
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

    void insertNode(char p);
    node *searchNode (char p);

    void constructTree(char parent, char child);
    void constructTreeManually(tree &T);

    void nodeInformation(char p);

    bool isInternal(char v);
    bool isInternal(node *temp);

    bool isExternal(char v);
    bool isExternal(node *temp);

    childrenNodes *children(char v);
    childrenNodes *children(node *temp);

    void preOrder(node *temp);
    void postOrder(node *temp);

    int depth(char v);
    int height2(node *temp);

    node* getRoot();
    node* getNodeList();
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
    node* temp=listNode;

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

void tree::insertNode(char p)
{
    node *temp;
    node *newNode = new node;

    newNode->element = p;
    newNode->parentNode = NULL;
    newNode->childrenList = new childrenNodes;
    newNode->childrenList = NULL;
    newNode->next = NULL;

    if(listNode == NULL)
    {
        listNode = newNode;
    }
    else
    {
        if(!searchNode(p))
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

void tree::constructTree(char parent, char child)
{
    node* tempParent = searchNode(parent);
    node* tempChild = searchNode(child);

    childrenNodes* tempList = tempParent->childrenList;

    childrenNodes *newChild = new childrenNodes;
    newChild->child = tempChild;
    newChild->nextChild = NULL;

    if(tempChild)
    {
        tempChild->parentNode=tempParent;

        if(tempParent->childrenList==NULL)
        {
            tempParent->childrenList = newChild;
        }

        else
        {
            while(tempList->nextChild!=NULL)
            {
                tempList = tempList->nextChild;
            }
            tempList->nextChild = newChild;
        }
    }
    root = findRoot(listNode);
}

void tree::nodeInformation(char p)
{
    node* temp = searchNode(p);
    childrenNodes *tempList = temp->childrenList;

    cout<<"\n\nnode : "<<temp->element<<endl;

    if(temp->parentNode!=NULL)
    {
        cout<<"parent : "<<temp->parentNode->element<<endl;
    }

    cout<<"Childrens are : ";
    while(tempList!=NULL)
    {
        cout<<tempList->child->element<<"\t";
        tempList=tempList->nextChild;
    }
    cout<<"\n";
}

//private function. finds the root of the  tree and return its link.
node* tree::findRoot(node *temp)
{
    while(temp!=NULL)
    {
        if(temp->parentNode==NULL)
        {
            return temp;
            break;
        }
        temp = temp->next;
    }
}

node* tree::getRoot()
{
    return root;
}

childrenNodes* tree::children(node *temp)
{
    return temp->childrenList;
}

childrenNodes* tree::children(char v)
{
    node *temp = searchNode(v);
    return temp->childrenList;
}

bool tree::isInternal(char v)
{
    node *temp = searchNode(v);
    isInternal(temp);
}

bool tree::isExternal(char v)
{
    node *temp = searchNode(v);
    isExternal(temp);
}

bool tree::isInternal(node *temp)
{
    if(temp->childrenList!=NULL)
        return true;

    return false;
}

bool tree::isExternal(node *temp)
{
    if(temp->childrenList==NULL)
        return true;

    return false;
}

void tree::preOrder(node *root)
{
    if(root==NULL)
        return;

    else
    {
        cout<<root->element<<"  ";
        for(    childrenNodes *child    =   root->childrenList  ;   child   !=  NULL    ;   child   =   child->nextChild    )
        {
            preOrder(child->child);
        }
    }
}

void tree::postOrder(node *root)
{
    if(root==NULL)
        return;

    else
    {
        for(    childrenNodes *child    =   root->childrenList  ;   child   !=  NULL    ;   child   =   child->nextChild    )
        {
            postOrder(child->child);
        }
        cout<<root->element<<"  ";
    }
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
        for(    childrenNodes *child    =   Node->childrenList  ;   child   !=  NULL    ;   child   =   child->nextChild    )
        {
            h = max(h,height2(child->child));
        }
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
    if(temp)                                               // check if char v is a node or not. if v is not a node, returns 0;
    {
        if(temp == root)
            return 0;
        else
        {
            return 1+depth(temp->parentNode->element);
        }
    }
}

void tree::constructTreeManually(tree &T)
{
    string str;
    cout<<"\nfirst type the parent. then type ',' and children. add the children after ',' \nrepeatedly if needed. finally press Enter.\n";
    cin>>str;
    for(int i=0;i<str.size();i+=2)          //index : 0 == parent ; others are children.
    {
        if(!T.searchNode(str[i]))
        {
            T.insertNode(str[i]);
            nodeNumber++;
        }
    }
    for(int i=2;i<str.size();i+=2)          //index : 0 == parent ; others are children.
    {
        T.constructTree(str[0],str[i]);
    }
}

class operationTree
{
public:
    static void inputTree(tree &T);
    static void readFromFile(tree &T);
    static void choice(tree &T,int choice);
};

void operationTree::inputTree(tree &T)
{
        ofstream fout ("treeInput.txt");

        if(!fout)
        {
            cout<<"Can't open.\n";
            exit(-1);
        }

        cin>>nodeNumber;
        fout<<nodeNumber<<endl;
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
    fin>>nodeNumber;

    for(int i=0;i<nodeNumber;i++)
    {
        fin>>str;
        T.insertNode(str[0]);
    }

    while(!fin.eof())
    {
        fin>>str;
        for(int i=2;i<str.size();i+=2)
        {
            T.constructTree(str[0],str[i]);                     //str[0] == parentNode; str[i] == child;
        }
    }
    fin.close();
}

void operationTree::choice(tree &T,int choice)
{
    char v;
    if(choice==1)
    {
        cout<<"\nPreOrder :\t";
        T.preOrder(T.getRoot());
        cout<<endl<<endl;
    }

    if(choice==2)
    {
        cout<<"\nPostOrder :\t";
        T.postOrder(T.getRoot());
        cout<<endl<<endl;
    }

    if(choice==3)
    {
        cout<<"Height of the Tree is : "<<T.height2(T.getRoot())<<endl<<endl;
    }

    if(choice==4)
    {
        cout<<"Enter a Node to Find Depth : ";
        cin>>v;
        cout<<"\nDepth of node "<<v<<" is "<<T.depth(v)<<endl<<endl;
    }

    if(choice==5)
    {
        T.constructTreeManually(T);
    }

    if(choice==6)
    {
        cout<<"Enter a Node to Find as it is Internal Node or Not : ";
        cin>>v;
        if(T.isInternal(v)) cout<<"\nYes. "<<v<<" is the Internal Node of the Tree.\n";
        else cout<<"\nNo. "<<v<<" is not the Internal Node of the Tree.\n";
    }

    if(choice==7)
    {
        cout<<"Enter a Node to Find as it is External Node or Not : ";
        cin>>v;
        if(T.isExternal(v)) cout<<"\nYes. "<<v<<" is the External Node of the Tree.\n";
        else cout<<"\nNo. "<<v<<" is not the External Node of the Tree.\n";
    }
    if(choice==8)
    {
        cout<<"Enter a Node to Find it's All Information : ";
        cin>>v;
        T.nodeInformation(v);
        cout<<endl;
    }
}

int main()
{
    tree T;
    operationTree::readFromFile(T);

    cout<<"\n1. PreOrder\n2. PostOrder\n3. Height\n4. Depth\n5. ContructManually\n6. isInternal\n7. isExternal\n8. Node Information\n\n";
    int choice;
    cin>>choice;

    while(choice!=0)
    {
        operationTree::choice(T,choice);
        cin>>choice;
    }
    return 0;
}
