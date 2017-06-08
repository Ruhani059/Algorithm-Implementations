#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
class binary_tree
{
private:
    node *root;
    void destroy_tree(node *leaf);
    void insert(int key, node *leaf);
    node *search(int key, node *leaf);
    void show (node *leaf);
public:
    binary_tree();
    ~binary_tree();
    void insert(int key);
    node *search(int key);
    void destroy_tree();
    void show ();
};

binary_tree::binary_tree()
{
    root = NULL;
}

binary_tree::~binary_tree()
{
    destroy_tree();
}

void binary_tree::destroy_tree(node *leaf)
{
    if( leaf != NULL)
    {
        destroy_tree( leaf->left );
        destroy_tree( leaf->right );
        delete leaf;
    }
}

void binary_tree::insert(int key, node *leaf)
{
    if (key < leaf->data)
    {
        if(leaf->left!=NULL)
        {
            insert (key , leaf->left);
        }
        else
        {
            leaf->left = new node;
            leaf->left->data = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }
    else
    {
        if(leaf->right != NULL)
        {
            insert(key , leaf->right);
        }
        else
        {
            leaf->right = new node;
            leaf->right->data = key;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}

node *binary_tree::search(int key, node *leaf)
{
    if (leaf != NULL)
    {
        if(key < leaf->data)
            return search( key, leaf->left);

        else if(key > leaf->data)
            return search( key, leaf->right);

        else
            return leaf;
    }
    else
        return NULL;
}

void binary_tree::show(node *leaf)
{
    if(leaf!=NULL)
    {
        cout<<leaf->data<<" ";
        show(leaf->left);
        show(leaf->right);
    }
}

void binary_tree::insert(int key)
{
    if (root != NULL)
        insert(key, root);

    else
    {
        root = new node;
        root->data = key;
        root->left = NULL;
        root->right = NULL;
    }
}

node *binary_tree::search(int key)
{
    search(key,root);
}

void binary_tree::destroy_tree()
{
    destroy_tree ( root );
}

void binary_tree::show()
{
    show(root);
}
int main ()
{
    int N,key;
    cin>>N;
    binary_tree a;
    for(int i=0;i<N;i++)
    {
        cin>>key;
        a.insert(key);
    }
    a.show();
    return 0;
}
