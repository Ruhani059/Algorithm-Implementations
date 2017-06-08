#include<iostream>
using namespace std;
class node
{
public:
    int key;
    node *next;
};
class Queue
{
    node *front;  //
public:
    Queue();
    ~Queue();
    void enqueue (int key);
    void dequeue ();
    void display ();
    bool isEmpty ();
};

Queue::Queue()
{
    front = NULL;
}

Queue::~Queue()
{
    delete front;
}

void Queue::enqueue(int key)
{
    node *temp;
    temp = front;
    if(front == NULL)
    {
        front = new node;
        front->key = key;
        front->next = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new node;
        temp->next->key = key;
        temp->next->next = NULL;
    }
}

void Queue::dequeue()
{
    if( isEmpty() )
    {
        cout<<"Sorry, Queue is Empty.\n";
    }
    else
    {
        cout<<"Deleted : "<<front->key<<endl;
        node *temp;
        temp = front;
        front = front->next;
        delete temp;
    }
}

void Queue::display()
{
    cout<<"Queue : ";
    node *temp;
    temp = front;
    while(temp != NULL)
    {
        cout<<temp->key<<"\t";
        temp = temp->next;
    }
    cout<<"\n";
}

bool Queue::isEmpty()
{
    if (front == NULL) return true;
    return false;
}

int main()
{
    Queue Q;
    Q.enqueue(2);
    Q.display();
    Q.enqueue(3);
    Q.display();
    Q.enqueue(4);
    Q.display();
    Q.dequeue();
    Q.display();
    Q.enqueue(5);
    Q.display();
    Q.dequeue();
    Q.display();
    Q.dequeue();
    Q.display();
    Q.dequeue();
    Q.display();
    Q.dequeue();
    Q.display();
    Q.dequeue();
    Q.display();
    return 0;
}
