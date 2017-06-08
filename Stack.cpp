#include<iostream>
using namespace std;
class node
{
public:
    int key;
    node *next;
};
class Stack
{
    node *top;  //
public:
    Stack();
    ~Stack();
    void push (int key);
    void pop ();
    void display ();
    bool isEmpty ();
};

Stack::Stack()
{
    top = NULL;
}

Stack::~Stack()
{
    delete top;
}

void Stack::push(int key)
{
    node *temp;
    temp = new node;
    temp->key = key;
    temp->next = NULL;
    if(top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}

void Stack::pop()
{
    if( isEmpty() )
    {
        cout<<"Sorry, Stack is Empty.\n";
    }
    else
    {
        cout<<"Deleted : "<<top->key<<endl;
        node *temp;
        temp = top;
        top = top->next;
        delete temp;
    }
}

void Stack::display()
{
    cout<<"Stack : ";
    node *temp;
    temp = top;
    while(temp != NULL)
    {
        cout<<temp->key<<"\t";
        temp = temp->next;
    }
    cout<<"\n";
}

bool Stack::isEmpty()
{
    if (top == NULL) return true;
    return false;
}

int main()
{
    Stack S;
    S.push(2);
    S.display();
    S.push(3);
    S.display();
    S.push(4);
    S.display();
    S.pop();
    S.display();
    S.push(5);
    S.display();
    S.pop();
    S.display();
    S.pop();
    S.display();
    S.pop();
    S.display();
    S.pop();
    S.display();
    S.push(7);
    S.display();
    S.pop();
    S.display();
    S.pop();
    S.display();
    S.pop();
    S.display();
    return 0;
}
