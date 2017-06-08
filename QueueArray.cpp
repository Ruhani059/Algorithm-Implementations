#include<iostream>
using namespace std;
#define max 100
class Queue
{
    int front;
    int rear;
    int item[max];
public:
    Queue();
    void enqueue (int key);
    int dequeue ();
    int dequeueModified ();
    void display ();
    bool isEmpty ();
    bool isFull ();
    int size ();
};

Queue::Queue()
{
    front = 0;
    rear = -1;
}

void Queue::enqueue(int key)
{
    rear++;
    item[rear]=key;
}

int Queue::dequeue()
{
    int p;
    if( isEmpty() )
    {
        p = NULL;
        cout<<"Sorry, Queue is Empty.\n";
    }
    else
    {
        p = item[front];
        front++;
    }
    return p;
}

int Queue::dequeueModified ()
{
    int p;
    if( isEmpty() )
    {
        p = NULL;
        cout<<"Sorry, Queue is Empty.\n";
    }
    else
    {
        p = item[0];
        for(int i=1;i<=rear;i++ )
        {
            item[i-1] = item[i];
        }
        rear--;
    }
    return p;
}

void Queue::display()
{
    cout<<"Queue : ";
    for(int i=front;i<=rear;i++ )
    {
        cout<<item[i]<<"  ";
    }
    cout<<"\n";
}

bool Queue::isEmpty()
{
    if (front > rear) return true;
    return false;
}

bool Queue::isFull()
{
    if(rear-front==-1) return true;
    else return false;
}

int Queue::size()
{
    return rear-front+1;
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
    cout<<"size : "<<Q.size()<<endl;
    cout<<Q.dequeueModified()<<endl;
    Q.display();
    Q.enqueue(5);
    Q.display();
//    cout<<Q.dequeue()<<endl;
    cout<<Q.dequeueModified()<<endl;
    Q.display();
    cout<<"size : "<<Q.size()<<endl;
//    cout<<Q.dequeue()<<endl;
    cout<<Q.dequeueModified()<<endl;
    Q.display();
//    cout<<Q.dequeue()<<endl;
    cout<<Q.dequeueModified()<<endl;
    Q.display();
//    cout<<Q.dequeue()<<endl;
    cout<<Q.dequeueModified()<<endl;
    Q.display();
    cout<<"size : "<<Q.size()<<endl;
//    cout<<Q.dequeue()<<endl;
    cout<<Q.dequeueModified()<<endl;
    Q.display();
    return 0;
}

